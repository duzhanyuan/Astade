wxFileName aName(myFileName);

aName.AppendDir("sequences");

return wxFileName::DirExists(aName.GetPath());