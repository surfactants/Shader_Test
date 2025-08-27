#include <SFML/Graphics.hpp>

#include <iostream>
#include <windows.h>

#include "choose_shader.hpp"
#include "prng.hpp"

int main()
{
    // check shader availability
    if (!sf::Shader::isAvailable()) {
        std::cout << "shaders are not supported by your graphics card :(\n";
        return 0;
    }

    // create shader
    sf::Shader shader;
    std::string shader_key = chooseShader();
    const std::string directory = "shaders/";
    const std::string extension = ".frag";
    std::string shader_file = directory + shader_key + extension;
    if (!shader.loadFromFile(shader_file, sf::Shader::Fragment)) {
        return 0;
    }

    // make the SFML window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(),
                            "Shader Test",
                            sf::Style::Fullscreen,
                            sf::ContextSettings(0, 0, 16));
    // WINDOWS API
    // minimize the console before requesting focus
    // (otherwise the request does nothing)
    ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
    SetFocus(window.getSystemHandle());

    // declare and assign sfml types
    sf::Vector2f window_size(window.getSize());
    sf::RectangleShape backdrop(window_size);
    backdrop.setFillColor(sf::Color::Black);
    sf::Event event;
    sf::Clock shader_clock;

    // load drawable
    sf::Drawable* drawable { nullptr };
if (shader_key == "stars") {
    //drawable = new Stars();
}
else if (shader_key == "whatever) {
    // etc
}

    // WINDOW LOOP
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        const sf::Vector2f fmouse(sf::Mouse::getPosition());
        const float t = shader_clock.getElapsedTime().asSeconds();

        shader.setUniform("u_time", t);
        shader.setUniform("u_resolution", window_size);
        shader.setUniform("u_mouse", fmouse);

        window.clear();
        if (drawable) {
            window.draw(backdrop);
            window.draw(*drawable, &shader);
        }
        else {
            window.draw(backdrop, &shader);
        }
        window.draw(backdrop, &shader);
        window.display();
    }

    // WINDOWS API
    //re-focus the console after the SFML window closes
    ShowWindow(GetConsoleWindow(), SW_NORMAL);
    return 0;
}
