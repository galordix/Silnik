#pragma once
#include "Vertex.h"
#include "Renderer/Renderer.h"
#include <vector>
namespace Engine
{
	struct Mesh
	{
	protected:
		/*std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;*/
	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		VertexArray vertexArray;
		static Mesh Quad(float x, float y, float z, float w, float h)
		{
			std::vector<Vertex> quadVertices;
			float nx = 0.0f, ny = 0.0f, nz = 1.0f;
			quadVertices = 
			{
				{x, y, z, nx, ny, nz}, // bottom-left
				{x + w, y,     z, nx, ny, nz}, // bottom-right
				{x + w, y + h, z, nx, ny, nz}, // top-right
				{x,     y + h, z, nx, ny, nz}  // top-left
			};
			std::vector<unsigned int> quadIndices =
			{
				0, 1, 2,
				2, 3, 0
			};
			Mesh quad;
			quad.indices = quadIndices;
			quad.vertices = quadVertices;

			
			return quad;
		}
	};
}