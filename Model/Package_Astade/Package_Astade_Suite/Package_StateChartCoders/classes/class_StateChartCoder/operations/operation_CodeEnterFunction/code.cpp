spec << "\t//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec << "\t//! @param theEvent The event passed to the actions and guards." << std::endl;
spec << "\tvoid EnterState(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::EnterState(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\twhile (nextState)" << std::endl;
impl << "\t\t(this->*nextState)(theEvent);" << std::endl;
impl << "}" << std::endl;