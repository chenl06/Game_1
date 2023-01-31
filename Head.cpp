// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
//  WSB: copied Madhav's Ship to make my Head class
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Head.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "CircleComponent.h"

Head::Head(Game* game)
	:Actor(game),
	//,mRightSpeed(0.0f) //WSB
	mDownSpeed(300.0f)
{
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Head.png"));
	Vector2 pos(float(rand() % Game::SCREEN_WIDTH), 0.0f); 

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);
	SetPosition(pos);
	//WSB: don't need animated sprite, so we're done
}

void Head::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.y += mDownSpeed * deltaTime;

	if (pos.y < 25.0f)		//WSB: simplified all this.  Still need to eliminate Madav's bare constants
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f) //should never happen -- Game loop checks for reaching 480 and resets to top
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}


