#include <Geode/modify/GJItemIcon.hpp>

using namespace geode::prelude;

class $modify(GJItemIcon) {
	bool init(UnlockType p0, int p1, cocos2d::ccColor3B p2, cocos2d::ccColor3B p3, bool p4, bool p5, bool p6, cocos2d::ccColor3B p7) {
		if (!GJItemIcon::init(p0, p1, p2, p3, p4, p5, p6, p7)) return false;
		auto simplePlayer = getChildByType<SimplePlayer>(0);
		log::info("FUCK");
		if (!simplePlayer || !m_player) return true;
		log::info("ING");
		if (m_player->getContentHeight() > simplePlayer->getContentHeight()) {
			m_player->setScale(m_player->getContentHeight() / simplePlayer->getContentHeight());
		} else if (m_player->getContentHeight() < simplePlayer->getContentHeight()) {
			m_player->setScale(simplePlayer->getContentHeight() / m_player->getContentHeight());
		}
		
		if (m_player->getContentWidth() > simplePlayer->getContentWidth()) {
			m_player->setScale(m_player->getContentWidth() / simplePlayer->getContentWidth());
		} else if (m_player->getContentWidth() < simplePlayer->getContentWidth()) {
			m_player->setScale(simplePlayer->getContentWidth() / m_player->getContentWidth());
		}
		return true;
	}
};