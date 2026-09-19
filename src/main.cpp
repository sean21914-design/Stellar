#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class StellarMenu : public FLAlertLayer {
protected:
    bool init() {
        if (!FLAlertLayer::init(
            0,
            "Stellar",
            "Close",
            nullptr,
            nullptr
        )) {
            return false;
        }

        auto title = CCLabelBMFont::create("STELLAR", "bigFont.fnt");
        title->setScale(0.8f);
        title->setPosition(
            m_mainLayer->getContentSize().width / 2,
            m_mainLayer->getContentSize().height - 35
        );
        m_mainLayer->addChild(title);

        auto text = CCLabelBMFont::create(
            "Stellar menu coming soon...",
            "goldFont.fnt"
        );
        text->setScale(0.7f);
        text->setPosition(
            m_mainLayer->getContentSize().width / 2,
            m_mainLayer->getContentSize().height / 2
        );
        m_mainLayer->addChild(text);

        return true;
    }

public:
    static StellarMenu* create() {
        auto ret = new StellarMenu();

        if (ret->init()) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};

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
        StellarMenu::create()->show();
    }
};