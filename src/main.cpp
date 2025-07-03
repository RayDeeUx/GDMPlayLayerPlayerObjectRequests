#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

bool enabled = true;

int cubeFrameNrmlP1 = -1;
int cubeFrameNrmlP2 = -1;

int cubeFrameMiniP1 = -1;
int cubeFrameMiniP2 = -1;

int shipFrameNrmlP1 = -1;
int shipFrameNrmlP2 = -1;

int shipFrameMiniP1 = -1;
int shipFrameMiniP2 = -1;

int ballFrameNrmlP1 = -1;
int ballFrameNrmlP2 = -1;

int ballFrameMiniP1 = -1;
int ballFrameMiniP2 = -1;

int birdFrameNrmlP1 = -1;
int birdFrameNrmlP2 = -1;

int birdFrameMiniP1 = -1;
int birdFrameMiniP2 = -1;

int waveFrameNrmlP1 = -1;
int waveFrameNrmlP2 = -1;

int waveFrameMiniP1 = -1;
int waveFrameMiniP2 = -1;

int spdrFrameNrmlP1 = -1;
int spdrFrameNrmlP2 = -1;

int spdrFrameMiniP1 = -1;
int spdrFrameMiniP2 = -1;

int rbotFrameNrmlP1 = -1;
int rbotFrameNrmlP2 = -1;

int rbotFrameMiniP1 = -1;
int rbotFrameMiniP2 = -1;

int swngFrameNrmlP1 = -1;
int swngFrameNrmlP2 = -1;

int swngFrameMiniP1 = -1;
int swngFrameMiniP2 = -1;


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
		if (changeToFrame < 0) return;\
		return callback(changeToFrame);\
	}

class $modify(MyPlayerObject, PlayerObject) {
	void togglePlayerScale(bool toMini, bool fromPortal) {
		PlayerObject::togglePlayerScale(isMini, fromPortal);
		if (!m_gameLayer || !enabled) return;
		int changeToFrame = -1;
		CHANGE_TO_FRAME(isInBasicMode(), cubeFrameMiniP1, cubeFrameMiniP2, cubeFrameNrmlP1, cubeFrameNrmlP2, PlayerObject::updatePlayerFrame)
		CHANGE_TO_FRAME(m_isShip, shipFrameMiniP1, shipFrameMiniP2, shipFrameNrmlP1, shipFrameNrmlP2, PlayerObject::updatePlayerShipFrame)
		CHANGE_TO_FRAME(m_isBall, ballFrameMiniP1, ballFrameMiniP2, ballFrameNrmlP1, ballFrameNrmlP2, PlayerObject::updatePlayerRollFrame)
		CHANGE_TO_FRAME(m_isBird, birdFrameMiniP1, birdFrameMiniP2, birdFrameNrmlP1, birdFrameNrmlP2, PlayerObject::updatePlayerBirdFrame)
		CHANGE_TO_FRAME(m_isDart, waveFrameMiniP1, waveFrameMiniP2, waveFrameNrmlP1, waveFrameNrmlP2, PlayerObject::updatePlayerDartFrame)
		CHANGE_TO_FRAME(m_isRobot, rbotFrameMiniP1, rbotFrameMiniP2, rbotFrameNrmlP1, rbotFrameNrmlP2, PlayerObject::updatePlayerRobotFrame)
		CHANGE_TO_FRAME(m_isSpider, spdrFrameMiniP1, spdrFrameMiniP2, spdrFrameNrmlP1, spdrFrameNrmlP2, PlayerObject::updatePlayerSpiderFrame)
		CHANGE_TO_FRAME(m_isSwing, swngFrameMiniP1, swngFrameMiniP2, swngFrameNrmlP1, swngFrameNrmlP2, PlayerObject::updatePlayerSwingFrame)
	}
};

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](bool newEnabled) {
		enabled = newEnabled;
	});
	CACHE_FRAME(cubeFrameNrmlP1)
	CACHE_FRAME(cubeFrameNrmlP2)
	CACHE_FRAME(cubeFrameMiniP1)
	CACHE_FRAME(cubeFrameMiniP2)
	CACHE_FRAME(shipFrameNrmlP1)
	CACHE_FRAME(shipFrameNrmlP2)
	CACHE_FRAME(shipFrameMiniP1)
	CACHE_FRAME(shipFrameMiniP2)
	CACHE_FRAME(ballFrameNrmlP1)
	CACHE_FRAME(ballFrameNrmlP2)
	CACHE_FRAME(ballFrameMiniP1)
	CACHE_FRAME(ballFrameMiniP2)
	CACHE_FRAME(birdFrameNrmlP1)
	CACHE_FRAME(birdFrameNrmlP2)
	CACHE_FRAME(birdFrameMiniP1)
	CACHE_FRAME(birdFrameMiniP2)
	CACHE_FRAME(waveFrameNrmlP1)
	CACHE_FRAME(waveFrameNrmlP2)
	CACHE_FRAME(waveFrameMiniP1)
	CACHE_FRAME(waveFrameMiniP2)
	CACHE_FRAME(spdrFrameNrmlP1)
	CACHE_FRAME(spdrFrameNrmlP2)
	CACHE_FRAME(spdrFrameMiniP1)
	CACHE_FRAME(spdrFrameMiniP2)
	CACHE_FRAME(rbotFrameNrmlP1)
	CACHE_FRAME(rbotFrameNrmlP2)
	CACHE_FRAME(rbotFrameMiniP1)
	CACHE_FRAME(rbotFrameMiniP2)
	CACHE_FRAME(swngFrameNrmlP1)
	CACHE_FRAME(swngFrameNrmlP2)
	CACHE_FRAME(swngFrameMiniP1)
	CACHE_FRAME(swngFrameMiniP2)
}