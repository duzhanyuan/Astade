wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString PartnerPath = theConfig.Read("Astade/PartnerPath");
wxFileName PartnerFile(PartnerPath);
PartnerFile.MakeAbsolute();
thePartnerFileName = PartnerFile;