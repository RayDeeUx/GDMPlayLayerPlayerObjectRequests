#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

bool enabled = true;

$on_mod(Loaded) {
	enabled = Mod::get()->getSettingValue<bool>("enabled");
	listenForSettingChanges<bool>("enabled", [](const bool enabledNew){
		enabled = enabledNew;
	});
}

// based on (and adapted from) Windows and Android decompilations by chagh: https://pastes.dev/52bUN5Vo5B + https://pastes.dev/vLFJR9GWKy
class $modify(fuck, GJBaseGameLayer) {
	static void onModify(auto& self) {
		(void) self.setHookPriority("GJBaseGameLayer::handleButton", Priority::Replace);
	}
	void handleButton(bool down, int button, bool isPlayer1) {
		bool m_isPlatformerOriginal = this->m_isPlatformer;
		this->m_isPlatformer = true;
		GJBaseGameLayer::handleButton(down, button, isPlayer1);
		this->m_isPlatformer = m_isPlatformerOriginal;
		/*
		if (!enabled) {
			GJBaseGameLayer::handleButton(down, button, isPlayer1);
			return;
		}

		constexpr bool obeyRobTop = false;
		const bool shouldReturn = !this->m_isPlatformer && static_cast<unsigned int>(button - 2) <= 1;

		if (obeyRobTop && shouldReturn) {
			return;
		}

		if (down) {
			this->m_unk7b0 = true;
		}

		if (!this->m_isPlatformer && !this->m_useReplay) {
			if (GameManager::get()->getGameVariable(GameVar::Flip2PlayerControls)) {
				isPlayer1 = !isPlayer1;
			}
		}

		#ifdef GEODE_IS_IOS
		bool dualTouch = false;
		for (auto& action : this->m_effectManager->m_unkVector1e0) {
			if (action.m_dualMode && !action.m_disabled) {
				dualTouch = true;
				break;
			}
		}
		#else
		bool dualTouch = this->m_effectManager->hasActiveDualTouch();
		#endif

		if (down) {
			this->m_dualTouchTrigger = dualTouch;
		} else if (!this->m_dualTouchTrigger) {
			dualTouch = false;
		}

		bool result = false, appliedToP2 = false;
		const bool twoPlayerMode = this->m_levelSettings->m_twoPlayerMode;

		if (isPlayer1 || (!dualTouch && !twoPlayerMode)) {
			result = down ? this->m_player1->pushButton(static_cast<PlayerButton>(button)) : this->m_player1->releaseButton(static_cast<PlayerButton>(button));
		}

		if (!this->m_dualTouchTrigger && this->m_gameState.m_isDualMode && (!isPlayer1 || !twoPlayerMode)) {
			appliedToP2 = true;
			result = down ? this->m_player2->pushButton(static_cast<PlayerButton>(button)) : this->m_player2->releaseButton(static_cast<PlayerButton>(button));
		}

		if (result) {
			int playerId = (twoPlayerMode && appliedToP2) ? 2 : 1;
			GJGameEvent event = GJGameEvent::None;

			if (down) {
				switch (button) {
					case 1: event = GJGameEvent::JumpPush; break;
					case 2: event = GJGameEvent::LeftPush; break;
					case 3: event = GJGameEvent::RightPush; break;
					default: break;
				}
			} else {
				switch (button) {
					case 1: event = GJGameEvent::JumpRelease; break;
					case 2: event = GJGameEvent::LeftRelease; break;
					case 3: event = GJGameEvent::RightRelease; break;
					default: break;
				}
			}

			if (event != GJGameEvent::None) {
				this->gameEventTriggered(event, 0, playerId);
			}
		}

		if (!this->m_player1->m_isDead) {
			this->m_effectManager->playerButton(down, isPlayer1);
		}

		// see https://raw.githubusercontent.com/geode-sdk/bindings/main/bindings/2.2091/inline/GJBaseGameLayer.cpp
		#ifdef GEODE_IS_MACOS
		if (this->m_recordInputs && !this->m_useReplay && this->m_queuedRecordedButtons.size() < 100000) {
			RecordButtonCommand command;
			command.m_button = static_cast<PlayerButton>(button);
			command.m_isPush = down;
			command.m_isPlayer2 = (twoPlayerMode && !isPlayer1);
			command.m_step = 0;
			command.m_checkpointID = 0;
			this->m_queuedRecordedButtons.push_back(command);
		}
		#else
		this->recordAction(button, down, twoPlayerMode && !isPlayer1);
		#endif

		if (down) {
			++this->m_clicks;
			++this->m_clickIndex;
			if (button == 1) {
				this->m_jumping = true;
			}
		}
		*/
	}
};
