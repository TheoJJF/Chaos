#ifndef THOMAS_SYSTEM_H
#define THOMAS_SYSTEM_H

#include "Chaotic_Dynamical_Systems.h"

class ThomasSystem : public ChaoticDynamicalSystems
{
    public:
        ThomasSystem(); 
        ~ThomasSystem(); 

        void run(sf::RenderWindow &window) override;
        void update(const float &dt) override;
        sf::Vector3f pointScaling() const override;

    private:
        float b;
};

#endif