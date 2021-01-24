#include <stdio.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int BOARDSIZE = 10;
enum Move{up, down, left, right};
enum Move Direction;

void draw(SDL_Window* window) {
    SDL_FillRect(SDL_GetWindowSurface(window), NULL, 0xEEDDDD);
    float square_size = 4 * SCREEN_WIDTH/(5 * BOARDSIZE + 1);
    float gap_width = SCREEN_WIDTH/(5 * BOARDSIZE + 1);
    SDL_Rect rect = {
        .x = gap_width,
        .y = gap_width,
        .w = square_size,
        .h = square_size,
    };
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            SDL_FillRect(SDL_GetWindowSurface(window), &rect, 0xFFEEEE);
            rect.x += square_size + gap_width;
        }
        rect.x = gap_width;
        rect.y += square_size + gap_width;
    }
    SDL_UpdateWindowSurface(window);
}

void draw_movement() {

}

void move(int dir) {

}

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow(
            "SDL Tutorial",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
		if(window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
		}

    draw(window);
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event) == 1) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_DOWN:
                        Direction = down;
                        move(down);
                        puts("Nu åker jag ner");
                        continue;
                    case SDLK_UP:
                        puts("Nu åker jag upp");
                        continue;
                    case SDLK_LEFT:
                        puts("Nu åker jag åt vänster");
                        continue;
                    case SDLK_RIGHT:
                        puts("Nu åker jag åt höger");
                        continue;
                }
            }
        }
    puts("updating state");
    draw(window);
    SDL_Delay(1000);
    }
}
