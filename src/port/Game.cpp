#include <libultraship.h>

#include <Fast3D/gfx_pc.h>
#include "Engine.h"
#include "engine/World.h"
#include "engine/courses/MarioRaceway.h"
#include "engine/courses/ChocoMountain.h"
#include "engine/courses/BowsersCastle.h"
#include "engine/courses/BansheeBoardwalk.h"
#include "engine/courses/YoshiValley.h"
#include "engine/courses/FrappeSnowland.h"
#include "engine/courses/KoopaTroopaBeach.h"
#include "engine/courses/RoyalRaceway.h"
#include "engine/courses/LuigiRaceway.h"
#include "engine/courses/MooMooFarm.h"
#include "engine/courses/ToadsTurnpike.h"
#include "engine/courses/KalimariDesert.h"
#include "engine/courses/SherbetLand.h"
#include "engine/courses/RainbowRoad.h"
#include "engine/courses/WarioStadium.h"
#include "engine/courses/BlockFort.h"
#include "engine/courses/Skyscraper.h"
#include "engine/courses/DoubleDeck.h"
#include "engine/courses/DKJungle.h"
#include "engine/courses/BigDonut.h"
#include "engine/courses/TestCourse.h"

#include "engine/courses/PodiumCeremony.h"

#include "engine/Registry.h"

#include "port/Game.h"

extern "C" {
#include "main.h"
#include "audio/load.h"
#include "audio/external.h"
#include "networking/networking.h"
#include "engine/wasm.h"
}

extern "C" void Graphics_PushFrame(Gfx* data) {
    GameEngine::ProcessGfxCommands(data);
}

extern "C" void Timer_Update();

// Create the world instance
World gWorldInstance;

extern "C" {
int gMarioRacewayId;
int gChocoMountainId;
int gBowsersCastleId;
int gBansheeBoardwalkId;
int gYoshiValleyId;
int gFrappeSnowlandId;
int gKoopaTroopaBeachId;
int gRoyalRacewayId;
int gLuigiRacewayId;
int gMooMooFarmId;
int gToadsTurnpikeId;
int gKalimariDesertId;
int gSherbetLandId;
int gRainbowRoadId;
int gWarioStadiumId;
int gBlockFortId;
int gSkyscraperId;
int gDoubleDeckId;
int gDkJungleId;
int gBigDonutId;
int gPodiumCeremonyId;
int gTestCourseId;
}

void CustomEngineInit() {
    /* Add all courses to the global course list */
    gMarioRacewayId = addCourse("mk64:mario_raceway", new MarioRaceway());
    gChocoMountainId = addCourse("mk64:choco_mountain", new ChocoMountain());
    gBowsersCastleId = addCourse("mk64:bowser_calstle", new BowsersCastle());
    gBansheeBoardwalkId = addCourse("mk64:banshee_boardwalk", new BansheeBoardwalk());
    gYoshiValleyId = addCourse("mk64:yoshi_valley", new YoshiValley());
    gFrappeSnowlandId = addCourse("mk64:frappe_snowland", new FrappeSnowland());
    gKoopaTroopaBeachId = addCourse("mk64:koopa_troopa_beach", new KoopaTroopaBeach());
    gRoyalRacewayId = addCourse("mk64:royal_raceway", new RoyalRaceway());
    gLuigiRacewayId = addCourse("mk64:luigi_raceway", new LuigiRaceway());
    gMooMooFarmId = addCourse("mk64:moo_moo_farm", new MooMooFarm());
    gToadsTurnpikeId = addCourse("mk64:toads_turnpike", new ToadsTurnpike());
    gKalimariDesertId = addCourse("mk64:kalimari_desert", new KalimariDesert());
    gSherbetLandId = addCourse("mk64:sherbet_land", new SherbetLand());
    gRainbowRoadId = addCourse("mk64:rainbow_road", new RainbowRoad());
    gWarioStadiumId = addCourse("mk64:wario_stadium", new WarioStadium());
    gBlockFortId = addCourse("mk64:block_fort", new BlockFort());
    gSkyscraperId = addCourse("mk64:skyscraper", new Skyscraper());
    gDoubleDeckId = addCourse("mk64:double_deck", new DoubleDeck());
    gDkJungleId = addCourse("mk64:dk_jungle", new DKJungle());
    gBigDonutId = addCourse("mk64:big_donut", new BigDonut());
    gPodiumCeremonyId = addCourse("mk64:big_donut", new PodiumCeremony());
    gTestCourseId = addCourse("mk64:test_course", new TestCourse());

    /* Instantiate Cups */
    addCup("mk64:mushroom_cup", new Cup("mushroom cup", std::vector<int>{ gLuigiRacewayId, gMooMooFarmId,
                                                                          gKoopaTroopaBeachId, gKalimariDesertId }));
    int flowerid =
        addCup("mk64:flower_cup", new Cup("flower cup", std::vector<int>{ gToadsTurnpikeId, gFrappeSnowlandId,
                                                                          gChocoMountainId, COURSE_MARIO_RACEWAY }));
    addCup("mk64:star_cup",
           new Cup("star cup", std::vector<int>{ gWarioStadiumId, gSherbetLandId, gRoyalRacewayId, gBowsersCastleId }));
    addCup("mk64:special_cup", new Cup("special cup", std::vector<int>{ gDkJungleId, gYoshiValleyId,
                                                                        gBansheeBoardwalkId, gRainbowRoadId }));
    addCup("mk64:battle",
           new Cup("battle", std::vector<int>{ gBigDonutId, gBlockFortId, gDoubleDeckId, gSkyscraperId }));

    /* Set default course; mario raceway */
    SetCourseFromId(COURSE_MARIO_RACEWAY);
    SetCupIndex(flowerid);
    gWorldInstance.CurrentCup->CursorPosition = 3;
}

extern "C" {
u32 WorldNextCup(void) {
    return gWorldInstance.NextCup();
}

u32 WorldPreviousCup(void) {
    return gWorldInstance.PreviousCup();
}

void SetCourseFromId(int courseId) {
    gWorldInstance.SetCourseFromId(courseId);
}

void SetCupIndex(int cupId) {
    gWorldInstance.SetCupIndex(cupId);
}

void SetCup() {
    gWorldInstance.SetCup();
}

u32 GetCupIndex(void) {
    return gWorldInstance.GetCupIndex();
}

const char* GetCupName(void) {
    return gWorldInstance.Cups[gWorldInstance.CupIndex]->Name;
}

void LoadCourse() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->Load();
    }
}

CProperties* GetCoursePropsA() {
    return (CProperties*) gWorldInstance.GetCourseProps();
}

size_t GetCourseIndex() {
    return gWorldInstance.CourseIndex;
}

void SetCourse(const char* name) {
    gWorldInstance.SetCourse(name);
}

void NextCourse() {
    gWorldInstance.NextCourse();
}

void PreviousCourse() {
    gWorldInstance.PreviousCourse();
}

void CourseManager_SpawnVehicles() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SpawnVehicles();
    }
}

void CourseManager_UpdateVehicles() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->UpdateVehicles();
    }
}

void CourseManager_LoadTextures() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->LoadTextures();
    }
}

void CourseManager_RenderCourse(struct UnkStruct_800DC5EC* arg0) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->Render(arg0);
    }
}

void CourseManager_RenderCredits() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->RenderCredits();
    }
}

void CourseManager_SpawnActors() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SpawnActors();
    }
}

void CourseManager_InitClouds() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->InitClouds();
    }
}

void CourseManager_UpdateClouds(s32 arg0, Camera* camera) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->UpdateClouds(arg0, camera);
    }
}

void CourseManager_Waypoints(Player* player, int8_t playerId) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->Waypoints(player, playerId);
    }
}

void CourseManager_GenerateCollision() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->GenerateCollision();
    }
}

void CourseManager_SomeCollisionThing(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5,
                                      f32* arg6, f32* arg7) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SomeCollisionThing(player, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void CourseManager_MinimapSettings() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->MinimapSettings();
    }
}

void CourseManager_InitCourseObjects() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->InitCourseObjects();
    }
}

void CourseManager_UpdateCourseObjects() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->UpdateCourseObjects();
    }
}

void CourseManager_RenderCourseObjects(s32 cameraId) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->RenderCourseObjects(cameraId);
    }
}

void CourseManager_SomeSounds() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SomeSounds();
    }
}

void CourseManager_SetCourseVtxColours() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SetCourseVtxColours();
    }
}

void CourseManager_WhatDoesThisDo(Player* player, int8_t playerId) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->WhatDoesThisDo(player, playerId);
    }
}

void CourseManager_WhatDoesThisDoAI(Player* player, int8_t playerId) {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->WhatDoesThisDoAI(player, playerId);
    }
}

void CourseManager_MinimapFinishlinePosition() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->MinimapFinishlinePosition();
    }
}

void CourseManager_SetStaffGhost() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SetStaffGhost();
    }
}

CProperties* CourseManager_GetProps() {
    if (gWorldInstance.CurrentCourse) {
        return (CProperties*) &gWorldInstance.CurrentCourse->Props;
    }
}

void CourseManager_SpawnBombKarts() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->SpawnBombKarts();
    }
}

void CourseManager_Water() {
    if (gWorldInstance.CurrentCourse) {
        gWorldInstance.CurrentCourse->Water();
    }
}

size_t GetCupCursorPosition() {
    return gWorldInstance.CurrentCup->CursorPosition;
}

void SetCupCursorPosition(size_t position) {
    gWorldInstance.CurrentCup->CursorPosition = position;
}

size_t GetCupSize() {
    return gWorldInstance.CurrentCup->GetSize();
}

void SetCourseFromCup() {
    gWorldInstance.SetCourseFromCup();
}

void* GetCourse(void) {
    return gWorldInstance.CurrentCourse;
}

void SetCourseByClass(void* course) {
    gWorldInstance.CurrentCourse = (Course*) course;
}
}

void push_frame() {
    // GameEngine::StartAudioFrame();
    GameEngine::Instance->StartFrame();
    thread5_iteration();
    // thread5_game_loop();
    // Graphics_ThreadUpdate();w
    // Timer_Update();
    // GameEngine::EndAudioFrame();
}

#ifdef _WIN32
int SDL_main(int argc, char** argv) {
#else
#if defined(__cplusplus) && defined(PLATFORM_IOS)
extern "C"
#endif
    int
    main(int argc, char* argv[]) {
#endif
    GameEngine::Create();
    // audio_init();
    // sound_init();

    CustomEngineInit();
    load_wasm();
    thread5_game_loop();
    while (WindowIsRunning()) {
        push_frame();
    }
    // GameEngine::Instance->ProcessFrame(push_frame);
    GameEngine::Instance->Destroy();
    return 0;
}
