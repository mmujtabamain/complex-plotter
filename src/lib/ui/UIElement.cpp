#include "UIElement.hpp"

lib::ui::UIElement::UIElement(core::Screen &screen) : m_screen(screen)
{
}

lib::ui::UIElement::UIElement(core::Screen &screen, const core::SceneData &position) : m_screen(screen)
{
}

void lib::ui::UIElement::OnClick(std::function<void(const core::SceneData &)> callback)
{
    m_screen.AddSubscription<sf::Event::MouseButtonPressed>(callback);
}

void lib::ui::UIElement::drawCall()
{
}
