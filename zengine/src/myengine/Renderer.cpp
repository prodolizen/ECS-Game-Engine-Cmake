#include "Renderer.h"
#include "Entity.h"
#include "Texture.h"
#include "Core.h"
#include "Resources.h"
#include "Model.h"

namespace zengine
{
	void zengine::Renderer::setModel(std::shared_ptr<Model> model)
	{
		m_model = model;
	}

	void zengine::Renderer::setTexture(std::shared_ptr<Texture> texture)
	{
		m_texture = texture;
	}

	void zengine::Renderer::onInitialize()
	{
		m_modelShader = std::make_shared<rend::ModelShader>();
	}

	void zengine::Renderer::onDisplay()
	{
		glm::mat4 model(1.0f); //model matrix
		m_modelShader->model(*m_model->m_model);
		m_modelShader->lighting(false);
		m_modelShader->projection(glm::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_modelShader->model(model);
		m_modelShader->render();

	}
}
