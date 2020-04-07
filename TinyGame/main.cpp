#include "window.h"
#include "rect.h"

void pollEvents(Window& window, Rect& rect) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				rect.setPostion(-10, 0);
				break;

			case SDLK_RIGHT:
				rect.setPostion(10, 0);
				break;

			case SDLK_UP:
				rect.setPostion(0, -10);
				break;

			case SDLK_DOWN:
				rect.setPostion(0, 10);
				break;

			default:
				break;
			}
		}
        window.pollEvents(event);
    }
}

int main(int argc, char* argv[]) {

    Window window("TinyGame", 800, 600);
    Rect rect(window, 120, 120, 100, 100, "res/tennis_ball.png");

    while (!window.isClosed()) {
        pollEvents(window, rect);
        rect.draw();
        window.clear();
    }

    return 0;
}