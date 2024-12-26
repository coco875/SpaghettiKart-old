#include <libultraship.h>
#include <libultra/gbi.h>
#include <vector>
#include <memory>

#include "LuigiRaceway.h"
#include "GameObject.h"
#include "World.h"
#include "engine/vehicles/OBombKart.h"
#include "assets/luigi_raceway_data.h"
#include "engine/actors/AFinishline.h"

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
#include "code_8003DC40.h"
#include "memory.h"
#include "courses/staff_ghost_data.h"
#include "framebuffer_effects.h"
#include "skybox_and_splitscreen.h"
extern const char* luigi_raceway_dls[];
extern s16 currentScreenSection;
}

LuigiRaceway::LuigiRaceway() {
    this->vtx = d_course_luigi_raceway_vertex;
    this->gfx = d_course_luigi_raceway_packed_dls;
    this->gfxSize = 6377;
    this->textures = luigi_raceway_textures;
    Props.MinimapTexture = gTextureCourseOutlineLuigiRaceway;
    Props.D_800E5548[0] = 64;
    Props.D_800E5548[1] = 96;

    Props.Id = "mk:luigi_raceway";
    Props.Name = "luigi raceway";
    Props.DebugName = "l circuit";
    Props.CourseLength = "717m";
    Props.AIBehaviour = D_0D0091E8;
    Props.AIMaximumSeparation = 50.0f;
    Props.AIMinimumSeparation = 0.7f;
    Props.SomePtr = D_800DCAF4;
    Props.AISteeringSensitivity = 48;

    Props.NearPersp = 9.0f;
    Props.FarPersp = 4500.0f;

    Props.PathSizes = { 0x2DA, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

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

    Props.PathTable[0] = (TrackWaypoint*) LOAD_ASSET_RAW(d_course_luigi_raceway_unknown_waypoints);
    Props.PathTable[1] = NULL;
    Props.PathTable[2] = NULL;
    Props.PathTable[3] = NULL;

    Props.PathTable2[0] = (TrackWaypoint*) LOAD_ASSET_RAW(d_course_luigi_raceway_track_waypoints);
    Props.PathTable2[1] = NULL;
    Props.PathTable2[2] = NULL;
    Props.PathTable2[3] = NULL;

    Props.Clouds = gLuigiRacewayClouds;
    Props.CloudList = gLuigiRacewayClouds;
    Props.MinimapFinishlineX = 0;
    Props.MinimapFinishlineY = 0;

    Props.Skybox.TopRight = { 128, 184, 248 };
    Props.Skybox.BottomRight = { 216, 232, 248 };
    Props.Skybox.BottomLeft = { 216, 232, 248 };
    Props.Skybox.TopLeft = { 128, 184, 248 };
    Props.Skybox.FloorTopRight = { 216, 232, 248 };
    Props.Skybox.FloorBottomRight = { 0, 0, 0 };
    Props.Skybox.FloorBottomLeft = { 0, 0, 0 };
    Props.Skybox.FloorTopLeft = { 216, 232, 248 };
    Props.Sequence = MusicSeq::MUSIC_SEQ_RACEWAYS_WARIO_STADIUM;
}

void LuigiRaceway::Load() {
    Course::Load();

    parse_course_displaylists((TrackSectionsI*) LOAD_ASSET_RAW(d_course_luigi_raceway_addr));
    func_80295C6C();
    D_8015F8E4 = gCourseMinY - 10.0f;
}

void LuigiRaceway::LoadTextures() {
    dma_textures(gTextureTrees5Left, 0x000003E8U, 0x00000800U);
    dma_textures(gTextureTrees5Right, 0x000003E8U, 0x00000800U);
}

void LuigiRaceway::SpawnActors() {
    gWorldInstance.AddActor(new AFinishline());
    spawn_foliage((struct ActorSpawnData*) LOAD_ASSET_RAW(d_course_luigi_raceway_tree_spawn));
    spawn_all_item_boxes((struct ActorSpawnData*) LOAD_ASSET_RAW(d_course_luigi_raceway_item_box_spawns));
}

void LuigiRaceway::SpawnVehicles() {
    if (gModeSelection == VERSUS) {
        Vec3f pos = { 0, 0, 0 };

        gWorldInstance.AddBombKart(pos, &D_80164550[0][50], 50, 1, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][200], 200, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][305], 305, 1, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][440], 440, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][515], 515, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][0], 0, 0, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][0], 0, 0, 0.8333333f);
    }
}

// Likely sets minimap boundaries
void LuigiRaceway::MinimapSettings() {
    D_8018D220 = reinterpret_cast<uint8_t(*)[1024]>(dma_textures(gTextureExhaust2, 0x4F4U, 0xC00));
    D_8018D2A0 = 0.0155f;
    D_8018D2C0[0] = 271;
    D_8018D2E0 = 45;
    D_8018D2E8 = 60;
    D_80165718 = -140;
    D_80165720 = -44;
    D_80165728 = -215;
}

void LuigiRaceway::InitCourseObjects() {
    size_t i;
    if (gGamestate != CREDITS_SEQUENCE) {
        if (gModeSelection == GRAND_PRIX) {
            func_80070714();
        }
        D_80165898 = 0;
        init_object(indexObjectList1[0], 0);
        for (i = 0; i < D_80165738; i++) {
            find_unused_obj_index(&gObjectParticle3[i]);
            init_object(gObjectParticle3[i], 0);
        }
    }
}

void LuigiRaceway::UpdateCourseObjects() {
    if (D_80165898 != 0) {
        update_hot_air_balloon();
    }
}

void LuigiRaceway::RenderCourseObjects(s32 cameraId) {
    if (D_80165898 != 0) {
        render_object_hot_air_balloon(cameraId);
    }
}

void LuigiRaceway::SomeSounds() {
    vec3f_set(D_8015F748, 85.0f, 21.0f, -219.0f);
    func_800C9D80(D_8015F748, D_802B91C8, 0x5103700B);
}

void LuigiRaceway::WhatDoesThisDo(Player* player, int8_t playerId) {
    if (((s16) gNearestWaypointByPlayerId[playerId] >= 0x145) && ((s16) gNearestWaypointByPlayerId[playerId] < 0x18B)) {
        if (D_80165300[playerId] != 1) {
            func_800CA288(playerId, 0x55);
        }
        D_80165300[playerId] = 1;
    } else {
        if (D_80165300[playerId] != 0) {
            func_800CA2B8(playerId);
            D_80165300[playerId] = 0;
        }
    }
}

void LuigiRaceway::WhatDoesThisDoAI(Player* player, int8_t playerId) {
    if (((s16) gNearestWaypointByPlayerId[playerId] >= 0x145) && ((s16) gNearestWaypointByPlayerId[playerId] < 0x18B)) {
        if (D_80165300[playerId] != 1) {
            func_800CA2E4(playerId, 0x55);
        }
        D_80165300[playerId] = 1;
    } else {
        if (D_80165300[playerId] != 0) {
            func_800CA30C(playerId);
            D_80165300[playerId] = 0;
        }
    }
}

// Positions the finishline on the minimap
void LuigiRaceway::MinimapFinishlinePosition() {
    //! todo: Place hard-coded values here.
    draw_hud_2d_texture_8x8(this->Props.MinimapFinishlineX, this->Props.MinimapFinishlineY,
                            (u8*) common_texture_minimap_finish_line);
}

void LuigiRaceway::SetStaffGhost() {
    u32 temp_v0 = func_800B4E24(0) & 0xfffff;
    if (temp_v0 <= 11200) {
        D_80162DD6 = 0;
        D_80162DF4 = 0;
    } else {
        D_80162DD6 = 1;
        D_80162DF4 = 1;
    }
    D_80162DC4 = d_luigi_raceway_staff_ghost;
    D_80162DE4 = 1;
}

void LuigiRaceway::Render(struct UnkStruct_800DC5EC* arg0) {
    UNUSED s32 pad;
    u16 sp22 = (u16) arg0->pathCounter;
    s16 prevFrame;

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);

    // Invalidate Jumbotron textures so they update each frame
    // This could be more efficient if we exposed the non-opcode based invalidation to be called
    // inside copy_framebuffers_port
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0xF800);
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0x10800);
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0x11800);
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0x12800);
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0x13800);
    gSPInvalidateTexCache(gDisplayListHead++, gSegmentTable[5] + 0x14800);

    if (func_80290C20(arg0->camera) == 1) {
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        // d_course_luigi_raceway_packed_dl_9EC0
        gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual(reinterpret_cast<void*>(0x07009EC0))));
    }

    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);

    render_course_segments(luigi_raceway_dls, arg0);

    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    // d_course_luigi_raceway_packed_dl_E0
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual(reinterpret_cast<void*>(0x070000E0))));
    // d_course_luigi_raceway_packed_dl_68
    gSPDisplayList(gDisplayListHead++, (segmented_gfx_to_virtual(reinterpret_cast<void*>(0x07000068))));

    D_800DC5DC = 88;
    D_800DC5E0 = 72;

    // Render only the first player camera onto the television billboard. Screen agnostic screens of other players).
    if ((gActiveScreenMode == SCREEN_MODE_1P) && (sp22 >= 10) && (sp22 < 17)) {

        prevFrame = (s16) sRenderedFramebuffer - 1;

        if (prevFrame < 0) {
            prevFrame = 2;
        } else if (prevFrame >= 3) {
            prevFrame = 0;
        }
        currentScreenSection++;
        if (currentScreenSection >= 6) {
            currentScreenSection = 0;
        }

        /**
         * The jumbo television screen used to be split into six sections to fit into the n64's texture size
         * restrictions It isn't split into six sections anymore
         */
        copy_jumbotron_fb_port(D_800DC5DC, D_800DC5E0, currentScreenSection, (u16*) gPortFramebuffers[prevFrame],
                               (u16*) (gSegmentTable[5] + 0xF800));
    }
}

void LuigiRaceway::RenderCredits() {
    gSPDisplayList(gDisplayListHead++, (Gfx*) (d_course_luigi_raceway_dl_FD40));
}

void LuigiRaceway::Collision() {
}

void LuigiRaceway::SomeCollisionThing(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5,
                                      f32* arg6, f32* arg7) {
    func_8003E9EC(player, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void LuigiRaceway::Destroy() {
}
