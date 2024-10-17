#pragma once

#include <libultraship.h>
#include "engine/Actor.h"

extern "C" {
#include "common_structs.h"
}

class ABall : public AActor {
  public:
    virtual ~ABall() = default;
    explicit ABall(Vec3f pos);

    virtual void Tick() override;
    virtual void Draw(Camera*) override;
};
