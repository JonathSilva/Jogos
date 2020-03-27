/**********************************************************************************
// Platformer (Arquivo de Cabe�alho)
//
// Cria��o:		05 Out 2011
// Atualiza��o:	11 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de jogo estilo platforma
//
**********************************************************************************/

#ifndef _GRAVITYGUY_H_
#define _GRAVITYGUY_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Platform.h"
#include "Background.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class Platformer : public Game
{
private:
	Player * player = nullptr;		// gravity guy controlado pelo jogador
	Background * backg = nullptr;	// pano de fundo do jogo

public:
	static Scene * scene;			// gerenciador de cena

	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif