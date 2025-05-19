#pragma once

#include "resource/Resource.h"
#include <vector>
#include <libultra/gbi.h>

struct TrackPathPointData {
    int16_t posX;
    int16_t posY;
    int16_t posZ;
    uint16_t trackSegment;
};

namespace MK64 {
// Used for binary import from torch
class TrackPathPoints : public Ship::Resource<TrackPathPointData> {
  public:
    using Resource::Resource;

    TrackPathPoints();

    TrackPathPointData* GetPointer() override;
    size_t GetPointerSize() override;

    std::vector<TrackPathPointData> TrackPathPointList;
};

// Used for xml
class Paths : public Ship::Resource<TrackPathPointData> {
  public:
    using Resource::Resource;

    Paths();

    TrackPathPointData* GetPointer() override;
    size_t GetPointerSize() override;

    std::vector<std::vector<TrackPathPointData>> PathList;
};

} // namespace MK64
