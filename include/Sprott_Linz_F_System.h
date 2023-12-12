#ifndef SPROTT_LINZ_F_SYSTEM_H
#define SPROTT_LINZ_F_SYSTEM_H

#define _USE_MATH_DEFINE

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class SprottLinzFSystem
{
    public:
        SprottLinzFSystem();
        ~SprottLinzFSystem();
        void update(const float &dt);
        sf::Vector3f pointScaling() const;
        const std::vector<sf::Vector3f> &returnPointsVector() const;


    private:
        float x, y, z;
        float a;

        const float scale = 120.0;
        const float cameraAngle = M_PI;

        std::vector<sf::Vector3f> points;
};

#endif
