#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "View.h"

class Carrier : public Object {
protected:

public:
    Carrier();
    ~Carrier();
    void Update(GAME_FLT gameTime);
    void Draw(GAME_FLT gameTime, View* view);
    void Initialize(std::string tex, GAME_VEC pos, GAME_FLT ang);
};
