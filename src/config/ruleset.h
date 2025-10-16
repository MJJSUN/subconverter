#ifndef RULESET_H_INCLUDED
#define RULESET_H_INCLUDED

#include "def.h"

enum class RulesetType
{
  SurgeRuleset,
  QuantumultX,
  ClashDomain,
  ClashIpCidr,
  ClashClassic,
  SingBoxRuleset // 添加 sing-box ruleset 类型
};

struct RulesetConfig
{
  String Group;
  RulesetType Type = RulesetType::SurgeRuleset;
  String Url;
  Integer Interval = 86400;
  bool operator==(const RulesetConfig &r) const
  {
    return Group == r.Group && Type == r.Type && Url == r.Url && Interval == r.Interval;
  }
};

using RulesetConfigs = std::vector<RulesetConfig>;

#endif // RULESET_H_INCLUDED
