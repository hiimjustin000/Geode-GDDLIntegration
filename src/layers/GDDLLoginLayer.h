#ifndef GDDLINTEGRATION_GDDLLOGINLAYER_H
#define GDDLINTEGRATION_GDDLLOGINLAYER_H

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include "settings/LoginSettingNodeV3.h"

using namespace geode::prelude;

class GDDLLoginLayer final : public FLAlertLayer {
    CCMenuItemSpriteExtra* m_closeBtn{};
    CCLabelBMFont* statusLabel = nullptr;
    CCTextInputNode* usernameTextField = nullptr;
    CCTextInputNode* passwordTextField = nullptr;

    const inline static std::string loginEndpoint = "https://gdladder.com/api/login";
    EventListener<web::WebTask> loginListener;
    LoginSettingNodeV3* settingNode;

    bool init() override;
    void onClose(cocos2d::CCObject* sender);
    void onLoginClicked(cocos2d::CCObject *sender);

    void prepareSearchListener();
    void updateStatusLabel(const std::string& newStatus, bool error);
    void saveLoginData(const std::string& sid, const std::string& sig);
    void closeLoginPanel();

public:
    static GDDLLoginLayer* create();
    void show() override;

    void setSettingNode(LoginSettingNodeV3* settingNode);
};


#endif //GDDLINTEGRATION_GDDLLOGINLAYER_H