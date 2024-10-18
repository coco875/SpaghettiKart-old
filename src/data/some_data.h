#ifndef SOME_DATA_HH
#define SOME_DATA_HH
// SOME_DATA_HH named this way prevent conflict with <assets/some_data.h>

#include <libultra/gbi.h>
#include "spline.h"
#include <assets/other_textures.h>
#include "objects.h"
#include <mk64.h>

extern Vtx D_800E49C0[];
extern Vtx D_800E4AC0[];
extern Vtx D_800E4BC0[];
extern Vtx D_800E4CC0[];
extern Vtx D_800E4DC0[];
extern Vtx D_800E4EC0[];
extern Vtx D_800E4FD0[];
extern Vtx D_800E50D0[];
extern Vtx D_800E51D0[];
extern Vtx D_800E5210[];
extern Vtx gBalloonVertexPlane1[];
extern Vtx gBalloonVertexPlane2[];
extern u8* gCourseOutlineTextures[];
extern s16 D_800E5520[NUM_COURSES];
extern s16 D_800E5548[];
extern u16 D_800E55A0[];
extern u16 D_800E55B0[];
extern u8 D_800E55D0[][3];
extern s32 D_800E55F8[];
extern s32 D_800E5618[];
extern s8 D_800E5628[];
extern f32 D_800E594C[][2];
extern u64 D_800E5974;
extern s16 D_800E597C[];
extern SplineData D_800E5988;
extern SplineData D_800E5A44;
extern SplineData D_800E5B08;
extern SplineData D_800E5BD4;
extern SplineData D_800E5C90;
extern SplineData D_800E5D54;
extern SplineData D_800E5D78;
extern SplineData* D_800E5D9C[];
extern SplineData* D_800E5DB0;
extern s8 D_800E5DB4[];
extern s16 D_800E5FD0[];
extern SplineData D_800E6034;
extern SplineData D_800E60F0;
extern SplineData D_800E61B4;
extern SplineData D_800E6280;
extern SplineData* D_800E633C[];
extern Vec3s D_800E634C[];
extern SplineData D_800E641C;
extern SplineData D_800E64D8;
extern SplineData D_800E659C;
extern SplineData D_800E6668;
extern SplineData* D_800E6724[];
extern SplineData* D_800E672C[];
// This should really be `extern Vec3s gTorchSpawns[];`
extern SplineData D_800E67B8;
extern SplineData D_800E6834;
extern SplineData D_800E68E0;
extern SplineData D_800E694C;
extern SplineData D_800E69B0;
extern SplineData D_800E69F4;
extern CloudData gLuigiRacewayIdClouds[];
extern CloudData gYoshiValleyIdMooMooFarmClouds[];
extern CloudData gKoopaTroopaBeachIdClouds[];
extern CloudData gRoyalRacewayIdClouds[];
extern CloudData gSherbetLandIdClouds[];
extern CloudData gKalimariDesertIdClouds[];
extern StarData gToadsTurnpikeIdRainbowRoadStars[];
extern StarData gWarioStadiumIdStars[];
extern u8 D_800E6F30[][3];
extern u8 D_800E6F48[][3];

#endif
