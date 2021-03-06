wxString estimatedFilename = GetName();
estimatedFilename.Replace(wxS(" "), wxS("_"));
estimatedFilename = wxS("Components_") + estimatedFilename;

wxFileName realFileName = GetFileName();
wxFileName newFilename(realFileName);

newFilename.RemoveLastDir();
newFilename.AppendDir(estimatedFilename);

realFileName.SetFullName(wxEmptyString);
newFilename.SetFullName(wxEmptyString);

if (realFileName != newFilename)
{
	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(realFileName, newFilename);
	if (rc == 0)
		SetFileName(newFilename);
}
