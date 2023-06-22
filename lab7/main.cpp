#include <iostream>
#include "GeometricShapes.hpp"

int main()
{
	Triangle tr(1, 2, Color::RED, 4.4, 3.4, 5.6);
	tr.PrintArea();

	Circle ci(3, 2, Color::WHITE, 10);
	ci.PrintArea();

	Rectangle re(6, 10, Color::PINK, 9, 3);
	re.PrintArea();
}