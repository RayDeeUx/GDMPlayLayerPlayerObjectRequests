#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
	void loadPageFromUserInfo(GJUserScore* score) {
		score->m_globalRank = (this->m_ownProfile && score && Mod::get()->getSettingValue<bool>("enabled")) ? std::clamp<int>(Mod::get()->getSettingValue<int>("rank"), 0, std::numeric_limits<int>::max()) : score->m_globalRank;
		ProfilePage::loadPageFromUserInfo(score);
	}
};