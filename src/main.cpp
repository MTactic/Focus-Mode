#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
private:
    CCNode* socialMenu;
    CCNode* moreGames;
    CCNode* bottomMenu;
    CCNode* profileMenu;
    CCNode* rightMenu;
    CCNode* closeMenu;
    CCNode* playerName;
    CCNode* settingsButton;

    //int value;
    bool visibility = true;

public:
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Obtener referencias a los menus solo una vez
        socialMenu = this->getChildByID("social-media-menu");
        moreGames = this->getChildByID("more-games-menu");
        bottomMenu = this->getChildByID("bottom-menu");
        profileMenu = this->getChildByID("profile-menu");
        rightMenu = this->getChildByID("right-side-menu");
        closeMenu = this->getChildByID("close-menu");
        playerName = this->getChildByID("player-username");

        setMenuVisibility(false);

        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_zoomInBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );
        myButton->setID("focusBtn"_spr);

        auto topRightMenu = this->getChildByID("top-right-menu");
        if (topRightMenu) {
            topRightMenu->addChild(myButton);
        }
        topRightMenu->updateLayout();
        return true;
    }

    void onMyButton(CCObject * sender) {
        if (profileMenu) {
            setMenuVisibility(visibility);
            if (visibility == true) {
                visibility = false;
            }
            else
            {
                visibility = true;
            }
        }
    }
    void setMenuVisibility(bool visible) {
        socialMenu->setVisible(visible);
        moreGames->setVisible(visible);
        bottomMenu->setVisible(visible);
        profileMenu->setVisible(visible);
        rightMenu->setVisible(visible);
        closeMenu->setVisible(visible);
        playerName->setVisible(visible);
    }
};