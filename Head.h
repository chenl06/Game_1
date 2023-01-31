// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
//  WSB: copied Madhav's Ship to make my Head class
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
class Head : public Actor
{
public:
	Head (class Game* game);
	void UpdateActor(float deltaTime) override;
	//void ProcessKeyboard(const uint8_t* state); //WSB
	//float GetRightSpeed() const { return mRightSpeed; } //WSB
	float GetDownSpeed() const { return mDownSpeed; }
	class CircleComponent* GetCircle() { return mCircle; }
private:
	//float mRightSpeed; //WSB
	float mDownSpeed;
	class CircleComponent* mCircle;
};