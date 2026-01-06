#include <SDL3/SDL.h>
#include <vector>
#include <algorithm>
#include <deque>

int main(int argc, char* argv[]) {
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Snake", 1000, 1000, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_Event event;

	enum Direction { DOWN, LEFT, RIGHT, UP };

	//body parts of the snake
	std::deque<SDL_FRect> snake; //snake body parts

	//snake size
	int size = 1;

	//apple container
	std::vector<SDL_FRect> apples;

	//create apples
	for (int i = 0; i < 50; i++) {
		apples.emplace_back(rand() % 100 * 10.0f, rand() % 100 * 10.0f, 10, 10);
	}

	bool running = true;
	int dir = -1; //initial direction
	SDL_FRect head { 500.0f, 500.0f, 10, 10 }; //initial position of snake head

	//main loop
	while (running) {
		//check input events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) { running = false; }
			if (event.type == SDL_EVENT_KEY_DOWN) { 
				if(event.key.key == SDLK_DOWN) { dir = DOWN; }
				if (event.key.key == SDLK_LEFT) { dir = LEFT; }
				if (event.key.key == SDLK_UP) { dir = UP; }
				if (event.key.key == SDLK_RIGHT) { dir = RIGHT; }
			}
		}

		//move snake
		switch (dir) {
			case DOWN:
				head.y += 10;
				break;
			case LEFT:
				head.x -= 10;
				break;
			case RIGHT:
				head.x += 10;
				break;
			case UP:
				head.y -= 10;
				break;
		}
		if (head.x < 0.0f) head.x = 990.0f;
		if (head.x > 990.0f) head.x = 0.0f;
		if (head.y < 0.0f) head.y = 990.0f;
		if (head.y > 990.0f) head.y = 0.0f;

		//collision detection
		std::for_each(apples.begin(), apples.end(), [&](auto& apple) {
			if (head.x == apple.x && head.y == apple.y) {
				size+=10;
				apple.x = -10;
				apple.y = -10;
			}
		});

		std::for_each(snake.begin(), snake.end(), [&](auto& snake_segment) {
			if (head.x == snake_segment.x && head.y == snake_segment.y) {
				size = 1;
			}
		});

		//add newest head
		snake.push_front(head);
		while (snake.size() > size) snake.pop_back();
		
		//clear window
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//draw apples
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		std::for_each(apples.begin(), apples.end(), [&](auto& apples) {
			SDL_RenderFillRect(renderer, &apples);
		});

		//draw snake
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::for_each(snake.begin(), snake.end(), [&](auto& snake_segment) {
			SDL_RenderFillRect(renderer, &snake_segment);
		});

		//display
		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	}
	
	return 0;
}