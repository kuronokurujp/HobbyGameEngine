/**
 * @file Windows.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 #include "../../../Include/Platform/Windows/Windows.h"


namespace Platform
{
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool Windows::Initialize() 
    {
        int SdlResult = SDL_Init(SDL_INIT_VIDEO);
        if (SdlResult != 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return false;
        }

        // Create an SDL Window
        mWindow = SDL_CreateWindowWithPosition(
            "Game Programming in C++ (Chapter 1)", // Window title
            100,	// Top left x-coordinate of window
            100,	// Top left y-coordinate of window
            1024,	// Width of window
            768,	// Height of window
            0		// Flags (0 for no flags set)
        );

        if (!mWindow)
        {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            return false;
        }
        
        //// Create SDL renderer
        mRenderer = SDL_CreateRenderer(
            mWindow, // Window to create renderer for
            nullptr,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        if (!mRenderer)
        {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            return false;
        }

        return false;
    }
        
    /**
     * @brief 
     * 
     */
    void Windows::Shutdown() 
    {
    } 
};