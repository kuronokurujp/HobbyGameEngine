#include "../Include/Engine.h"

#include <stdio.h>
#include <SDL3/SDL.h>

const HobbyEngine::InitResultCode HobbyEngine::Initialize()
{
    printf("init\n");

	int SdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (SdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return HobbyEngine::InitResultCode::Error_SDLInit;
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
        return HobbyEngine::InitResultCode::Error_SDLInit;
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
        return HobbyEngine::InitResultCode::Error_SDLInit;
	}

    return HobbyEngine::InitResultCode::Success;
}

const HobbyEngine::RunResultCode HobbyEngine::RunLoop()
{
    printf("run\n");
	while (1)
	{
	}

    return HobbyEngine::RunResultCode::End;
}

void HobbyEngine::Shutdown()
{
    printf("shutdown\n");
}
