#include "Renderer.h"
#include "Entity.h"
#include "Texture.h"
#include "Core.h"
#include "Resources.h"
#include "Model.h"
#include "Transform.h"

namespace zengine
{
	void Renderer::setModel(std::shared_ptr<Model> model)
	{
		m_model = model;
	}

	void Renderer::setTexture(std::shared_ptr<Texture> texture)
	{
		m_texture = texture;
	}

	void Renderer::onInitialize()
	{
		m_modelShader = std::make_shared<rend::ModelShader>();
	}

	void Renderer::onDisplay()
	{
		if (!m_model)
			return;

		//render the entity to the screen
		glm::mat4 model(1.0f); //model matrix
		model = getEntity()->getTransform()->getModel();
		m_modelShader->model(*m_model->m_model);
		m_modelShader->lighting(false);
		m_modelShader->projection(glm::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_modelShader->model(model);
		m_modelShader->depth_test(true);
		m_modelShader->render();
	}
}
