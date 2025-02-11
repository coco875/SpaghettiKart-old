#pragma once

#include <libultraship.h>

extern "C" {
#include "camera.h"
#include "objects.h"
}

class OObject {
  public:
    uint8_t uuid[16];
    Object o;
    bool PendingDestroy = false;

    virtual ~OObject() = default;

    explicit OObject();

    virtual void Tick();
    virtual void Tick60fps();
    virtual void Draw(s32 cameraId);
    virtual void Expire();
    virtual void Destroy(); // Mark object for deletion at the start of the next frame
    virtual void Reset();
};
