#include "Player.h"

namespace zengine
{
	void Player::onInitialize()
	{

	}
	void Player::onTick()
	{
	}
	int Player::getScore()
	{
		return m_score;
	}
	void Player::increaseScore(int _amount)
	{
		m_score += _amount;
	}
}
