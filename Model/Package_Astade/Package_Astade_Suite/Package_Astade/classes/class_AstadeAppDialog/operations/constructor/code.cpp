//~~ AstadeAppDialog() [AstadeAppDialog] ~~

// Controls
sizerList_staticbox = new wxStaticBox(this, -1, wxS("Applications"));

//|wxSUNKEN_BORDER
lstApps = new wxListBox(this, ID_LISTBOX_APPS, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxLB_SORT);

txtExt = new wxTextCtrl(this, ID_TEXTCTRL_EXT);
txtApp = new wxTextCtrl(this, ID_TEXTCTRL_APP);
txtIcon = new wxTextCtrl(this, ID_TEXTCTRL_ICON);
btnAdd = new wxButton(this, ID_BUTTON_ADD, wxS("&Add"));
btnRemove = new wxButton(this, ID_BUTTON_REMOVE, wxS("&Remove"));
btnUpdate = new wxButton(this, ID_BUTTON_UPDATE, wxS("&Update"));
btnCancel = new wxButton(this, wxID_CANCEL);
btnOk = new wxButton(this, wxID_OK);
btnBrowseExt = new wxBitmapButton(this, ID_BUTTON_EXT, wxBitmap(fileopen));
btnBrowseApp = new wxBitmapButton(this, ID_BUTTON_APP, wxBitmap(fileopen));
btnBrowseIcon = new wxBitmapButton(this, ID_BUTTON_ICON, wxBitmap(fileopen));

// Layout
wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
wxBoxSizer* sizerAddRemove = new wxBoxSizer(wxHORIZONTAL);
wxBoxSizer* sizerCancelOk = new wxBoxSizer(wxHORIZONTAL);
wxStaticBoxSizer* sizerList = new wxStaticBoxSizer(sizerList_staticbox, wxVERTICAL);
wxStaticBox* sizerUpdate_staticbox = new wxStaticBox(this, -1, wxS("Update Entry"));
wxStaticBoxSizer* sizerUpdateBox = new wxStaticBoxSizer(sizerUpdate_staticbox, wxVERTICAL);
wxFlexGridSizer* sizerUpdate = new wxFlexGridSizer(3);

sizerUpdate->AddGrowableCol(1, 1);
sizerUpdate->Add(new wxStaticText(this, -1, wxS("File Type")), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxLEFT | wxRIGHT, 10);
sizerUpdate->Add(txtExt, 0, wxALL|wxEXPAND, 2);
sizerUpdate->Add(btnBrowseExt, 0, wxALIGN_RIGHT | wxLEFT, 10);
sizerUpdate->Add(new wxStaticText(this, -1, wxS("Application")), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxLEFT | wxRIGHT, 10);
sizerUpdate->Add(txtApp, 0, wxALL|wxEXPAND, 2);
sizerUpdate->Add(btnBrowseApp, 0, wxALIGN_RIGHT | wxLEFT, 10);
sizerUpdate->Add(new wxStaticText(this, -1, wxS("Icon")), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT | wxLEFT | wxRIGHT, 10);
sizerUpdate->Add(txtIcon, 0, wxALL|wxEXPAND, 2);
sizerUpdate->Add(btnBrowseIcon, 0, wxALIGN_RIGHT | wxLEFT, 10);
sizerUpdate->SetMinSize(sizerUpdate->CalcMin());

sizerUpdateBox->Add(sizerUpdate, 0, wxALL|wxEXPAND, 2);
sizerUpdateBox->SetMinSize(sizerUpdateBox->CalcMin());

sizerAddRemove->AddStretchSpacer();
sizerAddRemove->Add(btnAdd, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 10);
sizerAddRemove->AddStretchSpacer();
sizerAddRemove->Add(btnRemove, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 10);
sizerAddRemove->AddStretchSpacer();
sizerAddRemove->Add(btnUpdate, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 10);
sizerAddRemove->AddStretchSpacer();

sizerList->Add(lstApps, 1, wxALL|wxEXPAND, 2);
sizerList->Add(sizerUpdateBox, 0, wxALL|wxEXPAND, 2);
sizerList->Add(sizerAddRemove, 0, wxALL|wxEXPAND, 2);
sizerList->SetMinSize(sizerList->CalcMin());
topSizer->Add(sizerList, 1, wxALL|wxEXPAND, 5);

sizerCancelOk->AddStretchSpacer();
sizerCancelOk->Add(btnCancel,  0, wxRIGHT, 10);
sizerCancelOk->Add(btnOk, 0, wxALIGN_RIGHT | wxRIGHT, 10);
topSizer->Add(sizerCancelOk, 0, wxALL|wxEXPAND, 5);

//topSizer->SetMinSize(wxSize(450, 700));
SetAutoLayout(true);
SetSizerAndFit(topSizer);
