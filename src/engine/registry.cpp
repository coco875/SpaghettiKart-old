#include <string.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

typedef float Vec3f[3];

// avoid over lap on original Actor struct and need to decide what argument render and udpate should have
extern "C" {
#include "camera.h"
#include "actor_types.h"
#include "code_800029B0.h"
#include "registry.h"
#include "actors.h"
}

std::vector<ActorConstructor> gActorRegistry;

extern "C" int register_actor(ActorConstructor init) {
    int id = gActorRegistry.size();
    gActorRegistry.push_back(init);
    return id;
}

extern "C" void spawn_new_actor(int id, Vec3f pos, Vec3s rot, Vec3f velocity) {
    int index = add_actor_to_empty_slot(pos, rot, velocity, id);
    gActorRegistry[id](&gActorList[index]);
}

void custom_update(struct Actor* actor) {
}

void custom_render(struct Actor* actor, Camera* camera, Mat4 arg1) {
    render_actor_banana(camera, arg1, (BananaActor*) actor);
}

void custom_init(struct Actor* actor) {
    actor->update = custom_update;
    actor->render = custom_render;
}

// will replace update_course_actors and update_object and use a vec instead
extern "C" void new_update_actor() {
    for (int i = 0; i < ACTOR_LIST_SIZE; i++) {
        if (gActorList[i].update != NULL) {
            gActorList[i].update(&gActorList[i]);
        }
    }
}

// will replace render_course_actors and render_object and use a vec instead
extern "C" void new_render_actor(Camera* camera, Mat4 arg1) {
    for (int i = 0; i < ACTOR_LIST_SIZE; i++) {
        if (gActorList[i].render != NULL) {
            gActorList[i].render(&gActorList[i], camera, arg1);
        }
    }
}

extern "C" int myActorID;
extern "C" int myActorID2;

extern "C" void init_new_actor() {
    myActorID = register_actor((ActorConstructor*) NULL);
    myActorID2 = register_actor(custom_init);
}
