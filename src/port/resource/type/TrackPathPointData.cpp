#include "TrackPathPointData.h"
#include "libultraship/libultra/gbi.h"

namespace MK64 {
TrackPathPointData::TrackPathPointData() : Resource(std::shared_ptr<Ship::ResourceInitData>()) {
}

TrackPathPoint* TrackPathPointData::GetPointer() {
    return TrackPathPointList.data();
}

size_t TrackPathPointData::GetPointerSize() {
    return TrackPathPointList.size() * sizeof(TrackPathPoint);
}
} // namespace MK64
