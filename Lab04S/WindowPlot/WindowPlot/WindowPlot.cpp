/**********************************************************************************
// WindowPlot
// 
// Cria��o:		19 Ago 2011
// Atualiza��o:	09 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Exemplo de game loop. 
//              Desenha pixels aleatoriamente na janela.
//
**********************************************************************************/

#include <windows.h>	// fun��es do windows
#include <windowsx.h>	// extens�es do windows
#include "Resources.h"  // defini��es dos recursos utilizados
#include <random>		// n�meros aleat�rios

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// prot�tipo do procedimento da janela
LRESULT CALLBACK WinProc (HWND, UINT, WPARAM, LPARAM);

// -----------------------------------------------------------------------
// constantes, vari�veis e fun��es globais

int windowWidth = 960;		// largura da janela
int windowHeight = 540;		// altura da janela
bool fullScreen = false;	// tela cheia ou modo janela

bool vkKeys[256] = { 0 };	// estado das teclas do teclado

HWND	 hwnd;				// id da janela
HDC      hdc;				// id do contexto do dispositivo
int      x, y;				// posi��o do pixel
COLORREF color;				// cor do pixel

random_device rd;			// gerador aleat�rio n�o determin�stico 
mt19937 mt;					// gerador aleat�rio Mersenne Twister

// distribui��es uniformes para cor, largura e altura
uniform_int_distribution<int> randColor(0, 255);
uniform_int_distribution<int> randWidth(0, windowWidth-1);
uniform_int_distribution<int> randHeight(0, windowHeight-1);

// -----------------------------------------------------------------------
// fun��es do jogo

// inicializa o jogo alocando recursos
void GameInit()
{
	// pega o contexto do dispositivo gr�fico
	hdc = GetDC(hwnd);
}

// atualiza a l�gica do jogo
void GameUpdate()
{
	// sai do jogo com o pressionamento da tecla ESC
	if (vkKeys[VK_ESCAPE])
		PostMessage(hwnd, WM_DESTROY, 0, 0);

	// calcula a posi��o do pr�ximo pixel
	x = randWidth(mt);
	y = randHeight(mt);

	// define a cor do pr�ximo pixel
	color = RGB(randColor(mt), randColor(mt), randColor(mt));
}

// desenha o pr�ximo quadro do jogo
void GameDraw()
{
	// desenha um pixel na posi��o e cor indicadas
	SetPixel(hdc, x, y, color);
}

// finaliza o jogo desalocando recursos
void GameFinalize()
{
	// libera o contexto do dispositivo gr�fico
	ReleaseDC(hwnd, hdc);
}

// -----------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    MSG          msg;
    WNDCLASS     wndclass; 

	// Definindo uma classe de janela chamada "GameWindow" 
    wndclass.style         = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc   = WinProc;
    wndclass.cbClsExtra    = 0;
    wndclass.cbWndExtra    = 0;
    wndclass.hInstance     = hInstance;
    wndclass.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
    wndclass.hCursor       = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR));
    wndclass.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wndclass.lpszMenuName  = NULL;
    wndclass.lpszClassName = "GameWindow";

	// Registrando "GameWindow"
    if (!RegisterClass (&wndclass))
    {
         MessageBox (NULL, "Erro na cria��o da janela!", "Game", MB_ICONERROR);
         return 0 ;
    }

	// inicialmente o estilo escolhido � em janela
	int windowStyle = WS_OVERLAPPED | WS_SYSMENU;

	// tela cheia ou janela
	if (fullScreen)
	{
		windowWidth  = GetSystemMetrics(SM_CXSCREEN);
		windowHeight = GetSystemMetrics(SM_CYSCREEN);
		windowStyle  = WS_POPUP;
	}

	// criando uma janela baseada na classe "GameWindow" 
    hwnd = CreateWindowEx(
			NULL,							// estilos extras
			"GameWindow",					// nome da "window class"
			"Game",							// t�tulo da janela
			windowStyle,					// estilo da janela
			CW_USEDEFAULT,					// posi��o x inicial
			CW_USEDEFAULT,					// posi��o y inicial
			windowWidth,					// largura da janela
			windowHeight,					// altura da janela
			NULL,							// identificador do objeto pai
			NULL,							// identificador do menu
			hInstance,						// identificador da aplica��o
			NULL);							// par�metros de cria��o

	if (!fullScreen)
	{
		// ret�ngulo com o tamanho da �rea cliente desejada
		RECT winRect = {0, 0, windowWidth, windowHeight};

		// ajuste do tamanho da janela
		AdjustWindowRectEx(&winRect,
						   GetWindowStyle(hwnd),
						   GetMenu(hwnd) != NULL,
						   GetWindowExStyle(hwnd));

		// atualiza posi��o da janela
		int windowPosX = (GetSystemMetrics(SM_CXSCREEN)/2) - ((winRect.right - winRect.left)/2);
		int windowPosY = (GetSystemMetrics(SM_CYSCREEN)/2) - ((winRect.bottom - winRect.top)/2);

		// redimensiona janela com uma chamada a MoveWindow
		MoveWindow(
			hwnd,							// identificador da janela
			windowPosX,						// posi��o x
			windowPosY,						// posi��o y
			winRect.right - winRect.left,	// largura
			winRect.bottom - winRect.top,	// altura
			TRUE);							// repintar
	}

	// mostra e atualiza a janela
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

	GameInit();

	// la�o principal do jogo
	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GameUpdate();
			GameDraw();
		}
	} 
	while (msg.message != WM_QUIT);

	GameFinalize();


	// fim do programa
    return msg.wParam;
}

// -----------------------------------------------------------------------
// procedimento da janela

LRESULT CALLBACK WinProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// processa teclas pressionadas
	case WM_KEYDOWN:
		vkKeys[wParam] = true;
		return 0;

		// processa teclas liberadas
	case WM_KEYUP:
		vkKeys[wParam] = false;
		return 0;

		// janela foi fechada
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

// -----------------------------------------------------------------------