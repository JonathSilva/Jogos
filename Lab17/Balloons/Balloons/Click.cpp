/**********************************************************************************
// Click (C�digo Fonte)
//
// Cria��o:		29 Jun 2019
// Atualiza��o:	03 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Click do Mouse
//
**********************************************************************************/

#include "Click.h"
#include "Balloons.h"

// ---------------------------------------------------------------------------------

Click::Click(TileSet * tiles)
{
	anim = new Animation(tiles, 0.030f, false);
	bbox = new Point();
}

// ---------------------------------------------------------------------------------

Click::~Click()
{
	delete bbox;
	delete anim;
}

// ---------------------------------------------------------------------------------

void Click::Update()
{
	// segue a posi��o do mouse
	MoveTo(window->MouseX(), window->MouseY());
	
	// atualiza a anima��o
	anim->NextFrame();
	if (anim->Inactive())
		Balloons::scene->Delete();
}

// ---------------------------------------------------------------------------------