if (myFileName.GetExt()=="cpp")
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt()=="c")
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt()=="h")
	return ITEM_IS_HFILE;
if (myFileName.GetExt()=="dox")
	return ITEM_IS_DOXFILE;

return ITEM_IS_FILE;