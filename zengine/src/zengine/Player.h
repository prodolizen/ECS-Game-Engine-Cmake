#pragma once
#include "Component.h"

namespace zengine
{
	struct Player : Component
	{
		void onInitialize();
		void onTick();
		int getScore();
		void increaseScore(int _amount);

	private:
		int m_score;
	};
}