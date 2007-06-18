wxPoint aPosition = event.GetPosition();
bool refreshNeeded = false;

for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
{
	std::list<ACNode*> aList = (*itR)->GetNodes();

	for (std::list<ACNode*>::iterator itN = aList.begin(); itN != aList.end(); itN++)
 		if ((*itN)->SetMouseOver((*itN)->IsInArea(aPosition)))
 			refreshNeeded = true;
}

if (refreshNeeded)
	Refresh();