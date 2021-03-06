//~~ wxString GetDiagramLabel() [AdeState] ~~
wxString label = myConfig->Read(wxS("Astade/Name"), wxS("<name unknown>"));
wxString internals;

if (!myConfig->Read(wxS("Astade/Timeout")).empty())
{
    if (!internals.empty())
        internals += wxS("\\n");
    internals += wxS("Timeout: ");
    internals += myConfig->Read(wxS("Astade/Timeout"));
}

if (!myConfig->Read(wxS("Astade/EntryAction")).empty())
{
    if (!internals.empty())
        internals += wxS("\\n");
    internals += wxS("Entry: ");
    internals += myConfig->Read(wxS("Astade/EntryAction"));
}

if (!myConfig->Read(wxS("Astade/ExitAction")).empty())
{
    if (!internals.empty())
        internals += wxS("\\n");
    internals += wxS("Exit: ");
    internals += myConfig->Read(wxS("Astade/ExitAction"));
}

// events with guards
for (AdeElementIterator it = begin(); it != end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if ((aTransition->IsInternalTransition()) && 
            (!aTransition->GetGuard().empty()) && 
            (!aTransition->IsAllTransition()))
        {
            if (!internals.empty())
                internals += wxS("\\n");
            internals += aTransition->GetLabel();
        }
    }
    delete anElement;
}

// events without guards
for (AdeElementIterator it = begin(); it != end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if ((aTransition->IsInternalTransition()) && 
            (aTransition->GetGuard().empty()) && 
            (!aTransition->IsAllTransition()))
        {
            if (!internals.empty())
                internals += wxS("\\n");
            internals += aTransition->GetLabel();
        }
    }
    delete anElement;
}

// all with guards
for (AdeElementIterator it = begin(); it != end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if ((aTransition->IsInternalTransition()) && 
            (!aTransition->GetGuard().empty()) && 
            (aTransition->IsAllTransition()))
        {
            if (!internals.empty())
                internals += wxS("\\n");
            internals += aTransition->GetLabel();
        }
    }
    delete anElement;
}

// all without guards
for (AdeElementIterator it = begin(); it != end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if ((aTransition->IsInternalTransition()) && 
            (aTransition->GetGuard().empty()) && 
            (aTransition->IsAllTransition()))
        {
            if (!internals.empty())
                internals += wxS("\\n");
            internals += aTransition->GetLabel();
        }
    }
    delete anElement;
}

if (!internals.empty())
{
    label += wxS(" | ");
    label += internals;
}

return label;
