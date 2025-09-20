#pragma once
struct Vertex
{
	float x, y, z; // Position coordinates
	static const unsigned int positionCoordinateCount = 3;
	static const unsigned int positionCoordinateSize = positionCoordinateCount * sizeof(float);
	
	
	float s, t; // Texture coordinatess
	static const unsigned int textureCoordinateCount = 2;
	static const unsigned int textureCoordinateSize = textureCoordinateCount * sizeof(float);
	
	float r, g, b, a; // Colour values
	static const unsigned int colourValuesCount = 4;
	static const unsigned int colorValuesSize = colourValuesCount * sizeof(float);

	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f,
		float s = 0.0f, float t = 0.0f,
		float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f)
		: x(x), y(y), z(z),
		s(s), t(t),
		r(r), g(g), b(b), a(a) 
	{}
	
};