#include <Geode/modify/SimplePlayer.hpp>

using namespace geode::prelude;

class $modify(SimplePlayer) {
	void updatePlayerFrame(int id, IconType type) {
		SimplePlayer::updatePlayerFrame(id, type);
		if (!this->getParent() || !typeinfo_cast<GJItemIcon*>(this->getParent())) return;
		auto childSprite = this->getChildByType<CCSprite>(0);
		if (!childSprite || childSprite->getChildrenCount() < 4
		// gjitemicon 30x30
		if (childSprite->getContentHeight() > this->getContentHeight()) {
			childSprite->setScale(childSprite->getContentHeight() / this->getContentHeight());
		} else if (childSprite->getContentHeight() < this->getContentHeight()) {
			childSprite->setScale(this->getContentHeight() / childSprite->getContentHeight());
		}
		
		if (childSprite->getContentWidth() > this->getContentWidth()) {
			childSprite->setScale(childSprite->getContentWidth() / this->getContentWidth());
		} else if (childSprite->getContentWidth() < this->getContentWidth()) {
			childSprite->setScale(this->getContentWidth() / childSprite->getContentWidth());
		}
	}
};