#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"

class Infantry : public Object {
protected:

public:
    Infantry();
    ~Infantry();
    void Update(GAME_FLT gameTime);
    void Draw(GAME_FLT gameTime, View* view);
    void Initialize(std::string tex, GAME_VEC pos, GAME_FLT ang);
};
