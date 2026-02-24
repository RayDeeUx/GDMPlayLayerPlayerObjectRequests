#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <random>

using namespace geode::prelude;

bool insidePlayerWillSwitchMode = false;

bool isFromRandomizerPlayerOne = false;
bool isFromRandomizerPlayerTwo = false;

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

class $modify(MyGJBaseGameLayer, GJBaseGameLayer) {
	struct Fields {
		~Fields() {
			isFromRandomizerPlayerOne = false;
			isFromRandomizerPlayerTwo = false;
			insidePlayerWillSwitchMode = false;
		}
	};
	
	void playerWillSwitchMode(PlayerObject* player, GameObject* object) {
		if (player == this->m_player1 || player == this->m_player2) insidePlayerWillSwitchMode = true;
		GJBaseGameLayer::playerWillSwitchMode(player, object);
		if (player == this->m_player1 || player == this->m_player2) insidePlayerWillSwitchMode = false;
	}
};

class $modify(MyPlayerObject, PlayerObject) {
	void toggleBirdMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleBirdMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleBirdMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleBirdMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleBirdMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleBirdMode(false, noEffects);
			case 1: return PlayerObject::toggleDartMode(true, noEffects);
			case 2: return PlayerObject::toggleFlyMode(true, noEffects);
			case 3: return PlayerObject::toggleRobotMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleBirdMode(true, noEffects);
		}
	}
	void toggleDartMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleDartMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleDartMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleDartMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleDartMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleDartMode(false, noEffects);
			case 1: return PlayerObject::toggleBirdMode(true, noEffects);
			case 2: return PlayerObject::toggleFlyMode(true, noEffects);
			case 3: return PlayerObject::toggleRobotMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleDartMode(true, noEffects);
		}
	}
	void toggleFlyMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleFlyMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleFlyMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleFlyMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleFlyMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleFlyMode(false, noEffects);
			case 1: return PlayerObject::toggleDartMode(true, noEffects);
			case 2: return PlayerObject::toggleBirdMode(true, noEffects);
			case 3: return PlayerObject::toggleRobotMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleFlyMode(true, noEffects);
		}
	}
	void toggleRobotMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleRobotMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleRobotMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleRobotMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleRobotMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleRobotMode(false, noEffects);
			case 1: return PlayerObject::toggleBirdMode(true, noEffects);
			case 2: return PlayerObject::toggleFlyMode(true, noEffects);
			case 3: return PlayerObject::toggleDartMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleRobotMode(true, noEffects);
		}
	}
	void toggleRollMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleRollMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleRollMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleRollMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleRollMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleRollMode(false, noEffects);
			case 1: return PlayerObject::toggleBirdMode(true, noEffects);
			case 2: return PlayerObject::toggleFlyMode(true, noEffects);
			case 3: return PlayerObject::toggleRobotMode(true, noEffects);
			case 4: return PlayerObject::toggleDartMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleRollMode(true, noEffects);
		}
	}
	void toggleSpiderMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleSpiderMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleSpiderMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleSpiderMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleSpiderMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleSpiderMode(false, noEffects);
			case 1: return PlayerObject::toggleDartMode(true, noEffects);
			case 2: return PlayerObject::toggleBirdMode(true, noEffects);
			case 3: return PlayerObject::toggleRobotMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleFlyMode(true, noEffects);
			case 6: return PlayerObject::toggleSwingMode(true, noEffects);
			case 7: return PlayerObject::toggleSpiderMode(true, noEffects);
		}
	}
	void toggleSwingMode(bool enable, bool noEffects) {
		if (!insidePlayerWillSwitchMode || !m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleSwingMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleSwingMode(enable, noEffects);

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			return PlayerObject::toggleSwingMode(enable, noEffects);
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			return PlayerObject::toggleSwingMode(enable, noEffects);
		}

		if (this == m_gameLayer->m_player1 && !isFromRandomizerPlayerOne) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2 && !isFromRandomizerPlayerTwo) isFromRandomizerPlayerTwo = true;

		const int randomGamemode = getRandomGamemode();
		switch (randomGamemode) {
			default: return;
			case 0: return PlayerObject::toggleSwingMode(false, noEffects);
			case 1: return PlayerObject::toggleBirdMode(true, noEffects);
			case 2: return PlayerObject::toggleFlyMode(true, noEffects);
			case 3: return PlayerObject::toggleDartMode(true, noEffects);
			case 4: return PlayerObject::toggleRollMode(true, noEffects);
			case 5: return PlayerObject::toggleSpiderMode(true, noEffects);
			case 6: return PlayerObject::toggleRobotMode(true, noEffects);
			case 7: return PlayerObject::toggleSwingMode(true, noEffects);
		}
	}
};