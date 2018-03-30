/*
 * Screen.h
 *
 *  Created on: 28 Mar 2018
 *      Author: chrissherfield
 */
#include <SDL2/SDL.h>

#ifndef SCREEN_H_
#define SCREEN_H_

class Screen {

public:

	 const static int SCREEN_WIDTH = 800;
	 const static int SCREEN_HEIGHT = 600;
private:

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	bool processEvents();
	bool update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clear();
	void close();
	void boxBlur();
};

#endif /* SCREEN_H_ */
