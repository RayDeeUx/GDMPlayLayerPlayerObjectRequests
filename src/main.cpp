#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void resetLevel() {
		PlayLayer::resetLevel();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		PlayLayer::toggleFlipped(false, m_startPosObject->m_startSettings->m_mirrorMode);
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		PlayLayer::toggleFlipped(false, m_startPosObject->m_startSettings->m_mirrorMode);
	}
	void toggleFlipped(bool whatTheFUCK, bool fuckingHelpME) {
		log::info("whatTheFUCK (false): {}", whatTheFUCK);
		log::info("fuckingHelpME (m_startPosObject->m_startSettings->m_mirrorMode): {}", fuckingHelpME);
		PlayLayer::toggleFlipped(whatTheFUCK, fuckingHelpME);
	}
};