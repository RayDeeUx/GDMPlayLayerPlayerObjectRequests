#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void resetLevel() {
		PlayLayer::resetLevel();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, false);
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, false);
	}
};

class $modify(MyGJBaseGameLayer, GJBaseGameLayer) {
	void toggleFlipped(bool whatTheFUCK, bool fuckingHelpME) {
		log::info("whatTheFUCK (false): {}", whatTheFUCK);
		log::info("fuckingHelpME (m_startPosObject->m_startSettings->m_mirrorMode): {}", fuckingHelpME);
		GJBaseGameLayer::toggleFlipped(whatTheFUCK, fuckingHelpME);
	}
};