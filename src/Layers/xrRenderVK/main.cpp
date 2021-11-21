#pragma once

#include "Layers/xrRender/D3DXRenderBase.h" //TODO: Remove this later

#include "xrEngine/IRenderable.h" //basic rendering stuff?
#include "xrCore/FMesh.hpp" //mesh defenitions

//this shouldn't need to be here, but its one less includes chain
#include "stdint.h"
#ifndef u32
#	define u32 uint32_t
#endif

class CRender : public D3DXRenderBase //TODO: remove this inheritance
{
public:
	enum
	{
		PHASE_NORMAL = 0,
		PHASE_SMAP = 1,
	};

public:
	struct _options
	{
		u32 bug : 1;

		u32 ssao_blur_on : 1;

	};
public:
	// Models
	IRenderVisual* model_Create(LPCSTR name, IReader* data = nullptr) override;
};
