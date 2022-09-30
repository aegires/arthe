#include <iostream>
#include "util/GameAdapter.h"
#include <GLFW/glfw3.h>
#include "util/DrawUtils.h"

class Game : public GameAdapter
{
private:
    int i = 0;
    int inc = 1;
    Image sprite;
public:
    void load() {
        sprite = Image("sprites/sprite.png", false);
    }

    void update(float delta) {
        if (i >= 255)
            inc = -1;
        if (i <= 0)
            inc = 1;
        i += inc;
    }

    void draw() {
        DrawUtils::clear(Color(0, i, 127, 255));
        DrawUtils::rect(100, 100, 200, 200, Color(0, 255-i, 127, 255));
        DrawUtils::texture(sprite, 400, 400);
    }

    void unload() {
        delete &sprite;
    }
};

int main()
{
    Game game = Game();
    game.run("Game", 1920 / 1.5, 1080 / 1.5, false);
}