#pragma once
#include <stdlib.h>
namespace ParticlesP{
    class Particle{
        public:
            double m_x;
            double m_y;

            double m_speed;
            double m_direction;
        public:
            Particle();
            void update();
    };
}