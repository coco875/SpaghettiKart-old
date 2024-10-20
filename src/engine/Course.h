#ifndef COURSE_H
#define COURSE_H

#include <libultraship.h>

// C-compatible function declaration
#ifdef __cplusplus
// #include "World.h"
extern "C" {
#endif

#include "camera.h"
#include "course_offsets.h"
#include "data/some_data.h"
#include "defines.h"
#include "bomb_kart.h"
#include "path_spawn_metadata.h"
#include "Engine.h"

CProperties* CourseManager_GetProps();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

class World; // <-- Forward declare

class Course {

  public:
    CProperties Props;

    const char* vtx = nullptr;
    const char* gfx = nullptr;
    size_t gfxSize = 0;
    const course_texture* textures = nullptr;

    virtual ~Course() = default; // Virtual destructor for proper cleanup in derived classes

    // Constructor
    explicit Course(); // UUID should be passed in constructor

    // Virtual functions to be overridden by derived classes
    virtual void Load();
    // This function may not be needed due to otr system.
    virtual void LoadTextures();
    virtual void SpawnActors();
    virtual void InitClouds();
    virtual void UpdateClouds(s32, Camera*);
    virtual void SomeCollisionThing(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5, f32* arg6,
                                    f32* arg7);
    virtual void MinimapSettings();
    virtual void MinimapFinishlinePosition();
    virtual void InitCourseObjects();
    virtual void UpdateCourseObjects();
    virtual void RenderCourseObjects(s32 cameraId);
    virtual void SomeSounds();
    virtual void SetCourseVtxColours();
    virtual void WhatDoesThisDo(Player*, int8_t);
    virtual void WhatDoesThisDoAI(Player*, int8_t);
    virtual void SetStaffGhost();
    virtual void SpawnBombKarts();
    virtual void BeginPlay();
    virtual void Render(struct UnkStruct_800DC5EC*);
    virtual void RenderCredits();
    virtual void SpawnVehicles();
    virtual void UpdateVehicles();
    virtual void Waypoints(Player* player, int8_t playerId);
    virtual void Collision();
    virtual void GenerateCollision();
    virtual void Water();
    virtual void Destroy();
};

#endif

#endif // COURSE_H
