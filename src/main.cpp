#include <Geode/modify/GJItemIcon.hpp>

using namespace geode::prelude;

class $modify(GJItemIcon) {
	bool init(UnlockType p0, int p1, cocos2d::ccColor3B p2, cocos2d::ccColor3B p3, bool p4, bool p5, bool p6, cocos2d::ccColor3B p7) {
		if (!GJItemIcon::init(p0, p1, p2, p3, p4, p5, p6, p7)) return false;
		if (!m_player) return true;
		auto simplePlayerChildSprite = m_player->getChildByType<CCSprite>(0);
		if (!simplePlayerChildSprite || simplePlayerChildSprite->getChildrenCount() < 4) return true;
		const float originalScale = simplePlayerChildSprite->getScale();
		if (m_player->getContentHeight() > simplePlayerChildSprite->getContentHeight()) {
			simplePlayerChildSprite->setScale(m_player->getContentHeight() / simplePlayerChildSprite->getContentHeight());
		} else if (m_player->getContentHeight() < simplePlayerChildSprite->getContentHeight()) {
			simplePlayerChildSprite->setScale(simplePlayerChildSprite->getContentHeight() / m_player->getContentHeight());
		}
		if (originalScale != simplePlayerChildSprite->getScale()) return true;
		if (m_player->getContentWidth() > simplePlayerChildSprite->getContentWidth()) {
			simplePlayerChildSprite->setScale(m_player->getContentWidth() / simplePlayerChildSprite->getContentWidth());
		} else if (m_player->getContentWidth() < simplePlayerChildSprite->getContentWidth()) {
			simplePlayerChildSprite->setScale(simplePlayerChildSprite->getContentWidth() / m_player->getContentWidth());
		}
		return true;
	}
};