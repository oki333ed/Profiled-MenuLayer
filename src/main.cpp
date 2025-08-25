#include "utils.hpp"

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(ProfiledMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto mod = Mod::get();

        if (!mod->getSettingValue<bool>("main-title")) {
            if (auto title = this->getChildByID("main-title")) {
                title->removeFromParentAndCleanup(true);
            }
        }

        if (!mod->getSettingValue<bool>("player-username")) {
            if (auto username = this->getChildByID("player-username")) {
                username->removeFromParentAndCleanup(true);
            }
        }

        if (!mod->getSettingValue<bool>("close-button")) {
            if (auto container = this->getChildByID("close-menu")) {
                if (auto btn = findChildByID(container, "close-button")) {
                    btn->removeFromParentAndCleanup(true);
                    container->updateLayout();
                }
            }
        }

        if (!mod->getSettingValue<bool>("daily-chest-button")) {
            if (auto container = this->getChildByID("right-side-menu")) {
                if (auto btn = findChildByID(container, "daily-chest-button")) {
                    btn->removeFromParentAndCleanup(true);
                    container->updateLayout();
                }
            }
        }

        for (auto id : {"icon-kit-button", "play-button", "editor-button"}) {
            if (!mod->getSettingValue<bool>(id)) {
                if (auto container = this->getChildByID("main-menu")) {
                    if (auto btn = findChildByID(container, id)) {
                        btn->removeFromParentAndCleanup(true);
                        container->updateLayout();
                    }
                }
            }
        }

        for (auto id : {"achievements-button", "settings-button", "stats-button", "newgrounds-button"}) {
            if (!mod->getSettingValue<bool>(id)) {
                if (auto container = this->getChildByID("bottom-menu")) {
                    if (auto btn = findChildByID(container, id)) {
                        btn->removeFromParentAndCleanup(true);
                        container->updateLayout();
                    }
                }
            }
        }

        if (!mod->getSettingValue<bool>("more-games-button")) {
            if (auto container = this->getChildByID("more-games-menu")) {
                if (auto btn = findChildByID(container, "more-games-button")) {
                    btn->removeFromParentAndCleanup(true);
                }
            }
        }

        for (auto id : {"robtop-logo-button", "facebook-button", "twitter-button", "youtube-button", "twitch-button", "discord-button"}) {
            if (!mod->getSettingValue<bool>(id)) {
                if (auto container = this->getChildByID("social-media-menu")) {
                    if (auto btn = findChildByID(container, id)) {
                        btn->removeFromParentAndCleanup(true);
                    }
                }
            }
        }

        if (!mod->getSettingValue<bool>("profile-button")) {
            if (auto container = this->getChildByID("profile-menu")) {
                if (auto btn = findChildByID(container, "profile-button")) {
                    btn->setVisible(false);
                }
            }
        }

        return true;
    }
};