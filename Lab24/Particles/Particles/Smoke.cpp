/**********************************************************************************
// Smoke (C�digo Fonte)
// 
// Cria��o:		17 Mar 2013
// Atualiza��o:	31 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de fuma�a usando sistema de part�culas
//
**********************************************************************************/

#include "Smoke.h"
#include "Refinery.h"

// ---------------------------------------------------------------------------------

Smoke::Smoke(float pX, float pY, float angle, bool night)
{
	// configura emissor de part�culas
	Emitter smoke;
	smoke.imgFile   = "Resources/Smoke.png";	// arquivo de imagem
	smoke.angle     = angle;					// dire��o da fuma�a
	smoke.spread    = 15;						// espalhamento em graus
	smoke.lifeTime  = 1.0f;						// tempo de vida em segundos
	smoke.genTime   = 0.010f;					// tempo entre gera��o de novas part�culas
	smoke.percToDim = 0.6f;						// desaparece ap�s 60% da vida
	smoke.minSpeed  = 75.0f;					// velocidade m�nima das part�culas
	smoke.maxSpeed  = 100.0f;					// velocidade m�xima das part�culas

	// cor da part�cula depende da ilumina��o
	if (night)
	{
		smoke.r = 0.2f;							// cor da part�cula
		smoke.g = 0.2f;							// cor da part�cula
		smoke.b = 0.2f;							// cor da part�cula
		smoke.a = 1.0f;							// cor da part�cula
	}
	else
	{
		smoke.r = 1.0f;							// cor da part�cula
		smoke.g = 1.0f;							// cor da part�cula
		smoke.b = 1.0f;							// cor da part�cula
		smoke.a = 1.0f;							// cor da part�cula
	}

	// cria sistema de part�culas
	smokeGen = new Particles(smoke);
	MoveTo(pX, pY);
	stop = false;
	type = SMOKE;
}

// ---------------------------------------------------------------------------------

Smoke::~Smoke()
{
	delete smokeGen;
}

// -------------------------------------------------------------------------------

void Smoke::TurnOff()
{
	stop = true;
}

// -------------------------------------------------------------------------------

void Smoke::Update()
{
	if (stop)
	{
		if (smokeGen->Inactive())
			Refinery::scene->Delete();
	}
	else
	{
		smokeGen->Generate(x, y);
	}

	smokeGen->Update(gameTime);
}

// -------------------------------------------------------------------------------
