// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vlan.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_vlan_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_vlan_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
#include "common.pb.h"
#include "interface.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_vlan_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_vlan_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_vlan_2eproto;
namespace Net {
class Vlan;
struct VlanDefaultTypeInternal;
extern VlanDefaultTypeInternal _Vlan_default_instance_;
class VlanMember;
struct VlanMemberDefaultTypeInternal;
extern VlanMemberDefaultTypeInternal _VlanMember_default_instance_;
}  // namespace Net
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace Net {
enum VlanMode : int {
  VLAN_ACCESS = 0,
  VLAN_TAGGED = 1,
  VLAN_UNTAGGED = 2,
  VlanMode_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  VlanMode_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool VlanMode_IsValid(int value);
extern const uint32_t VlanMode_internal_data_[];
constexpr VlanMode VlanMode_MIN = static_cast<VlanMode>(0);
constexpr VlanMode VlanMode_MAX = static_cast<VlanMode>(2);
constexpr int VlanMode_ARRAYSIZE = 2 + 1;
const ::google::protobuf::EnumDescriptor*
VlanMode_descriptor();
template <typename T>
const std::string& VlanMode_Name(T value) {
  static_assert(std::is_same<T, VlanMode>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to VlanMode_Name().");
  return VlanMode_Name(static_cast<VlanMode>(value));
}
template <>
inline const std::string& VlanMode_Name(VlanMode value) {
  return ::google::protobuf::internal::NameOfDenseEnum<VlanMode_descriptor,
                                                 0, 2>(
      static_cast<int>(value));
}
inline bool VlanMode_Parse(absl::string_view name, VlanMode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<VlanMode>(
      VlanMode_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class Vlan final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Net.Vlan) */ {
 public:
  inline Vlan() : Vlan(nullptr) {}
  ~Vlan() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Vlan(
      ::google::protobuf::internal::ConstantInitialized);

  inline Vlan(const Vlan& from) : Vlan(nullptr, from) {}
  inline Vlan(Vlan&& from) noexcept
      : Vlan(nullptr, std::move(from)) {}
  inline Vlan& operator=(const Vlan& from) {
    CopyFrom(from);
    return *this;
  }
  inline Vlan& operator=(Vlan&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Vlan& default_instance() {
    return *internal_default_instance();
  }
  static inline const Vlan* internal_default_instance() {
    return reinterpret_cast<const Vlan*>(
        &_Vlan_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Vlan& a, Vlan& b) { a.Swap(&b); }
  inline void Swap(Vlan* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Vlan* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Vlan* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Vlan>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Vlan& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Vlan& from) { Vlan::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Vlan* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "Net.Vlan"; }

 protected:
  explicit Vlan(::google::protobuf::Arena* arena);
  Vlan(::google::protobuf::Arena* arena, const Vlan& from);
  Vlan(::google::protobuf::Arena* arena, Vlan&& from) noexcept
      : Vlan(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kIdFieldNumber = 1,
  };
  // string id = 1;
  void clear_id() ;
  const std::string& id() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_id(Arg_&& arg, Args_... args);
  std::string* mutable_id();
  PROTOBUF_NODISCARD std::string* release_id();
  void set_allocated_id(std::string* value);

  private:
  const std::string& _internal_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(
      const std::string& value);
  std::string* _internal_mutable_id();

  public:
  // @@protoc_insertion_point(class_scope:Net.Vlan)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      19, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr id_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_vlan_2eproto;
};
// -------------------------------------------------------------------

class VlanMember final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Net.VlanMember) */ {
 public:
  inline VlanMember() : VlanMember(nullptr) {}
  ~VlanMember() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR VlanMember(
      ::google::protobuf::internal::ConstantInitialized);

  inline VlanMember(const VlanMember& from) : VlanMember(nullptr, from) {}
  inline VlanMember(VlanMember&& from) noexcept
      : VlanMember(nullptr, std::move(from)) {}
  inline VlanMember& operator=(const VlanMember& from) {
    CopyFrom(from);
    return *this;
  }
  inline VlanMember& operator=(VlanMember&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const VlanMember& default_instance() {
    return *internal_default_instance();
  }
  static inline const VlanMember* internal_default_instance() {
    return reinterpret_cast<const VlanMember*>(
        &_VlanMember_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(VlanMember& a, VlanMember& b) { a.Swap(&b); }
  inline void Swap(VlanMember* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(VlanMember* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  VlanMember* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<VlanMember>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const VlanMember& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const VlanMember& from) { VlanMember::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(VlanMember* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "Net.VlanMember"; }

 protected:
  explicit VlanMember(::google::protobuf::Arena* arena);
  VlanMember(::google::protobuf::Arena* arena, const VlanMember& from);
  VlanMember(::google::protobuf::Arena* arena, VlanMember&& from) noexcept
      : VlanMember(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kMembersFieldNumber = 3,
    kVlanIdFieldNumber = 1,
    kModeFieldNumber = 2,
  };
  // repeated .Net.Iface members = 3;
  int members_size() const;
  private:
  int _internal_members_size() const;

  public:
  void clear_members() ;
  ::Net::Iface* mutable_members(int index);
  ::google::protobuf::RepeatedPtrField<::Net::Iface>* mutable_members();

  private:
  const ::google::protobuf::RepeatedPtrField<::Net::Iface>& _internal_members() const;
  ::google::protobuf::RepeatedPtrField<::Net::Iface>* _internal_mutable_members();
  public:
  const ::Net::Iface& members(int index) const;
  ::Net::Iface* add_members();
  const ::google::protobuf::RepeatedPtrField<::Net::Iface>& members() const;
  // string vlan_id = 1;
  void clear_vlan_id() ;
  const std::string& vlan_id() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_vlan_id(Arg_&& arg, Args_... args);
  std::string* mutable_vlan_id();
  PROTOBUF_NODISCARD std::string* release_vlan_id();
  void set_allocated_vlan_id(std::string* value);

  private:
  const std::string& _internal_vlan_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_vlan_id(
      const std::string& value);
  std::string* _internal_mutable_vlan_id();

  public:
  // .Net.VlanMode mode = 2;
  void clear_mode() ;
  ::Net::VlanMode mode() const;
  void set_mode(::Net::VlanMode value);

  private:
  ::Net::VlanMode _internal_mode() const;
  void _internal_set_mode(::Net::VlanMode value);

  public:
  // @@protoc_insertion_point(class_scope:Net.VlanMember)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 1,
      30, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::RepeatedPtrField< ::Net::Iface > members_;
    ::google::protobuf::internal::ArenaStringPtr vlan_id_;
    int mode_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_vlan_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Vlan

// string id = 1;
inline void Vlan::clear_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_.ClearToEmpty();
}
inline const std::string& Vlan::id() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Net.Vlan.id)
  return _internal_id();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Vlan::set_id(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Net.Vlan.id)
}
inline std::string* Vlan::mutable_id() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_id();
  // @@protoc_insertion_point(field_mutable:Net.Vlan.id)
  return _s;
}
inline const std::string& Vlan::_internal_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.id_.Get();
}
inline void Vlan::_internal_set_id(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_.Set(value, GetArena());
}
inline std::string* Vlan::_internal_mutable_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.id_.Mutable( GetArena());
}
inline std::string* Vlan::release_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Net.Vlan.id)
  return _impl_.id_.Release();
}
inline void Vlan::set_allocated_id(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.id_.IsDefault()) {
          _impl_.id_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Net.Vlan.id)
}

// -------------------------------------------------------------------

// VlanMember

// string vlan_id = 1;
inline void VlanMember::clear_vlan_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.vlan_id_.ClearToEmpty();
}
inline const std::string& VlanMember::vlan_id() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Net.VlanMember.vlan_id)
  return _internal_vlan_id();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void VlanMember::set_vlan_id(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.vlan_id_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Net.VlanMember.vlan_id)
}
inline std::string* VlanMember::mutable_vlan_id() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_vlan_id();
  // @@protoc_insertion_point(field_mutable:Net.VlanMember.vlan_id)
  return _s;
}
inline const std::string& VlanMember::_internal_vlan_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.vlan_id_.Get();
}
inline void VlanMember::_internal_set_vlan_id(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.vlan_id_.Set(value, GetArena());
}
inline std::string* VlanMember::_internal_mutable_vlan_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.vlan_id_.Mutable( GetArena());
}
inline std::string* VlanMember::release_vlan_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Net.VlanMember.vlan_id)
  return _impl_.vlan_id_.Release();
}
inline void VlanMember::set_allocated_vlan_id(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.vlan_id_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.vlan_id_.IsDefault()) {
          _impl_.vlan_id_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Net.VlanMember.vlan_id)
}

// .Net.VlanMode mode = 2;
inline void VlanMember::clear_mode() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mode_ = 0;
}
inline ::Net::VlanMode VlanMember::mode() const {
  // @@protoc_insertion_point(field_get:Net.VlanMember.mode)
  return _internal_mode();
}
inline void VlanMember::set_mode(::Net::VlanMode value) {
  _internal_set_mode(value);
  // @@protoc_insertion_point(field_set:Net.VlanMember.mode)
}
inline ::Net::VlanMode VlanMember::_internal_mode() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::Net::VlanMode>(_impl_.mode_);
}
inline void VlanMember::_internal_set_mode(::Net::VlanMode value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mode_ = value;
}

// repeated .Net.Iface members = 3;
inline int VlanMember::_internal_members_size() const {
  return _internal_members().size();
}
inline int VlanMember::members_size() const {
  return _internal_members_size();
}
inline ::Net::Iface* VlanMember::mutable_members(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:Net.VlanMember.members)
  return _internal_mutable_members()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::Net::Iface>* VlanMember::mutable_members()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:Net.VlanMember.members)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_members();
}
inline const ::Net::Iface& VlanMember::members(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Net.VlanMember.members)
  return _internal_members().Get(index);
}
inline ::Net::Iface* VlanMember::add_members() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::Net::Iface* _add = _internal_mutable_members()->Add();
  // @@protoc_insertion_point(field_add:Net.VlanMember.members)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::Net::Iface>& VlanMember::members() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:Net.VlanMember.members)
  return _internal_members();
}
inline const ::google::protobuf::RepeatedPtrField<::Net::Iface>&
VlanMember::_internal_members() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.members_;
}
inline ::google::protobuf::RepeatedPtrField<::Net::Iface>*
VlanMember::_internal_mutable_members() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.members_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace Net


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::Net::VlanMode> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::Net::VlanMode>() {
  return ::Net::VlanMode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_vlan_2eproto_2epb_2eh
