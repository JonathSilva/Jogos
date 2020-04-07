/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:		21 Abr 2012
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_BACKGROUND_H_
#define _GRAVITYGUY_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Sprite.h"						// desenho de sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
	Sprite * backgF;					// background front
	Sprite * backgB;					// background back
	Sprite * sky;						// fundo est�tico do background
	float xF, xB;						// posi��o horizontal dos sprites

public:
	Background();						// construtor
	~Background();						// destrutor

	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif