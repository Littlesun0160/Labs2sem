#pragma once
#include <iostream>

enum class Color
{
	WHITE,
	GREEN,
	RED,
	PINK
};

class GeometricShape
{
private:
	double CoordinateX; double CoordinateY;
	Color ColorOfShape;
protected:
	std::string TypeOfShape;
	double AreaOfShape = 0;

	virtual void CalculateArea() {};
public:
	GeometricShape(double x, double y, Color color): CoordinateX(x), CoordinateY(y), ColorOfShape(color) {}
	virtual ~GeometricShape() {}

	void PrintArea();
};

class Triangle : public GeometricShape
{
private: 
	double SideA; double SideB; double SideC;
protected:
	void CalculateArea() override;
public:
	Triangle(double x, double y, Color color, double A, double B, double C): GeometricShape(x,y,color), SideA(A), SideB(B), SideC(C) 
	{
		TypeOfShape = "Triangle";
	}
	~Triangle() {}

};

class Rectangle : public GeometricShape
{
private: 
	double SideA; double SideB;
protected:
	void CalculateArea() override;
public:
	Rectangle(double x, double y, Color color, double A, double B): GeometricShape(x, y, color), SideA(A), SideB(B) 
	{
		TypeOfShape = "Rectangle";
	}
	~Rectangle() {}
};

class Circle : public GeometricShape
{
private:
	double Radius;
protected:
	void CalculateArea() override;
public: 
	Circle(double x, double y, Color color, double R): GeometricShape(x, y, color), Radius(R) 
	{
		TypeOfShape = "Circle";
	}
	~Circle() {}
};