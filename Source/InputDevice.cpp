#include "InputDevice.h"
#include <iostream>

InputDevice::InputDevice() {
    gEvent = GAME_NA;
}

InputDevice::~InputDevice() {

}

bool InputDevice::Initialize(SDL_Event* event) {
    //gEvent = *event; //unnecessary for this assignment ::TODO
	return true;
}

void InputDevice::Update(SDL_Event* event) {
    SDL_PollEvent(event);
}

GAME_EVENT InputDevice::Translate(SDL_Event* event) {

	return gEvent;
}

GAME_EVENT InputDevice::GetEvent() {
    return gEvent;
}
