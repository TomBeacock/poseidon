#include "poseidon.h"

#include <SDL.h>
#include <iostream>

using namespace std;

void poseidon::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	cout << "Initialized" << endl;
	SDL_Quit();
}
