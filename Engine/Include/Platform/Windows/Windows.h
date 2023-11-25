/**
 * @file Windows.h
 * @author tonakaijp (tonakaijp01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma one

#include "../PlatformInterface.h"

#include <SDL3/SDL.h>

namespace Platform
{
    /**
     * @brief プラットフォームウィンドウズの機能
     * 
     */
    class Windows final : public IInterface
    {
    public:
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
		bool Initialize() final;
        
        /**
         * @brief 
         * 
         */
		void Shutdown() final;

    private:
        // Window created by SDL
        struct SDL_Window* mWindow;
        // Renderer for 2D drawing
        struct SDL_Renderer* mRenderer;
    };
};