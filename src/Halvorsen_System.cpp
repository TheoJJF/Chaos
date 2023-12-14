#include "../include/Halvorsen_System.h"

HalvorsenSystem::HalvorsenSystem()
{
    x = 0.1, y = z = 0.0;
    a = 1.4;

    scale = 20.0;
    theta1 = M_PI_4 / 1.5, theta2 = M_PI_4;
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
    float xModified = x * std::cos(theta1) - z * std::sin(theta1);
    float yModified = y * std::cos(theta2) - z * std::sin(theta2);
    float zModified = y * std::sin(theta2) + z * std::cos(theta2);

    float xFinal = scale * (xModified + 2.125);
    float yFinal = scale * yModified;
    float zFinal = scale * zModified / 1.1125;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}