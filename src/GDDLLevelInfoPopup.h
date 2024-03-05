#ifndef GDDLINTEGRATION_GDDLLEVELINFOPOPUP_H
#define GDDLINTEGRATION_GDDLLEVELINFOPOPUP_H

#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class GDDLLevelInfoPopup final : public FLAlertLayer {
    explicit GDDLLevelInfoPopup(int levelId);
    bool init() override;
    void onClose(CCObject *sender);
    void onOpenInBrowser(CCObject *sender);

    int levelID;
    const inline static CCPoint popupSize = {300.0f, 190.0f};
    void addLevelInfo();
    void addTextRow(const std::string& text, int zOrder);
public:
    static GDDLLevelInfoPopup* create(int levelID);
    void show() override;
};


#endif //GDDLINTEGRATION_GDDLLEVELINFOPOPUP_H
