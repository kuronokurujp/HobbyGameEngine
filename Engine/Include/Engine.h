/**
 * @file Engine.h
 * @author tonakaijp01 (tonakaijp01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma one

// 前方宣言
namespace Platform {
    class IInterface;
};

/**
 * @brief ホビーエンジンのエンジン定義
 * 
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
    
    Platform::IInterface* mpPlatformInterface = nullptr;
};
