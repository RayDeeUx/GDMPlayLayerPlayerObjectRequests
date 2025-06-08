#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void resetLevel() {
		PlayLayer::resetLevel();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, true);
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		static_cast<GJBaseGameLayer*>(this)->toggleFlipped(m_startPosObject->m_startSettings->m_mirrorMode, true);
	}
};