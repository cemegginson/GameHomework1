#pragma once

#include <string>
#include "pugixml.hpp"
#include "Object.h"
#include "ArtAssetLibrary.h"

class ObjectFactory {
protected:
	GraphicsDevice* gDevice;
	ArtAssetLibrary* aLibrary;

public:
	ObjectFactory();
	ObjectFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~ObjectFactory();
	virtual Object* Create(pugi::xml_node) = 0;
};

class CarrierFactory : ObjectFactory {
protected:
public:
	CarrierFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~CarrierFactory();
	Object* Create(pugi::xml_node);
};

class InfantryFactory : ObjectFactory {
protected:
public:
	InfantryFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~InfantryFactory();
	Object* Create(pugi::xml_node);
};

class PlayerFactory : ObjectFactory {
protected:
public:
	PlayerFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~PlayerFactory();
	Object* Create(pugi::xml_node);
};

class RockFactory : ObjectFactory {
protected:
public:
	RockFactory(GraphicsDevice* gDev, ArtAssetLibrary* aLib);
	~RockFactory();
	Object* Create(pugi::xml_node);
};
