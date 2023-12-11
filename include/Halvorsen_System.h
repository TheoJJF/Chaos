#ifndef HALVORSEN_SYSTEM_H
#define HALVORSEN_SYSTEM_H

#define _USE_MATH_DEFINE

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class HalvorsenSystem
{
    public:
        HalvorsenSystem();
        ~HalvorsenSystem();

        void update(const float &dt);
        sf::Vector3f pointScaling() const;
        const std::vector<sf::Vector3f> &returnPointsVector() const;

    private:
        float x, y, z;
        float a; 

        const float scale = 20.0;
        const float cameraAngle = M_PI_4;

        std::vector<sf::Vector3f> points;
};

#endif