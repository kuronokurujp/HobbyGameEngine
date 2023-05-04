#pragma one

/**
 * ホビーエンジンのエンジン定義
*/
class HobbyEngine
{
public:
    enum InitResultCode {
        Success = 0,
        Error_SDLInit
    };
    
    enum RunResultCode {
        Loop = 0,
        End,
    };

    const InitResultCode Initialize();
    const RunResultCode RunLoop();
    void Shutdown();
    
private:
	// Window created by SDL
	struct SDL_Window* mWindow;
	// Renderer for 2D drawing
	struct SDL_Renderer* mRenderer;
};
