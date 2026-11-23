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
			temp->m_mainLayer->addChild(fakeTSC.data());
			fakeTSC.data()->setUserObject("x-pos"_spr, CCFloat::create(p->getPositionX()));
			fakeTSC.data()->setUserObject("y-pos"_spr, CCFloat::create(p->getPositionY()));
			fakeTSC.data()->setRotation(270.f);
			fakeTSC.data()->setPosition(temp->m_mainLayer->getContentSize() / 2.f);
			fakeTSC.data()->setPositionX(fakeTSC.data()->getPositionX() - 10.f);
			fakeTSC.data()->setVisible(true);
			temp->show();
			temp->addOnExitCallback([s = fakeTSC]() {
				if (!CCScene::get() || !CCScene::get()->getChildByType<PauseLayer>(-1)) return;
				s.data()->setVisible(false);
				s.data()->setRotation(0);
				s.data()->setPositionX(typeinfo_cast<CCFloat*>(s.data()->getUserObject("x-pos"_spr))->getValue());
				s.data()->setPositionY(typeinfo_cast<CCFloat*>(s.data()->getUserObject("y-pos"_spr))->getValue());
			});
		}), nullptr));
	}
};