#pragma once
#include <SDL2/SDL.h>

namespace ScreenP{

    class Screen{
        public:
            const static int SCREEN_WIDTH = 1280;
            const static int SCREEN_HEIGHT = 720;
        private:
            SDL_Window *m_window;
            SDL_Renderer *m_renderer;
            SDL_Texture *m_texture;
            Uint32 *m_buffer;
        public:
            Screen();
            void update();
            void setPixel(int x, int y, Uint8 red,Uint8 green,Uint8 blue);
            bool Init();
            bool processEvents();
            void close();
            void clear() {
                memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT*sizeof(Uint32));
            }
    };
}