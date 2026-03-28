#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
	virtual void setRotation(float rotation) {
		if (this->m_gameLayer && (this == m_gameLayer->m_player1 || this == m_gameLayer->m_player2) && this->isInNormalMode() && !this->m_isDashing && this->m_isOnGround && !this->m_isOnSlope) {
			rotation = std::round(x / 90.f) * 90.f;
		}
		PlayerObject::setRotation(rotation);
	}
};