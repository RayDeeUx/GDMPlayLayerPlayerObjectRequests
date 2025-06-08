#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void resetLevel() {
		PlayLayer::resetLevel();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		PlayLayer::toggleFlipped(m_startPosObject->m_startSettings->m_isFlipped, false);
		log::info("[resetLevel] flipped");
	}
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_isTestMode || !m_startPosObject || !m_startPosObject->m_startSettings) return;
		PlayLayer::toggleFlipped(m_startPosObject->m_startSettings->m_isFlipped, false);
		log::info("[setupHasCompleted] flipped");
	}
};