#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
	void addObject(GameObject* object) {
		if (object->m_objectType != GameObjectType::SecretCoin) PlayLayer::addObject(object);
	}
};