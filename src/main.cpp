#include <Geode/modify/GJItemIcon.hpp>

using namespace geode::prelude;

class $modify(MyGJItemIcon, GJItemIcon) {
	struct Fields {
		UnlockType unlockType = UnlockType::Cube;
	};
	void scaleGracefully(float dt) {
		if (!m_player) return;
		auto simplePlayerChildSprite = m_player->getChildByType<CCSprite>(0);
		if (!simplePlayerChildSprite || simplePlayerChildSprite->getChildrenCount() < 4) return;
		const float originalScale = this->scaleForType(m_fields->unlockType);
		float futureScale = originalScale;
		log::info("this->getContentHeight(): {}", this->getContentHeight());
		log::info("simplePlayerChildSprite->getContentHeight(): {}", simplePlayerChildSprite->getContentHeight());
		log::info("this->getContentWidth(): {}", this->getContentWidth());
		log::info("simplePlayerChildSprite->getContentWidth(): {}", simplePlayerChildSprite->getContentWidth());
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
		
		log::info("futureScale: {}", futureScale);
		log::info("==========================================");

		this->setScale(futureScale);
	}
	bool init(UnlockType p0, int p1, cocos2d::ccColor3B p2, cocos2d::ccColor3B p3, bool p4, bool p5, bool p6, cocos2d::ccColor3B p7) {
		if (!GJItemIcon::init(p0, p1, p2, p3, p4, p5, p6, p7)) return false;
		m_fields->unlockType = p0;
		this->scheduleOnce(schedule_selector(MyGJItemIcon::scaleGracefully), .05f);
		return true;
	}
};