#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
	void update(float dt) {
		PlayerObject::update(dt);
		if (!m_gameLayer || !this->isInNormalMode() || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2) || m_isOnGround || m_isCollidingWithSlope) return;
		PlayerObject::setRotation(0);
	}
};