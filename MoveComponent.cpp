// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Actor.h"
#include "Game.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mForwardSpeed(0.0f)
	,mDownwardSpeed(0.0f)
{

}

void MoveComponent::Update(float deltaTime)
{

	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

		// (Screen wrapping code only for asteroids)
		if (pos.x >= (Game::SCREEN_WIDTH - 15) && mForwardSpeed > 0.0f) 
		{ 
			mForwardSpeed *= -1.0f;
		}
		else if (pos.x <= 15 && mForwardSpeed < 0.0f)
		{
			mForwardSpeed *= -1.0f;
		}

		if (pos.y >= (Game::SCREEN_HEIGHT - 15) && mForwardSpeed > 0.0f) 
		{
			mDownwardSpeed *= -1.0f;
		}
		else if (pos.y <= 15 && mForwardSpeed < 0.0f) {
			mDownwardSpeed *= -1.0f;
		}

		mOwner->SetPosition(pos);
	}

}
