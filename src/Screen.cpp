#include "Screen.hpp"
#include <SDL_stdinc.h>
#include <iostream>
namespace ScreenP
{
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){

    }
    
    bool Screen::Init(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
        std::cout << "SDL INIT FAILED" << std::endl;
        return false;
        }

    std::cout << "SDL INIT SUCCESS" << std::endl;
        m_window = SDL_CreateWindow("Particle Fire Explosion",
         SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
         SCREEN_WIDTH, SCREEN_HEIGHT,
          SDL_WINDOW_SHOWN);
    
        if (m_window == NULL) {
            std::cout << "SDL RETURNED: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        m_renderer =SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC); 
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,SCREEN_WIDTH, SCREEN_HEIGHT);
        
        if (m_renderer == NULL) {
            std::cout << "COULDN'T CREATE RENDERER: " << SDL_GetError() << std::endl;
            SDL_DestroyRenderer(m_renderer);
            SDL_Quit();
            return false;
        }

        if (m_texture == NULL) {
            std::cout << "COULDN'T CREATE TEXTURE: " << SDL_GetError() << std::endl;
            SDL_DestroyTexture(m_texture);
            SDL_Quit();
            return false;
        }
    
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT*sizeof(Uint32));
        
        return true;
    }
    
    void Screen::update()
    {
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture,NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    void Screen::setPixel(int x, int y, Uint8 red,Uint8 green,Uint8 blue)
    {
        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return;
        
        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    bool Screen::processEvents()
    {
        
        SDL_Event event;
        
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }
    void Screen::close()
    {
        delete []m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}