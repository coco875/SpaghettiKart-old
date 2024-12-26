#include <libultraship.h>

#include "Actor.h"

// GameActor()

AActor::AActor() {
}

// Virtual functions to be overridden by derived classes
void AActor::Tick() {
}
void AActor::Draw(Camera* camera) {
}
void AActor::Collision(Player* player, AActor* actor) {
}
void AActor::Destroy() {
    // Set uuid to zero.
    memset(uuid, 0, sizeof(uuid));
}
bool AActor::IsMod() {
    return false;
}
