/**********************************************************************************
// WavesDemo (Arquivo de Cabe�alho)
// 
// Cria��o:		23 Out 2012
// Atualiza��o:	07 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Demonstra��o de movimento retil�neo
//
**********************************************************************************/

#ifndef _WAVESDEMO_H_
#define _WAVESDEMO_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Sprite.h"
#include "Player.h"
#include "Hud.h"


// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, MISSILE, ORANGE, WALLHIT };

enum SoundIds { THEME, FIRE, EXPLODE, HITWALL, SPAWN };

// ------------------------------------------------------------------------------

class WavesDemo : public Game
{
private:
	Sprite * backg = nullptr;		// pano de fundo
	Hud * hud = nullptr;			// heads up display	
	bool viewBBox = false;			// bouding box vis�vel

public:
	static Audio * audio;			// sitema de �udio
	static Scene * scene;			// cena do jogo
	static Player* player;			// ponteiro para o jogador

	void Init();					// inicializa��o
	void Update();					// atualiza��o
	void Draw();					// desenho
	void Finalize();				// finaliza��o
};

// ---------------------------------------------------------------------------------

#endif