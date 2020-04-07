/**********************************************************************************
// Trials (Arquivo de Cabe�alho)
// 
// Cria��o:		14 Mai 2012
// Atualiza��o:	03 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de interface com menus
//
**********************************************************************************/

#ifndef _TRIALS_H_
#define _TRIALS_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Mouse.h"
#include "Item.h"
#include "Sprite.h"
#include "Scene.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

enum MenuID {SINGLE, MULTI, TRACKS, LEADERBOARD, OPTIONS, EXIT};

enum Music  {EVOLUTION};

// ------------------------------------------------------------------------------

class Trials : public Game
{
private:
	static const int MaxItens = 6;	// n�mero de itens do menu

	Scene   * scene = nullptr;		// cena do jogo
	Audio   * audio = nullptr;		// sistema de �udio
	Sprite  * backg = nullptr;		// plano de fundo
	Mouse   * mouse = nullptr;		// objeto mouse
	
	Item * menu[MaxItens] = { 0 };	// itens do menu
	Item * selected = nullptr;		// item selecionado

	bool viewBBox = false;			// visualiza bounding box	
	bool editMode = false;			// jogo em modo de edi��o
	bool followMode = false;		// item em modo de persegui��o
	
public:
	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif