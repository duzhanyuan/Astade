wxFileName ret;

if ((myOperationParser == 0) || (!myOperationParser->ParseSuccessful()))
	return ret;

if (!myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] != '~')
{
	// normal operation
	ret = AdeOperation::CreateNewElement(myModelElement->GetFileName(),
			myOperationParser->functionName,
			myOperationParser->returnType,
			myOperationParser->isVirtual,
			false,
			myOperationParser->isStatic,
			myOperationParser->isConst);

	ReEngineerParameter(ret);
	ReEngineerBody(ret);
}

if (myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] == '~')
{
	// destructor
	ret = AdeDestructor::CreateNewElement(myModelElement->GetFileName());
	ReEngineerBody(ret);
}

if (myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] != '~')
{
	// possible Constructor
	int result = wxMessageDialog(ourTree, "The function in clipboard has no return type.\nIs it a constructor?", "Constructor?", wxYES_NO).ShowModal();

	if (result == wxID_YES)
		ret = AdeConstructor::CreateNewElement(myModelElement->GetFileName());
	else
		// normal operation
		ret = AdeOperation::CreateNewElement(myModelElement->GetFileName(),
				myOperationParser->functionName,
				"int",
				myOperationParser->isVirtual,
				false,
				myOperationParser->isStatic,
				myOperationParser->isConst);

	ReEngineerParameter(ret);
	ReEngineerBody(ret);
}


return ret;