/**********************************************************************************
// Fireworks (C�digo Fonte)
// 
// Cria��o:		17 Mar 2013
// Atualiza��o:	31 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "Refinery.h"
#include "Fireworks.h"

// ---------------------------------------------------------------------------------

Fireworks::Fireworks()
{
	// configura emissor de part�culas
	Emitter explosion;
	explosion.imgFile   = "Resources/Star.png";		// arquivo de imagem
	explosion.angle     = float(rand() % 360);		// dire��o da explos�o
	explosion.spread    = 180.0f;					// espalhamento em graus
	explosion.lifeTime  = 2.0f;						// tempo de vida em segundos
	explosion.genTime   = 0.000f;					// tempo entre gera��o de novas part�culas
	explosion.percToDim = 0.6f;						// desaparece ap�s 60% da vida
	explosion.minSpeed  = 25.0f;					// velocidade m�nima das part�culas
	explosion.maxSpeed  = 250.0f;					// velocidade m�xima das part�culas
	explosion.r = rand() % 101 * 0.01f;				// cor da part�cula entre 0 e 1
	explosion.g = rand() % 101 * 0.01f;				// cor da part�cula entre 0 e 1
	explosion.b = rand() % 101 * 0.01f;				// cor da part�cula entre 0 e 1
	explosion.a = 1.0f;								// transpar�ncia da part�cula

	// cria sistema de part�culas
	starsGen = new Particles(explosion);

	// gera 50 part�culas na posi��o do mouse
	starsGen->Generate(window->MouseX(), window->MouseY(), 50);
	type = FIREWORKS;
}

// ---------------------------------------------------------------------------------

Fireworks::~Fireworks()
{
	delete starsGen;
}

// -------------------------------------------------------------------------------

void Fireworks::Update()
{
	// atualiza posi��o de cada part�cula
	starsGen->Update(gameTime);

	// remove da cena quando todas as part�culas est�o inativas
	if (starsGen->Inactive())
		Refinery::scene->Delete();
}

// -------------------------------------------------------------------------------