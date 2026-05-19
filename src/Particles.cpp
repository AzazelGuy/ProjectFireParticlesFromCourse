#include "Particles.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

namespace ParticlesP{
    Particle::Particle() : m_x(0), m_y(0) {
        m_direction = (2.0 * rand()) / RAND_MAX * M_PI * 2;
        m_speed = (0.001 * rand()) / RAND_MAX;
    }

    void Particle::update() {
        double xSpeed = m_speed * cos(m_direction);
        double ySpeed = m_speed * sin(m_direction);

        m_x += xSpeed;
        m_y += ySpeed;
    }
}
