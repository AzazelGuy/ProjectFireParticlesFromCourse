#pragma once
#include "Particles.hpp"

namespace SwarmP{
    class Swarm{
        public:
            int NPARTICLES = 1000;
            Swarm();
            Swarm(int numParticles) : NPARTICLES(numParticles) {
                m_particles = new ParticlesP::Particle[NPARTICLES];
            }

            ParticlesP::Particle* getParticles() { return m_particles; }
            void update(int elapsed);
        private:
            ParticlesP::Particle* m_particles;
            int lastTime = 0;
    };
}