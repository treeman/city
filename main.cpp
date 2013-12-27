
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <iostream>
#include <sstream>

// program starts here
int main()
{
    // creates the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // green squares
    sf::Texture texture;
    texture.loadFromFile("Tiles.png");
    sf::Sprite tiles;
    tiles.setTexture(texture);

    // red squares
    sf::Texture redtexture;
    redtexture.loadFromFile("RedTiles.png");
    sf::Sprite redtiles;
    redtiles.setTexture(redtexture);

    int is_red[30][40];
    for (int i = 0; i < 30; i = i + 1) {
        for (int j = 0; j < 40; j = j + 1) {
            is_red[i][j] = 0;
        }
    }

    // how the text looks like
    sf::Font font;
    font.loadFromFile("georgia.ttf");

    // text position and size and coulor
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);

    // one clock
    sf::Clock clock;

    // use to convert numbers to strings
    std::stringstream ss;

    //while window is open it will do this
    while (window.isOpen())
    {
        // moves as fast on slow and fast computers
        // use: speed * dt
        float dt = clock.restart().asSeconds();

        // while we have events like keypresses do this
        sf::Event event;
        while (window.pollEvent(event))
        {
            // if you press close window window closes
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int tile_x = event.mouseButton.x / 20;
                    int tile_y = event.mouseButton.y / 20;
                    is_red[tile_y][tile_x] = 1;
                }
            }
        }

        // window is cleared  from anything
        window.clear(sf::Color::Black);

        // takes out mouse position
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

        // draw all tiles
        for (int i = 0; i < 30; i = i + 1) {
            for (int j = 0; j < 40; j = j + 1) {
                int x = j * 20;
                int y = i * 20;

                // tile should be drawn red
                if (is_red[i][j] == 1) {
                    redtiles.setPosition(x,y);
                    window.draw(redtiles);
                }
                else {
                    tiles.setPosition(x,y);
                    window.draw(tiles);
                }
            }
        }

        // test print
        ss.str("");
        ss << mouse_pos.x / 20; // use to calculate index in is_red
        text.setPosition(204,14);
        text.setString(ss.str());
        window.draw(text);

        // print mouse position
        ss.str("");
        ss << mouse_pos.x;
        //ss << mouse_pos.x << "," << mouse_pos.y;
        text.setPosition(14,14);
        text.setString(ss.str());
        window.draw(text);

        // shows the window
        window.display();
    }

    return 0;
}
