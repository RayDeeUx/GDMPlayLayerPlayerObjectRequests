#include <Geode/modify/GJPathRewardPopup.hpp>
#include <Geode/modify/PurchaseItemPopup.hpp>
#include <Geode/modify/RewardUnlockLayer.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// credit to user95401 for finding these function calls
// i was staring at PlayLayer::levelComplete decomp for
// what felt like hours and never found out about these
// was also a coward for not asking prev for IDA decomp
// oh well. life happens, and now we're here --raydeeux

void saveProgress(const std::string& reason) {
	if (!Mod::get()->getSettingValue<bool>("enabled") || !Mod::get()->getSettingValue<bool>(reason)) return;
	AppDelegate::sharedApplication()->trySaveGame(false);
	GameManager::get()->save();
	LocalLevelManager::get()->save();
}

class $modify(GJPathRewardPopup) {
	bool init(int p0) {
		if (!GJPathRewardPopup::init(p0)) return false;
		saveProgress("onUnlockingPath");
		return true;
	}
};

class $modify(PurchaseItemPopup) {
	void onPurchase(CCObject* sender) {
		PurchaseItemPopup::onPurchase(sender);
		saveProgress("onPurchase");
	}
};

class $modify(RewardUnlockLayer) {
	bool init(int p0, RewardsPage* p1) {
		if (!RewardUnlockLayer::init(p0, p1)) return false;
		saveProgress("onChest");
		return true;
	}
};

class $modify(EditorPauseLayer) {
	void onSaveAndExit(CCObject* sender) {
		EditorPauseLayer::onSaveAndExit(sender);
		saveProgress("onSaveEditor");
	}
	void onSaveAndPlay(CCObject* sender) {
		EditorPauseLayer::onSaveAndPlay(sender);
		saveProgress("onPlaytestEditor");
	}
};

class $modify(EditLevelLayer) {
	void onEdit(cocos2d::CCObject* sender) {
		EditLevelLayer::onEdit(sender);
		saveProgress("onEnterEditor");
	}
};

class $modify(PlayLayer) {
	void levelComplete() {
		PlayLayer::levelComplete();
		saveProgress("onComplete");
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		saveProgress("onSetupHasCompleted");
	}
	void onQuit() {
		PlayLayer::onQuit();
		saveProgress("onQuit");
	}
};