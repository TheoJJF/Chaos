#ifndef LORENZ_SYSTEM_H
#define LORENZ_SYSTEM_H

#include "Chaotic_Dynamical_Systems.h"

class LorenzSystem : public ChaoticDynamicalSystems
{
    public:
        LorenzSystem();
        ~LorenzSystem();

        void run(sf::RenderWindow &window) override;
        void update(const float &dt) override;
        sf::Vector3f pointScaling() const override;

    private:
        float sigma, rho, beta;
};

#endif