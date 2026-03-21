#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

bool enabled = false;
bool insideMenuItemFromObjectString = false;

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](const bool enabledNew) {
		enabled = enabledNew;
	});
}

class $modify(MyEditorUI, EditorUI) {
	CreateMenuItem* menuItemFromObjectString(gd::string str, int id) {
		if (!enabled) return EditorUI::menuItemFromObjectString(str, id);

		insideMenuItemFromObjectString = true;
		CreateMenuItem* result = EditorUI::menuItemFromObjectString(str, id);
		insideMenuItemFromObjectString = false;

		return result;
	}
	CCSprite* spriteFromObjectString(gd::string str, bool absoluteCenter, bool useGroup, int objLimit, cocos2d::CCArray* objects, cocos2d::CCArray* group, GameObject* groupParent) {
		if (!enabled || !insideMenuItemFromObjectString || !m_editorLayer) return EditorUI::spriteFromObjectString(str, absoluteCenter, useGroup, objLimit, objects, group, groupParent);

		CCArray* fireeToldMeToUseThis = CCArray::create();
		CCSprite* endResult = EditorUI::spriteFromObjectString(str, false, false, 2123456789, fireeToldMeToUseThis, nullptr, nullptr);
		m_editorLayer->updateObjectColors(fireeToldMeToUseThis);
		return endResult;
	}
};