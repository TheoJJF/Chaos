#include "../../include/Lorenz_System.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Lorenz Attractor");
    window.setFramerateLimit(120);

    LorenzSystem lorenz;

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
        
        lorenz.update(0.005);
        window.clear(sf::Color::Black);

        sf::VertexArray line(sf::LineStrip);
        line.resize(lorenz.returnPointsVector().size());

        for (size_t i = 0; i < lorenz.returnPointsVector().size(); i++)
        {
            sf::Vector3f point = lorenz.returnPointsVector().at(i);

            line[i].position = sf::Vector2f(point.x, point.y) + window.getView().getCenter();
            line[i].color = sf::Color(255, 215, 115, 150);
        }
        
        window.draw(line);
        window.display();
    }
    

    return 0;
}