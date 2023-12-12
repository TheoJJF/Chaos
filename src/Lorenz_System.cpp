#include "../include/Lorenz_System.h"

LorenzSystem::LorenzSystem()
{
    x = 0.000001, y = z = 0.0;
    sigma = 10.0, rho = 28.0, beta = 8.0 / 3.0;
}

LorenzSystem::~LorenzSystem() { }

void LorenzSystem::update(const float &dt)
{
    float dx = sigma * (y - x);
    float dy = x * (rho - z) - y;
    float dz = x * y - beta * z;

    x += dx * dt;
    y += dy * dt;
    z += dz * dt;

    points.push_back(pointScaling());
    return;
}

sf::Vector3f LorenzSystem::pointScaling() const
{
    // Rotate around x-axis
    float yModified = y * std::cos(cameraAngle1) - z * std::sin(cameraAngle1);
    float zModified = y * std::sin(cameraAngle1) + z * std::cos(cameraAngle1);

    float xFinal = scale * x;
    float yFinal = scale * (yModified + 27.5);
    float zFinal = scale * zModified;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}

const std::vector<sf::Vector3f> &LorenzSystem::returnPointsVector() const
{
    return points;
}