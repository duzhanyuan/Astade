/* vi: set tabstop=4: */

GrafNode::OnDraw(dc);

if (m_MouseOver)
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
}
else
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));
}

int w,h;
GetSize(&w,&h);
dc.DrawEllipse((-w/2)+m_DrawPosition.xCoord(),(-h/2)+m_DrawPosition.yCoord(),w,h);

wxString label = myLabel->GetLineText(0);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_DrawPosition.xCoord()-(w/2),m_DrawPosition.yCoord()-(h+(h/2)));

label.Empty();
if (myLabel->GetNumberOfLines() > 1)
	label = myLabel->GetLineText(1);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_DrawPosition.xCoord()-(w/2),m_DrawPosition.yCoord()-(h/2));

label.Empty();
if (myLabel->GetNumberOfLines() > 2)
	label = myLabel->GetLineText(2);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_DrawPosition.xCoord()-(w/2),m_DrawPosition.yCoord()+(h/2));

for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
	(*it)->OnDraw(dc);

for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
	(*it)->OnDraw(dc);

for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
	(*it)->OnDraw(dc);
