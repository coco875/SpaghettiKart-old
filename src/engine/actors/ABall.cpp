#include "ABall.h"

#include <libultra/gbi.h>

extern "C" {
#include "common_structs.h"
#include "math_util.h"
#include "main.h"
extern Gfx mario_Sphere_030_mesh[];
}

ABall::ABall(Vec3f pos) {
    Pos[0] = pos[0];
    Pos[1] = pos[1];
    Pos[2] = pos[2];
}

// Virtual functions to be overridden by derived classes
void ABall::Tick() {
    Rot[1] += 0x70;
    Rot[0] += 20;
}

void ABall::Draw(Camera* camera) {
    Mat4 sp38;
    gSPSetGeometryMode(gDisplayListHead++, G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);

    mtxf_pos_rotation_xyz(sp38, Pos, Rot);

    if (render_set_position(sp38, 0) != 0) {

        gSPDisplayList(gDisplayListHead++, mario_Sphere_030_mesh);
    }
}
