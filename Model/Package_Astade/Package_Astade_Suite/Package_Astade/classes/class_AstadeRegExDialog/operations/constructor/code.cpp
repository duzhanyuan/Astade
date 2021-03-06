//~~ AstadeRegExDialog() [AstadeRegExDialog] ~~

wxBoxSizer* aSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(aSizer);

aSizer->AddStretchSpacer();

// identify expression
aSizer->Add(
	new wxStaticText(this, -1, wxS("Identify an error line in the make output")), 
	0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);

identifyExpression = new wxTextCtrl(this, 0, wxEmptyString);
aSizer->Add(identifyExpression, 0, wxEXPAND | wxRIGHT | wxLEFT, 10);

// errorFile expression
aSizer->Add(
	new wxStaticText(this, -1, wxS("Find the file name where the error occurred")), 
	0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);

errorFileExpression = new wxTextCtrl(this, 0, wxEmptyString);
aSizer->Add(errorFileExpression, 0, wxEXPAND | wxRIGHT | wxLEFT, 10);

// errorLine expression
aSizer->Add(
	new wxStaticText(this, -1, wxS("Find the line number where the error occurred")), 
	0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);

errorLineExpression = new wxTextCtrl(this, 0, wxEmptyString);
aSizer->Add(errorLineExpression, 0, wxEXPAND  | wxBOTTOM | wxRIGHT | wxLEFT, 10);

//Buttons
wxBoxSizer* anotherSize = new wxBoxSizer(wxHORIZONTAL);
anotherSize->Add(new wxButton(this, ID_DEFAULT, wxS("Restore Defaults")), 0, wxALIGN_LEFT | wxLEFT | wxRIGHT, 10);
anotherSize->AddStretchSpacer();
cancel = new wxButton(this, wxID_CANCEL);
anotherSize->Add(cancel, 0, wxRIGHT, 10);
anotherSize->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT | wxRIGHT, 10);

aSizer->AddStretchSpacer();
aSizer->Add(anotherSize, 0, wxEXPAND | wxBOTTOM, 10);

aSizer->SetSizeHints(this);
