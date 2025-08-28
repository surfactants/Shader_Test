#include "stars.hpp"

#include <prng.hpp>

Stars::Stars(const sf::Vector2f& window_size)
{
    vertices.setPrimitiveType(sf::PrimitiveType::Points);
    size_t count = prng::number(50u, 250u);
    vertices.resize(count);
    for (size_t i = 0; i < count; i++) {
        sf::Vector2f pos;
        pos.x = prng::number(0.f, window_size.x) + 0.5f;
        pos.y = prng::number(0.f, window_size.y) + 0.5f;
        vertices[i].position = pos;
        vertices[i].color = sf::Color::Magenta;
    }

}

void Stars::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(vertices, states);
}
