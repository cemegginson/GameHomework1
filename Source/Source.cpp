/*
* Author:	Keith Bush
*			UALR
*
* Date:		February 23, 2015
*
* File:		Source.cpp
*
* Purpose:	This programming task examines the following concepts
*				- Abstraction of game devices (Graphics, Input)
*from SDL Library
*               - AssetManagement using Libraries
*               - Object Factory Design Pattern
*               - XML Construction of 2-D game system
*               - Main Game Loop
*/

// C++ Libraries
#include <ctime>
#include <iostream>

// Media Libraries
#include "SDL.h"

// Physics
#include <Box2D/Box2D.h>

// Project Libraries
#include "Definitions.h"
#include "Game.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"

int main(int argc, char* argv[]) {
	//========================================
	// Initialize the random number generator
	//========================================
	srand((unsigned int)time(NULL));

	//========================================
	// Base Game Constants
	//========================================
	uint32 SCREEN_WIDTH = 800;
	uint32 SCREEN_HEIGHT = 600;

	//========================================
	// Construct Graphical Device
	//========================================
	GraphicsDevice* gDevice =
	    new GraphicsDevice(SCREEN_WIDTH, SCREEN_HEIGHT);
	// if (!gDevice->Initialize(true)) { Not sure what this true is about
	if (!gDevice->Initialize()) {
		printf("Graphics Device could not initialize!");
		exit(1);
	}

	//========================================
	// Construct Event System
	//========================================
	SDL_Event* event = new SDL_Event();
	if (!event) {
		printf("SDL Event could not initialize!");
		exit(1);
	}

	//========================================
	// Construct Input Device
	//========================================
	InputDevice* iDevice = new InputDevice();
	if (!iDevice->Initialize(event)) {
		printf("Input Device could not initialize!");
		exit(1);
	}

	//========================================
	// Construct Game
	//========================================
	Game* game = new Game();
	if (!game->Initialize(gDevice, iDevice)) {
		printf("Game could not Initialize!");
		exit(1);
	}

	//========================================
	// Load Level
	//========================================
	game->Reset();
	std::string levelConfigFile = "./Assets/Config/level.xml";
	if (!game->LoadLevel(levelConfigFile)) {
		printf("Game could not load level %s: ",
		       levelConfigFile.c_str());
		exit(1);
	}

	//========================================
	// Main Game Loop
	//========================================
	bool quit = false;
	// While the user hasn't quit
	while (!quit) {
		// Check for Event
		while (SDL_PollEvent(event)) {
			if (event->type == SDL_QUIT) {
				quit = true;
			}
			// Update the Input Device with the Event
			iDevice->Update(event);
		}
		// Execute the Game
		game->Run();
	}

	//========================================
	// Clean-up
	//========================================
	if (game) {
		delete game;
		game = nullptr;
	}

	if (iDevice) {
		delete iDevice;
		iDevice = nullptr;
	}

	if (gDevice) {
		delete gDevice;
		gDevice = nullptr;
	}

	SDL_Quit();

	return 0;
}
