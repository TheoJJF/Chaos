#ifndef LORENZ_SYSTEM
#define LORENZ_SYSTEM

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

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

        const float scale = 12.5;

        std::vector<sf::Vector3f> points;
};

#endif