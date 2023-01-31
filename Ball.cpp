#include "Ball.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleComponent.h"
#include "Game.h"
#include "Head.h"


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

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);

}

void Ball::UpdateActor(float deltaTime)
{
	// If we run out of time, laser is dead
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		// Do we intersect with an asteroid?
		for (auto ast : GetGame()->GetHead())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				// The first asteroid we intersect with,
				// set ourselves and the asteroid to dead
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}


}