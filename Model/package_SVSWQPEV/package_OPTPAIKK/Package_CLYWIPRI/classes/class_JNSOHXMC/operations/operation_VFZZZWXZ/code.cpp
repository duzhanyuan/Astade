wxString cmd = "svn del "+fileName.GetFullPath();
long retVal = wxExecute(cmd, *theOutput, wxEXEC_SYNC);
return (retVal)? -1 : 0;