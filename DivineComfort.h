#ifndef DIVINECOMFORT_H
#define DIVINECOMFORT_H
#include "UtilitySkill.h"
#include <vector>

class DivineComfort : public UtilitySkill {
public:

DivineComfort();
~DivineComfort();

void DivineComfortBuff(std::vector<Hero>& vec);

};

#endif
