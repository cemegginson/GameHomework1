#pragma once

#include <string>
#include "Definitions.h"
#include "Object.h"
#include "ArtAssetLibrary.h"

class Infantry : public Object {
protected:
	b2CircleShape shape; 
    b2FixtureDef shapefd;
	float32 rotation;
	int w, h;

public:
	Infantry();
	~Infantry();
	void Update(float32);
	void Draw(float32, View*);
	void Initialize(GraphicsDevice*, Texture*, b2World*, GAME_VEC, float32);
};
