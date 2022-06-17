#include "src/Engine.h"

int main()
{
    using namespace illus2d;
    using namespace graphics;
    using namespace util;

    Window window(800, 600, "illus2D Engine");
    if (!window.init())
    {
        std::cout << "Init Error" << std::endl;
        std::cin.get();
        return -1;
    }
    window.bgColor(0.3f, 0.3f, 0.3f, 1.0f);
    window.setVSyncEnabled(false);

    // Init the utilities
    Clock::Init();
    Input::Init(&window);
    
    // Main Loop
    while (!window.isClosed())
    {
        window.clear();
        Clock::Update();
        Input::Update();

        Clock::ShowFps();
       
#if 0
        if(Input::IsKeyHold(KEY_SPACE))
            std::cout << "SPACE KEY IS HOLD!" << "\n";
        if (Input::IsKeyPressed(KEY_UP))
            std::cout << "UP ARROW IS PRESSED!" << "\n";
        if (Input::IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            std::cout << "LEFT MOUSE PRESSED!" << "\n";
        if (Input::IsMouseButtonHold(MOUSE_BUTTON_RIGHT))
            std::cout << "RIGHT MOUSE HOLD!" << "\n";
        if (Input::IsMouseScrollUp())
            std::cout << "Mouse Scroll Up!" << "\n";
        if (Input::IsMouseScrollDown())
            std::cout << "Mouse Scroll Down!" << "\n";

#endif

        window.pollEvents();
        window.swapBuffers();
    }

    return 0;
}