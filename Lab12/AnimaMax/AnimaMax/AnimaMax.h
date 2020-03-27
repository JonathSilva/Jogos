/**********************************************************************************
// AnimaMax (Arquivo de Cabe�alho)
//
// Cria��o:		10 Abr 2012
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de uso da classe Animation
//
**********************************************************************************/

#ifndef _ANIMAMAX_H_
#define _ANIMAMAX_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class AnimaMax : public Game
{
private:
	Sprite * bar = nullptr;			// instru��es
	Sprite * backg = nullptr;		// sprite de fundo
	TileSet * tileset = nullptr;	// folha de sprites da explos�o
	bool keyCtrl = false;			// controla pressionamento de teclas	

public:
	static Scene * scene;			// gerenciador de cena

	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif