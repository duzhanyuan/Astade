fprintf(implementationFile, "#include \"%s.h\"\n\n", (const char*)theStatechart.GetName().c_str());

wxArrayString nativeTypes;

nativeTypes.Add("void");
nativeTypes.Add("int");
nativeTypes.Add("float");
nativeTypes.Add("double");
nativeTypes.Add("char");
nativeTypes.Add("bool");
nativeTypes.Add("wchar_t");

nativeTypes.Add("unsigned char");
nativeTypes.Add("signed char");
nativeTypes.Add("unsigned int");
nativeTypes.Add("unsigned");
nativeTypes.Add("signed int");
nativeTypes.Add("signed");
nativeTypes.Add("short int");
nativeTypes.Add("unsigned short int");
nativeTypes.Add("signed short int");
nativeTypes.Add("long int");
nativeTypes.Add("long");
nativeTypes.Add("signed long int");
nativeTypes.Add("unsigned long int");
nativeTypes.Add("long double");

if (nativeTypes.Index(theStatechart.GetEventType().c_str()) == wxNOT_FOUND)
{
	fprintf(specificationFile, "// forward declaration of event type\n");
	fprintf(specificationFile, "struct %s;\n\n", (const char*)theStatechart.GetEventType().c_str());
}

fprintf(specificationFile, "// include of the handle class\n");
fprintf(specificationFile, "#include %s_impl.h;\n\n", (const char*)theStatechart.GetName().c_str());

fprintf(specificationFile, "/**@dot\n");
StateChartDrawer::drawStatechart(theStatechart, specificationFile);
fprintf(specificationFile, "@enddot\n\n");

wxString description(theStatechart.GetDescription());
if (!description.empty())
    fprintf(specificationFile,"%s\n*/\n",description.c_str());
else
    fprintf(specificationFile,"*/\n");

fprintf(specificationFile, "typedef struct\n{\n");
CodeState(theStatechart);
CodeEnterPointer(theStatechart);
CodeHandlePointer(theStatechart);
fprintf(specificationFile,"} %s;\n\n", (const char*)theStatechart.GetName().c_str());

CodeTriggerIDs(theStatechart);
CodeInitialize(theStatechart);
CodeTakeEvent(theStatechart);

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateFunction(theStatechart, *static_cast<AdeState*>(aElement));
	delete aElement;
}

CodeEnterFunction(theStatechart);

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(theStatechart, *aState);
		CodeEnterState(theStatechart, *aState);
	}
	delete aElement;
}