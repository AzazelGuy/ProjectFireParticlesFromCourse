#include "Swarm.hpp"

namespace SwarmP {
    Swarm::Swarm() : lastTime(0) {
        NPARTICLES = 1000;
        m_particles = new ParticlesP::Particle[NPARTICLES];
    }

    void Swarm::update(int elapsed) {

        int interval = elapsed - lastTime;

        for (int i = 0; i < NPARTICLES; i++) {
            m_particles[i].update(interval);
        }

        lastTime = elapsed;
    }
}