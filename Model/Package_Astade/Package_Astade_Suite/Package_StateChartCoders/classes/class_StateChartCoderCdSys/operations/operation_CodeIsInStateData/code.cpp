//~~ void CodeIsInStateData(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~

fprintf(specificationFile, "/*!@brief List of states */\n");
fprintf(specificationFile, "typedef enum\t%s_sm_state_id\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(specificationFile, "{\n");

fprintf(implementationFile, "// This array is for the is in State Function \n");
fprintf(implementationFile, "static\t%s_SM_STATE\t_the_states[%s_SM_STATE_ID_LAST_ELEMENT] =\n",
(const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(implementationFile, "{\n");

AdeElementIterator it;
for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
		CodeIsInStateDataElement(theStatechart, *static_cast<AdeState*>(anElement));
	delete anElement;
}

fprintf(implementationFile, "};\n\n");

fprintf(specificationFile, "\n");
fprintf(specificationFile, "\t%s_SM_STATE_ID_LAST_ELEMENT\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "} %s_SM_STATE_ID;\n\n", (const char*)theStatechart.GetName().Upper().utf8_str());
