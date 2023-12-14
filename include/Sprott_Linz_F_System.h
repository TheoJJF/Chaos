#ifndef SPROTT_LINZ_F_SYSTEM_H
#define SPROTT_LINZ_F_SYSTEM_H

#include "Chaotic_Dynamical_Systems.h"

class SprottLinzFSystem : public ChaoticDynamicalSystems
{
    public:
        SprottLinzFSystem();
        ~SprottLinzFSystem();

        void update(const float &dt);
        sf::Vector3f pointScaling() const;

    private:
        float a;
};

#endif
