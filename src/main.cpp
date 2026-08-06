#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

class $modify(MyGameManager, GameManager) {
	void checkSteamrolling(bool fromLevelComplete) {
		AchievementManager* ach = AchievementManager::sharedState();
		if (!ach->isAchievementEarned("geometry.ach.steam01") && ach->isAchievementEarned("geometry.ach.level01b") && ach->isAchievementEarned("geometry.ach.level02b") && ach->isAchievementEarned("geometry.ach.level03b")) GameManager::sharedState()->reportAchievementWithID("geometry.ach.steam01", 100, !fromLevelComplete);
	}
	void checkSteamStep(bool fromLevelComplete) {
		AchievementManager* ach = AchievementManager::sharedState();
		if (!ach->isAchievementEarned("geometry.ach.steam02") && ach->isAchievementEarned("geometry.ach.level14b")) return GameManager::sharedState()->reportAchievementWithID("geometry.ach.steam02", 100, !fromLevelComplete);
	}
	void checkSteamAchievementUnlockManualReimpl(int levelID, int percentage, bool isPlatformer) {
		if (isPlatformer || percentage < 100) return;
		if (levelID == 14) return MyGameManager::checkSteamStep(true);
		if (levelID < 4) return MyGameManager::checkSteamrolling(true);
	}
	void reportPercentageForLevel(int levelID, int percentage, bool isPlatformer) {
		GameManager::reportPercentageForLevel(levelID, percentage, isPlatformer);
		MyGameManager::checkSteamAchievementUnlockManualReimpl(levelID, percentage, isPlatformer);
	}
	void dataLoaded(DS_Dictionary* dict) {
		GameManager::dataLoaded(dict);
		MyGameManager::checkSteamStep(false);
		MyGameManager::checkSteamrolling(false);
	}
};
