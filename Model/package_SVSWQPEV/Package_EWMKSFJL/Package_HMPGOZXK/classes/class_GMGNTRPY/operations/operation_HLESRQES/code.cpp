int minx, maxx, miny, maxy;
glVector absStartPoint = absGetStartPoint();
glVector absEndPoint = absGetEndPoint();

if (absStartPoint.xCoord() < absEndPoint.xCoord())
{
	minx = absStartPoint.xCoord();
	maxx = absEndPoint.xCoord();
}
else
{
	maxx = absStartPoint.xCoord();
	minx = absEndPoint.xCoord();
}

if (absStartPoint.yCoord() < absEndPoint.yCoord())
{
	miny = absStartPoint.yCoord();
	maxy = absEndPoint.yCoord();
}
else
{
	maxy = absStartPoint.yCoord();
	miny = absEndPoint.yCoord();
}

myParent->RefreshRect(wxRect(minx-1, miny-1, (maxx-minx) + 2, (maxy-miny) + 2));
