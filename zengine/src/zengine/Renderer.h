#include "Component.h"
#include <rend/rend.h>
#include <memory>

namespace zengine
{
	struct Model;
	struct Texture;

	struct Renderer : Component
	{
		void setModel(std::shared_ptr<Model> model);
		void setTexture(std::shared_ptr<Texture> texture);
		void onInitialize();
		void onDisplay();

	private:
		std::shared_ptr<Model> m_model;
		std::shared_ptr<rend::Mesh> m_mesh;
		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<rend::Shader> m_shader;
		std::shared_ptr<rend::ModelShader> m_mshader;
	};
}