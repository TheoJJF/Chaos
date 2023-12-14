#include "../include/Lorenz_System.h"
#include <iostream>

LorenzSystem::LorenzSystem()
{
    x = 0.000001, y = z = 0.0;
    sigma = 10.0, rho = 28.0, beta = 8.0 / 3.0;

    scale = 11.25;
    theta1 = theta2 = M_PI_2;
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
    float yModified = y * std::cos(theta1) - z * std::sin(theta1);
    float zModified = y * std::sin(theta1) + z * std::cos(theta1);

    float xFinal = scale * x;
    float yFinal = scale * (yModified + 27.5);
    float zFinal = scale * zModified;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}

void LorenzSystem::run(sf::RenderWindow &window)
{
    this->update(0.005);
    window.clear(sf::Color::Black);

    sf::VertexArray line(sf::LineStrip);
    line.resize(this->returnPointsVector().size());

    for (size_t i = 0; i < this->returnPointsVector().size(); i++)
    {
        sf::Vector3f point = this->returnPointsVector().at(i);

        line[i].position = sf::Vector2f(point.x, point.y) + window.getView().getCenter();
        line[i].color = sf::Color(253, 220, 92, 150);
    }
        
    window.draw(line);
    window.display();
}