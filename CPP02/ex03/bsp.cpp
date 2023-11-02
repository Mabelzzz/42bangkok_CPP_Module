#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c);
	Fixed pbc = area(point, b, c);
	Fixed apc = area(a, point, c);
	Fixed abp = area(a, b, point);
	if ((abc == (pbc + apc + abp)) && pbc != 0 && apc != 0 && abp != 0)
		return (true);
	return (false);
}

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed ax = a.getPointX() * (b.getPointY() - c.getPointY());
	Fixed bx = b.getPointX() * (c.getPointY() - a.getPointY());
	Fixed cx = c.getPointX() * (a.getPointY() - b.getPointY());
	Fixed zx = ax + bx + cx;
	if (zx < 0)
		zx = zx * -1;
	return (zx / Fixed(2));
}
