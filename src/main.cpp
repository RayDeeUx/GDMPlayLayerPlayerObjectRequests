#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <random>

using namespace geode::prelude;

bool isRandomizingPlayerOne = false;
bool isRandomizingPlayerTwo = false;

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

	listenForSettingChanges<bool>("enabled", [](const bool v) { enabled = v; });
	listenForSettingChanges<bool>("dontEnableInEditor", [](const bool v) { dontEnableInEditor = v; });
}

class $modify(MyGJBaseGameLayer, GJBaseGameLayer) {
	struct Fields {
		~Fields() {
			isRandomizingPlayerOne = false;
			isRandomizingPlayerTwo = false;
		}
	};
};

static bool shouldPassThrough(PlayerObject* self, GJBaseGameLayer* layer) {
	if (!layer || !enabled || !self) return true;
	if (self != layer->m_player1 && self != layer->m_player2) return true;
	if (layer->m_isEditor && dontEnableInEditor) return true;

	if (self == layer->m_player1 && isRandomizingPlayerOne) return true;
	if (self == layer->m_player2 && isRandomizingPlayerTwo) return true;

	return false;
}

static void setRandomizing(PlayerObject* self, GJBaseGameLayer* layer, bool value) {
	if (self == layer->m_player1) isRandomizingPlayerOne = value;
	else if (self == layer->m_player2) isRandomizingPlayerTwo = value;
}

class $modify(MyPlayerObject, PlayerObject) {
	void toggleBirdMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleBirdMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleBirdMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleDartMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleDartMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleDartMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleFlyMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleFlyMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleFlyMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleRobotMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleRobotMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleRobotMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleRollMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleRollMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleRollMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleSpiderMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleSpiderMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleSpiderMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleSwingMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
	void toggleSwingMode(bool enable, bool noEffects) {
		if (shouldPassThrough(this, m_gameLayer)) return PlayerObject::toggleSwingMode(enable, noEffects);
		setRandomizing(this, m_gameLayer, true);
		const int r = getRandomGamemode();
		switch (r) {
		default:
		case 0:
			PlayerObject::toggleSwingMode(false, noEffects);
			break;
		case 1:
			PlayerObject::toggleBirdMode(true, noEffects);
			break;
		case 2:
			PlayerObject::toggleFlyMode(true, noEffects);
			break;
		case 3:
			PlayerObject::toggleDartMode(true, noEffects);
			break;
		case 4:
			PlayerObject::toggleRollMode(true, noEffects);
			break;
		case 5:
			PlayerObject::toggleSpiderMode(true, noEffects);
			break;
		case 6:
			PlayerObject::toggleRobotMode(true, noEffects);
			break;
		}
		setRandomizing(this, m_gameLayer, false);
	}
};