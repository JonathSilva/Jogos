/**********************************************************************************
// Plane (C�digo Fonte)
// 
// Cria��o:		24 Set 2012
// Atualiza��o:	15 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para um avi�o
//
**********************************************************************************/

#include "Plane.h"

// ---------------------------------------------------------------------------------

Plane::Plane()
{
	// configura sprite
	sprite = new Sprite("Resources/Airplane.png");

	// configura posi��o do objeto
	MoveTo(window->CenterX(), window->CenterY());
}

// ---------------------------------------------------------------------------------

Plane::~Plane()
{
	delete sprite;
	delete bbox;
}
// -------------------------------------------------------------------------------

void Plane::Update()
{
	
}

// -------------------------------------------------------------------------------

void Plane::Draw()
{
	// converte �ngulo em radianos antes de desenhar
	sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------