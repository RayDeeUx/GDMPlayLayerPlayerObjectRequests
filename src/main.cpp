#include <Geode/modify/UILayer.hpp>

using namespace geode::prelude;

bool enabled = false;

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](const bool enabledNew) {
		enabled = enabledNew;
		if (!GJBaseGameLayer::get() || !GJBaseGameLayer::get()->m_uiLayer) return;
		GJBaseGameLayer::get()->m_uiLayer->m_inPlatformer = enabled;
		GJBaseGameLayer::get()->m_uiLayer->refreshDpad();
		GJBaseGameLayer::get()->m_uiLayer->updateUINodeVisibility(enabled);
	});
}

class $modify(MyUILayer, UILayer) {
	void togglePlatformerMode(bool inPlatformer) {
		if (enabled && m_gameLayer && !m_gameLayer->m_isPlatformer) {
			inPlatformer = true;
			UILayer::refreshDpad();
			UILayer::updateUINodeVisibility(inPlatformer);
		} else {
			UILayer::togglePlatformerMode(inPlatformer);
		}
	}
};