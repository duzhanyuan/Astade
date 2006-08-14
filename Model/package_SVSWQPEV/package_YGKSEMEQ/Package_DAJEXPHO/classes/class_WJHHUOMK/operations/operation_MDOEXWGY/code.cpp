fprintf(implementationFile,"#include \"%s.h\"\n\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"// Include of event primitive defines\n");
fprintf(specificationFile,"#include %s\n\n",theStatechart.GetEventType().c_str());
fprintf(specificationFile,"// Include of VirtualStateMachine base class\n");
fprintf(specificationFile,"#include VirtualStateMachine.hpp\n\n");

fprintf(specificationFile,"class %s : public CVirtualStateMachine\n{\n",theStatechart.GetName().c_str());

fprintf(specificationFile,"\tpublic:\n");
CodeTriggerIDs(theStatechart);
CodeConstructor(theStatechart);

AdeElementIterator it;

fprintf(specificationFile,"\n\tprotected:\n");

CodeActions(theStatechart);
CodeGuards(theStatechart);

fprintf(specificationFile,"\n\tprivate:\n");

CodeNoState(theStatechart);
CodeEnterPointer(theStatechart);
CodeEnterFunction(theStatechart);

for (it=theStatechart.begin();it!=theStatechart.end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		CodeStateFunction(theStatechart,*aState);
		CodeEnterState(theStatechart,*aState);
	}
	delete aElement;
}

fprintf(specificationFile,"};\n");
