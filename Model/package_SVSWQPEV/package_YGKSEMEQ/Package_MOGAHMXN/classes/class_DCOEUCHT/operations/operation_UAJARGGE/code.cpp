indexBase = AstadeIcons::Instance()->GetImageCount();

wxBitmap aBitmap(ASTADEICONWIDTH,ASTADEICONHIGHT);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(AstadeIcons::GetFileIcon(),0,0,true);
dc.DrawBitmap(AstadeIcons::GetMakeIcon(),0,0,true);
AstadeIcons::Instance()->Add(wxBitmap(aBitmap.ConvertToImage()));