/**********************************************************************************
// BackScroll (Arquivo de Cabe�alho)
// 
// Cria��o:		22 Out 2012
// Atualiza��o:	14 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Desenhando e movimentando um background maior que a janela
//
**********************************************************************************/

#ifndef _BACKSCROLL_H_
#define _BACKSCROLL_H_

// ------------------------------------------------------------------------------

#include "Resources.h"				// recursos utilizados no jogo (cursor, �cone, etc.) 
#include "Game.h"					// defini��o da classe jogo
#include "Font.h"					// fonte para exibi��o de texto
#include "Sprite.h"					// defini��o dos sprites
#include <sstream>					// sa�da para strings
using std::stringstream;	

// ------------------------------------------------------------------------------

class BackScroll : public Game
{
private:
	Sprite * infoBox;				// caixa de informa��es
	Sprite * keyMap;				// caixa para teclas de atalho
	Font   * font;					// fonte para texto normal
	Font   * bold;					// fonte para texto negrito
	stringstream text;				// texto tempor�rio

	ViewPort viewport;				// viewport do jogo
	Sprite * backg;					// pano de fundo com scrolling
	float maxWidth;					// largura m�xima do background
	float maxHeight;				// altura m�xima do background
	float scrollSpeed;				// velocidade de scrolling

public:
	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif