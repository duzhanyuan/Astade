aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE | COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDPACKAGE,"add package",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCLASSES,"add classes",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDSEQUENCES,"add sequence diagrams",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_OBJECTMODELDIALOG,"Object model diagram",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();

if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
	aPopUp.Append(ID_RENAMEELEMENT,"Rename package folder",wxEmptyString, wxITEM_NORMAL);

aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasClasses())
	aPopUp.Enable(ID_ADDCLASSES,false);

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasSequences())
	aPopUp.Enable(ID_ADDSEQUENCES,false);

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasUsecaseDiagrams())
	aPopUp.Enable(ID_ADDUSECASEDS,false);
