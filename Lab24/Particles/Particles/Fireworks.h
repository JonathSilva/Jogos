/**********************************************************************************
// Fireworks (Arquivo de Cabe�alho)
// 
// Cria��o:		17 Mar 2013
// Atualiza��o:	31 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#ifndef _REFINERY_FIREWORKS_H_
#define _REFINERY_FIREWORKS_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Fireworks : public Object
{
private:
	Particles * starsGen;				// sistema de part�culas
	
public:
	Fireworks();						// construtor
	~Fireworks();						// destrutor

	int  Size();						// quantidade de part�culas
	void Update();						// atualiza��o
	void Draw();						// desenho
}; 

// ---------------------------------------------------------------------------------

inline int Fireworks::Size()
{	return starsGen->Size(); }

inline void Fireworks::Draw()
{	starsGen->Draw(Layer::MIDDLE, 0.0f); }

// ---------------------------------------------------------------------------------


#endif