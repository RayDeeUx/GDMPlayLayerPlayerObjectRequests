#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
	void updatePlayerScale() {
		PlayerObject::updatePlayerScale();
		GJBaseGameLayer* gjbgl = GJBaseGameLayer::get();
		if (!gjbgl || (this != gjbgl->m_player1 && this != gjbgl->m_player2) || !this->m_isSwing) return;
		this->updatePlayerSwingFrame(GameManager::get()->getPlayerSwing());
	}
};