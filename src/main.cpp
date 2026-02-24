#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <random>

using namespace geode::prelude;

bool isFromRandomizerPlayerOne = false;
bool isFromRandomizerPlayerTwo = false;

bool mutualExclusion = false;

bool enabled = true;
bool dontEnableInEditor = true;

int getRandomGamemode() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist(0, 7);

    return dist(gen);
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
			mutualExclusion = false;
		}
	};
};

class $modify(MyPlayerObject, PlayerObject) {
	void toggleBirdMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleBirdMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleBirdMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleBirdMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleBirdMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleBirdMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleDartMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleDartMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleDartMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleDartMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleDartMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleDartMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleFlyMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleFlyMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleFlyMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleFlyMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleFlyMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleFlyMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleRobotMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleRobotMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleRobotMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleRobotMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleRobotMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleRobotMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleRollMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleRollMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleRollMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleRollMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleRollMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleRollMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleSpiderMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleSpiderMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleSpiderMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleSpiderMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleSpiderMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleSpiderMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
	void toggleSwingMode(bool enable, bool noEffects) {
		if (!m_gameLayer || !enabled || (this != m_gameLayer->m_player1 && this != m_gameLayer->m_player2)) return PlayerObject::toggleSwingMode(enable, noEffects);
		if (m_gameLayer->m_isEditor && dontEnableInEditor) return PlayerObject::toggleSwingMode(enable, noEffects);

		if (mutualExclusion) {
			PlayerObject::toggleSwingMode(enable, noEffects);
			mutualExclusion = false;
			return;
		}

		if (this == m_gameLayer->m_player1 && isFromRandomizerPlayerOne) {
			isFromRandomizerPlayerOne = false;
			mutualExclusion = true;
			PlayerObject::toggleSwingMode(enable, noEffects);
			return;
		}
		if (this == m_gameLayer->m_player2 && isFromRandomizerPlayerTwo) {
			isFromRandomizerPlayerTwo = false;
			mutualExclusion = true;
			PlayerObject::toggleSwingMode(enable, noEffects);
			return;
		}

		if (this == m_gameLayer->m_player1) isFromRandomizerPlayerOne = true;
		else if (this == m_gameLayer->m_player2) isFromRandomizerPlayerTwo = true;

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
		}
	}
};