#include <libultraship.h>
#include <libultra/gbi.h>
#include <vector>
#include <memory>

#include "Skyscraper.h"
#include "GameObject.h"
#include "World.h"
#include "engine/vehicles/OBombKart.h"
#include "assets/skyscraper_data.h"

extern "C" {
#include "main.h"
#include "camera.h"
#include "course_offsets.h"
#include "code_800029B0.h"
#include "render_courses.h"
#include "code_8006E9C0.h"
#include "code_80057C60.h"
#include "defines.h"
#include "math_util.h"
#include "external.h"
#include "code_80005FD0.h"
#include "spawn_players.h"
#include "render_objects.h"
#include "assets/common_data.h"
#include "save.h"
#include "staff_ghosts.h"
#include "actors.h"
#include "collision.h"
#include "memory.h"
extern const char* skyscraper_dls[];
extern s16 currentScreenSection;
}

Skyscraper::Skyscraper() {
    this->vtx = d_course_skyscraper_vertex;
    this->gfx = d_course_skyscraper_packed_dls;
    this->gfxSize = 548;
    this->textures = skyscraper_textures;
    Props.MinimapTexture = gTextureCourseOutlineSkyscraper;
    Props.D_800E5548[0] = 64;
    Props.D_800E5548[1] = 64;

    Props.Name = "skyscraper";
    Props.DebugName = "skyscraper";
    Props.CourseLength = "";
    Props.AIBehaviour = D_0D008F18;
    Props.AIMaximumSeparation = -1.0f;
    Props.AIMinimumSeparation = 0.5f;
    Props.SomePtr = D_800DCAF4;
    Props.AISteeringSensitivity = 53;

    Props.NearPersp = 2.0f;
    Props.FarPersp = 2700.0f;

    Props.PathSizes = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

    Props.D_0D009418[0] = 4.1666665f;
    Props.D_0D009418[1] = 5.5833334f;
    Props.D_0D009418[2] = 6.1666665f;
    Props.D_0D009418[3] = 6.75f;

    Props.D_0D009568[0] = 3.75f;
    Props.D_0D009568[1] = 5.1666665f;
    Props.D_0D009568[2] = 5.75f;
    Props.D_0D009568[3] = 6.3333334f;

    Props.D_0D0096B8[0] = 3.3333332f;
    Props.D_0D0096B8[1] = 3.9166667f;
    Props.D_0D0096B8[2] = 4.5f;
    Props.D_0D0096B8[3] = 5.0833334f;

    Props.D_0D009808[0] = 3.75f;
    Props.D_0D009808[1] = 5.1666665f;
    Props.D_0D009808[2] = 5.75f;
    Props.D_0D009808[3] = 6.3333334f;

    Props.PathTable[0] = NULL;
    Props.PathTable[1] = NULL;
    Props.PathTable[2] = NULL;
    Props.PathTable[3] = NULL;

    Props.PathTable2[0] = NULL;
    Props.PathTable2[1] = NULL;
    Props.PathTable2[2] = NULL;
    Props.PathTable2[3] = NULL;

    Props.Clouds = NULL; // no clouds
    Props.CloudList = NULL;
    Props.MinimapFinishlineX = 0;
    Props.MinimapFinishlineY = 0;

    Props.Skybox.TopRight = { 0, 0, 0 };
    Props.Skybox.BottomRight = { 0, 0, 0 };
    Props.Skybox.BottomLeft = { 0, 0, 0 };
    Props.Skybox.TopLeft = { 0, 0, 0 };
    Props.Skybox.FloorTopRight = { 0, 0, 0 };
    Props.Skybox.FloorBottomRight = { 0, 0, 0 };
    Props.Skybox.FloorBottomLeft = { 0, 0, 0 };
    Props.Skybox.FloorTopLeft = { 0, 0, 0 };
    Props.Sequence = MusicSeq::MUSIC_SEQ_BATTLE_ARENAS;
}

void Skyscraper::Load() {
    Course::Load();

    // d_course_skyscraper_packed_dl_1110
    generate_collision_mesh_with_default_section_id((Gfx*) segmented_gfx_to_virtual((void*) 0x07001110), 1);
    // d_course_skyscraper_packed_dl_258
    generate_collision_mesh_with_default_section_id((Gfx*) segmented_gfx_to_virtual((void*) 0x07000258), 1);
    func_80295C6C();

    D_8015F8E4 = -480.0f;
}

void Skyscraper::LoadTextures() {
}

void Skyscraper::SpawnActors() {
    spawn_all_item_boxes((ActorSpawnData*) LOAD_ASSET_RAW(d_course_skyscraper_item_box_spawns));
}

void Skyscraper::SpawnVehicles() {
    if (gModeSelection == VERSUS) {
        Vec3f pos = { 0, 0, 0 };

        gWorldInstance.AddBombKart(pos, &D_80164550[0][20], 20, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][40], 40, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][60], 60, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][80], 80, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][100], 100, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][120], 120, 0, 1.0f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][140], 140, 0, 1.0f);
    }
}

// Likely sets minimap boundaries
void Skyscraper::MinimapSettings() {
    D_8018D2A0 = 0.0445f;
    D_8018D2E0 = 32;
    D_8018D2E8 = 32;
}

void Skyscraper::InitCourseObjects() {
}

void Skyscraper::SomeSounds() {
}

void Skyscraper::WhatDoesThisDo(Player* player, int8_t playerId) {
}

void Skyscraper::WhatDoesThisDoAI(Player* player, int8_t playerId) {
}

// Positions the finishline on the minimap
void Skyscraper::MinimapFinishlinePosition() {
    //! todo: Place hard-coded values here.
    draw_hud_2d_texture_8x8(this->Props.MinimapFinishlineX, this->Props.MinimapFinishlineY,
                            (u8*) common_texture_minimap_finish_line);
}

void Skyscraper::Render(struct UnkStruct_800DC5EC* arg0) {
    func_802B5D64(D_800DC610, D_802B87D4, 0, 1);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
    // d_course_skyscraper_packed_dl_FE8
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x07000FE8)));
    // d_course_skyscraper_packed_dl_C60
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x07000C60)));
    // d_course_skyscraper_packed_dl_B70
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x07000B70)));
    // d_course_skyscraper_packed_dl_6B8
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x070006B8)));
    // d_course_skyscraper_packed_dl_570
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x07000570)));
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);
    // d_course_skyscraper_packed_dl_10C8
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x070010C8)));
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
    // d_course_skyscraper_packed_dl_258
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual((void*) 0x07000258)));
}

void Skyscraper::RenderCredits() {
}

void Skyscraper::Collision() {
}

void Skyscraper::Waypoints(Player* player, int8_t playerId) {
    player->nearestWaypointId = 0;
}

void Skyscraper::Destroy() {
}
