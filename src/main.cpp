#include <Geode/modify/GameLevelManager.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

void deleteSavedLevels() {
	bool originalVibecodedValue = false;
	bool actuallyDelete = Mod::get()->getSettingValue<bool>("actuallyDelete");
	if (geode::Mod* vibecoded = geode::Loader::get()->getLoadedMod("maytid.mark-of-vengeance"); vibecoded) {
		originalVibecodedValue = vibecoded->getSavedValue<bool>("vg-filter", false);
		vibecoded->setSavedValue<bool>("vg-filter", false);
	}
	if (auto glm = GameLevelManager::get(); glm) {
		if (auto savedLevels = glm->getSavedLevels(Mod::get()->getSettingValue<bool>("alsoApplyToFavoritedLevels"), 0); savedLevels && savedLevels->count() > 0) {
			for (GJGameLevel* level : CCArrayExt<GJGameLevel*>(savedLevels)) {
				if (!level || level->m_levelType == GJLevelType::Main || level->m_levelType == GJLevelType::Editor || level->m_levelType == GJLevelType::Default) continue;
				if (actuallyDelete) {
					glm->deleteLevel(level);
				} else {
					level->m_levelString = "";
					level->m_dontSave = true;
				}
			}
		}
	}
	if (geode::Mod* vibecoded = geode::Loader::get()->getLoadedMod("maytid.mark-of-vengeance"); vibecoded) {
		vibecoded->setSavedValue<bool>("vg-filter", originalVibecodedValue);
	}
}

class $modify(MyGameLevelManager, GameLevelManager) {
	static void onModify(auto& self) {
		(void) self.setHookPriorityPre("GameLevelManager::saveLevel", Priority::VeryEarlyPre);
	}
	void saveLevel(GJGameLevel* level) {
		if (level) level->m_dontSave = true;
		GameLevelManager::saveLevel(level);
	}
};

class $modify(MyAppDelegate, AppDelegate) {
	static void onModify(auto& self) {
		(void) self.setHookPriorityPre("AppDelegate::trySaveGame", Priority::VeryEarlyPre);
	}
	void trySaveGame(bool force) {
		deleteSavedLevels();
		AppDelegate::trySaveGame(force);
	}
};

class $modify(MyGameManager, GameManager) {
	static void onModify(auto& self) {
		(void) self.setHookPriorityPre("GameManager::encodeDataTo", Priority::VeryEarlyPre);
	}
	void encodeDataTo(DS_Dictionary* p0) {
		deleteSavedLevels();
		GameManager::encodeDataTo(p0);
	}
};