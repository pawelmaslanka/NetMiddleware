// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lag.proto
// Protobuf C++ Version: 5.26.1

#include "lag.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace Net {

inline constexpr Result::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : error_message_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Result::Result(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ResultDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResultDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResultDefaultTypeInternal() {}
  union {
    Result _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResultDefaultTypeInternal _Result_default_instance_;

inline constexpr Port::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Port::Port(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PortDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PortDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PortDefaultTypeInternal() {}
  union {
    Port _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PortDefaultTypeInternal _Port_default_instance_;

inline constexpr LagInstance::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR LagInstance::LagInstance(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct LagInstanceDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LagInstanceDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~LagInstanceDefaultTypeInternal() {}
  union {
    LagInstance _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LagInstanceDefaultTypeInternal _LagInstance_default_instance_;

inline constexpr LagMember::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        members_{},
        lag_{nullptr} {}

template <typename>
PROTOBUF_CONSTEXPR LagMember::LagMember(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct LagMemberDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LagMemberDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~LagMemberDefaultTypeInternal() {}
  union {
    LagMember _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LagMemberDefaultTypeInternal _LagMember_default_instance_;
}  // namespace Net
static ::_pb::Metadata file_level_metadata_lag_2eproto[4];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_lag_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_lag_2eproto = nullptr;
const ::uint32_t
    TableStruct_lag_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Net::LagInstance, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::LagInstance, _impl_.id_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Net::Port, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::Port, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::Net::LagMember, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::Net::LagMember, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::LagMember, _impl_.lag_),
        PROTOBUF_FIELD_OFFSET(::Net::LagMember, _impl_.members_),
        0,
        ~0u,
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Net::Result, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::Result, _impl_.error_message_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Net::LagInstance)},
        {9, -1, -1, sizeof(::Net::Port)},
        {18, 28, -1, sizeof(::Net::LagMember)},
        {30, -1, -1, sizeof(::Net::Result)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::Net::_LagInstance_default_instance_._instance,
    &::Net::_Port_default_instance_._instance,
    &::Net::_LagMember_default_instance_._instance,
    &::Net::_Result_default_instance_._instance,
};
const char descriptor_table_protodef_lag_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\tlag.proto\022\003Net\"\031\n\013LagInstance\022\n\n\002id\030\001 "
    "\001(\t\"\022\n\004Port\022\n\n\002id\030\001 \001(\t\"F\n\tLagMember\022\035\n\003"
    "lag\030\001 \001(\0132\020.Net.LagInstance\022\032\n\007members\030\002"
    " \003(\0132\t.Net.Port\"\037\n\006Result\022\025\n\rerror_messa"
    "ge\030\001 \001(\t2\314\001\n\rLagManagement\022,\n\tCreateLag\022"
    "\020.Net.LagInstance\032\013.Net.Result\"\000\022,\n\tDele"
    "teLag\022\020.Net.LagInstance\032\013.Net.Result\"\000\022-"
    "\n\014AddLagMember\022\016.Net.LagMember\032\013.Net.Res"
    "ult\"\000\0220\n\017RemoveLagMember\022\016.Net.LagMember"
    "\032\013.Net.Result\"\000b\006proto3"
};
static ::absl::once_flag descriptor_table_lag_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_lag_2eproto = {
    false,
    false,
    383,
    descriptor_table_protodef_lag_2eproto,
    "lag.proto",
    &descriptor_table_lag_2eproto_once,
    nullptr,
    0,
    4,
    schemas,
    file_default_instances,
    TableStruct_lag_2eproto::offsets,
    file_level_metadata_lag_2eproto,
    file_level_enum_descriptors_lag_2eproto,
    file_level_service_descriptors_lag_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_lag_2eproto_getter() {
  return &descriptor_table_lag_2eproto;
}
namespace Net {
// ===================================================================

class LagInstance::_Internal {
 public:
};

LagInstance::LagInstance(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.LagInstance)
}
inline PROTOBUF_NDEBUG_INLINE LagInstance::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : id_(arena, from.id_),
        _cached_size_{0} {}

LagInstance::LagInstance(
    ::google::protobuf::Arena* arena,
    const LagInstance& from)
    : ::google::protobuf::Message(arena) {
  LagInstance* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:Net.LagInstance)
}
inline PROTOBUF_NDEBUG_INLINE LagInstance::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : id_(arena),
        _cached_size_{0} {}

inline void LagInstance::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
LagInstance::~LagInstance() {
  // @@protoc_insertion_point(destructor:Net.LagInstance)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void LagInstance::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.id_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
LagInstance::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(LagInstance, _impl_._cached_size_),
              false,
          },
          &LagInstance::MergeImpl,
          &LagInstance::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void LagInstance::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.LagInstance)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.id_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* LagInstance::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 26, 2> LagInstance::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_LagInstance_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::LagInstance>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(LagInstance, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string id = 1;
    {PROTOBUF_FIELD_OFFSET(LagInstance, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\17\2\0\0\0\0\0\0"
    "Net.LagInstance"
    "id"
  }},
};

::uint8_t* LagInstance::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.LagInstance)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    const std::string& _s = this->_internal_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Net.LagInstance.id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.LagInstance)
  return target;
}

::size_t LagInstance::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.LagInstance)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void LagInstance::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<LagInstance*>(&to_msg);
  auto& from = static_cast<const LagInstance&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.LagInstance)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void LagInstance::CopyFrom(const LagInstance& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.LagInstance)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool LagInstance::IsInitialized() const {
  return true;
}

void LagInstance::InternalSwap(LagInstance* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.id_, &other->_impl_.id_, arena);
}

::google::protobuf::Metadata LagInstance::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_lag_2eproto_getter,
                                   &descriptor_table_lag_2eproto_once,
                                   file_level_metadata_lag_2eproto[0]);
}
// ===================================================================

class Port::_Internal {
 public:
};

Port::Port(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.Port)
}
inline PROTOBUF_NDEBUG_INLINE Port::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : id_(arena, from.id_),
        _cached_size_{0} {}

Port::Port(
    ::google::protobuf::Arena* arena,
    const Port& from)
    : ::google::protobuf::Message(arena) {
  Port* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:Net.Port)
}
inline PROTOBUF_NDEBUG_INLINE Port::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : id_(arena),
        _cached_size_{0} {}

inline void Port::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Port::~Port() {
  // @@protoc_insertion_point(destructor:Net.Port)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Port::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.id_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Port::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Port, _impl_._cached_size_),
              false,
          },
          &Port::MergeImpl,
          &Port::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Port::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.Port)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.id_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Port::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 19, 2> Port::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Port_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::Port>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Port, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string id = 1;
    {PROTOBUF_FIELD_OFFSET(Port, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\10\2\0\0\0\0\0\0"
    "Net.Port"
    "id"
  }},
};

::uint8_t* Port::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.Port)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    const std::string& _s = this->_internal_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Net.Port.id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.Port)
  return target;
}

::size_t Port::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.Port)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Port::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Port*>(&to_msg);
  auto& from = static_cast<const Port&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.Port)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Port::CopyFrom(const Port& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.Port)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Port::IsInitialized() const {
  return true;
}

void Port::InternalSwap(Port* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.id_, &other->_impl_.id_, arena);
}

::google::protobuf::Metadata Port::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_lag_2eproto_getter,
                                   &descriptor_table_lag_2eproto_once,
                                   file_level_metadata_lag_2eproto[1]);
}
// ===================================================================

class LagMember::_Internal {
 public:
  using HasBits = decltype(std::declval<LagMember>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(LagMember, _impl_._has_bits_);
};

LagMember::LagMember(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.LagMember)
}
inline PROTOBUF_NDEBUG_INLINE LagMember::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        members_{visibility, arena, from.members_} {}

LagMember::LagMember(
    ::google::protobuf::Arena* arena,
    const LagMember& from)
    : ::google::protobuf::Message(arena) {
  LagMember* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.lag_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::Net::LagInstance>(
                              arena, *from._impl_.lag_)
                        : nullptr;

  // @@protoc_insertion_point(copy_constructor:Net.LagMember)
}
inline PROTOBUF_NDEBUG_INLINE LagMember::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        members_{visibility, arena} {}

inline void LagMember::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.lag_ = {};
}
LagMember::~LagMember() {
  // @@protoc_insertion_point(destructor:Net.LagMember)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void LagMember::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  delete _impl_.lag_;
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
LagMember::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(LagMember, _impl_._cached_size_),
              false,
          },
          &LagMember::MergeImpl,
          &LagMember::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void LagMember::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.LagMember)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.members_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.lag_ != nullptr);
    _impl_.lag_->Clear();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* LagMember::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 2, 0, 2> LagMember::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(LagMember, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_LagMember_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::LagMember>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .Net.Port members = 2;
    {::_pbi::TcParser::FastMtR1,
     {18, 63, 1, PROTOBUF_FIELD_OFFSET(LagMember, _impl_.members_)}},
    // .Net.LagInstance lag = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(LagMember, _impl_.lag_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .Net.LagInstance lag = 1;
    {PROTOBUF_FIELD_OFFSET(LagMember, _impl_.lag_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .Net.Port members = 2;
    {PROTOBUF_FIELD_OFFSET(LagMember, _impl_.members_), -1, 1,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::Net::LagInstance>()},
    {::_pbi::TcParser::GetTable<::Net::Port>()},
  }}, {{
  }},
};

::uint8_t* LagMember::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.LagMember)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // .Net.LagInstance lag = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        1, *_impl_.lag_, _impl_.lag_->GetCachedSize(), target, stream);
  }

  // repeated .Net.Port members = 2;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_members_size());
       i < n; i++) {
    const auto& repfield = this->_internal_members().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            2, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.LagMember)
  return target;
}

::size_t LagMember::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.LagMember)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Net.Port members = 2;
  total_size += 1UL * this->_internal_members_size();
  for (const auto& msg : this->_internal_members()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // .Net.LagInstance lag = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.lag_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void LagMember::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<LagMember*>(&to_msg);
  auto& from = static_cast<const LagMember&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.LagMember)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_members()->MergeFrom(
      from._internal_members());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(from._impl_.lag_ != nullptr);
    if (_this->_impl_.lag_ == nullptr) {
      _this->_impl_.lag_ =
          ::google::protobuf::Message::CopyConstruct<::Net::LagInstance>(arena, *from._impl_.lag_);
    } else {
      _this->_impl_.lag_->MergeFrom(*from._impl_.lag_);
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void LagMember::CopyFrom(const LagMember& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.LagMember)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool LagMember::IsInitialized() const {
  return true;
}

void LagMember::InternalSwap(LagMember* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.members_.InternalSwap(&other->_impl_.members_);
  swap(_impl_.lag_, other->_impl_.lag_);
}

::google::protobuf::Metadata LagMember::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_lag_2eproto_getter,
                                   &descriptor_table_lag_2eproto_once,
                                   file_level_metadata_lag_2eproto[2]);
}
// ===================================================================

class Result::_Internal {
 public:
};

Result::Result(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.Result)
}
inline PROTOBUF_NDEBUG_INLINE Result::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : error_message_(arena, from.error_message_),
        _cached_size_{0} {}

Result::Result(
    ::google::protobuf::Arena* arena,
    const Result& from)
    : ::google::protobuf::Message(arena) {
  Result* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:Net.Result)
}
inline PROTOBUF_NDEBUG_INLINE Result::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : error_message_(arena),
        _cached_size_{0} {}

inline void Result::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Result::~Result() {
  // @@protoc_insertion_point(destructor:Net.Result)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Result::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.error_message_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Result::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Result, _impl_._cached_size_),
              false,
          },
          &Result::MergeImpl,
          &Result::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Result::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.Result)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.error_message_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Result::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 32, 2> Result::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Result_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::Result>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string error_message = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Result, _impl_.error_message_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string error_message = 1;
    {PROTOBUF_FIELD_OFFSET(Result, _impl_.error_message_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\12\15\0\0\0\0\0\0"
    "Net.Result"
    "error_message"
  }},
};

::uint8_t* Result::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.Result)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string error_message = 1;
  if (!this->_internal_error_message().empty()) {
    const std::string& _s = this->_internal_error_message();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Net.Result.error_message");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.Result)
  return target;
}

::size_t Result::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.Result)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string error_message = 1;
  if (!this->_internal_error_message().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_error_message());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Result::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Result*>(&to_msg);
  auto& from = static_cast<const Result&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.Result)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_error_message().empty()) {
    _this->_internal_set_error_message(from._internal_error_message());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Result::CopyFrom(const Result& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.Result)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Result::IsInitialized() const {
  return true;
}

void Result::InternalSwap(Result* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.error_message_, &other->_impl_.error_message_, arena);
}

::google::protobuf::Metadata Result::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_lag_2eproto_getter,
                                   &descriptor_table_lag_2eproto_once,
                                   file_level_metadata_lag_2eproto[3]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace Net
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_lag_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"