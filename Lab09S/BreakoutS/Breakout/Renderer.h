/**********************************************************************************
// Renderer (Arquivo de Cabe�alho)
//
// Cria��o:		11 Mai 2014
// Atualiza��o:	24 Mai 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define um renderizador de grupos de sprites
//
**********************************************************************************/

#ifndef _DESENVJOGOS_RENDERER_H_
#define _DESENVJOGOS_RENDERER_H_

// ---------------------------------------------------------------------------------

#include "Window.h"
#include "Graphics.h"
#include "Sprite.h"
#include <DirectXMath.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace DirectX;

// ---------------------------------------------------------------------------------

struct Vertex
{
	XMFLOAT3 pos;
	XMFLOAT4 color;
	XMFLOAT2 tex;
};

// ---------------------------------------------------------------------------------

class Renderer
{
private:
	Graphics                 * pGraphics;					// ponteiro para dispositivo gr�fico

	ID3D11InputLayout		 * inputLayout;					// input layout
	ID3D11VertexShader		 * vertexShader;				// vertex shader
	ID3D11PixelShader		 * pixelShader;					// pixel shader
	ID3D11RasterizerState	 * rasterState;					// estado do rasterizador
	ID3D11SamplerState		 * sampler;						// estado do amostrador de textura
	ID3D11Buffer			 * vertexBuffer;				// buffer de v�rtices
	ID3D11Buffer			 * indexBuffer;					// buffer de �ndices
	ID3D11Buffer			 * constantBuffer;				// buffer para o shader
	uint                       vertexBufferPosition;		// posi��o atual do vertex buffer

	static const uint MinBatchSize = 128;					// tamanho m�nimo do lote de sprites
	static const uint MaxBatchSize = 4096;					// tamanho m�ximo do lote de sprites	
	static const uint VerticesPerSprite = 4;				// n�mero de v�rtices por sprite
	static const uint IndicesPerSprite = 6;					// n�mero de �ndices por sprite

	vector<SpriteData*> spriteVector;						// vetor de sprites
	
	// renderiza um grupo de sprites de mesma textura
	void RenderBatch(ID3D11ShaderResourceView * texture, SpriteData ** sprites, uint cont);

public:
	Renderer();												// construtor
	~Renderer();											// destrutor
	
	bool Initialize(Window * window, Graphics * graphics);	// inicializa o renderizador
	void Draw(SpriteData * sprite);							// adiciona sprite na lista
	void Render();											// envia sprites para desenho	
};

// ---------------------------------------------------------------------------------

#endif