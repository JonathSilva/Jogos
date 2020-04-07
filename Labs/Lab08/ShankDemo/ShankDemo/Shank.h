/**********************************************************************************
// Shank (Arquivo de Cabe�alho)
//
// Cria��o:		21 Dez 2012
// Atualiza��o:	24 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define personagem Shank como um objeto do jogo
//
**********************************************************************************/

#ifndef _D3DSHANK_SHANK_H_
#define _D3DSHANK_SHANK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"			// tipos espec�ficos da engine
#include "Object.h"			// interface de object
#include "Sprite.h"			// interface de sprites

// ---------------------------------------------------------------------------------

class Shank : public Object
{
private:
	Sprite * sprite;

public:
	Shank();
	~Shank();

	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------

#endif