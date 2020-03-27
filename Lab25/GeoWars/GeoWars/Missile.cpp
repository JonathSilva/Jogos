/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:		23 Nov 2011
// Atualiza��o:	03 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para um m�ssil
//
**********************************************************************************/

#include "Missile.h"
#include "WallHit.h"
#include "GeoWars.h"

// ------------------------------------------------------------------------------

Player* & Missile::player = GeoWars::player;		// refer�ncia para o player

// ------------------------------------------------------------------------------

Missile::Missile()
{
	// inicializa sprite
	sprite = new Sprite("Resources/Missile.png");

	// cria bounding box
	bbox = new Circle(8);
	
	// inicializa velocidade
	speed.angle = player->speed->angle;
	speed.magnitude = 10.0f;
	
	// move para posi��o
	MoveTo(player->X() + 22 * cos(speed.Radians()), player->Y() - 22 * sin(speed.Radians()));
	RotateTo(-player->speed->angle + 90.0f);

	// define tipo
	type = MISSILE;
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
	delete sprite;
	delete bbox;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
	// move m�ssel com vetor resultante
	Translate(speed.XCom() * 90.0f * gameTime, -speed.YCom() * 90.0f * gameTime);

	// remove m�ssil da cena se ele sair da �rea de jogo
	if (x > game->Width() - 50 || x < 50 || y > game->Height() - 50 || y < 50)
	{
		// volume do som de destrui��o depende da dist�ncia para o jogador
		const float MaxDistance = 4406;
		const float BaseVolume = 0.8f;
		float distance = Point(x, y).Distance(Point(player->X(), player->Y()));
		float level = (MaxDistance - distance) / MaxDistance * BaseVolume;
		GeoWars::audio->Volume(HITWALL, level);
		GeoWars::audio->Play(HITWALL);

		// adiciona explos�o na cena
		GeoWars::scene->Add(new WallHit(x,y), STATIC);

		// remove m�ssil da cena
		GeoWars::scene->Delete();
	}
}

// -------------------------------------------------------------------------------
