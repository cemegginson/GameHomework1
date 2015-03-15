#pragma once

class InputDevice {
      protected:
	GAME_Event gEvent;

      public:
	InputDevice();
	~InputDevice();
	bool Initialize(SDL_Event*);
	Void Update(SDL_Event*);
	GAME_EVENT Translate(SDL_Event*);
	GAME_EVENT GetEvent();
}
