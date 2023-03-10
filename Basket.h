// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
//  WSB: copied Madhav's Ship to make my Basket class
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
class Basket : public Actor
{
public:
	Basket(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; } //WSB
private:
	float mRightSpeed;
	float mDownSpeed; //WSB
	float mColdDown;
};