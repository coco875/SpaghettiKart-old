#pragma once

#include <libultraship.h>
#include "Course.h"

extern "C" {
#include "assets/royal_raceway_vertices.h"
#include "assets/royal_raceway_displaylists.h"
#include "assets/royal_raceway_data.h"
#include "course_offsets.h"
#include "camera.h"
#include "data/some_data.h"
#include "objects.h"
#include "path_spawn_metadata.h"
extern const course_texture royal_raceway_textures[];
}

class PodiumCeremony : public Course {
  public:
    virtual ~PodiumCeremony() = default; // Virtual destructor for proper cleanup in derived classes

    // Constructor
    explicit PodiumCeremony();

    //    virtual void Load(const char* courseVtx,
    //                  course_texture* textures, const char* displaylists, size_t dlSize);
    virtual void LoadTextures() override;
    virtual void SpawnActors() override;
    // virtual void InitClouds() override;
    virtual void MinimapSettings() override;
    virtual void InitCourseObjects() override;
    virtual void SomeSounds() override;
    virtual void WhatDoesThisDo(Player* player, int8_t playerId) override;
    virtual void WhatDoesThisDoAI(Player* player, int8_t playerId) override;
    virtual void MinimapFinishlinePosition() override;
    virtual void SetStaffGhost() override;
    virtual void BeginPlay() override;
    virtual void Render(struct UnkStruct_800DC5EC*) override;
    virtual void RenderCredits() override;
    virtual void Collision() override;
    virtual void SpawnBombKarts() override;
    virtual void GenerateCollision() override;
    virtual void Destroy() override;
};
