#pragma once

#include <string>
#include "Definitions.h"
#include "View.h"

#ifdef _WIN32
#include "SDL.h"
#include "SDL_image.h"
#elif _LINUX
#include <SDL.h>
#endif

class Texture {
protected:
	SDL_Texture* texture;

public:
	Texture();
	~Texture();
	bool Initialize(SDL_Renderer* renderer, std::string image);
	void Draw(SDL_Renderer* renderer, View* view, vector2 position,
		  float32 angle, SDL_Rect* clip = nullptr);
	void GetDimensions(int*, int*);
};
