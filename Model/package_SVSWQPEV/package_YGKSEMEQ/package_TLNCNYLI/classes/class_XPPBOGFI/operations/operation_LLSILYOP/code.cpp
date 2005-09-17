wxConfigBase* theConfig = wxConfigBase::Get();

modelPathTextControl.SetValue(theConfig->Read("TreeView/ModelPath"));
helpPathTextControl.SetValue(theConfig->Read("TreeView/Helpfile"));
featureEditPathTextControl.SetValue(theConfig->Read("Tools/FeatureEdit"));
codeEditPathTextControl.SetValue(theConfig->Read("Tools/CodeEdit"));
omdPathTextControl.SetValue(theConfig->Read("Tools/OmdViewPath"));
coderPathTextControl.SetValue(theConfig->Read("Tools/Coder"));
makePathTextControl.SetValue(theConfig->Read("Tools/Make"));
templatesPathTextControl.SetValue(theConfig->Read("TreeView/TemplatesPath"));

Show(true);
