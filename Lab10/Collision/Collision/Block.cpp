/**********************************************************************************
// Block (Arquivo de Cabe�alho)
// 
// Cria��o:		22 Dez 2012
// Atualiza��o:	31 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Bloco do jogo Breakout
//
**********************************************************************************/

#include "Block.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Block::Block(Image * img)
{
	// tamanho do bloco � 60x24
	bbox = new Rect(0, 0, 59, 23);

	sprite  = new Sprite(img);
	velX = 0.0f;
	velY = 0.0f;
	type = BLOCK;
}

// ---------------------------------------------------------------------------------

Block::~Block()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Block::Update()
{
	Translate(velX * gameTime, velY * gameTime);

	// tamanho do bloco � 60x24
	if (y > window->Height())
		Breakout::scene->Delete();
}

// ---------------------------------------------------------------------------------
