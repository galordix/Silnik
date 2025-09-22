#include "AppLayer.h"
#include "glad/glad.h"
AppLayer::AppLayer()
{
	_shader = Engine::Renderer::CreateShaderProgram("Shaders/vertexShader.vert", "Shaders/fragmentShader.frag");
	_scene = std::make_shared<Engine::Scene>();
	_scene->entities.push_back(0);
	_scene->createMesh(0);
	_scene->createTransform(0);
	_scene->entities.push_back(1);
	_scene->createTransform(1);
	_scene->transformComponents[1].position = { 0.5f, 0.5f, 0.5f };
	std::vector<Engine::TransformComponent> toRender;
	toRender.push_back(_scene->transformComponents[0]);
	toRender.push_back(_scene->transformComponents[1]);
	_scene->meshes[0].BindInstances(toRender);
}

void AppLayer::onUpdate(float deltaTime)
{

}

void AppLayer::onRender()
{
	glUseProgram(_shader);
	for (auto mesh : _scene->meshes)
	{
		glBindVertexArray(mesh.vertexArray);
		glDrawElementsInstanced(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0, 2);
	}
	
	
	glBindVertexArray(0);
}
