// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
//  WSB: copied Madhav's Ship to make my Basket class
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Basket.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Basket::Basket(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f) //WSB
{
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/basket.png"));
}

void Basket::UpdateActor(float deltaTime) //WSB: greatly simplified, as baskets only move l<->r
{
	Actor::UpdateActor(deltaTime);

	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;

	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > Game::SCREEN_WIDTH)
	{
		pos.x = Game::SCREEN_WIDTH;
	}

	pos.y = 460.0f;
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > Game::SCREEN_HEIGHT)
	{
		pos.y = Game::SCREEN_HEIGHT;
	}
	//THESE BARE CONSTANTS ARE NOT NICE

	SetPosition(pos);
}

void Basket::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;

	// right/left movement
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mRightSpeed -= 300.0f;
	}
	if (state[SDL_SCANCODE_S])
	{
		mRightSpeed += 300.0f;
	}
}
