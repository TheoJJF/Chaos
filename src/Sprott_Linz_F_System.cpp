#include "../include/Sprott_Linz_F_System.h"

SprottLinzFSystem::SprottLinzFSystem()
{
    x = 0.1, y = z = 0;
    a = 0.5;
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
    // Across Y-axis
    float xModified = x * std::cos(cameraAngle) + z * std::sin(cameraAngle);
    float zModified = z * std::cos(cameraAngle) + x * std::sin(cameraAngle);

    float xFinal = scale * (xModified - 0.5);
    float yFinal = scale * (y + 1.875);
    float zFinal = scale * zModified;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}

const std::vector<sf::Vector3f> &SprottLinzFSystem::returnPointsVector() const
{
    return points;
}