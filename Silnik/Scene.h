#pragma once
#include <vector>
#include <map>
#include "TransformComponent.h"
#include "MeshComponent.h"
#include "Mesh.h"
namespace Engine
{
	class Scene
	{
	public:
		std::vector<Mesh> meshes;
		std::vector<unsigned int> entities;
		std::map<unsigned int, TransformComponent> transformComponents;
		std::map<unsigned int, MeshComponent> meshComponents;
	public:
		Scene();
		void createTransform(unsigned int entity);
		void createMesh(unsigned int entity);
	};
}
