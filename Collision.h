#pragma once

bool collison(si::Segment first, si::Segment second)
{
	//(first.b - second.b) / (first.k - second.k)
	if (first.k != second.k)
	{
		return true;
	}
	return false;
}

