#include <Geode/modify/GJItemIcon.hpp>

using namespace geode::prelude;

class $modify(GJItemIcon) {
	bool init(UnlockType p0, int p1, cocos2d::ccColor3B p2, cocos2d::ccColor3B p3, bool p4, bool p5, bool p6, cocos2d::ccColor3B p7) {
		if (!GJItemIcon::init(p0, p1, p2, p3, p4, p5, p6, p7)) return false;
		if (!m_player) return true;
		auto simplePlayerChildSprite = m_player->getChildByType<CCSprite>(0);
		if (!simplePlayerChildSprite || simplePlayerChildSprite->getChildrenCount() < 4) return true;
		const float originalScale = this->getScale();
		float futureScale = 1.f;
		if (this->getContentHeight() > simplePlayerChildSprite->getContentHeight()) {
			futureScale = this->getContentHeight() / simplePlayerChildSprite->getContentHeight();
		} else if (this->getContentHeight() < simplePlayerChildSprite->getContentHeight()) {
			futureScale = simplePlayerChildSprite->getContentHeight() / this->getContentHeight();
		}
		if (originalScale == futureScale) {
			if (this->getContentWidth() > simplePlayerChildSprite->getContentWidth()) {
				futureScale = this->getContentWidth() / simplePlayerChildSprite->getContentWidth();
			} else if (this->getContentWidth() < simplePlayerChildSprite->getContentWidth()) {
				futureScale = simplePlayerChildSprite->getContentWidth() / this->getContentWidth();
			}
		}

		if (originalScale != futureScale) {
			Loader::get()->queueInMainThread([this, futureScale](){
				Loader::get()->queueInMainThread([this, futureScale](){
					Loader::get()->queueInMainThread([this, futureScale](){
						Loader::get()->queueInMainThread([this, futureScale](){
							this->setScale(futureScale);
						});
					});
				});
			});
		}
		return true;
	}
};