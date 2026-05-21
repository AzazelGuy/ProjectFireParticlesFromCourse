#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <time.h>
#include "Swarm.hpp"

using namespace ScreenP;
int main(int argc, char* argv[])
{

    srand(time(NULL));
    
    Screen screen;

    if (screen.Init() == false) std::cout << "Error Initializing SDL." <<std::endl;

    SwarmP::Swarm swarm(5000);
    
    while (true)
    {
        int elapsed = SDL_GetTicks();

        
        swarm.update(elapsed);

        unsigned char green = (1 + std::sin(elapsed * 0.001)) * 128;
        unsigned char red = (1 + std::sin(elapsed * 0.002)) * 128;
        unsigned char blue = (1 + std::sin(elapsed * 0.003)) * 128;

        const ParticlesP::Particle* const pParticles = swarm.getParticles();

        for(int i=0; i < swarm.NPARTICLES; i++)
        {
            ParticlesP::Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;
            int distanc_toCenter = std::sqrt(particle.m_x * particle.m_x + particle.m_y * particle.m_y);
            screen.setPixel(x, y, red, green, blue);
            //screen.setPixel(x, y, 255 - distanc_toCenter, 0, 0);
        }

        screen.boxBlur();
        /*
        
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));

            }
        }
        */

        //screen.setPixel(Screen::SCREEN_WIDTH/2, Screen::SCREEN_HEIGHT/2, 255, 255, 255);
        
        //Draw the screen
        screen.update();
        
        if (!screen.processEvents()) break;
    }

    return 0;
}