#include "../../include/Halvorsen_System.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Halvorsen Attractor");
    // window.setFramerateLimit(120);

    HalvorsenSystem halvorsen;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
        }
        
        halvorsen.update(0.005);
        window.clear(sf::Color::Black);

        sf::VertexArray line(sf::LineStrip);
        line.resize(halvorsen.returnPointsVector().size());

        for (size_t i = 0; i < halvorsen.returnPointsVector().size(); i++)
        {
            sf::Vector3f point = halvorsen.returnPointsVector().at(i);

            line[i].position = sf::Vector2f(point.x, point.y) + window.getView().getCenter();
            line[i].color = sf::Color(255, 185, 180, 100);
        }
        
        window.draw(line);
        window.display();
    }


    return 0;
}