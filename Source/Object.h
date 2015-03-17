#pragma once

#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "Texture.h"
#include "Definitions.h"

class Object {
protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Texture* texture;
	GAME_VEC position;
	GAME_FLT angle;

public:
    Object();
    ~Object();
	virtual void Update(GAME_FLT gameTime) = 0;
	virtual void Draw(GAME_FLT gameTime, View* view) = 0;
    virtual void Initialize() = 0;
}
