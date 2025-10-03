#include "Screen.hpp"

core::Screen::Screen(const sf::Vector2u &size)
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 16;

    m_window = sf::RenderWindow(sf::VideoMode(size), "Complex Plotter", sf::Style::Close, sf::State::Windowed, settings);

    // m_window.setFramerateLimit(5);
    m_window.setVerticalSyncEnabled(true);
}

void core::Screen::StartLoop()
{
    sf::Clock deltaClock;

    while (m_window.isOpen())
    {
        while (const std::optional<sf::Event> event = m_window.pollEvent())
        {
            if (!event.has_value())
                continue;

            if (event->is<sf::Event::Closed>())
                m_window.close();

            for (auto sub : m_ui_elements_subs)
            {
                if (sub.matchEvent(event.value()))
                {
                    core::SceneData data;
                    data.mousePos = sf::Mouse::getPosition(m_window);
                    sub.callback(data);
                }
            }
        }

        m_window.clear();

        drawUIElements();

        m_window.display();
    }
}

sf::RenderWindow &core::Screen::GetWindow()
{
    return m_window;
}

void core::Screen::drawUIElements()
{
}
