#pragma once
#pragma once
struct Vertex
{
	float x, y, z; // Wsp�rz�dne pozycji
	float r, g, b, a; // Sk�adowe kolor�w

	static const unsigned int positionCoordinateCount = 3;
	static const unsigned int positionCoordinateSize = 3 * sizeof(float);
	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f,
		float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f)
		: x(x), y(y), z(z),
		r(r), g(g), b(b), a(a) 
	{}
	
};