#include "Model.h"

namespace zengine
{
	void zengine::Model::onLoad()
	{
		m_model = std::make_shared<rend::Model>(std::string(getPath()).c_str());
	}
}
