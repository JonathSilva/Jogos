/**********************************************************************************
// AnimaCtrl
// 
// Cria��o:		10 Abr 2012
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de uso da classe Animation
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

class AnimaCtrl : public Game
{
private:
	Sprite * bar = nullptr;			// instru��es
	Sprite * backg = nullptr;		// sprite de fundo
	TileSet * explosion = nullptr;	// folha de sprites da explos�o
	Animation * anim = nullptr;		// anima��o da explos�o
	unsigned frame = 0;				// quadro atual da anima��o
	bool keyCtrl = false;			// controla pressionamento de teclas	

public:
	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

void AnimaCtrl::Init()
{
	bar       = new Sprite("Resources/Bar.png");
	backg     = new Sprite("Resources/Background.jpg");
	explosion = new TileSet("Resources/Explosion.png", 192, 192, 5, 10);
	anim      = new Animation(explosion, 0.120f, true);
}

// ------------------------------------------------------------------------------

void AnimaCtrl::Update()
{
	window->CloseOnEscape();

	// habilita leitura da tecla
	if (!keyCtrl && window->KeyUp(VK_RETURN))
		keyCtrl = true;

	// passa para o pr�ximo frame da anima��o manualmente
	if (keyCtrl && window->KeyDown(VK_RETURN))
	{
		frame = (frame + 1) % 10;
		anim->frame = frame;
		keyCtrl = false;
	}

	// passa para o pr�ximo frame da anima��o automaticamente
	if (window->KeyDown(VK_SPACE))
	{
		anim->NextFrame();
		frame = anim->frame;
	}
} 

// ------------------------------------------------------------------------------

void AnimaCtrl::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	bar->Draw(float(window->CenterX()), window->CenterY() + 40.0f);
	anim->Draw(float(window->CenterX()), window->CenterY() - 140.0f);	
} 

// ------------------------------------------------------------------------------

void AnimaCtrl::Finalize()
{
	delete bar;
	delete backg;
	delete explosion;
	delete anim;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine * engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(0, 0, 0);
	engine->window->Title("Animation Control");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gr�fico
	//engine->graphics->VSync(true);
	
	// inicia o jogo
	int status = engine->Start(new AnimaCtrl());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

