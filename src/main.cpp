#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

bool enabled = false;
bool insideMenuItemFromObjectString = false;

std::vector<geode::Ref<cocos2d::CCArray>> dummyArrays {};

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](const bool enabledNew) {
		enabled = enabledNew;
	});
}

class $modify(MyEditorUI, EditorUI) {
	struct Fields {
		~Fields() {
			if (!dummyArrays.empty()) dummyArrays.clear();
		}
	};
	bool init(LevelEditorLayer* editorLayer) {
		if (!EditorUI::init(editorLayer)) return false;

		if (enabled && editorLayer && !dummyArrays.empty()) {
			for (CCArray* stupid : dummyArrays) {
				editorLayer->updateObjectColors(stupid);
			}
		}
		
		return true;
	}
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
		dummyArrays.push_back(geode::Ref(fireeToldMeToUseThis));
		return endResult;
	}
};