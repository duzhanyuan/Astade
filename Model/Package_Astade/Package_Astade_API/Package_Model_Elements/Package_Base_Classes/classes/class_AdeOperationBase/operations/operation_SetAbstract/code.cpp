//~~ void SetAbstract(bool value) [AdeOperationBase] ~~
if (value)
	myConfig->Write(wxS("Astade/Abstract"), wxS("yes"));
else
	myConfig->Write(wxS("Astade/Abstract"), wxS("no"));
