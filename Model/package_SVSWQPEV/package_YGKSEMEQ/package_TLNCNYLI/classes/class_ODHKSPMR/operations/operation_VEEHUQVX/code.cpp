wxTreeItemId aID = myTree->GetSelection();

if (!myTree->GetItemObject(aID)->OfferPaste())
	return;

wxFileName destination = myTree->GetItem(aID)->GetFileName();

AdeModelElement* aElement = AstadeTreeItemBase::GetGlobalCopySource()->GetModelElement();

wxFileName parentPath;
parentPath.AssignDir(destination.GetPath());			   //directory where to make copy for whatever element from Astade tree.

if(doCut)
{
	aElement->Move(parentPath);                          //
	myTree->Delete(AstadeTreeItemBase::GetGlobalCopySource()->GetId());
}
else
{
	aElement->CreateCopy(parentPath);                          //Applying polymorphism CreateCopy(...). An element should define this function.
}

myTree->GetItemObject(aID)->Touch();
UpdateSubtree(aID);