#include <iostream>
#include "util/GameAdapter.h"
#include <GLFW/glfw3.h>
#include "util/DrawUtils.h"

class Game : public GameAdapter
{
public:
    int i = 0;
    int inc = 1;

    void load() {

    }

    void update(float delta) {
        if (i >= 255)
            inc = -1;
        if (i <= 0)
            inc = 1;
        i += inc;
    }

    void draw() {
        DrawUtils::clear(Color(255, i, 127, 255));
        DrawUtils::rect(0, 0, 200, 200);
    }

    void unload() {
        
    }
};

int main()
{
    Game().run("Game", 1920 / 1.5, 1080 / 1.5, false);
}