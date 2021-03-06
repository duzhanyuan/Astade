//~~ void AddActionSizer(wxSizer* topSizer, wxWindow* parent) [ResourceEdit] ~~
wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(parent, -1, wxS("Action 1:"), wxDefaultPosition, wxSize(70,15)));

action1 =  new wxTextCtrl(parent, -1);
action1->SetMaxLength(128);

box->Add(action1,1);
action1->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Action1"), wxEmptyString));

box->Add(new wxStaticText(parent, -1, wxS("Action 2:"), wxDefaultPosition, wxSize(70,15)), 0, wxLEFT, 10);

action2 =  new wxTextCtrl(parent, -1);
action2->SetMaxLength(128);

box->Add(action2,1);
action2->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Action2"), wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);



box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(parent, -1, wxS("Action 3:"), wxDefaultPosition, wxSize(70,15)));

action3 =  new wxTextCtrl(parent, -1);
action3->SetMaxLength(128);

box->Add(action3,1);
action3->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Action3"), wxEmptyString));

box->Add(new wxStaticText(parent, -1, wxS("Action 4:"), wxDefaultPosition, wxSize(70,15)), 0, wxLEFT, 10);

action4 =  new wxTextCtrl(parent, -1);
action4->SetMaxLength(128);

box->Add(action4,1);
action4->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Action4"), wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT,10);
