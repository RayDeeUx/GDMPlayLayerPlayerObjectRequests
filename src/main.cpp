#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

// m_score->m_globalRank
class $modify(MyProfilePage, ProfilePage) {
	void loadPageFromUserInfo(GJUserScore* score) {
		const int fakeRank = std::clamp<int>(Mod::get()->getSettingValue<int>("rank"), 0, std::numeric_limits<int>::max());
		if (this->m_ownProfile && score && Mod::get()->getSettingValue<bool>("enabled") && fakeRank > 0) {
			score->m_globalRank = fakeRank;
		}
		ProfilePage::loadPageFromUserInfo(score);
	}
};