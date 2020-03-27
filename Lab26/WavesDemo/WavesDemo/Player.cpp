/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:		10 Out 2012
// Atualiza��o:	07 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "WavesDemo.h"

// -------------------------------------------------------------------------------

Player::Player()
{
	// inicializa controle
	ctrl = new Controller();
	ctrlOn = ctrl->Initialize();

	// configura��o do objeto
	sprite = new Sprite("Resources/Player.png");
	speed  = new Vector(90.0f, 0.0f);
	bbox   = new Circle(18.0f);
	MoveTo(game->CenterX(), game->CenterY());
	type = PLAYER;

	// configura��o do emissor de part�culas
	Emitter emitter;
	emitter.imgFile = "Resources/Star.png";		// arquivo de imagem
	emitter.angle = 270.0f;						// �ngulo base do emissor
	emitter.spread = 25;						// espalhamento em graus
	emitter.lifeTime = 0.3f;					// tempo de vida em segundos
	emitter.genTime = 0.010f;					// tempo entre gera��o de novas part�culas
	emitter.percToDim = 0.6f;					// desaparece ap�s 60% da vida
	emitter.minSpeed = 50.0f;					// velocidade m�nima das part�culas
	emitter.maxSpeed = 100.0f;					// velocidade m�xima das part�culas
	emitter.r = 1.0f;							// componente Red da part�cula 
	emitter.g = 1.0f;							// componente Green da part�cula 
	emitter.b = 1.0f;							// componente Blue da part�cula 
	emitter.a = 1.0f;							// transpar�ncia da part�cula

	// cria sistema de part�culas
	tail = new Particles(emitter);
}

// -------------------------------------------------------------------------------

Player::~Player()
{
	delete sprite;
	delete speed;
	delete bbox;
	delete tail;
	delete ctrl;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector && v)
{
	speed->Add(v);

	// limita velocidade m�xima
	if (speed->magnitude > 10.0f)
		speed->magnitude = 10.0f;

}

// -------------------------------------------------------------------------------

void Player::Update()
{
	// magnitude do vetor acelera��o
	float accel = 40.0f * gameTime;

	// -----------------
	// Controle
	// -----------------

	if (ctrlOn)
	{
		ctrl->UpdateState();

		float ang = Vector::Angle(0, 0, ctrl->Axis(AxisX) / 25.0f, ctrl->Axis(AxisY) / 25.0f);
		float mag = Vector::Distance(0, 0, ctrl->Axis(AxisX) / 25.0f, ctrl->Axis(AxisY) / 25.0f);

		// nenhuma dire��o selecionada
		if (mag == 0)
		{
			// se a velocidade estiver muita baixa
			if (speed->magnitude < 0.1)
			{
				// pare
				speed->magnitude = 0.0f;
			}
			else
			{
				// comece a frear
				Move(Vector(speed->angle + 180.0f, 5.0f * gameTime));
			}
		}
		else
		{
			// ande na dire��o selecionada
			Move(Vector(ang, mag * gameTime));
		}

		// dispara m�ssil
		if (ctrl->ButtonCtrl(0))
		{
			WavesDemo::audio->Play(FIRE);
			WavesDemo::scene->Add(new Missile(), STATIC);
		}
	}
	else
	{
		// modifica vetor velocidade do player
		if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP))
			Move(Vector(45.0f, accel));
		else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP))
			Move(Vector(135.0f, accel));
		else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN))
			Move(Vector(225.0f, accel));
		else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN))
			Move(Vector(315.0f, accel));
		else if (window->KeyDown(VK_RIGHT))
			Move(Vector(0.0f, accel));
		else if (window->KeyDown(VK_LEFT))
			Move(Vector(180.0f, accel));
		else if (window->KeyDown(VK_UP))
			Move(Vector(90.0f, accel));
		else if (window->KeyDown(VK_DOWN))
			Move(Vector(270.0f, accel));
		else
			// se nenhuma tecla est� pressionada comece a frear
			if (speed->magnitude > 0.1f)
				Move(Vector(speed->angle + 180.0f, 5.0f * gameTime));
			else
				// velocidade muita baixa, n�o use soma vetorial, apenas pare
				speed->magnitude = 0.0f;

		// dispara m�ssil
		if (window->KeyCtrl(VK_SPACE))
		{
			WavesDemo::audio->Play(FIRE);
			WavesDemo::scene->Add(new Missile(), STATIC);
		}
	}

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XCom() * 50.0f * gameTime, -speed->YCom() * 50.0f * gameTime);

	// atualiza calda do jogador
	tail->Generator().angle = speed->angle + 180;
	tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
	tail->Update(gameTime);

	// restringe a �rea do jogo
	if (x < 0)
		MoveTo(0, y);
	if (y < 0)
		MoveTo(x, 0);
	if (x > game->Width())
		MoveTo(game->Width(), y);
	if (y > game->Height())
		MoveTo(x, game->Height());
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed->angle + 90.0f);
	tail->Draw(Layer::MIDBACK, 1.0f);
}


// -------------------------------------------------------------------------------
