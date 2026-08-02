#include <Geode/modify/MusicDownloadManager.hpp>

using namespace geode::prelude;

class $modify(MyMusicDownloadManager, MusicDownloadManager) {
	bool isSFXDownloaded(int id) {
		if (Mod::get()->getSettingValue<bool>("enabled")) return true;
		return MusicDownloadManager::isSFXDownloaded(id);
	}
};