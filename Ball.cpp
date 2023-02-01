#include "Ball.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Head.h"


Ball::Ball(Game* game)
	:Actor(game)
	, mDeathTimer(1.0f)
{
	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Laser.png"));

	// Create a move component, and set a forward speed
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(500.0f);
	mc->SetDownwardSpeed(-200.0f);

}

void Ball::UpdateActor(float deltaTime)
{
	
	// Update ball position based on ball velocity
	
}