#ifndef LORENZ_SYSTEM_H
#define LORENZ_SYSTEM_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <vector>

class LorenzSystem
{
    public:
        LorenzSystem();
        ~LorenzSystem();

        void update(const float &dt);
        sf::Vector3f pointScaling() const;
        const std::vector<sf::Vector3f> &returnPointsVector() const;


    private:
        float x, y, z;
        float sigma, rho, beta;

        const float scale = 11.25;

        std::vector<sf::Vector3f> points;
};

#endif