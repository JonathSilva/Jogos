/**********************************************************************************
// Debris (C�digo Fonte)
//
// Cria��o:		07 Fev 2013
// Atualiza��o:	28 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Anima��o de explos�o
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
	anim = new Animation(Asteroids::debriSet, 0.030f, false);
	MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
	delete anim;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
	anim->NextFrame();

	if (anim->Inactive())
		Asteroids::scene->Delete();	
}

// ---------------------------------------------------------------------------------