/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:		22 Dez 2012
// Atualiza��o:	31 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"			// tipos espec�ficos da engine
#include "Object.h"			// interface de Object
#include "Sprite.h"			// interface de Sprites
#include "Player.h"			// jogador do Breakout

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
	Player * player;		// ponteiro para jogador
	Sprite * sprite;		// sprite do player

public:
	float velX;				// velocidade horizontal
	float velY;				// velocidade vertical	

	Ball(Player * p);
	~Ball();

	void OnCollision(Object * obj);
	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------

inline void Ball::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif