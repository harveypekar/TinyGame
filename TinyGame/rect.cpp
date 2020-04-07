#include "rect.h"
#include <SDL_image.h>
#include <iostream>

Rect::Rect(const Window& window, int w, int h, int x, int y, int r, int g, int b, int a) :
	Window(window), _w(w), _h(h), _x(x), _y(y),  _r(r), _g(g), _b(b), _a(a)
{}

Rect::Rect(const Window& window, int w, int h, int x, int y, const std::string& image_path) :
	Window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if(!surface) {
		std::cerr << "Failed to load the surface.\n";
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	if (!_texture) {
		std::cerr << "Failed to create the texture.\n";
	}

	SDL_FreeSurface(surface);
}

Rect::~Rect() { SDL_DestroyTexture(_texture); }

void Rect::draw() const {
	SDL_Rect rect;
	rect.w = _w;
	rect.h = _h;
	rect.x = _x;
	rect.y = _y;

	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &rect);
	}
}

void Rect::setPostion(int x, int y) {
	_x += x;
	_y += y;
}