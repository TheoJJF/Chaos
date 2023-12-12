#include "../../include/Sprott_Linz_F_System.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Sprott-Linz F Attractor");
    // window.setFramerateLimit(120);

    SprottLinzFSystem sprott_linz;

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
        
        sprott_linz.update(0.005);
        window.clear(sf::Color::Black);

        sf::VertexArray line(sf::LineStrip);
        line.resize(sprott_linz.returnPointsVector().size());

        for (size_t i = 0; i < sprott_linz.returnPointsVector().size(); i++)
        {
            sf::Vector3f point = sprott_linz.returnPointsVector().at(i);

            line[i].position = sf::Vector2f(point.x, point.y) + window.getView().getCenter();
            line[i].color = sf::Color(0, 255, 255, 100);
        }
        
        window.draw(line);
        window.display();
    }
    

    return 0;
}