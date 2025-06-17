#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
	void update(float dt) {
		PlayerObject::update(dt);
		if (!m_gameLayer || !this->isInNormalMode() || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2) || m_isOnGround || m_isOnSlope) return;
		PlayerObject::setRotation(0);
	}
	void togglePlayerScale(bool p0, bool p1) {
		PlayerObject::togglePlayerScale(p0, p1);
		if (!m_isSwing || !m_defaultMiniIcon || !m_gameLayer || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return;
		PlayerObject::updatePlayerSwingFrame(GameManager::get()->getPlayerSwing());
	}
};