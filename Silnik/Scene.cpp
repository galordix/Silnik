#include "Scene.h"
namespace Engine
{
	Scene::Scene()
	{
		meshes.push_back(Mesh::Quad(0, 0, 0, 0.5, 0.5));
	}
	void Scene::createTransform(unsigned int entity)
	{
		TransformComponent transform;
		transform.angle = { 0, 0, 0, 0 };
		transform.position = { -1, 0, 0 };
		transform.scale = { 0, 0, 0 };
		transformComponents[entity] = transform;
	}
	void Scene::createMesh(unsigned int entity)
	{
		MeshComponent mesh;
		mesh.meshID;
	}
}