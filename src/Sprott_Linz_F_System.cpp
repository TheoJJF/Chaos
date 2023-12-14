#include "../include/Sprott_Linz_F_System.h"

SprottLinzFSystem::SprottLinzFSystem()
{
    x = 0.1, y = z = 0;
    a = 0.5;

    scale = 120.0;
    theta1 = theta2 = M_PI;
}

SprottLinzFSystem::~SprottLinzFSystem() { }

void SprottLinzFSystem::update(const float &dt)
{
    float dx = y + z;
    float dy = -x + a * y;
    float dz = x * x - z;

    x += dx * dt;
    y += dy * dt;
    z += dz * dt;

    points.push_back(pointScaling());
    return;
}

sf::Vector3f SprottLinzFSystem::pointScaling() const
{
    float xModified = x * std::cos(theta1) + z * std::sin(theta1);
    float zModified = z * std::cos(theta1) + x * std::sin(theta1);

    float xFinal = scale * (xModified - 0.5);
    float yFinal = scale * (y + 1.875);
    float zFinal = scale * zModified;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}