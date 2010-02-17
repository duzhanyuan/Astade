		bool retVal = false;

wxTreeItemId aID = myTree->HitTest(point);
if(!aID.IsOk())
	return false;

myTree->SelectItem(aID);
AdeModelElement* dest = myTree->GetItem(aID);
wxFileName parentPath = dest->GetFileName();

for(unsigned int i = 0; i < filenames.GetCount(); i++)
{
	wxFileName aFile(filenames[i]);
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(aFile);
	// do this type of element fit here?
	if(aElement->GetFileName() != parentPath)
	{
		if(dest->CanContain(*aElement))
		{
			wxFileName theNewElement = aElement->CreateCopy(parentPath); // copy the element here
			myTree->AppendItem(aID,theNewElement);
			retVal = true;
		}
		// if the source is a class and the destination is a relations-folder => create a relation
		else if((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS
				 && (dest->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATIONS)
		{
			wxTreeItemId startId = myTree->GetItemParent(aID);
			wxFileName theNewRelation = AdeRelation::CreateNewElement(myTree->GetItem(startId)->GetFileName(), aElement->GetFileName());
			myTree->AppendItem(aID,theNewRelation);
		}
		else
		{
			wxString aString = wxString("The File '") + filenames[i] + "' cannot be dropped here. This type of element does not fit!";
			wxLogMessage("%s",aString.GetData());
		}
	}
	else
	{
		wxString aString = wxString("The File '") + filenames[i] + "' cannot be dropped here. The element cannot be copied to itself!";
		wxLogMessage("%s",aString.GetData());
	}
	delete(aElement);
}

return retVal;