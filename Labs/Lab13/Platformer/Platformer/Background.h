/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:		21 Abr 2012
// Atualiza��o: 11 Jun 2019
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
#include "Sprite.h"						// background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
	float xF, xB;						// posi��o horizontal dos sprites
	Image * backgF;						// imagem front
	Image * backgB;						// imagem back	
	Sprite * backgF1;					// background front A
	Sprite * backgF2;					// background front B
	Sprite * backgB1;					// background back A
	Sprite * backgB2;					// background back B
	Sprite * sky;						// fundo est�tico do background

public:
	Background();						// construtor
	~Background();						// destrutor

	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif