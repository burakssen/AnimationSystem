// Author: Burak Şen
#include "Game/Game.h"

int main()
{
    Game &game = Game::getInstance();
    game.Run();
    return 0;
}