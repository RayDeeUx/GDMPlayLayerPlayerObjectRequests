#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void resetLevel() {
		PlayLayer::resetLevel();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		log::info("[resetLevel] m_startPosObject->m_startSettings->m_mirrorMode: {}", m_startPosObject->m_startSettings->m_mirrorMode);
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, false);
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		log::info("[setupHasCompleted] m_startPosObject->m_startSettings->m_mirrorMode: {}", m_startPosObject->m_startSettings->m_mirrorMode);
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, false);
	}
};