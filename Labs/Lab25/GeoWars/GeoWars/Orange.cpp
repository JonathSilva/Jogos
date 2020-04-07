/**********************************************************************************
// Orange (C�digo Fonte)
// 
// Cria��o:		05 Ago 2019
// Atualiza��o:	05 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Objeto faz movimento retil�neo
//
**********************************************************************************/

#include "GeoWars.h"
#include "Orange.h"
#include "Random.h" 

// ---------------------------------------------------------------------------------

Orange::Orange(Player * p)
{
	player = p;
	sprite = new Sprite("Resources/Orange.png");
	bbox   = new Circle(20.0f);
	speed  = new Vector(0, 2.0f);

	// ajusta �ngulo do vetor na dire��o do jogador
	speed->angle = speed->Angle(x, y, player->X(), player->Y());
	RotateTo(-speed->angle);
	
	// move para uma posi��o aleat�ria (canto superior esquerdo)
	FloatRand posX{ 100, 150 };
	FloatRand posY{ 100, 150 };
	MoveTo(posX.Rand(), posY.Rand());

	multiplier = 70.0f;
	type = ORANGE;

	// configura��o do emissor de part�culas
	Emitter emitter;
	emitter.imgFile = "Resources/Star.png";		// arquivo de imagem
	emitter.angle = speed->angle + 180;			// �ngulo base do emissor
	emitter.spread = 5;						// espalhamento em graus
	emitter.lifeTime = 0.2f;					// tempo de vida em segundos
	emitter.genTime = 0.010f;					// tempo entre gera��o de novas part�culas
	emitter.percToDim = 0.7f;					// desaparece ap�s 60% da vida
	emitter.minSpeed = 50.0f;					// velocidade m�nima das part�culas
	emitter.maxSpeed = 100.0f;					// velocidade m�xima das part�culas
	emitter.r = 1.0f;							// componente Red da part�cula 
	emitter.g = 0.5;							// componente Green da part�cula 
	emitter.b = 0.0f;							// componente Blue da part�cula 
	emitter.a = 1.0f;							// transpar�ncia da part�cula

	// cria sistema de part�culas
	tail = new Particles(emitter);
}

// ---------------------------------------------------------------------------------

Orange::~Orange()
{
	delete sprite;
	delete speed;
	delete bbox;
	delete tail;
}

// -------------------------------------------------------------------------------

void Orange::OnCollision(Object * obj)
{
	if (obj->Type() == MISSILE)
		GeoWars::scene->Delete(this, MOVING);
}

// -------------------------------------------------------------------------------

void Orange::Update()
{
	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XCom() * multiplier * gameTime, -speed->YCom() * multiplier * gameTime);

	// ajusta �ngulo do vetor na dire��o do jogador
	if (x < 100 || y < 100 || x > game->Width() - 100 || y > game->Height() - 100)
	{
		multiplier = 200;
		speed->angle = speed->Angle(x, y, player->X(), player->Y());
		RotateTo(-speed->angle);
	}

	// atualiza calda da nave
	tail->Generator().angle = speed->angle + 180;
	tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
	tail->Update(gameTime);
}

// ---------------------------------------------------------------------------------

void Orange::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
	tail->Draw(Layer::MIDBACK, 1.0f);
}

// -------------------------------------------------------------------------------