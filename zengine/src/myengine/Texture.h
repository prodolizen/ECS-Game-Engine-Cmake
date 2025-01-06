#include "Resource.h"

namespace zengine {

	struct TriangleRenderer;

	struct Texture : Resource
	{
		void onLoad();
	private:
		std::shared_ptr<Texture> m_texture;
		friend struct zengine::TriangleRenderer;
		//friend struct zengine::Renderer;
	};
}