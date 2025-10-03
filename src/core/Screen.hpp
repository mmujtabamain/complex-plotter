#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <SFML/Window/Event.hpp>

#include <vector>
#include <functional>
#include <deque>
#include <any>

#include "Timer.hpp"
#include "UIElement.hpp"

#include "_macros.hpp"

namespace lib::ui
{
    class UIElement;
}

namespace core
{
    struct SceneData
    {
        sf::Vector2i mousePos;
    };

    struct EventSubscription
    {
        std::function<bool(const sf::Event &)> matchEvent;
        std::function<void(const SceneData &)> callback; // data is stored in callback
    };

    class Screen
    {
    private:
        sf::RenderWindow m_window;
        std::vector<lib::ui::UIElement> m_ui_elements;

        std::vector<EventSubscription> m_ui_elements_subs;

    public:
        Screen() = delete;
        Screen(const sf::Vector2u &size);

        void StartLoop();

        sf::RenderWindow &GetWindow();

        // add subscription requires a function that takes in SceneData as argument
        // SceneData is read only thus; const &
        template <typename T_EventType>
        void AddSubscription(std::function<void(const SceneData &)> callback)
        {
            auto defaultMatcher = [](const sf::Event &e)
            { return e.is<T_EventType>(); };
            m_ui_elements_subs.push_back({defaultMatcher, std::move(callback)});
        }

    private:
        void drawUIElements();
    };
}