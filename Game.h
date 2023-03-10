// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Alterations WSB for CS 365 class
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL/SDL.h"
#include <unordered_map>
#include "Actor.h"
#include <string>
#include <vector>

class Game
{
public:
	enum {SCREEN_WIDTH=640, SCREEN_HEIGHT=480}; //WSB
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	
	SDL_Texture* GetTexture(const std::string& fileName);
	std::vector<class Head*>& GetHead() { return mHeads; }
	std::vector<class Ball*>& GetBalls() { return mBalls; }
	
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
	
	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;

	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;

	std::vector<class Head*> mHeads;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific stuff -- WSB		
	class Basket* mBasket;	// Player's basket
	class Head*   mHead;	// Current falling head
	std::vector<class Ball*> mBalls; // The amount of bullets on the screen
	int   headsCaught_ = 0;
	int   headsMissed_ = 0;


};
