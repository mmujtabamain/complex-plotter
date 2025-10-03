#pragma once
#include "SFML/Graphics.hpp"
#include "Screen.hpp"
#include <functional>

namespace core
{
    class Screen;
    class SceneData;
}

namespace lib::ui
{
    class UIElement
    {
    private:
        core::Screen &m_screen;
        void drawCall();

    public:
        UIElement() = delete;

        UIElement(core::Screen &screen);
        UIElement(core::Screen &screen, const core::SceneData &position);

        void OnClick(std::function<void(const core::SceneData &)> callback);

    protected:
    };
}