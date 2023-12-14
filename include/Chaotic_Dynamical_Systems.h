#ifndef CHAOTIC_DYNAMICAL_SYSTEMS_H
#define CHAOTIC_DYNAMICAL_SYSTEMS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#define _USE_MATH_DEFINE

class ChaoticDynamicalSystems
{
    public:
        virtual void run(sf::RenderWindow &window) = 0;
        virtual void update(const float &dt) = 0;
        virtual sf::Vector3f pointScaling() const = 0;
        const std::vector<sf::Vector3f> &returnPointsVector() const;

    protected:
        float x,y,z;
        float scale;
        float theta1, theta2;
        std::vector<sf::Vector3f> points;
};


#endif