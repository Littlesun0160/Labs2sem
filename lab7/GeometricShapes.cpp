#include "GeometricShapes.hpp"
#include <cmath>
#include <iostream>

void GeometricShape::PrintArea()
{
	CalculateArea();
	std::cout << "Area of " << TypeOfShape << " is " << AreaOfShape << "\n";
}

void Triangle::CalculateArea()
{
	if (SideA > 0 && SideB > 0 && SideC > 0)
	{
		double Perimeter = (SideA + SideB + SideC)/2;
		AreaOfShape = sqrt(Perimeter*(Perimeter-SideA)*(Perimeter-SideB)*(Perimeter-SideC));
	}
}

void Rectangle::CalculateArea()
{
	if (SideA > 0 && SideB > 0)
	{
		AreaOfShape = SideA * SideB;
	}
}

void Circle::CalculateArea()
{
	if (Radius > 0)
	{
		const double PI = acos(-1);
		AreaOfShape = PI * Radius * Radius;
	}
}