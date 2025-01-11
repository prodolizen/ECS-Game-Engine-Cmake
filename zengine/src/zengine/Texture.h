#pragma once
#include "Resource.h"

namespace zengine {

	struct TriangleRenderer;
	struct Resource;
	struct Renderer;

	struct Texture : Resource
	{
		void onLoad();
	private:
		friend struct zengine::TriangleRenderer;
		friend struct zengine::Renderer;
		std::shared_ptr<rend::Texture> m_texture;
	};
}