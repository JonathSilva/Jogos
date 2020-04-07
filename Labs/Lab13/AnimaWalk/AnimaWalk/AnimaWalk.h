/**********************************************************************************
// AnimaWalk (Arquivo de Cabe�alho)
//
// Cria��o:		18 Abr 2012
// Atualiza��o: 11 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Usando a classe Animation para animar um personagem
//
**********************************************************************************/

#ifndef _ANIMAWALK_H_
#define _ANIMAWALK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "Lady.h"

// ------------------------------------------------------------------------------

class AnimaWalk : public Game
{
private:
	Sprite * backg = nullptr;		// sprite de fundo
	Lady * lady = nullptr;			// objeto com anima��o	

public:
	static Scene * scene;			// gerenciador de cena

	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif