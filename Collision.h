#pragma once

bool collison(si::Segment first, si::Segment second)
{
	if (first.k != second.k)
	{
		float pointX = (second.b - first.b) / (first.k - second.k);
		if (first.FPoint.x <= pointX  && first.SPoint.x >= pointX && second.FPoint.x <= pointX && second.SPoint.x >= pointX)
		{
			return true;
		}
		//return false;
	}
	return false;
}

