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

        return true;
    }

    void onStellarButton(CCObject*) {
        auto alert = FLAlertLayer::create(
            "STELLAR",
            "Stellar menu is working! ⭐\n\n"
            "This is the first version of the Stellar menu.",
            "Close"
        );

        alert->show();
    }
};