#ifndef GDDLINTEGRATION_DUMMYSETTINGLOGINV3_H
#define GDDLINTEGRATION_DUMMYSETTINGLOGINV3_H

#include <Geode/loader/SettingV3.hpp>

using namespace geode::prelude;

class DummySettingLoginV3 : public SettingV3 {
public:
    static Result<std::shared_ptr<DummySettingLoginV3>>
    parse(std::string const &key, std::string const &modID, matjson::Value const &json);

    bool load(matjson::Value const &json) override;
    bool save(matjson::Value &json) const override;
    bool isDefaultValue() const override;
    void reset() override;
    SettingNodeV3 *createNode(float width) override;
};


#endif //GDDLINTEGRATION_DUMMYSETTINGLOGINV3_H