#pragma once
#include "Component.h"
//#include <zenderer/Mesh.h>
//#include <zenderer/Shader.h>
//#include "Texture.h"
#include <memory>
#include <rend/rend.h>

namespace zengine
{
	struct Texture;

	struct TriangleRenderer : Component
	{
		//TriangleRenderer();
		void onInitialize();
		void onDisplay();
		void setTexture(std::shared_ptr<Texture> texture);

	private:		
		//zenderer::Shader m_shader;
		//zenderer::Mesh m_mesh;
		std::shared_ptr<rend::Mesh> m_mesh;
		std::shared_ptr<rend::Shader> m_shader;
		//Texture m_texture;
		std::shared_ptr<Texture> m_texture;
	};
}

