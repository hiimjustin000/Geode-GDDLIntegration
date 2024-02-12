#ifndef GDDLSEARCHLAYER_H
#define GDDLSEARCHLAYER_H

#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class GDDLSearchLayer : public FLAlertLayer {
    // endpoint args, ignoring chunk (always set to 10) and stddev args
    // value limits
    static constexpr int highestTier = 35;
    static constexpr float highestEnjoyment = 10.0f;
    static constexpr int maxSubmissions = 9999;
    // 0 defaults treated as null (not passed to the query) (well, it depends)
    // page - parse as is, check for valid numbers of course
    inline static int page = 1;
    // name - use a url parser
    inline static std::string name;
    // lowTier, highTier - parse as is, check for valid numbers
    inline static int lowTier = 0, highTier = 0;
    // difficulty - passed as a number from 0 to 4, shown as strings from the vector below, 5 = any
    inline static int difficulty = 5;
    const inline static std::vector<std::string> demonDifficulties = {"Easy", "Medium", "Hard", "Insane", "Extreme", "Any"};
    // creator - use a url parser
    inline static std::string creator;
    // song - use a url parser
    inline static std::string song;
    // bool switches
    inline static bool exactName = false, removeUnrated = false, removeUnratedEnj = false, removeRated = false, removeRatedEnj = false;
    // submission count limits
    inline static int subLowCount = 0, subHighCount = 0;
    // enjoyment submission count limits
    inline static int enjLowCount = 0, enjHighCount = 0;
    // enjoyment rating limits
    inline static float enjLow = 0, enjHigh = highestEnjoyment;
    // sort - displayed as sortBy, mapped to a value in the sort vector, default - ID
    inline static int sortOptionIndex = 0;
    const inline static std::vector<std::string> sortBy = {"ID", "Name", "Rating", "Enjoyment", "Rating Count", "Enjoyment Count", "Random"};
    const inline static std::vector<std::string> sort = {"ID", "Name", "Rating", "Enjoyment", "RatingCount", "EnjoymentCount", "Random"};
    // sortDirection - same as sort basically, default - asc
    inline static int sortDirectionIndex = 0;
    const inline static std::vector<std::string> orderDirection = {"Ascending", "Descending"};
    const inline static std::vector<std::string> sortDirection = {"asc", "desc"};
    // have fun remembering all of that lmao


    // some of the controls should probably be here so searching with getChildByIDRecursive() isn't needed
    CCTextInputNode *nameTextfield = nullptr;
    CCMenuItemToggler *nameExactMatchToggler = nullptr;
    CCTextInputNode *creatorTextfield = nullptr;
    CCTextInputNode *songTextfield = nullptr;
    CCLabelBMFont *difficultyLabel = nullptr;
    CCTextInputNode *tierLowTextfield = nullptr;
    CCTextInputNode *tierHighTextfield = nullptr;
    CCTextInputNode *enjoymentLowTextfield = nullptr;
    CCTextInputNode *enjoymentHighTextfield = nullptr;
    CCTextInputNode *submissionsCountHighTextfield = nullptr;
    CCTextInputNode *submissionsCountLowTextfield = nullptr;
    CCTextInputNode *enjSubmissionsCountHighTextfield = nullptr;
    CCTextInputNode *enjSubmissionsCountLowTextfield = nullptr;
    CCMenuItemToggler *noUnratedToggler = nullptr;
    CCMenuItemToggler *noRatedToggler = nullptr;
    CCMenuItemToggler *noUnratedEnjToggler = nullptr;
    CCMenuItemToggler *noRatedEnjToggler = nullptr;
    CCLabelBMFont *sortByLabel = nullptr;
    CCLabelBMFont *sortDirectionLabel = nullptr;

    const CCPoint popupSize = {440.0f, 290.0f};

    bool init() override;
    void loadPage();
    void loadValues();
    void saveValues();
    void resetValues();
    void onClose(CCObject *sender);
    TodoReturn keyBackClicked() override;
    void onInfo(CCObject *sender);
    // utility
    void createLabel(CCLayer* parent, std::string font, std::string text, int maxWidth, CCPoint position, int zOrder = 1);
    CCScale9Sprite* createLabelForChoice(CCLayer* parent, CCLabelBMFont *&label, std::string font, std::string text, int maxWidth, CCPoint position, CCPoint bgSize, int zOrder = 1);
    void scaleLabelToWidth(CCLabelBMFont *&label, float maxWidth);
    void createTextInputNode(CCLayer* parent, CCTextInputNode* &textfield, std::string font, std::string placeholder, CCPoint bgSize, CCPoint position, int zOrder = 1);
    void createLeftRightButtonsAround(CCNode* object, CCPoint size, SEL_MenuHandler leftCallback, SEL_MenuHandler rightCallback, int zOrder = 1);
    void createCheckbox(CCLayer* parent, CCMenuItemToggler* &toggler, std::string label, float labelOffset, float scale, CCPoint position, SEL_MenuHandler callback, int zOrder = 1);
    float calculateNewFloat(float currentValue, bool increase, float lowerbound, float upperbound);
    // callbacks for all buttons that will be needed
    void onToggleExactMatch(CCObject* sender);
    void onInGameRatingLeft(CCObject* sender);
    void onInGameRatingRight(CCObject* sender);
    void onTierLowLeft(CCObject* sender);
    void onTierLowRight(CCObject* sender);
    void onTierHighLeft(CCObject* sender);
    void onTierHighRight(CCObject* sender);
    void onEnjoymentLowLeft(CCObject* sender);
    void onEnjoymentLowRight(CCObject* sender);
    void onEnjoymentHighLeft(CCObject* sender);
    void onEnjoymentHighRight(CCObject* sender);
    void onSubmissionCountLowLeft(CCObject* sender);
    void onSubmissionCountLowRight(CCObject* sender);
    void onSubmissionCountHighLeft(CCObject* sender);
    void onSubmissionCountHighRight(CCObject* sender);
    void onEnjSubmissionCountLowLeft(CCObject* sender);
    void onEnjSubmissionCountLowRight(CCObject* sender);
    void onEnjSubmissionCountHighLeft(CCObject* sender);
    void onEnjSubmissionCountHighRight(CCObject* sender);
    void onToggleNoUnrated(CCObject* sender);
    void onToggleNoRated(CCObject* sender);
    void onToggleNoUnratedEnj(CCObject* sender);
    void onToggleNoRatedEnj(CCObject* sender);
    void onSortByLeft(CCObject* sender);
    void onSortByRight(CCObject* sender);
    void onSortDirectionLeft(CCObject* sender);
    void onSortDirectionRight(CCObject* sender);
    void onSearchClicked(CCObject* sender);
    void onResetClicked(CCObject* sender);
    // setters so I don't have to repeat that spaghetti again
    void setNumberWithDefZeroTextfield(int value, CCTextInputNode *&textfield);
    void setNumberFloatTextfield(float value, CCTextInputNode *&textfield);
    void setDifficultyLabel();
    void setSortByLabel();
    void setSortDirectionLabel();
    // getters for the same thing
    int getNumberTextfieldValue(CCTextInputNode *&textfield);
    float getFloatTextfieldValue(CCTextInputNode *&textfield);

public:
    static GDDLSearchLayer *create();
    void show() override;
    static void loadSettings(); // called on game startup
    static void saveSettings(); // called in menulayer after every modification of the search values
};


#endif // GDDLSEARCHLAYER_H
