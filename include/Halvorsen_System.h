#ifndef HALVORSEN_SYSTEM_H
#define HALVORSEN_SYSTEM_H

#include "Chaotic_Dynamical_Systems.h"

class HalvorsenSystem : public ChaoticDynamicalSystems
{
    public:
        HalvorsenSystem();
        ~HalvorsenSystem();

        void update(const float &dt) override;
        sf::Vector3f pointScaling() const override;

    private:
        float a; 
};

#endif