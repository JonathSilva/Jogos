/**********************************************************************************
// GravityGuy (C�digo Fonte)
// 
// Cria��o:		05 Out 2011
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Jogo estilo platformer usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game * GravityGuy::level = nullptr;
Audio * GravityGuy::audio = nullptr;
bool GravityGuy::viewBBox = false;

// ------------------------------------------------------------------------------

void GravityGuy::Init() 
{
	// cria sistema de �udio
	audio = new Audio();
	audio->Add(MENU, "Resources/Menu.wav");
	audio->Add(MUSIC, "Resources/Music.wav");
	audio->Add(TRANSITION, "Resources/Transition.wav");

	viewBBox = false;
	level = new Home();
	level->Init();
}

// ------------------------------------------------------------------------------

void GravityGuy::Update()
{
	// habilita/desabilita visualiza��o da bounding box
	if (window->KeyCtrl('B'))
		viewBBox = !viewBBox;	

	// atualiza n�vel
	level->Update();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Draw()
{
	// desenha n�vel
	level->Draw();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Finalize()
{
	level->Finalize();

	delete audio;
	delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine * engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(600, 300);
	engine->window->Color(30, 50, 80);
	engine->window->Title("Gravity Guy");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gr�fico
	//engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new GravityGuy());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

