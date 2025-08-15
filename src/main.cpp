#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
	void levelComplete() {
		AppDelegate::sharedApplication()->trySaveGame(false);
		GameManager::get()->save();
		LocalLevelManager::get()->save();
		PlayLayer::levelComplete();
	}
};