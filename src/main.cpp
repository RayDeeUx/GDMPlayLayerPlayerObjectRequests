#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

// source code stability audited by alphalaneous
class $modify(fuck, PauseLayer) {
	void onSideButtonPressed(CCObject* sender) {
		PauseLayer::onSideButtonPressed(sender);
		if (!sender || sender->getTag() != 8) return;
		TimeSpeedControl* pp = this->m_mainLayer->getChildByType<TimeSpeedControl>(-1);
		pp->setVisible(false);
		this->runAction(CCSequence::create(geode::cocos::CallFuncExt::create([p = pp]() {
			if (!p) return;
			FLAlertLayer* temp = FLAlertLayer::create("TimeSpeedControl", "", "Close");
			geode::Ref<TimeSpeedControl> fakeTSC = geode::Ref(p);
			temp->m_noElasticity = true;
			temp->m_scene = CCScene::get();
			temp->m_mainLayer->addChild(fakeTSC);
			fakeTSC->setUserObject("x-pos"_spr, CCFloat::create(p->getPositionX()));
			fakeTSC->setUserObject("y-pos"_spr, CCFloat::create(p->getPositionY()));
			fakeTSC->setRotation(270.f);
			fakeTSC->setPosition(temp->m_mainLayer->getContentSize() / 2.f);
			fakeTSC->setPositionX(fakeTSC->getPositionX() - 10.f);
			fakeTSC->setVisible(true);
			temp->show();
			temp->addOnExitCallback([s = fakeTSC]() {
				if (!CCScene::get() || !CCScene::get()->getChildByType<PauseLayer>(-1)) return;
				s->setVisible(false);
				s->setRotation(0);
				s->setPositionX(typeinfo_cast<CCFloat*>(s->getUserObject("x-pos"_spr))->getValue());
				s->setPositionY(typeinfo_cast<CCFloat*>(s->getUserObject("y-pos"_spr))->getValue());
			});
		}), nullptr));
	}
};