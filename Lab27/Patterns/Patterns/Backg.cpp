/**********************************************************************************
// Backg (C�digo Fonte)
// 
// Cria��o:		21 Abr 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019

//
// Descri��o:	Plano de fundo do jogo
//
**********************************************************************************/

#include "Backg.h"

// ---------------------------------------------------------------------------------

Backg::Backg()
{
	// posi��o inicial do plano de fundo
	MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);

	// cria sprites do plano de fundo
	backg = new Sprite("Resources/Space.png");
}

// ---------------------------------------------------------------------------------

Backg::~Backg()
{
	delete backg;
}

// -------------------------------------------------------------------------------

void Backg::Update()
{
	// move sprite
	Translate(0, 50 * gameTime);
}

// -------------------------------------------------------------------------------

void Backg::Draw()
{
	backg->Draw(x, y, Layer::BACK);
	
	if (y - backg->Height()/2.0f > 0)
		backg->Draw(x, y - backg->Height(), Layer::BACK);

	if (y - backg->Height()/2.0f > window->Height())
		Translate(0, -1.0f * backg->Height());
}

// -------------------------------------------------------------------------------
