/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:		18 Jan 2013
// Atualiza��o: 04 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Tela de abertura do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_HOME_H_
#define _PACMAN_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	Sprite * backg = nullptr;		// background
	bool ctrlKeyESC = false;		// controla o pressionamento do ESC

public:
	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif