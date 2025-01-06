#pragma once

#include <libultraship.h>
#include "../CoreMath.h"
#include "Course.h"

#include "World.h"

extern "C" {
#include "assets/koopa_troopa_beach_vertices.h"
#include "assets/koopa_troopa_beach_displaylists.h"
#include "assets/koopa_troopa_beach_data.h"
#include "course_offsets.h"
#include "camera.h"
#include "data/some_data.h"
#include "objects.h"
#include "path_spawn_metadata.h"
extern const course_texture koopa_troopa_beach_textures[];
}

class KoopaTroopaBeach : public Course {
  public:
    virtual ~KoopaTroopaBeach() = default; // Virtual destructor for proper cleanup in derived classes

    // Constructor
    explicit KoopaTroopaBeach();

    //    virtual void Load(const char* courseVtx,
    //                  course_texture* textures, const char* displaylists, size_t dlSize);
    virtual void Load() override;
    virtual void LoadTextures() override;
    virtual void SpawnActors() override;
    virtual void SpawnVehicles() override;
    virtual void MinimapSettings() override;
    virtual void InitCourseObjects() override;
    virtual void UpdateCourseObjects() override;
    virtual void RenderCourseObjects(s32 cameraId) override;
    virtual void SomeSounds() override;
    virtual void WhatDoesThisDo(Player* player, int8_t playerId) override;
    virtual void WhatDoesThisDoAI(Player* player, int8_t playerId) override;
    virtual void MinimapFinishlinePosition() override;
    virtual void Render(struct UnkStruct_800DC5EC*) override;
    virtual void RenderCredits() override;
    virtual void Collision() override;
    virtual void SomeCollisionThing(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5, f32* arg6,
                                    f32* arg7) override;
    virtual void ScrollingTextures() override;
    virtual void DrawWater(struct UnkStruct_800DC5EC* screen, uint16_t pathCounter, uint16_t cameraRot,
                           uint16_t playerDirection) override;
    virtual void Destroy() override;
};
