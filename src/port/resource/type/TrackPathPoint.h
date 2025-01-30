#pragma once

#include "resource/Resource.h"
#include <vector>
#include <libultra/gbi.h>

struct TrackPathPoint {
    int16_t posX;
    int16_t posY;
    int16_t posZ;
    uint16_t trackSegment;
};

namespace MK64 {
class TrackPathPoints : public Ship::Resource<TrackPathPoint> {
  public:
    using Resource::Resource;

    TrackPathPoints();

    TrackPathPoint* GetPointer() override;
    size_t GetPointerSize() override;

    std::vector<TrackPathPoint> TrackPathPointList;
};
} // namespace MK64
