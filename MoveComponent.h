// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	float GetDownwardSpeed() const { return mDownwardSpeed; }
	void SetDownwardSpeed(float speed) { mDownwardSpeed = speed; }
private:
	// Controls forward movement (units/second)
	float mForwardSpeed;
	float mDownwardSpeed;
};
