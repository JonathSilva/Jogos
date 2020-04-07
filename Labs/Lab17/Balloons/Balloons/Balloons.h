/**********************************************************************************
// Balloons (Arquivo de Cabe�alho)
// 
// Cria��o:		28 Out 2011
// Atualiza��o:	03 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de uso do mouse e teclado
//
**********************************************************************************/

#ifndef _BALLOONS_H_
#define _BALLOONS_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Scene.h"
#include "Audio.h"
#include "Font.h"
#include "Sprite.h"
#include "Timer.h"
#include "Resources.h"
#include <sstream>
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
using std::stringstream;

// ------------------------------------------------------------------------------

using DistReal = uniform_real_distribution<float>;

enum SoundIds {MUSIC, POP};

// ------------------------------------------------------------------------------

class Balloons : public Game
{
private:
	Sprite * backg = nullptr;				// plano de fundo
	Sprite * popBox;						// caixa de placar
	Sprite * lostBox;						// caixa de placar
	Sprite * infoBar;						// caixa de informa��es

	Image * ball = nullptr;					// imagem do bal�o
	TileSet* tilesClick = nullptr;			// folha de sprite do click
	TileSet * tilesPop = nullptr;			// folha de sprite do estouro	
	
	Font * sysFont = nullptr;				// fonte do sistema
	Font * gameFont = nullptr;				// fonte do jogo

	DistReal randColor{ 0.0f, 1.0f };		// distribui��o uniforme para cor
	DistReal randWidth{ 32.0f, 1247.0f };	// distribui��o uniforme para largura (1280x800)
	DistReal randHeight{ 856.0f, 956.0f };	// distribui��o uniforme para altura (1280x800)

	random_device rd;						// gerador aleat�rio n�o-determin�stico
	mt19937 mt{rd()};						// gerador aleat�rio Mersenne Twister
	Timer timer;							// controle do tempo
	stringstream text;						// texto para exibi��o

	bool viewBBox = false;					// visualiza bounding box

	float posX = 0.0f;						// posi��o x do �ltimo bal�o
	float posY = 0.0f;						// posi��o y do �ltimo bal�o

public:
	static Scene * scene;					// cena do jogo
	static Audio * audio;					// sistema de �udio

	static uint popped;						// n�mero de bal�es estourados
	static uint lost;						// n�mero de bal�es perdidos
	
	void Init();							// inicializa jogo
	void Update();							// atualiza l�gica do jogo
	void Draw();							// desenha jogo
	void Finalize();						// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif