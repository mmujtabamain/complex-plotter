#include "Scene.hpp"

engine::Scene::Scene(const sf::Vector2u &size)
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 16;

    m_window = sf::RenderWindow(sf::VideoMode(size), "Complex Plotter", sf::Style::Close, sf::State::Windowed, settings);

    // m_window.setFramerateLimit(5);
    m_window.setVerticalSyncEnabled(true);
}

void engine::Scene::StartLoop()
{
    sf::Clock deltaClock;

    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        m_window.clear();

        // DRAW

        m_window.display();
    }
}


sf::RenderWindow &engine::Scene::GetWindow()
{
    return m_window;
}
