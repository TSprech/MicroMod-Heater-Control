// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_HEATERSETTINGS_HEATERSETTINGS_H_
#define FLATBUFFERS_GENERATED_HEATERSETTINGS_HEATERSETTINGS_H_

#include "flatbuffers/flatbuffers.h"

namespace HeaterSettings {

struct HeaterSettings;
struct HeaterSettingsBuilder;

struct HeaterSettings FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef HeaterSettingsBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SET_POINT = 4,
    VT_LIGHTS = 6
  };
  uint8_t set_point() const {
    return GetField<uint8_t>(VT_SET_POINT, 0);
  }
  bool mutate_set_point(uint8_t _set_point = 0) {
    return SetField<uint8_t>(VT_SET_POINT, _set_point, 0);
  }
  bool lights() const {
    return GetField<uint8_t>(VT_LIGHTS, 0) != 0;
  }
  bool mutate_lights(bool _lights = 0) {
    return SetField<uint8_t>(VT_LIGHTS, static_cast<uint8_t>(_lights), 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_SET_POINT) &&
           VerifyField<uint8_t>(verifier, VT_LIGHTS) &&
           verifier.EndTable();
  }
};

struct HeaterSettingsBuilder {
  typedef HeaterSettings Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_set_point(uint8_t set_point) {
    fbb_.AddElement<uint8_t>(HeaterSettings::VT_SET_POINT, set_point, 0);
  }
  void add_lights(bool lights) {
    fbb_.AddElement<uint8_t>(HeaterSettings::VT_LIGHTS, static_cast<uint8_t>(lights), 0);
  }
  explicit HeaterSettingsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<HeaterSettings> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<HeaterSettings>(end);
    return o;
  }
};

inline flatbuffers::Offset<HeaterSettings> CreateHeaterSettings(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint8_t set_point = 0,
    bool lights = false) {
  HeaterSettingsBuilder builder_(_fbb);
  builder_.add_lights(lights);
  builder_.add_set_point(set_point);
  return builder_.Finish();
}

struct Traits {
  using type = HeaterSettings;
  static auto constexpr Create = CreateHeaterSettings;
};

inline const HeaterSettings *GetHeaterSettings(const void *buf) {
  return flatbuffers::GetRoot<HeaterSettings>(buf);
}

inline const HeaterSettings *GetSizePrefixedHeaterSettings(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<HeaterSettings>(buf);
}

inline HeaterSettings *GetMutableHeaterSettings(void *buf) {
  return flatbuffers::GetMutableRoot<HeaterSettings>(buf);
}

inline HeaterSettings *GetMutableSizePrefixedHeaterSettings(void *buf) {
  return flatbuffers::GetMutableSizePrefixedRoot<HeaterSettings>(buf);
}

inline bool VerifyHeaterSettingsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<HeaterSettings>(nullptr);
}

inline bool VerifySizePrefixedHeaterSettingsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<HeaterSettings>(nullptr);
}

inline void FinishHeaterSettingsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<HeaterSettings> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedHeaterSettingsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<HeaterSettings> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace HeaterSettings

#endif  // FLATBUFFERS_GENERATED_HEATERSETTINGS_HEATERSETTINGS_H_
