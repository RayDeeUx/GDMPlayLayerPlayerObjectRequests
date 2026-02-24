#include <Geode/modify/PlayerObject.hpp>
#include <random>

using namespace geode::prelude;

bool enabled = true;
bool dontEnableInEditor = true;

int getRandomGamemode() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist(0, 7);

    return dist(gen); // value ∈ {0,1,...,7}
}

$on_game(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	dontEnableInEditor = Mod::get()->getSettingValue<bool>("dontEnableInEditor");

	listenForSettingChanges<bool>("enabled", [](const bool enabledNew) {
		enabled = enabledNew;
	});
	listenForSettingChanges<bool>("dontEnableInEditor", [](const bool dontEnableInEditorNew) {
		dontEnableInEditor = dontEnableInEditorNew;
	});
}

class $modify(MyPlayerObject, PlayerObject) {
	void switchedToMode(GameObjectType type) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::switchedToMode(type);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::switchedToMode(type);

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: {
				type = GameObjectType::CubePortal;
				break;
			}
			case 1: {
				type = GameObjectType::ShipPortal;
				break;
			}
			case 2: {
				type = GameObjectType::BallPortal;
				break;
			}
			case 3: {
				type = GameObjectType::UfoPortal;
				break;
			}
			case 4: {
				type = GameObjectType::WavePortal;
				break;
			}
			case 5: {
				type = GameObjectType::RobotPortal;
				break;
			}
			case 6: {
				type = GameObjectType::SpiderPortal;
				break;
			}
			case 7: {
				type = GameObjectType::SwingPortal;
				break;
			}
		}

		PlayerObject::switchedToMode(type);
	}
};