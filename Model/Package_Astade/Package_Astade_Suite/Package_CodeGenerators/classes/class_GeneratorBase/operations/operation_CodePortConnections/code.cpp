//~~ void CodePortConnections(std::ofstream& out) [GeneratorBase] ~~

AdeConnections* theConnections = source->GetConnections();

if (theConnections)
{
    out << "\n\t//connecting the inner ports" << std::endl;
	for (AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
        AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(anElement);
		wxASSERT_MSG(aConnection, "the Connections folder should only contain connections");

        wxString InputObject = aConnection->GetInputObject();
        wxString InputPort = aConnection->GetInputPort();
        wxString OutputObject = aConnection->GetOutputObject();
        wxString OutputPort = aConnection->GetOutputPort();

        if (source->codingLanguage() == CODE_C)
        {
            out << "\tCONNECT_PORTS(" << "me->" << source->GetObject(InputObject, InputPort) << ", "
                                      << "me->" << source->GetObjectPort(InputObject, InputPort) << ", "
                                      << "me->" << source->GetObject(OutputObject, OutputPort) << ", "
                                      << "me->" << source->GetObjectPort(OutputObject, OutputPort) << ");" << std::endl;
        }
        else
        {
            out << "\tCONNECT_PORTS(" << source->GetObject(InputObject, InputPort) << ", "
                                      << source->GetObjectPort(InputObject, InputPort) << ", "
                                      << source->GetObject(OutputObject, OutputPort) << ", "
                                      << source->GetObjectPort(OutputObject, OutputPort) << ");" << std::endl;
        }

		delete anElement;
	}
    delete theConnections;
}