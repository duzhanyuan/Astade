//~~ void CopyMakefile(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName;
theFileName.AssignDir(theConfig->Read(wxS("TreeView/TemplatesPath")));

const wxString& dir = wxFileSelector(wxS("Select Makefile"), theFileName.GetPath(), wxS("Makefile"), wxEmptyString, wxS("*"), 0, this);  //Creates file select window.
if (dir.empty())  //This condition does not seem work.
	return;

wxFileName filename(dir);

wxTreeItemId anID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(anID)->GetFileName();

parentPath.SetFullName(wxS("Makefile"));

if (parentPath.FileExists())
{
	wxMessageDialog aDialog(this, wxS("File already exists. Overwrite?"), wxS("Copy Makefile:"), wxOK | wxCANCEL | wxICON_EXCLAMATION);
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;
	wxCopyFile(filename.GetFullPath(), parentPath.GetFullPath());
}
else
{
	wxCopyFile(filename.GetFullPath(), parentPath.GetFullPath());
	myTree->AppendItem(anID, parentPath);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		theRevisionControl->Add(parentPath);
		wxArrayString output = theRevisionControl->GetOutput();
	}
}
