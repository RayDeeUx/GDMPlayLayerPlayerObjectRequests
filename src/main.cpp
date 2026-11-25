#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
	void loadPageFromUserInfo(GJUserScore* score) {
		ProfilePage::loadPageFromUserInfo(score);
		if (!this->m_mainLayer) return;
		
		CCNode* foo = this->m_mainLayer->querySelector("stats-menu followers-label-container");
		CCNode* bar = this->m_mainLayer->querySelector("stats-menu followers-icon");
		CCNode* baz = this->m_mainLayer->querySelector("stats-menu");

		if (foo && bar && baz) {
			foo->setVisible(false);
			bar->setVisible(false);
			baz->updateLayout();
		}
	}
};