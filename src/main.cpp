#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

bool enabled = true;

int cubeFrameMiniP1 = -1;
int cubeFrameMiniP2 = -1;

int jtpkFrameMiniP1 = 0;
int jtpkFrameMiniP2 = 0;

int shipFrameMiniP1 = 0;
int shipFrameMiniP2 = 0;

int ballFrameMiniP1 = 0;
int ballFrameMiniP2 = 0;

int birdFrameMiniP1 = 0;
int birdFrameMiniP2 = 0;

int waveFrameMiniP1 = 0;
int waveFrameMiniP2 = 0;

int spdrFrameMiniP1 = 0;
int spdrFrameMiniP2 = 0;

int rbotFrameMiniP1 = 0;
int rbotFrameMiniP2 = 0;

int swngFrameMiniP1 = 0;
int swngFrameMiniP2 = 0;

#define CACHE_FRAME(setting)\
	setting = Mod::get()->getSettingValue<int64_t>(#setting);\
    geode::listenForSettingChanges<int64_t>(#setting, [](int64_t v) { setting = v; });

#define CHANGE_TO_FRAME(condition, frameMiniP1, frameMiniP2, frameNrmlP1, frameNrmlP2, callback)\
	if (condition) {\
		if (toMini) {\
			if (this == m_gameLayer->m_player1) changeToFrame = frameMiniP1;\
			else changeToFrame = frameMiniP2;\
		} else {\
			if (this == m_gameLayer->m_player1) changeToFrame = frameNrmlP1;\
			else changeToFrame = frameNrmlP2;\
		}\
		if ((changeToFrame < 1 && !isInBasicMode()) || (isInBasicMode() && changeToFrame < 0)) return;\
		return callback(changeToFrame);\
	}

class $modify(MyPlayerObject, PlayerObject) {
	void togglePlayerScale(bool toMini, bool fromPortal) {
		PlayerObject::togglePlayerScale(toMini, fromPortal);
		if (!m_gameLayer || !enabled) return;
		int changeToFrame = -1;
		CHANGE_TO_FRAME(isInBasicMode(), cubeFrameMiniP1, cubeFrameMiniP2, GameManager::get()->getPlayerFrame(), GameManager::get()->getPlayerFrame(), PlayerObject::updatePlayerFrame)
		CHANGE_TO_FRAME(m_isShip && !m_isPlatformer, shipFrameMiniP1, shipFrameMiniP2, GameManager::get()->getPlayerShip(), GameManager::get()->getPlayerShip(), PlayerObject::updatePlayerShipFrame)
		CHANGE_TO_FRAME(m_isShip && m_isPlatformer, jtpkFrameMiniP1, jtpkFrameMiniP2, GameManager::get()->getPlayerJetpack(), GameManager::get()->getPlayerJetpack(), PlayerObject::updatePlayerJetpackFrame)
		CHANGE_TO_FRAME(m_isBall, ballFrameMiniP1, ballFrameMiniP2, GameManager::get()->getPlayerBall(), GameManager::get()->getPlayerBall(), PlayerObject::updatePlayerRollFrame)
		CHANGE_TO_FRAME(m_isBird, birdFrameMiniP1, birdFrameMiniP2, GameManager::get()->getPlayerBird(), GameManager::get()->getPlayerBird(), PlayerObject::updatePlayerBirdFrame)
		CHANGE_TO_FRAME(m_isDart, waveFrameMiniP1, waveFrameMiniP2, GameManager::get()->getPlayerDart(), GameManager::get()->getPlayerDart(), PlayerObject::updatePlayerDartFrame)
		CHANGE_TO_FRAME(m_isRobot, rbotFrameMiniP1, rbotFrameMiniP2, GameManager::get()->getPlayerRobot(), GameManager::get()->getPlayerRobot(), PlayerObject::updatePlayerRobotFrame)
		CHANGE_TO_FRAME(m_isSpider, spdrFrameMiniP1, spdrFrameMiniP2, GameManager::get()->getPlayerSpider(), GameManager::get()->getPlayerSpider(), PlayerObject::updatePlayerSpiderFrame)
		CHANGE_TO_FRAME(m_isSwing, swngFrameMiniP1, swngFrameMiniP2, GameManager::get()->getPlayerSwing(), GameManager::get()->getPlayerSwing(), PlayerObject::updatePlayerSwingFrame)
	}
};

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](bool newEnabled) {
		enabled = newEnabled;
	});
	CACHE_FRAME(cubeFrameMiniP1)
	CACHE_FRAME(cubeFrameMiniP2)
	CACHE_FRAME(shipFrameMiniP1)
	CACHE_FRAME(shipFrameMiniP2)
	CACHE_FRAME(jtpkFrameMiniP1)
	CACHE_FRAME(jtpkFrameMiniP2)
	CACHE_FRAME(ballFrameMiniP1)
	CACHE_FRAME(ballFrameMiniP2)
	CACHE_FRAME(birdFrameMiniP1)
	CACHE_FRAME(birdFrameMiniP2)
	CACHE_FRAME(waveFrameMiniP1)
	CACHE_FRAME(waveFrameMiniP2)
	CACHE_FRAME(spdrFrameMiniP1)
	CACHE_FRAME(spdrFrameMiniP2)
	CACHE_FRAME(rbotFrameMiniP1)
	CACHE_FRAME(rbotFrameMiniP2)
	CACHE_FRAME(swngFrameMiniP1)
	CACHE_FRAME(swngFrameMiniP2)
}