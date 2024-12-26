#include <libultraship.h>
#include <libultra/gbi.h>
#include <vector>
#include <memory>

#include "MooMooFarm.h"
#include "GameObject.h"
#include "World.h"
#include "engine/actors/AFinishline.h"
#include "engine/vehicles/OBombKart.h"
#include "assets/moo_moo_farm_data.h"

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
#include "code_80086E70.h"
extern const char* moo_moo_farm_dls[];
extern s16 currentScreenSection;
extern s8 gPlayerCount;
}

MooMooFarm::MooMooFarm() {
    this->vtx = d_course_moo_moo_farm_vertex;
    this->gfx = d_course_moo_moo_farm_packed_dls;
    this->gfxSize = 3304;
    this->textures = moo_moo_farm_textures;
    Props.MinimapTexture = gTextureCourseOutlineMooMooFarm;
    Props.D_800E5548[0] = 64;
    Props.D_800E5548[1] = 64;

    Props.Name = "moo moo farm";
    Props.DebugName = "farm";
    Props.CourseLength = "527m";
    Props.AIBehaviour = D_0D009210;
    Props.AIMaximumSeparation = 50.0f;
    Props.AIMinimumSeparation = 0.5f;
    Props.SomePtr = D_800DCAF4;
    Props.AISteeringSensitivity = 48;

    Props.NearPersp = 9.0f;
    Props.FarPersp = 4500.0f;

    Props.PathSizes = { 0x230, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };

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

    Props.PathTable[0] = (TrackWaypoint*) LOAD_ASSET_RAW(d_course_moo_moo_farm_unknown_waypoints);
    Props.PathTable[1] = NULL;
    Props.PathTable[2] = NULL;
    Props.PathTable[3] = NULL;

    Props.PathTable2[0] = (TrackWaypoint*) LOAD_ASSET_RAW(d_course_moo_moo_farm_track_waypoints);
    Props.PathTable2[1] = NULL;
    Props.PathTable2[2] = NULL;
    Props.PathTable2[3] = NULL;

    Props.Clouds = gYoshiValleyMooMooFarmClouds;
    Props.CloudList = gYoshiValleyMooMooFarmClouds;
    Props.MinimapFinishlineX = 0;
    Props.MinimapFinishlineY = 0;

    Props.Skybox.TopRight = { 0, 18, 255 };
    Props.Skybox.BottomRight = { 197, 211, 255 };
    Props.Skybox.BottomLeft = { 197, 211, 255 };
    Props.Skybox.TopLeft = { 0, 18, 255 };
    Props.Skybox.FloorTopRight = { 255, 184, 99 };
    Props.Skybox.FloorBottomRight = { 0, 0, 0 };
    Props.Skybox.FloorBottomLeft = { 0, 0, 0 };
    Props.Skybox.FloorTopLeft = { 255, 184, 99 };
    Props.Sequence = MusicSeq::MUSIC_SEQ_MOO_MOO_FARM_YOSHI_VALLEY;
}

void MooMooFarm::Load() {
    Course::Load();

    parse_course_displaylists((TrackSectionsI*) LOAD_ASSET_RAW(d_course_moo_moo_farm_addr));
    func_80295C6C();
    D_8015F8E4 = gCourseMinY - 10.0f;
}

void MooMooFarm::LoadTextures() {
    dma_textures(gTextureTrees4Left, 0x000003E8U, 0x00000800U);
    dma_textures(gTextureTrees4Right, 0x000003E8U, 0x00000800U);
    dma_textures(gTextureCow01Left, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow01Right, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow02Left, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow02Right, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow03Left, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow03Right, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow04Left, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow04Right, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow05Left, 0x00000400U, 0x00000800U);
    dma_textures(gTextureCow05Right, 0x00000400U, 0x00000800U);
}

void MooMooFarm::SpawnActors() {
    gWorldInstance.AddActor(new AFinishline());

    if (gPlayerCountSelection1 != 4) {
        spawn_foliage((struct ActorSpawnData*) LOAD_ASSET_RAW(d_course_moo_moo_farm_tree_spawn));
    }
    spawn_all_item_boxes((struct ActorSpawnData*) LOAD_ASSET_RAW(d_course_moo_moo_farm_item_box_spawns));
}

void MooMooFarm::SpawnVehicles() {
    if (gModeSelection == VERSUS) {
        Vec3f pos = { 0, 0, 0 };

        gWorldInstance.AddBombKart(pos, &D_80164550[0][50], 50, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][140], 140, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][225], 225, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][316], 316, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][434], 434, 3, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][0], 0, 0, 0.8333333f);
        gWorldInstance.AddBombKart(pos, &D_80164550[0][0], 0, 0, 0.8333333f);
    }
}

// Likely sets minimap boundaries
void MooMooFarm::MinimapSettings() {
    D_8018D220 = reinterpret_cast<uint8_t(*)[1024]>(dma_textures(gTextureExhaust0, 0x479, 0xC00));
    D_8018D2A0 = 0.0155f;
    D_8018D2C0[0] = 271;
    D_8018D2E0 = 18;
    D_8018D2E8 = 36;
}

void MooMooFarm::InitCourseObjects() {
    size_t objectId;
    size_t i;
    if (gGamestate != CREDITS_SEQUENCE) {
        if ((gPlayerCount == 1) || ((gPlayerCount == 2) && (gModeSelection == VERSUS))) {
            switch (gCCSelection) { /* switch 2; irregular */
                case CC_50:         /* switch 2 */
                    D_8018D1C8 = 4;
                    D_8018D1D0 = 6;
                    D_8018D1D8 = 6;
                    break;
                case CC_100: /* switch 2 */
                    D_8018D1C8 = 5;
                    D_8018D1D0 = 8;
                    D_8018D1D8 = 8;
                    break;
                case CC_150: /* switch 2 */
                    D_8018D1C8 = 5;
                    D_8018D1D0 = 8;
                    D_8018D1D8 = 10;
                    break;
                case CC_EXTRA: /* switch 2 */
                    D_8018D1C8 = 5;
                    D_8018D1D0 = 8;
                    D_8018D1D8 = 8;
                    break;
            }
        } else {
            D_8018D1C8 = 4;
            D_8018D1D0 = 6;
            D_8018D1D8 = 6;
        }
        for (i = 0; i < NUM_GROUP1_MOLES; i++) {
            D_8018D198[i] = 0;
            find_unused_obj_index(&indexObjectList1[i]);
        }
        for (i = 0; i < NUM_GROUP2_MOLES; i++) {
            D_8018D1A8[i] = 0;
            find_unused_obj_index(&indexObjectList1[i]);
        }
        for (i = 0; i < NUM_GROUP3_MOLES; i++) {
            D_8018D1B8[i] = 0;
            find_unused_obj_index(&indexObjectList1[i]);
        }
        for (i = 0; i < NUM_TOTAL_MOLES; i++) {
            find_unused_obj_index(&gObjectParticle1[i]);
            objectId = gObjectParticle1[i];
            init_object(objectId, 0);
            gObjectList[objectId].pos[0] = gMoleSpawns.asVec3sList[i][0] * xOrientation;
            gObjectList[objectId].pos[2] = gMoleSpawns.asVec3sList[i][2];
            func_800887C0(objectId);
            gObjectList[objectId].sizeScaling = 0.7f;
        }
        for (i = 0; i < gObjectParticle2_SIZE; i++) {
            find_unused_obj_index(&gObjectParticle2[i]);
        }
    }
}

void MooMooFarm::UpdateCourseObjects() {
    if (gGamestate != CREDITS_SEQUENCE) {
        update_moles();
    }
}

void MooMooFarm::RenderCourseObjects(s32 cameraId) {
    if (gGamestate != CREDITS_SEQUENCE) {
        render_object_moles(cameraId);
    }
}

void MooMooFarm::SomeSounds() {
}

void MooMooFarm::WhatDoesThisDo(Player* player, int8_t playerId) {
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

void MooMooFarm::WhatDoesThisDoAI(Player* player, int8_t playerId) {
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
void MooMooFarm::MinimapFinishlinePosition() {
    //! todo: Place hard-coded values here.
    draw_hud_2d_texture_8x8(this->Props.MinimapFinishlineX, this->Props.MinimapFinishlineY,
                            (u8*) common_texture_minimap_finish_line);
}

void MooMooFarm::Render(struct UnkStruct_800DC5EC* arg0) {
    s16 temp_s0 = arg0->pathCounter;
    s16 temp_s1 = arg0->playerDirection;

    func_802B5D64(D_800DC610, D_802B87D4, 0, 1);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI, G_CC_MODULATEI);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    // d_course_moo_moo_farm_packed_dl_4DF8
    gSPDisplayList(gDisplayListHead++, segmented_gfx_to_virtual((void*) 0x07004DF8));
    // d_course_moo_moo_farm_packed_dl_5640
    gSPDisplayList(gDisplayListHead++, segmented_gfx_to_virtual((void*) 0x07005640));
    gSPFogPosition(gDisplayListHead++, D_802B87B0, D_802B87B4);

    render_course_segments(moo_moo_farm_dls, arg0);

    if ((temp_s0 < 14) && (temp_s0 > 10)) {
        if ((temp_s1 == 2) || (temp_s1 == 3) || (temp_s1 == 1)) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_13FF8);
        }

    } else if (temp_s0 < 16) {
        gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_13FF8);
    } else if (temp_s0 < 19) {
        if (temp_s1 != 2) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_13FF8);
        }

    } else if (temp_s0 < 20) {
        if (temp_s1 == 0) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_13FF8);
        }
    }
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI, G_CC_MODULATEI);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);

    if ((temp_s0 >= 16) && (temp_s0 < 24)) {
        if ((temp_s1 == 2) || (temp_s1 == 3)) {
            // d_course_moo_moo_farm_packed_dl_5410
            gSPDisplayList(gDisplayListHead++, segmented_gfx_to_virtual((void*) 0x07005410));
        }

    } else if (temp_s0 < 9) {
        if (temp_s1 == 2) {
            // d_course_moo_moo_farm_packed_dl_5410
            gSPDisplayList(gDisplayListHead++, segmented_gfx_to_virtual((void*) 0x07005410));
        }
    }
    if (temp_s0 < 4) {
        if (temp_s1 != 0) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_14060);
        }

    } else if (temp_s0 < 8) {
        if (temp_s1 == 2) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_14060);
        }

    } else if (temp_s0 >= 22) {
        gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_14060);
    } else if (temp_s0 >= 18) {
        if ((temp_s1 == 0) || (temp_s1 == 3)) {
            gSPDisplayList(gDisplayListHead++, (Gfx*) d_course_moo_moo_farm_dl_14060);
        }
    }
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    // d_course_moo_moo_farm_packed_dl_10C0
    gSPDisplayList(gDisplayListHead++, segmented_gfx_to_virtual((void*) 0x070010C0));
}

void MooMooFarm::RenderCredits() {
    gSPDisplayList(gDisplayListHead++, (Gfx*) (d_course_moo_moo_farm_dl_14088));
}

void MooMooFarm::Collision() {
}

void MooMooFarm::CreditsSpawnActors() {
    dma_textures(gTextureTrees4Left, 0x3E8, 0x800);
    dma_textures(gTextureTrees4Right, 0x3E8, 0x800);
    dma_textures(gTextureCow01Left, 0x400, 0x800);
    dma_textures(gTextureCow01Right, 0x400, 0x800);
    dma_textures(gTextureCow02Left, 0x400, 0x800);
    dma_textures(gTextureCow02Right, 0x400, 0x800);
    dma_textures(gTextureCow03Left, 0x400, 0x800);
    dma_textures(gTextureCow03Right, 0x400, 0x800);
    dma_textures(gTextureCow04Left, 0x400, 0x800);
    dma_textures(gTextureCow04Right, 0x400, 0x800);
    dma_textures(gTextureCow05Left, 0x400, 0x800);
    dma_textures(gTextureCow05Right, 0x400, 0x800);
    spawn_foliage((struct ActorSpawnData*) LOAD_ASSET_RAW(d_course_moo_moo_farm_tree_spawn));
}

void MooMooFarm::Destroy() {
}
