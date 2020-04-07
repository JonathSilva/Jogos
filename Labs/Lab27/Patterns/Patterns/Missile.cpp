/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:		21 Dez 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Representa um m�ssil
//
**********************************************************************************/

#include "Missile.h"
#include "Patterns.h"

// ---------------------------------------------------------------------------------

Missile::Missile(Image * img)
{
	sprite = new Sprite(img);
	bbox = new Rect(-3, -8, 3, 8);
	vel = 450;
	type = MISSILE;
}

// ---------------------------------------------------------------------------------

Missile::~Missile()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Missile::Update()
{
	// m�ssil se move apenas no eixo y
	Translate(0, -vel * gameTime);

	// remove m�sseis que saem da janela
	if (y < 0)
		Patterns::scene->Delete();
}

// ---------------------------------------------------------------------------------
