#include <string.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

typedef float Vec3f[3];

// avoid over lap on original Actor struct and need to decide what argument render and udpate should have
extern "C" {
struct CustomActor {
    int id;
    Vec3f position;
    Vec3f velocity;
    Vec3f rotation;
    void (*render)(struct CustomActor*);
    void (*update)(struct CustomActor*);
};

typedef void (*ActorConstructor)(struct CustomActor*);
}

std::vector<ActorConstructor> gActorRegistry;

extern "C" int register_actor(ActorConstructor init) {
    int id = gActorRegistry.size();
    gActorRegistry.push_back(init);
    return id;
}

// handle by actor manager
#if 0
struct Actor gActorList[1024] = {};
int gActorListSize = 0;

void spawn_actor(int id, Vec3f position, Vec3f velocity, Vec3f rotation) {
    struct Actor* actor = &gActorList[gActorListSize];
    actor->id = id;
    memcpy(actor->position, position, sizeof(Vec3f));
    memcpy(actor->velocity, velocity, sizeof(Vec3f));
    memcpy(actor->rotation, rotation, sizeof(Vec3f));
    if (gActorRegistry[id] != NULL) {
        gActorRegistry[id](actor);
    }
}

void update_actor() {
    for (int i = 0; i < gActorListSize; i++) {
        if (gActorList[i].update != NULL) {
            gActorList[i].update(&gActorList[i]);
        }
    }
}

void render_actor() {
    for (int i = 0; i < gActorListSize; i++) {
        if (gActorList[i].render != NULL) {
            gActorList[i].render(&gActorList[i]);
        }
    }
}
#endif

void custom_update(struct CustomActor* actor) {
    printf("custom update");
}

void custom_render(struct CustomActor* actor) {
    printf("custom render");
}

void custom_init(struct CustomActor* actor) {
    actor->update = custom_update;
    actor->render = custom_render;
}

int myActorID;
int myActorID2;

void init_actor() {
    myActorID = register_actor(NULL);
    myActorID2 = register_actor(custom_init);
}
