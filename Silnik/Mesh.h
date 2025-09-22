#pragma once
#include "Vertex.h"
#include "Renderer.h"
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
		unsigned int vertexArray=0;
		unsigned int vertexBuffer=0, elementBuffer=0, instanceBuffer=0;
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
			Renderer::InitBuffers(quad.vertexArray, quad.vertexBuffer, quad.elementBuffer, quad.instanceBuffer);

			glBindVertexArray(quad.vertexArray);
			
			glBindBuffer(GL_ARRAY_BUFFER, quad.vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * quad.vertices.size(), &quad.vertices[0], GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad.elementBuffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, quad.indices.size() * sizeof(unsigned int),
				&quad.indices[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));
			glEnableVertexAttribArray(3);
			glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
			glBindBuffer(GL_ARRAY_BUFFER, quad.instanceBuffer);
			glEnableVertexAttribArray(4);
			glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(TransformComponent), (void*)offsetof(TransformComponent, position));
			glEnableVertexAttribArray(5);
			glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(TransformComponent), (void*)offsetof(TransformComponent, angle));
			glEnableVertexAttribArray(6);
			glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, sizeof(TransformComponent), (void*)offsetof(TransformComponent, scale));
			
			glVertexAttribDivisor(4, 1);
			glVertexAttribDivisor(5, 1);
			glVertexAttribDivisor(6, 1);
			glBindVertexArray(0);
			return quad;
		}
		void BindInstances(std::vector<TransformComponent> transforms)
		{
			glBindBuffer(GL_ARRAY_BUFFER, instanceBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(TransformComponent) * transforms.size(), &transforms[0], GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	};
}