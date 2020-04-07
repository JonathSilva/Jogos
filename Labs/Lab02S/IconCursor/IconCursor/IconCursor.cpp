/**********************************************************************************
// IconCursor
// 
// Cria��o:		06 Mai 2011
// Atualiza��o:	30 Abr 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	O exemplo mostra como personalizar o �cone/cursor da janela e cria 
//              vari�veis globais para configurar facilmente o tamanho e o modo
//              da janela (tela cheia ou em janela).
//
**********************************************************************************/

// inclui tipos b�sicos e fun��es da API Win32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>	// inclui fun��es do windows
#include <windowsx.h>	// inclui fun��es extras do windows (como GetWindowStyle)
#include "Resources.h"  // defini��es dos recursos utilizados

// prot�tipo do procedimento da janela
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

// -----------------------------------------------------------------------
// constantes, vari�veis e fun��es globais

int WindowWidth = 960;
int WindowHeight = 540;
bool FullScreen = false;

HWND hwnd;

// -----------------------------------------------------------------------

// programa principal
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	MSG          msg;
	WNDCLASS     wndclass;

	// definindo uma classe de janela chamada "GameWindow" 
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = "GameWindow";

	// registrando "GameWindow"
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, "Erro na cria��o da janela!", "Game", MB_ICONERROR);
		return 0;
	}

	int WindowStyle = WS_OVERLAPPED | WS_SYSMENU;

	// tela cheia ou janela
	if (FullScreen)
	{
		WindowWidth = GetSystemMetrics(SM_CXSCREEN);
		WindowHeight = GetSystemMetrics(SM_CYSCREEN);
		WindowStyle = WS_POPUP;
	}

	// criando uma janela baseada na classe "GameWindow"
	// necess�rio usar CreateWindowEx para usar AdjustWindowRectEx
	hwnd = CreateWindowEx(
		NULL,							// estilos extras
		"GameWindow",					// nome da "window class"
		"Game",							// t�tulo da janela
		WindowStyle,					// estilo da janela
		CW_USEDEFAULT,					// posi��o x inicial
		CW_USEDEFAULT,					// posi��o y inicial
		WindowWidth,					// largura da janela
		WindowHeight,					// altura da janela
		NULL,							// identificador do objeto pai
		NULL,							// identificador do menu
		hInstance,						// identificador da aplica��o
		NULL);							// par�metros de cria��o

	if (!FullScreen)
	{
		// ret�ngulo com o tamanho da �rea cliente desejada
		RECT winRect = { 0, 0, WindowWidth, WindowHeight };

		// ajuste do tamanho da janela
		AdjustWindowRectEx(&winRect,
			GetWindowStyle(hwnd),
			GetMenu(hwnd) != NULL,
			GetWindowExStyle(hwnd));

		// atualiza posi��o da janela
		int windowPosX = (GetSystemMetrics(SM_CXSCREEN) / 2) - ((winRect.right - winRect.left) / 2);
		int windowPosY = (GetSystemMetrics(SM_CYSCREEN) / 2) - ((winRect.bottom - winRect.top) / 2);

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

	// tratamento de mensagens destinadas a janela da aplica��o
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// fim do programa
	return msg.wParam;
}

// -----------------------------------------------------------------------

// procedimento da janela
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

// -----------------------------------------------------------------------