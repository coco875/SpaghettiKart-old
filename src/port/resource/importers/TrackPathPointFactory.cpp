#include "TrackPathPointFactory.h"
#include "../type/TrackPathPoint.h"
#include "spdlog/spdlog.h"
#include "libultraship/libultra/gbi.h"

namespace MK64 {
std::shared_ptr<Ship::IResource>
ResourceFactoryBinaryTrackPathPointsV0::ReadResource(std::shared_ptr<Ship::File> file) {
    if (!FileHasValidFormatAndReader(file)) {
        return nullptr;
    }

    auto section = std::make_shared<TrackPathPoints>(file->InitData);
    auto reader = std::get<std::shared_ptr<Ship::BinaryReader>>(file->Reader);

    uint32_t count = reader->ReadUInt32();
    section->TrackPathPointList.reserve(count);

    for (uint32_t i = 0; i < count; i++) {
        TrackPathPoint data;
        data.posX = reader->ReadInt16();
        data.posY = reader->ReadInt16();
        data.posZ = reader->ReadInt16();
        data.trackSegment = reader->ReadUInt16();

        section->TrackPathPointList.push_back(data);
    }

    return section;
}
} // namespace MK64
