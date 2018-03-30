/*
 * Particle.cpp
 *
 *  Created on: 28 Mar 2018
 *      Author: chrissherfield
 */
#include<stdlib.h>
#include<math.h>
#include<iostream>

#include "Particle.h"

using namespace std;

Particle::Particle() : m_x(0), m_y(0) {
	init();

	m_direction = (2 * M_PI*rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {
	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);

	m_direction += interval * 0.0004;



	m_x += x_speed * interval;
	m_y += y_speed * interval;

	if (m_x > 1 || m_x < -1 || m_y > 1 || m_y < -1)
	{
		init();
	}

	if (rand() < RAND_MAX/100)
	{
		init();
	}
}

void Particle::init()
{
	m_x = 0;
	m_y = 0;
}
