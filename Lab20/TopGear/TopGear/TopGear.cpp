/**********************************************************************************
// TopGear (C�digo Fonte)
//
// Cria��o:		11 Jul 2019
// Atualiza��o:	15 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplificando o uso da escala
//
**********************************************************************************/

#include "Engine.h"
#include "TopGear.h"
#include "Stripes.h"
#include "Player.h"
#include "Cars.h"

// ------------------------------------------------------------------------------
// inicializa��o de membros est�ticos da classe

Audio * TopGear::audio = nullptr;
float   TopGear::speed = 1000.0f;

// ------------------------------------------------------------------------------

void TopGear::Init()
{
	// cria gerenciadores
	scene = new Scene();
	audio = new Audio();

	// carregar m�sicas e efeitos sonoros
	audio->Add(MUSIC, "Resources/Soundtrack.wav");
	audio->Add(ENGINE, "Resources/CarEngine.wav");
	audio->Add(COLLISION, "Resources/Collision.wav");

	// carrega sprites e imagens
	sky = new Sprite("Resources/Sky.png");
	track = new Sprite("Resources/Track.png");

	// cria e adiciona jogador na cena
	Player * player = new Player();
	scene->Add(player, MOVING);

	// cria e adiciona linhas da pista na cena
	Stripes * stripes = new Stripes();
	scene->Add(stripes, STATIC);

	// cria e adiciona carros advers�rios na cena
	Cars * cars = new Cars();
	scene->Add(cars, STATIC);

	// inicia m�sica e motor do carro
	audio->Volume(ENGINE, 0.25f);
	audio->Play(MUSIC, true);	
	audio->Play(ENGINE, true);
}

// ------------------------------------------------------------------------------

void TopGear::Update()
{
	// sai com o pressionamento do ESC
	window->CloseOnEscape();

	// atualiza a cena 
	scene->Update();
	scene->CollisionDetection();

	// habilita/desabilita bounding box
	if (window->KeyCtrl('B'))
		viewBBox = !viewBBox;
} 

// ------------------------------------------------------------------------------

void TopGear::Draw()
{
	// desenha o pano de fundo
	track->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	sky->Draw(window->CenterX(), window->CenterY(), Layer::MIDFRONT);
	
	// desenha a cena
	scene->Draw();

	// desenha bounding box dos objetos
	if (viewBBox)
	{
		Engine::renderer->BeginPixels();
		scene->Begin();
		Object* obj = nullptr;
		while (obj = scene->Next())
			if (obj->bbox)
				Engine::renderer->Draw(obj->bbox, 0xffff00ff);
		Engine::renderer->EndPixels();
	}
} 

// ------------------------------------------------------------------------------

void TopGear::Finalize()
{
	delete track;
	delete sky;
	delete scene;
	delete audio;
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
	engine->window->Title("Top Gear");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gr�fico
	//engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new TopGear());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

