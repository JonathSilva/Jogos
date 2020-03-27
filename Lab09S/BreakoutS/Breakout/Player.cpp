/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:		22 Dez 2012
// Atualiza��o: 28 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
	sprite  = new Sprite("Resources/Player.png");
	MoveTo(window->CenterX() - sprite->Width()/2.0f, window->Height() - 30.0f, Layer::MIDFRONT);
	vel = 300;
	state = STOPED;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// inicia o jogo com barra de espa�o
	if (state == STOPED && window->KeyDown(VK_SPACE))
		state = PLAYING;

	// desloca jogador horizontalmente
	if (window->KeyDown(VK_RIGHT))
		Translate(vel * gameTime, 0);
	if (window->KeyDown(VK_LEFT))
		Translate(-vel * gameTime, 0);

	// mant�m jogador dentro da janela (tam. da barra: 100x20)
	if (x < 0)
		MoveTo(0.0f, y);
	if (x + sprite->Width() > window->Width())
		MoveTo(float(window->Width() - sprite->Width()), y);
}

// ---------------------------------------------------------------------------------
