#include "../include/Halvorsen_System.h"

HalvorsenSystem::HalvorsenSystem()
{
    x = 0.1, y = z = 0.0;
    a = 1.4;
}

HalvorsenSystem::~HalvorsenSystem() { }

void HalvorsenSystem::update(const float &dt)
{
    float dx = -a * x - 4 * y - 4 * z - y * y;
    float dy = -a * y - 4 * z - 4 * x - z * z;
    float dz = -a * z - 4 * x - 4 * y - x * x;

    x += dx * dt;
    y += dy * dt;
    z += dz * dt;

    points.push_back(pointScaling());
    return;
}

sf::Vector3f HalvorsenSystem::pointScaling() const
{
    float rotatedX = x * std::cos(cameraAngle) - z * std::sin(cameraAngle);

    float xFinal = scale * rotatedX;
    float yFinal = scale * (y + 5.0);
    float zFinal = scale * z;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}

const std::vector<sf::Vector3f> &HalvorsenSystem::returnPointsVector() const
{
    return points;
}