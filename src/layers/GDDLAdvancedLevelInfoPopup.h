#ifndef GDDLINTEGRATION_GDDLADVANCEDLEVELINFOPOPUP_H
#define GDDLINTEGRATION_GDDLADVANCEDLEVELINFOPOPUP_H

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class GDDLAdvancedLevelInfoPopup final : public FLAlertLayer {
    EventListener<web::WebTask> spreadListener;
    int levelID = 0;
    std::string levelName, creator;

    CCMenuItemSpriteExtra* m_closeBtn{};

    bool init(const int levelID, const std::string& levelName, const std::string& creator);
    void onClose(cocos2d::CCObject* sender);

    void prepareSearchListener();
    void addBarCharts();
    static std::string getSpreadEndpointUrl(const int levelID);

public:
    static GDDLAdvancedLevelInfoPopup* create(const int levelID, const std::string& levelName, const std::string& creator);
    void show() override;

    void addRatingInfo();
};


#endif //GDDLINTEGRATION_GDDLADVANCEDLEVELINFOPOPUP_H