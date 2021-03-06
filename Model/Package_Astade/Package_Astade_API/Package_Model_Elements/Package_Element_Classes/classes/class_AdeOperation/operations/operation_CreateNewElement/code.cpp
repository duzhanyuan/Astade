//~~ wxFileName CreateNewElement(const wxFileName& parentFolder, const wxString& operationName = wxS("operation"), const wxString& codingType = wxS("void"), bool isVirtual = false, bool isAbstract = false, bool isStatic = false, bool isConst = false, bool isInline = false) [AdeOperation] ~~

wxFileName aFileName = AdeDirectoryElement::CreateNewElement(parentFolder, wxS("operation"), ITEM_IS_OPERATION | ITEM_IS_NORMALOP | ITEM_IS_PRIVATE, true);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/CodingType"), codingType);
theConfig.Write(wxS("Astade/Name"),       operationName);

theConfig.Write(wxS("Astade/Virtual"),  isVirtual  ? wxS("yes") : wxS("no"));
theConfig.Write(wxS("Astade/Abstract"), isAbstract ? wxS("yes") : wxS("no"));
theConfig.Write(wxS("Astade/Static"),   isStatic   ? wxS("yes") : wxS("no"));
theConfig.Write(wxS("Astade/Const"),    isConst    ? wxS("yes") : wxS("no"));
theConfig.Write(wxS("Astade/Inline"),   isInline   ? wxS("yes") : wxS("no"));

theConfig.Flush();

return aFileName;
