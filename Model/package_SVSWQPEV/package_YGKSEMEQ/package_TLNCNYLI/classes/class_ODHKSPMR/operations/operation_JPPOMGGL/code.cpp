wxMenu* aSubUp = new wxMenu(wxEmptyString);

int id = ID_JUMP;
AdeElementIterator it;
std::map<wxString,int> menuItems;

// Generating the classes
for (it = component.GetFirstBelongingClass(); it != component.end(); ++it)
{
	if (id >= ID_JUMPMAX)
		break;
	AdeModelElement* anElement = it.CreateNewElement();
	menuItems[anElement->GetName()] = id++;
	delete anElement;
}

// Generating the statecharts
for (it = component.GetFirstBelongingStatechart(); it != component.end(); ++it)
{
	if (id >= ID_JUMPMAX)
		break;
	AdeModelElement* anElement = it.CreateNewElement();
	menuItems[anElement->GetName()] = id++;
	delete anElement;
}

for (std::map<wxString,int>::iterator iter = menuItems.begin(); iter != menuItems.end(); iter++)
{
	aSubUp->Append((*iter).second, (*iter).first);
}

return aSubUp;