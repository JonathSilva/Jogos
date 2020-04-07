/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:		25 Mar 2013
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "Patterns.h"

// -------------------------------------------------------------------------------

TileSet * Player::exploSet = nullptr;

// -------------------------------------------------------------------------------

Player::Player()
{
	// carrega tilesets, imagens e sprites
	exploSet = new TileSet("Resources/Explosion.png", 60, 60, 5, 5);
	missile = new Image("Resources/Missile.png");
	sprite = new Sprite("Resources/Nave.png");
	MoveTo(window->CenterX(), window->Height() - 30.0f);
	type = PLAYER;
}

// -------------------------------------------------------------------------------

Player::~Player()
{
	delete exploSet;
	delete missile;
	delete sprite;
	delete bbox;
}

// -------------------------------------------------------------------------------

void Player::Update()
{
	// deslocamento padr�o
	float delta = 250 * gameTime;

	// dispara um m�ssil com a barra de espa�o
	if (window->KeyCtrl(VK_SPACE))
	{
		// tamanho da nave � 30x30
		Missile * firing = new Missile(missile);
		firing->MoveTo(x, y - 15, Layer::MIDFRONT);
		Patterns::scene->Add(firing, STATIC);
		Patterns::audio->Play(MISSILE);
	}

	// movimenta player
	if (window->KeyDown(VK_RIGHT))
		Translate(delta, 0);
	else if (window->KeyDown(VK_LEFT))
		Translate(-delta, 0);
	
	// mant�m player dentro da tela
	if (x - 15 < 0)
		MoveTo(15, y);
	if (x + 15 > window->Width())
		MoveTo(window->Width() - 15, y);
}

// -------------------------------------------------------------------------------
