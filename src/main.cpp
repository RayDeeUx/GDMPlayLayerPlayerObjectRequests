#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

bool enabled = true;

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](const bool newEnabled){ enabled = newEnabled; });
}

class $modify(MyPlayerObject, PlayerObject) {
	virtual void setRotation(float rotation) {
		if (enabled && this->m_gameLayer && (this == m_gameLayer->m_player1 || this == m_gameLayer->m_player2) && this->isInNormalMode() && !this->m_isDashing && this->m_isOnGround && !this->m_isOnSlope) {
			rotation = std::round(rotation / 90.f) * 90.f;
		}
		PlayerObject::setRotation(rotation);
	}
};