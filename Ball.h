#pragma once
#include "Actor.h"
#include "Game.h"


class Ball : public Actor
{
public:
	Ball(class Game* game);
	void UpdateActor(float deltaTime) override;

private:
	class CircleComponent* mCircle;
	Vector2 mBallPos;
	float mDeathTimer;
};
