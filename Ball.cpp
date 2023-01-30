#include "Ball.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"


Ball::Ball(Game* game)
	:Actor(game)
	, mDeathTimer(1.0f)
{
	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Basket.png"));

	// Create a move component, and set a forward speed
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(800.0f);

}

void Ball::UpdateActor(float deltaTime)
{
	// If we run out of time, laser is dead
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
}