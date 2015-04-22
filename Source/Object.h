#pragma once

#include <string>
#include <Box2D/Box2D.h>
#include "Definitions.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "Texture.h"
#include "View.h"

class Object {
protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	Texture* texture;
	vector2 position;
	float32 angle;
	b2Body* body;
	b2BodyDef bdef;
	b2World* world;

public:
	Object();
	virtual ~Object();
	virtual void Update(float32) = 0;
	virtual void Draw(float32, View*) = 0;
	// virtual void Initialize(GraphicsDevice* graphics, Texture* tex,
	// 			vector2 pos, float32 ang) = 0;
	b2Body* getPhysicsBody();
};
