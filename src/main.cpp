#include "Screen.hpp"
#include "Helpers.hpp"
#include "UIElement.hpp"

int main()
{
    core::Screen screen({800, 600});

    lib::ui::UIElement element(screen);

    element.OnClick([](core::SceneData data){
        utils::printVector("POS", data.mousePos);
    });

    screen.StartLoop();
}
