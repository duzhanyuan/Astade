//~~ void CodeStatechart() [StateChartCoderACF] ~~

spec << "#ifndef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
spec << "#  define __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h\n"
	<< std::endl;

spec << "// specification prolog" << std::endl;
InsertFile(spec, wxFileName(wxS("prolog.h")));
impl << "// implementation prolog" << std::endl;
InsertFile(impl, wxFileName(wxS("prolog.cpp")));

impl << "#include \""
	<< myAdeStatechart->GetName().utf8_str()
	<< ".h\"\n"
	<< "#include \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "_impl.h\"\n"
	<< "#include \"ACF_events.h\""
	<< std::endl;

spec << "#ifdef __cplusplus" << std::endl;
spec << "extern \"C\" {" << std::endl;
spec << "#endif\n" << std::endl;

spec << "// include the framework" << std::endl;
spec << "#include \"ACF.h\"\n" << std::endl;

spec << "/** @dot" << std::endl;
StateChartDrawer::drawStatechart(spec, *myAdeStatechart);
spec << "@enddot\n" << std::endl;
wxString description(myAdeStatechart->GetDescription());
if (!description.empty())
	spec << description.utf8_str() << std::endl;
spec << "*/" << std::endl;

impl << "#ifdef __cplusplus" << std::endl;
impl << "extern \"C\" {" << std::endl;
impl << "#endif\n" << std::endl;

CodeCommonEventFiles();

impl << "#ifdef __cplusplus" << std::endl;
impl << "}" << std::endl;
impl << "#endif\n" << std::endl;

spec << "typedef struct "
	<< myAdeStatechart->GetName().utf8_str()
	<< std::endl;
spec << "{" << std::endl;

CodeState();
CodeEnterPointer();

spec << "} "
	<< myAdeStatechart->GetName().utf8_str()
	<< ";\n"
	<< std::endl;

CodeConstructor();
CodeNoState();
CodeInitialize();
CodeTakeEvent();

CodeEnterFunction();

AdeElementIterator it;
for (it = myAdeStatechart->begin(); it != myAdeStatechart->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		CodeStateFunction(*aState);
		CodeEnterState(*aState);
	}
	delete anElement;
}

spec << "#ifdef __cplusplus" << std::endl;
spec << "}" << std::endl;
spec << "#endif\n" << std::endl;

spec << "\n// specification epilog" << std::endl;
InsertFile(spec, wxFileName(wxS("epilog.h")));
impl << "\n// implementation epilog" << std::endl;
InsertFile(impl, wxFileName(wxS("epilog.cpp")));

spec << "\n#endif // #ifdef __"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_h"
	<< std::endl;
