#ifndef KNITTINGBONES_H
#define KNITTINGBONES_H
#include "UtilitySkill.h"
#include <vector>

class KnittingBones : public UtilitySkill {
public:

KnittingBones();
~KnittingBones();

void KnittingBonesBuff(std::vector<Monster> vec2);

};

#endif // KNITTINGBONES_H
