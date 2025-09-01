#include "stars.hpp"

#include <prng.hpp>

Stars::Stars(const sf::Vector2f& window_size)
{
    vertices.setPrimitiveType(sf::PrimitiveType::Points);
    size_t count = prng::number(200u, 400u);
    vertices.resize(count);
    for (size_t i = 0; i < count; i++) {
        sf::Vector2f pos;
        pos.x = prng::number(0.f, window_size.x) + 0.5f;
        pos.y = prng::number(0.f, window_size.y) + 0.5f;
        vertices[i].position = pos;
        vertices[i].color = sf::Color::Magenta;

        circles.push_back(sf::CircleShape(prng::number(0.5f, 2.5f), prng::number(4u, 6u)));
        circles.back().setFillColor(sf::Color::Magenta);
        circles.back().setPosition(pos);
    }

}

void Stars::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(vertices, states);
    for (const auto& star : circles) {
        target.draw(star, states);
    }
}
