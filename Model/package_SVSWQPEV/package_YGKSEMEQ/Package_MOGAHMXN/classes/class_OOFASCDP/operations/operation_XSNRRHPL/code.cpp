AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDCLASS,"add class",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDLIBCLASS,"add lib class",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDSTATECHART,"add statechart",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_OBJECTMODELDIALOG,"Object model diagram",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);