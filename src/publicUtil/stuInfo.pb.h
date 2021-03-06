// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: stuInfo.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_stuInfo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_stuInfo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_stuInfo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_stuInfo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_stuInfo_2eproto;
class StuInfo;
class StuInfoDefaultTypeInternal;
extern StuInfoDefaultTypeInternal _StuInfo_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::StuInfo* Arena::CreateMaybeMessage<::StuInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class StuInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:StuInfo) */ {
 public:
  StuInfo();
  virtual ~StuInfo();

  StuInfo(const StuInfo& from);
  StuInfo(StuInfo&& from) noexcept
    : StuInfo() {
    *this = ::std::move(from);
  }

  inline StuInfo& operator=(const StuInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline StuInfo& operator=(StuInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const StuInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StuInfo* internal_default_instance() {
    return reinterpret_cast<const StuInfo*>(
               &_StuInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(StuInfo& a, StuInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(StuInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline StuInfo* New() const final {
    return CreateMaybeMessage<StuInfo>(nullptr);
  }

  StuInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<StuInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const StuInfo& from);
  void MergeFrom(const StuInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StuInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "StuInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_stuInfo_2eproto);
    return ::descriptor_table_stuInfo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStuIdFieldNumber = 1,
    kPasswdFieldNumber = 2,
    kStartTimeFieldNumber = 5,
    kEndTimeFieldNumber = 6,
    kDateFieldNumber = 7,
    kSeatNoFieldNumber = 3,
    kRoomIdFieldNumber = 4,
  };
  // required string stuId = 1;
  bool has_stuid() const;
  private:
  bool _internal_has_stuid() const;
  public:
  void clear_stuid();
  const std::string& stuid() const;
  void set_stuid(const std::string& value);
  void set_stuid(std::string&& value);
  void set_stuid(const char* value);
  void set_stuid(const char* value, size_t size);
  std::string* mutable_stuid();
  std::string* release_stuid();
  void set_allocated_stuid(std::string* stuid);
  private:
  const std::string& _internal_stuid() const;
  void _internal_set_stuid(const std::string& value);
  std::string* _internal_mutable_stuid();
  public:

  // required string passwd = 2;
  bool has_passwd() const;
  private:
  bool _internal_has_passwd() const;
  public:
  void clear_passwd();
  const std::string& passwd() const;
  void set_passwd(const std::string& value);
  void set_passwd(std::string&& value);
  void set_passwd(const char* value);
  void set_passwd(const char* value, size_t size);
  std::string* mutable_passwd();
  std::string* release_passwd();
  void set_allocated_passwd(std::string* passwd);
  private:
  const std::string& _internal_passwd() const;
  void _internal_set_passwd(const std::string& value);
  std::string* _internal_mutable_passwd();
  public:

  // required string startTime = 5;
  bool has_starttime() const;
  private:
  bool _internal_has_starttime() const;
  public:
  void clear_starttime();
  const std::string& starttime() const;
  void set_starttime(const std::string& value);
  void set_starttime(std::string&& value);
  void set_starttime(const char* value);
  void set_starttime(const char* value, size_t size);
  std::string* mutable_starttime();
  std::string* release_starttime();
  void set_allocated_starttime(std::string* starttime);
  private:
  const std::string& _internal_starttime() const;
  void _internal_set_starttime(const std::string& value);
  std::string* _internal_mutable_starttime();
  public:

  // required string endTime = 6;
  bool has_endtime() const;
  private:
  bool _internal_has_endtime() const;
  public:
  void clear_endtime();
  const std::string& endtime() const;
  void set_endtime(const std::string& value);
  void set_endtime(std::string&& value);
  void set_endtime(const char* value);
  void set_endtime(const char* value, size_t size);
  std::string* mutable_endtime();
  std::string* release_endtime();
  void set_allocated_endtime(std::string* endtime);
  private:
  const std::string& _internal_endtime() const;
  void _internal_set_endtime(const std::string& value);
  std::string* _internal_mutable_endtime();
  public:

  // required string date = 7;
  bool has_date() const;
  private:
  bool _internal_has_date() const;
  public:
  void clear_date();
  const std::string& date() const;
  void set_date(const std::string& value);
  void set_date(std::string&& value);
  void set_date(const char* value);
  void set_date(const char* value, size_t size);
  std::string* mutable_date();
  std::string* release_date();
  void set_allocated_date(std::string* date);
  private:
  const std::string& _internal_date() const;
  void _internal_set_date(const std::string& value);
  std::string* _internal_mutable_date();
  public:

  // required int32 seatNo = 3;
  bool has_seatno() const;
  private:
  bool _internal_has_seatno() const;
  public:
  void clear_seatno();
  ::PROTOBUF_NAMESPACE_ID::int32 seatno() const;
  void set_seatno(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_seatno() const;
  void _internal_set_seatno(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 roomId = 4;
  bool has_roomid() const;
  private:
  bool _internal_has_roomid() const;
  public:
  void clear_roomid();
  ::PROTOBUF_NAMESPACE_ID::int32 roomid() const;
  void set_roomid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_roomid() const;
  void _internal_set_roomid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:StuInfo)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr stuid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr passwd_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr starttime_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr endtime_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr date_;
  ::PROTOBUF_NAMESPACE_ID::int32 seatno_;
  ::PROTOBUF_NAMESPACE_ID::int32 roomid_;
  friend struct ::TableStruct_stuInfo_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StuInfo

// required string stuId = 1;
inline bool StuInfo::_internal_has_stuid() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool StuInfo::has_stuid() const {
  return _internal_has_stuid();
}
inline void StuInfo::clear_stuid() {
  stuid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& StuInfo::stuid() const {
  // @@protoc_insertion_point(field_get:StuInfo.stuId)
  return _internal_stuid();
}
inline void StuInfo::set_stuid(const std::string& value) {
  _internal_set_stuid(value);
  // @@protoc_insertion_point(field_set:StuInfo.stuId)
}
inline std::string* StuInfo::mutable_stuid() {
  // @@protoc_insertion_point(field_mutable:StuInfo.stuId)
  return _internal_mutable_stuid();
}
inline const std::string& StuInfo::_internal_stuid() const {
  return stuid_.GetNoArena();
}
inline void StuInfo::_internal_set_stuid(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  stuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void StuInfo::set_stuid(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  stuid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:StuInfo.stuId)
}
inline void StuInfo::set_stuid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  stuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:StuInfo.stuId)
}
inline void StuInfo::set_stuid(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  stuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:StuInfo.stuId)
}
inline std::string* StuInfo::_internal_mutable_stuid() {
  _has_bits_[0] |= 0x00000001u;
  return stuid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* StuInfo::release_stuid() {
  // @@protoc_insertion_point(field_release:StuInfo.stuId)
  if (!_internal_has_stuid()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return stuid_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void StuInfo::set_allocated_stuid(std::string* stuid) {
  if (stuid != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  stuid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), stuid);
  // @@protoc_insertion_point(field_set_allocated:StuInfo.stuId)
}

// required string passwd = 2;
inline bool StuInfo::_internal_has_passwd() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool StuInfo::has_passwd() const {
  return _internal_has_passwd();
}
inline void StuInfo::clear_passwd() {
  passwd_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& StuInfo::passwd() const {
  // @@protoc_insertion_point(field_get:StuInfo.passwd)
  return _internal_passwd();
}
inline void StuInfo::set_passwd(const std::string& value) {
  _internal_set_passwd(value);
  // @@protoc_insertion_point(field_set:StuInfo.passwd)
}
inline std::string* StuInfo::mutable_passwd() {
  // @@protoc_insertion_point(field_mutable:StuInfo.passwd)
  return _internal_mutable_passwd();
}
inline const std::string& StuInfo::_internal_passwd() const {
  return passwd_.GetNoArena();
}
inline void StuInfo::_internal_set_passwd(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void StuInfo::set_passwd(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  passwd_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:StuInfo.passwd)
}
inline void StuInfo::set_passwd(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:StuInfo.passwd)
}
inline void StuInfo::set_passwd(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:StuInfo.passwd)
}
inline std::string* StuInfo::_internal_mutable_passwd() {
  _has_bits_[0] |= 0x00000002u;
  return passwd_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* StuInfo::release_passwd() {
  // @@protoc_insertion_point(field_release:StuInfo.passwd)
  if (!_internal_has_passwd()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return passwd_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void StuInfo::set_allocated_passwd(std::string* passwd) {
  if (passwd != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  passwd_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), passwd);
  // @@protoc_insertion_point(field_set_allocated:StuInfo.passwd)
}

// required int32 seatNo = 3;
inline bool StuInfo::_internal_has_seatno() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool StuInfo::has_seatno() const {
  return _internal_has_seatno();
}
inline void StuInfo::clear_seatno() {
  seatno_ = 0;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 StuInfo::_internal_seatno() const {
  return seatno_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 StuInfo::seatno() const {
  // @@protoc_insertion_point(field_get:StuInfo.seatNo)
  return _internal_seatno();
}
inline void StuInfo::_internal_set_seatno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000020u;
  seatno_ = value;
}
inline void StuInfo::set_seatno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_seatno(value);
  // @@protoc_insertion_point(field_set:StuInfo.seatNo)
}

// required int32 roomId = 4;
inline bool StuInfo::_internal_has_roomid() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool StuInfo::has_roomid() const {
  return _internal_has_roomid();
}
inline void StuInfo::clear_roomid() {
  roomid_ = 0;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 StuInfo::_internal_roomid() const {
  return roomid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 StuInfo::roomid() const {
  // @@protoc_insertion_point(field_get:StuInfo.roomId)
  return _internal_roomid();
}
inline void StuInfo::_internal_set_roomid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000040u;
  roomid_ = value;
}
inline void StuInfo::set_roomid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_roomid(value);
  // @@protoc_insertion_point(field_set:StuInfo.roomId)
}

// required string startTime = 5;
inline bool StuInfo::_internal_has_starttime() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool StuInfo::has_starttime() const {
  return _internal_has_starttime();
}
inline void StuInfo::clear_starttime() {
  starttime_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& StuInfo::starttime() const {
  // @@protoc_insertion_point(field_get:StuInfo.startTime)
  return _internal_starttime();
}
inline void StuInfo::set_starttime(const std::string& value) {
  _internal_set_starttime(value);
  // @@protoc_insertion_point(field_set:StuInfo.startTime)
}
inline std::string* StuInfo::mutable_starttime() {
  // @@protoc_insertion_point(field_mutable:StuInfo.startTime)
  return _internal_mutable_starttime();
}
inline const std::string& StuInfo::_internal_starttime() const {
  return starttime_.GetNoArena();
}
inline void StuInfo::_internal_set_starttime(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  starttime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void StuInfo::set_starttime(std::string&& value) {
  _has_bits_[0] |= 0x00000004u;
  starttime_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:StuInfo.startTime)
}
inline void StuInfo::set_starttime(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000004u;
  starttime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:StuInfo.startTime)
}
inline void StuInfo::set_starttime(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000004u;
  starttime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:StuInfo.startTime)
}
inline std::string* StuInfo::_internal_mutable_starttime() {
  _has_bits_[0] |= 0x00000004u;
  return starttime_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* StuInfo::release_starttime() {
  // @@protoc_insertion_point(field_release:StuInfo.startTime)
  if (!_internal_has_starttime()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return starttime_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void StuInfo::set_allocated_starttime(std::string* starttime) {
  if (starttime != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  starttime_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), starttime);
  // @@protoc_insertion_point(field_set_allocated:StuInfo.startTime)
}

// required string endTime = 6;
inline bool StuInfo::_internal_has_endtime() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool StuInfo::has_endtime() const {
  return _internal_has_endtime();
}
inline void StuInfo::clear_endtime() {
  endtime_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000008u;
}
inline const std::string& StuInfo::endtime() const {
  // @@protoc_insertion_point(field_get:StuInfo.endTime)
  return _internal_endtime();
}
inline void StuInfo::set_endtime(const std::string& value) {
  _internal_set_endtime(value);
  // @@protoc_insertion_point(field_set:StuInfo.endTime)
}
inline std::string* StuInfo::mutable_endtime() {
  // @@protoc_insertion_point(field_mutable:StuInfo.endTime)
  return _internal_mutable_endtime();
}
inline const std::string& StuInfo::_internal_endtime() const {
  return endtime_.GetNoArena();
}
inline void StuInfo::_internal_set_endtime(const std::string& value) {
  _has_bits_[0] |= 0x00000008u;
  endtime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void StuInfo::set_endtime(std::string&& value) {
  _has_bits_[0] |= 0x00000008u;
  endtime_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:StuInfo.endTime)
}
inline void StuInfo::set_endtime(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000008u;
  endtime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:StuInfo.endTime)
}
inline void StuInfo::set_endtime(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000008u;
  endtime_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:StuInfo.endTime)
}
inline std::string* StuInfo::_internal_mutable_endtime() {
  _has_bits_[0] |= 0x00000008u;
  return endtime_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* StuInfo::release_endtime() {
  // @@protoc_insertion_point(field_release:StuInfo.endTime)
  if (!_internal_has_endtime()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000008u;
  return endtime_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void StuInfo::set_allocated_endtime(std::string* endtime) {
  if (endtime != nullptr) {
    _has_bits_[0] |= 0x00000008u;
  } else {
    _has_bits_[0] &= ~0x00000008u;
  }
  endtime_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), endtime);
  // @@protoc_insertion_point(field_set_allocated:StuInfo.endTime)
}

// required string date = 7;
inline bool StuInfo::_internal_has_date() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool StuInfo::has_date() const {
  return _internal_has_date();
}
inline void StuInfo::clear_date() {
  date_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000010u;
}
inline const std::string& StuInfo::date() const {
  // @@protoc_insertion_point(field_get:StuInfo.date)
  return _internal_date();
}
inline void StuInfo::set_date(const std::string& value) {
  _internal_set_date(value);
  // @@protoc_insertion_point(field_set:StuInfo.date)
}
inline std::string* StuInfo::mutable_date() {
  // @@protoc_insertion_point(field_mutable:StuInfo.date)
  return _internal_mutable_date();
}
inline const std::string& StuInfo::_internal_date() const {
  return date_.GetNoArena();
}
inline void StuInfo::_internal_set_date(const std::string& value) {
  _has_bits_[0] |= 0x00000010u;
  date_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void StuInfo::set_date(std::string&& value) {
  _has_bits_[0] |= 0x00000010u;
  date_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:StuInfo.date)
}
inline void StuInfo::set_date(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000010u;
  date_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:StuInfo.date)
}
inline void StuInfo::set_date(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000010u;
  date_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:StuInfo.date)
}
inline std::string* StuInfo::_internal_mutable_date() {
  _has_bits_[0] |= 0x00000010u;
  return date_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* StuInfo::release_date() {
  // @@protoc_insertion_point(field_release:StuInfo.date)
  if (!_internal_has_date()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000010u;
  return date_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void StuInfo::set_allocated_date(std::string* date) {
  if (date != nullptr) {
    _has_bits_[0] |= 0x00000010u;
  } else {
    _has_bits_[0] &= ~0x00000010u;
  }
  date_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), date);
  // @@protoc_insertion_point(field_set_allocated:StuInfo.date)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_stuInfo_2eproto
