#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <functional>
#include <deque>

#include "Timer.hpp"

#include "_macros.hpp"

namespace engine
{
    class Scene
    {
    private:
        sf::RenderWindow m_window;

    public:
        Scene() = delete;
        Scene(const sf::Vector2u &size);

        void StartLoop();

        sf::RenderWindow &GetWindow();
    };
}