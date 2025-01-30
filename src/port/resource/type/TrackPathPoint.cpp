#include "TrackPathPoint.h"
#include "libultraship/libultra/gbi.h"

namespace MK64 {
TrackPathPoints::TrackPathPoints() : Resource(std::shared_ptr<Ship::ResourceInitData>()) {
}

TrackPathPoint* TrackPathPoints::GetPointer() {
    return TrackPathPointList.data();
}

size_t TrackPathPoints::GetPointerSize() {
    return TrackPathPointList.size() * sizeof(TrackPathPoint);
}
} // namespace MK64
