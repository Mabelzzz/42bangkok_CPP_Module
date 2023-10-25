#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c);
	Fixed abc = area(a, b, c);
	Fixed abc = area(a, b, c);
	Fixed abc = area(a, b, c);
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
	// return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
