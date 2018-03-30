//============================================================================
// Name        : Basic_SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initialising SDL" << endl;
	}
	Swarm swarm;

	while(true) {
		double elapsed = SDL_GetTicks();
		swarm.update(elapsed);



		unsigned char green = ((1 + sin(elapsed * 0.0002))/2) * 255;
		unsigned char red = ((1 + sin(elapsed * 0.0003))/2) * 255;
		unsigned char blue = ((1 + sin(elapsed * 0.0004))/2) * 255;

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; ++i) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			if (x < 0 || x > Screen::SCREEN_WIDTH || y < 0 || y > Screen::SCREEN_HEIGHT) {
				cout << "------ From loop --------- " << endl;
				cout << "X: " << x << " Y: " << y << endl;
				cout << "m_X: " << particle.m_x << " m_Y: " << particle.m_y << endl;

			}

			screen.setPixel(x, y, red, green , blue);
		}

		screen.boxBlur();
		screen.update();



		if (screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
