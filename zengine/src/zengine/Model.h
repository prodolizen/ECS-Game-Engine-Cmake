#pragma once
#include "Resource.h"

namespace zengine {

	struct Resource;
	struct Renderer;

	struct Model : Resource
	{
		void onLoad();

	private:

		friend struct zengine::Renderer;
		std::shared_ptr<rend::Model> m_model;
	};
}