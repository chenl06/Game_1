#pragma once
#include "Actor.h"


class Ball : public Actor
{
public:
	Ball(class Game* game);
	void UpdateActor(float deltaTime) override;

private:
	float mDeathTimer;
};
