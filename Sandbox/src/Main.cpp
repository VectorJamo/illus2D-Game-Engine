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

    Clock clock;
    
    // Main Loop
    while (!window.isClosed())
    {
        window.clear();
        clock.processInputs();
        

        window.pollEvents();
        window.swapBuffers();
    }

    return 0;
}