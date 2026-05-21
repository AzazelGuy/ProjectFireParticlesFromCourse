#include "Particles.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

namespace ParticlesP{
    Particle::Particle() : m_x(0), m_y(0) {
        m_direction = (2.0 * rand()) / RAND_MAX * M_PI * 2;
        m_speed = (0.05 * rand()) / RAND_MAX;

        m_speed *= m_speed;
    }

    void Particle::update(int interval) {

        m_direction += interval * 0.0009;

        double xSpeed = m_speed * cos(m_direction);
        double ySpeed = m_speed * sin(m_direction);

        m_x += xSpeed * interval;
        m_y += ySpeed * interval;

        if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
            m_x = 0;
            m_y = 0;

            m_direction = (2.0 * rand()) / RAND_MAX * M_PI * 2;
            m_speed = (0.05 * rand()) / RAND_MAX;

            m_speed *= m_speed;
        }

        if (rand() % 100 < 10) {
            m_direction += (2.0 * rand()) / RAND_MAX * M_PI / 8 - M_PI / 16;
        }
    }
    
}
