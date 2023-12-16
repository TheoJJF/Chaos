#include "../include/Lorenz_System.h"
#include "../include/Thomas_System.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Chaos - TheoJJF");
    window.setFramerateLimit(120);

    sf::Event systemInitializationChoice;

    LorenzSystem lorenz;
    ThomasSystem thomas;

    bool selectedLorenz = false,
         selectedHalvorsen = false,
         selectedThomas = false;

    while (window.isOpen())
    {
        while (window.pollEvent(systemInitializationChoice))
        {
            switch (systemInitializationChoice.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    switch (systemInitializationChoice.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {
                            window.close();
                            break;
                        }
                        case sf::Keyboard::Num1:
                        {
                            selectedLorenz = true;
                            break;
                        }
                        case sf::Keyboard::Numpad1:
                        {
                            selectedLorenz = true;
                            break;
                        }
                        case sf::Keyboard::Num2:
                        {
                            selectedThomas = true;
                            break;
                        }
                        case sf::Keyboard::Numpad2:
                        {
                            selectedThomas = true;
                            break;
                        }

                        default:
                            break;
                    }
                }
            
                default:
                    break;
            }
        }
        
        if (selectedLorenz)
        {
            lorenz.run(window);
        }
        else if (selectedThomas)
        {
            thomas.run(window);
        }
    }
    
    return 0;
}
