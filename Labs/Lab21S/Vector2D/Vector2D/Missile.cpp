/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:		23 Nov 2011
// Atualiza��o:	16 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Missile.h"
#include "Vector2D.h"
#include <cmath>

// ------------------------------------------------------------------------------

Missile::Missile(Plane * plane, Image * img, float delta)
{
	// inicializa sprite
	sprite = new Sprite(img);

	// inicializa vetor velocidade
	speed.angle = plane->Angle() + delta;
	speed.magnitude = 500;
	
	// usa mesma rota��o do avi�o
	rotation = plane->rotation;
	
	// move para posi��o
	MoveTo(plane->X() + 50 * cos(speed.Radians()), plane->Y() - 50 * sin(speed.Radians()));
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
	delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
	Translate(speed.XCom() * gameTime, -speed.YCom() * gameTime);
	
	if (x > window->Width() || x < 0 || y > window->Height() || y < 0)
	{
		Vector2D::audio->Play(EXPLOSION);
		Vector2D::scene->Delete();
	}
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
	sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
