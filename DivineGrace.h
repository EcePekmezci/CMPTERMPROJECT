#ifndef DIVINEGRACE_H
#define DIVINEGRACE_H
#include "UtilitySkill.h"
#include <vector>

class DivineGrace : public UtilitySkill {
public:

DivineGrace();
~DivineGrace();

void DivineGraceBuff(std::vector<Hero>& vec);
void DivineGraceBuff(Hero usertarget);

};

#endif // DIVINEGRACE_H
