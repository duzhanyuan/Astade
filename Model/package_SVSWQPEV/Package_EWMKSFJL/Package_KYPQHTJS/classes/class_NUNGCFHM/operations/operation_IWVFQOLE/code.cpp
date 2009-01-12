glVector forceSum;

for (std::set<glGravityArea*>::iterator it = objectList.begin(); it != objectList.end(); it++)
{
	if ((*it) != this)
	{
		glVector diff = absGetPosition() - (*it)->absGetPosition();
		double modulo = diff.Mod();
		glVector direction = glVector(diff.m_x/modulo, diff.m_y/modulo);
		int radiusSum = (*it)->my_Radius + my_Radius;

		if (radiusSum > modulo-1)
			direction *= 0.2;
		else
		{
			double dist = (modulo - radiusSum);
			direction *= (0.4 / (dist*dist));
		}

		forceSum += direction;
	}
}

return forceSum;