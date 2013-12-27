
#include <SFML/Graphics.hpp>
#include <cstdio>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Texture texture;
    texture.loadFromFile("Tiles.png");
    sf::Sprite tiles;
    tiles.setTexture(texture);
    printf("ONDSKA");
    tiles.setPosition(200,100);
    sf::Clock clock;
    int dx = 0;
    int dy = 0;
    int speed = 200;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    printf("Left\n");
                    dx = -speed;
                }
                if (event.key.code == sf::Keyboard::Right) {
                    printf("Right\n");
                    dx = speed;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    printf("Up\n");
                    dy = -speed;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    printf("Down\n");
                    dy = speed;
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left) {
                    printf("ReleaseLeft\n");
                    dx = 0;
                }
                if (event.key.code == sf::Keyboard::Right) {
                    printf("ReleaseRight\n");
                    dx = 0;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    printf("ReleaseUp\n");
                    dy = 0;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    printf("ReleaseDown\n");
                    dy = 0;
                }
            }
        }

        tiles.move(dx * dt, dy * dt);
        window.clear(sf::Color::White);
        window.draw(tiles);
        window.display();
    }

    return 0;
}
