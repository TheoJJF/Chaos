#include "../include/Thomas_System.h"

ThomasSystem::ThomasSystem()
{
    x = 0.1, y = z = 0.0;
    b = 0.19;

    scale = 75.0;
    theta1 = M_PI_4 * 3.0, theta2 = M_PI;
}

ThomasSystem::~ThomasSystem() { }

void ThomasSystem::update(const float &dt)
{
    float dx = std::sin(y) - b * x;
    float dy = std::sin(z) - b * y;
    float dz = std::sin(x) - b * z;

    x += dx * dt;
    y += dy * dt;
    z += dz * dt;

    points.push_back(pointScaling());
    return;
}

sf::Vector3f ThomasSystem::pointScaling() const
{
    float xModified = x * std::cos(theta1) + z * std::sin(theta1);
    float yModified = x * std::sin(theta2) + y * std::cos(theta2);
    float zModified = z * std::cos(theta1) - x * std::sin(theta1);

    float xFinal = scale * xModified;
    float yFinal = scale * yModified;
    float zFinal = scale * zModified;

    return sf::Vector3f(xFinal, yFinal, zFinal);
}

void ThomasSystem::run(sf::RenderWindow &window)
{
    this->update(0.05);
    window.clear(sf::Color::Black);

    sf::VertexArray line(sf::LineStrip);
    line.resize(this->returnPointsVector().size());

    for (size_t i = 0; i < this->returnPointsVector().size(); i++)
    {
        sf::Vector3f point = this->returnPointsVector().at(i);

        line[i].position = sf::Vector2f(point.x, point.y) + window.getView().getCenter();
        line[i].color = sf::Color(0, 255, 255, 100);
    }
        
    window.draw(line);
    window.display();
}
