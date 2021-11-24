#pragma once

#include "Layers/xrRender/D3DXRenderBase.h" //TODO: Remove this later

#include "xrEngine/IRenderable.h" //basic rendering stuff? doesn't have 
#include "xrCore/FMesh.hpp" //mesh defenitions

//this shouldn't need to be here, but its one less includes chain
#include "stdint.h"
#ifndef u32
#	define u32 uint32_t
#endif
#ifndef s32
#	define s32 int32_t
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

	} o; //makes accessible through o?

	struct RenderR4Statistics //not a clue what this does!
	{
        u32 l_total;
        u32 l_visible;
        u32 l_shadowed;
        u32 l_unshadowed;
        s32 s_used;
        s32 s_merged;
        s32 s_finalclip;
        u32 ic_total;
        u32 ic_culled;

        RenderR4Statistics() { FrameStart(); }
        void FrameStart()
        {
            l_total = 0;
            l_visible = 0;
            l_shadowed = 0;
            l_unshadowed = 0;
            s_used = 0;
            s_merged = 0;
            s_finalclip = 0;
            ic_total = 0;
            ic_culled = 0;
        }

        void FrameEnd() {}
	};

public:
	RenderR4Statistics Stats;
	// Models
	virtual IRenderVisual* model_Create(LPCSTR name, IReader* data = nullptr) override;
};
