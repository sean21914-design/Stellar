#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(StellarMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(StellarMenuLayer::onStellarButton)
        );

        auto menu = this->getChildByID("bottom-menu");

        if (menu) {
            menu->addChild(button);
            button->setID("stellar-button"_spr);
            menu->updateLayout();
        }

        log::info("Stellar loaded successfully!");

        return true;
    }

    void onStellarButton(CCObject*) {
        FLAlertLayer::create(
            "Stellar",
            "Stellar is alive! ⭐",
            "OK"
        )->show();
    }
};