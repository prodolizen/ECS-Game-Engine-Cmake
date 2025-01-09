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
		m_mshader = std::make_shared<rend::ModelShader>();
	}

	void Renderer::onDisplay()
	{
		if (!m_model)
			return;

		glm::mat4 model(1.0f); //model matrix
		model = entity()->getTransform()->model();
		m_mshader->model(*m_model->m_model);
		m_mshader->lighting(false);
		m_mshader->projection(glm::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_mshader->model(model);
		m_mshader->depth_test(true);
		m_mshader->render();
	}
}
