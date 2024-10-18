#ifndef _GAME_H
#define _GAME_H

#include <libultraship.h>
#include "engine/Engine.h"

#ifdef __cplusplus
#include "engine/World.h"
extern World gWorldInstance;
extern "C" {
#include "camera.h"
#endif

u32 WorldNextCup(void);

u32 WorldPreviousCup(void);

void SetCourseFromId(int courseId);
void SetCupIndex(int cupId);
u32 GetCupIndex(void);

const char* GetCupName(void);

void LoadCourse();

CProperties* GetCoursePropsA();

size_t GetCourseIndex();

void SetCourse(const char* name);

void NextCourse();
void PreviousCourse();

void CourseManager_SpawnVehicles();

void CourseManager_UpdateVehicles();

void CourseManager_LoadTextures();

void CourseManager_RenderCourse(struct UnkStruct_800DC5EC* arg0);

void CourseManager_RenderCredits();

void CourseManager_SpawnActors();

void CourseManager_InitClouds();

void CourseManager_UpdateClouds(s32 arg0, Camera* camera);

void CourseManager_Waypoints(Player* player, int8_t playerId);

void CourseManager_GenerateCollision();

void CourseManager_SomeCollisionThing(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5,
                                      f32* arg6, f32* arg7);

void CourseManager_MinimapSettings();

void CourseManager_InitCourseObjects();

void CourseManager_UpdateCourseObjects();

void CourseManager_RenderCourseObjects(s32 cameraId);

void CourseManager_SomeSounds();

void CourseManager_SetCourseVtxColours();

void CourseManager_WhatDoesThisDo(Player* player, int8_t playerId);

void CourseManager_WhatDoesThisDoAI(Player* player, int8_t playerId);

void CourseManager_MinimapFinishlinePosition();

void CourseManager_SetStaffGhost();

CProperties* CourseManager_GetProps();

void CourseManager_SpawnBombKarts();

void CourseManager_Water();

size_t GetCupCursorPosition();

void SetCupCursorPosition(size_t position);

size_t GetCupSize();

void SetCourseFromCup();

void* GetCourse(void);

void SetCourseByClass(void* course);

extern int gMarioRacewayId;
extern int gChocoMountainId;
extern int gBowsersCastleId;
extern int gBansheeBoardwalkId;
extern int gYoshiValleyId;
extern int gFrappeSnowlandId;
extern int gKoopaTroopaBeachId;
extern int gRoyalRacewayId;
extern int gLuigiRacewayId;
extern int gMooMooFarmId;
extern int gToadsTurnpikeId;
extern int gKalimariDesertId;
extern int gSherbetLandId;
extern int gRainbowRoadId;
extern int gWarioStadiumId;
extern int gBlockFortId;
extern int gSkyscraperId;
extern int gDoubleDeckId;
extern int gDkJungleId;
extern int gBigDonutId;
extern int gPodiumCeremonyId;
extern int gTestCourseId;

extern int gMushroomCupId;
extern int gFlowerCupId;
extern int gStarCupId;
extern int gSpecialCupId;
extern int gBattleCupId;

void CourseManager_SpawnVehicles();
void CourseManager_VehiclesSpawn();
void CourseManager_VehiclesTick();
void CourseManager_VehiclesCollision(s32 playerId, Player* player);
void CourseManager_RenderTrucks(s32 playerId);
void CourseManager_ResetVehicles(void);
void CourseManager_CrossingTrigger();
void CourseManager_AICrossingBehaviour(s32 playerId);
void CourseManager_DrawActors(Camera* camera);
void CourseManager_InitClouds();
s32 CourseManager_GetCrossingOnTriggered(uintptr_t* crossing);
void CourseManager_TrainSmokeTick(void);
void CourseManager_TrainSmokeDraw(s32 cameraId);
void CourseManager_TickActors();

#ifdef __cplusplus
}
#endif

#endif // _GAME_H