#include <stdio.h>

#include <Engine.h>

int main()
{
    printf("game start\n");
    
    HobbyEngine GEngine;
    if (GEngine.Initialize() == HobbyEngine::InitResultCode::Error_SDLInit) {
        printf("error: sdl init\n");
        return 0;
    }
    
    GEngine.RunLoop();
    
    GEngine.Shutdown();
    
    printf("game end\n");
    
    return 0;
}
