#include <SFML/Graphics.hpp>

class Stars : public sf::Drawable {
public:
    Stars(const sf::Vector2f& window_size);

private:
    sf::VertexArray vertices { sf::Points };

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
