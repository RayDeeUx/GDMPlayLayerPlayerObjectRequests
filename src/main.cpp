#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

// source code stability audited by alphalaneous
class $modify(fuck, PauseLayer) {
	void onSideButtonPressed(CCObject* sender) {
		PauseLayer::onSideButtonPressed(sender);
		if (!sender || sender->getTag() != 8) return;
		TimeSpeedControl* pp = this->m_mainLayer->getChildByType<TimeSpeedControl>(-1);
		pp->setVisible(false);
		this->runAction(CCSequence::create(geode::cocos::CallFuncExt::create([ml = this->m_mainLayer, p = pp]() {
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
			if (auto lol = ml->getChildByType<TimeSpeedControl>(-1)) lol->removeMeAndCleanup();
			temp->show();
			temp->addOnExitCallback([t = temp->m_mainLayer, mlp = ml, s = fakeTSC]() {
				if (!mlp || !s) return;
				mlp->addChild(s);
				if (auto troll = t->getChildByType<TimeSpeedControl>(-1)) troll->removeMeAndCleanup();
				s->setVisible(false);
				s->setRotation(0);
				s->setPositionX(typeinfo_cast<CCFloat*>(s->getUserObject("x-pos"_spr))->getValue());
				s->setPositionY(typeinfo_cast<CCFloat*>(s->getUserObject("y-pos"_spr))->getValue());
			});
		}), nullptr));
	}
};