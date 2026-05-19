#include "Swarm.hpp"

namespace SwarmP {
    Swarm::Swarm() {
        NPARTICLES = 1000;
        m_particles = new ParticlesP::Particle[NPARTICLES];
    }

    void Swarm::update() {
        for (int i = 0; i < NPARTICLES; i++) {
            m_particles[i].update();
        }
    }
}