#ifndef COURSE_H
#define COURSE_H

#include <libultra/types.h>
#include <libultra/gbi.h>
#include "common_structs.h"
#include "camera.h"

typedef struct {
    Gfx* addr;
    u8 surfaceType;
    u8 sectionId;
    u16 flags;
} TrackSections;

typedef struct {
    /* 0x00 */ s16 posX;
    /* 0x02 */ s16 posY;
    /* 0x04 */ s16 posZ;
    /* 0x06 */ u16 trackSectionId;
} TrackWaypoint; // size = 0x08

typedef struct {
    RGB8 TopRight;
    RGB8 BottomRight;
    RGB8 BottomLeft;
    RGB8 TopLeft;
    RGB8 FloorTopRight;
    RGB8 FloorBottomRight;
    RGB8 FloorBottomLeft;
    RGB8 FloorTopLeft;
} SkyboxColours;

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ char padA[6];
} _struct_gCoursePathSizes_0x10; // size 0x10

typedef f32 Vec3f[3];
typedef f32 Vec4f[4];

typedef s32 Vec3iu[3];

typedef s16 Vec3s[3];
typedef u16 Vec3su[3];
typedef s16 Vec4s[4];

typedef f32 Mat3[3][3];
typedef f32 Mat4[4][4];

typedef struct {
    // rotY and posY seem relative to the camera.
    // See `func_800788F8` to see how rotY is used to decide whether and where to display clouds/stars
    // See `func_80078A44` and `func_800789AC` to see how stars and clouds (respectively) are looped over
    /* 0x00 */ uint16_t rotY;
    /* 0x02 */ uint16_t posY;
    // Can be bigger than 100!
    /* 0x04 */ uint16_t scalePercent;
    // There are a couple different cloud shapes, this decides which one is used
    // For stars, this is always 0 since they don't have multiple textures
    /* 0x06 */ uint16_t subType;
} StarData, CloudData; // size = 0x8

typedef struct {
    const char* addr;   // segmented address texture file
    uint32_t file_size; // compressed file size
    uint32_t data_size; // uncompressed texture size
    uint32_t padding;   // always zero
} course_texture;

typedef struct {
    int id;
    const char* nameId;
    const char* name;
    const char* debugName;
    const char* courseLength;
    const char* aiBehaviour;
    float aiMaximumSeparation;
    float aiMinimumSeparation;
    float nearPersp;
    float farPersp;
    int16_t* somePtr;
    uint32_t aiSteeringSensitivity;
    _struct_gCoursePathSizes_0x10 pathSizes;
    Vec4f D_0D009418;
    Vec4f D_0D009568;
    Vec4f D_0D0096B8;
    Vec4f D_0D009808;
    const char* pathTable[4];
    const char* pathTable2[4];
    CloudData* clouds;
    CloudData* cloudList;
    int32_t minimapFinishlineX;
    int32_t minimapFinishlineY;
    SkyboxColours skybox;
    const course_texture* textures;
    void (*load)();
    void (*load_textures)();
    void (*spawn_actors)();
    void (*init_clouds)();
    void (*update_clouds)(s32, Camera*);
    void (*some_collision_thing)(Player* player, Vec3f arg1, Vec3f arg2, Vec3f arg3, f32* arg4, f32* arg5, f32* arg6,
                                 f32* arg7);
    void (*minimap_settings)();
    void (*minimap_finish_line_position)();
    void (*init_course_objects)();
    void (*update_course_objects)();
    void (*render_course_objecrs)(s32);
    void (*some_sounds)();
    void (*set_course_vtx_colours)();
    void (*what_does_this_do)(Player*, int8_t);
    void (*what_does_this_do_ai)(Player*, int8_t);
    void (*set_staff_ghost)();
    void (*spawn_bomb_karts)();
    void (*begin_play)();
    void (*render)(struct UnkStruct_800DC5EC*);
    void (*render_credits)();
    void (*spawn_vehicles)();
    void (*update_vehicles)();
    void (*waypoints)(Player* player, int8_t playerId);
    void (*collision)();
    void (*generate_collision)();
    void (*water)();
    void (*destroy)();
} Course;

#endif