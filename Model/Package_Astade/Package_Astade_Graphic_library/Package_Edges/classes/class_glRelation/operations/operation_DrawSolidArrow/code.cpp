glVector diff;
glVector endcenter;
glVector end = absGetEndPoint();

if (width==0)
{
    diff =  absGetStartPoint() - end;
    diff =  diff.Dir();
    diff *= 10;
}
else
{
    endcenter = absCalculateCenterPoint() ;

    diff = end - endcenter;
    diff =  diff.Dir();
    diff *= 10;
    diff = diff.Rotate90Degree();
}

if (width > 0)
    diff *= -1;

glVector u = end + diff.RotateDegree(30);
glVector v = end + diff.RotateDegree(-30);
wxPoint points[3] = { wxPoint(u.xCoord(),u.yCoord()), wxPoint(v.xCoord(),v.yCoord()), wxPoint(end.xCoord(),end.yCoord()) };

dc.DrawPolygon(3, points);
