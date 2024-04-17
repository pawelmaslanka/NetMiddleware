// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vlan.proto
// Protobuf C++ Version: 5.26.1

#include "vlan.pb.h"

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

inline constexpr VlanInstance::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR VlanInstance::VlanInstance(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct VlanInstanceDefaultTypeInternal {
  PROTOBUF_CONSTEXPR VlanInstanceDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~VlanInstanceDefaultTypeInternal() {}
  union {
    VlanInstance _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 VlanInstanceDefaultTypeInternal _VlanInstance_default_instance_;

inline constexpr VlanMember::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        members_{},
        lag_{nullptr} {}

template <typename>
PROTOBUF_CONSTEXPR VlanMember::VlanMember(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct VlanMemberDefaultTypeInternal {
  PROTOBUF_CONSTEXPR VlanMemberDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~VlanMemberDefaultTypeInternal() {}
  union {
    VlanMember _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 VlanMemberDefaultTypeInternal _VlanMember_default_instance_;
}  // namespace Net
static ::_pb::Metadata file_level_metadata_vlan_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_vlan_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_vlan_2eproto = nullptr;
const ::uint32_t
    TableStruct_vlan_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Net::VlanInstance, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::VlanInstance, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::Net::VlanMember, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::Net::VlanMember, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::VlanMember, _impl_.lag_),
        PROTOBUF_FIELD_OFFSET(::Net::VlanMember, _impl_.members_),
        0,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Net::VlanInstance)},
        {9, 19, -1, sizeof(::Net::VlanMember)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::Net::_VlanInstance_default_instance_._instance,
    &::Net::_VlanMember_default_instance_._instance,
};
const char descriptor_table_protodef_vlan_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\nvlan.proto\022\003Net\032\014common.proto\032\nport.pr"
    "oto\"\032\n\014VlanInstance\022\n\n\002id\030\001 \001(\t\"H\n\nVlanM"
    "ember\022\036\n\003lag\030\001 \001(\0132\021.Net.VlanInstance\022\032\n"
    "\007members\030\002 \003(\0132\t.Net.Port2\325\001\n\016VlanManage"
    "ment\022.\n\nCreateVlan\022\021.Net.VlanInstance\032\013."
    "Net.Result\"\000\022.\n\nDeleteVlan\022\021.Net.VlanIns"
    "tance\032\013.Net.Result\"\000\022/\n\rAddVlanMember\022\017."
    "Net.VlanMember\032\013.Net.Result\"\000\0222\n\020RemoveV"
    "lanMember\022\017.Net.VlanMember\032\013.Net.Result\""
    "\000b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_vlan_2eproto_deps[2] =
    {
        &::descriptor_table_common_2eproto,
        &::descriptor_table_port_2eproto,
};
static ::absl::once_flag descriptor_table_vlan_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_vlan_2eproto = {
    false,
    false,
    369,
    descriptor_table_protodef_vlan_2eproto,
    "vlan.proto",
    &descriptor_table_vlan_2eproto_once,
    descriptor_table_vlan_2eproto_deps,
    2,
    2,
    schemas,
    file_default_instances,
    TableStruct_vlan_2eproto::offsets,
    file_level_metadata_vlan_2eproto,
    file_level_enum_descriptors_vlan_2eproto,
    file_level_service_descriptors_vlan_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_vlan_2eproto_getter() {
  return &descriptor_table_vlan_2eproto;
}
namespace Net {
// ===================================================================

class VlanInstance::_Internal {
 public:
};

VlanInstance::VlanInstance(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.VlanInstance)
}
inline PROTOBUF_NDEBUG_INLINE VlanInstance::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : id_(arena, from.id_),
        _cached_size_{0} {}

VlanInstance::VlanInstance(
    ::google::protobuf::Arena* arena,
    const VlanInstance& from)
    : ::google::protobuf::Message(arena) {
  VlanInstance* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:Net.VlanInstance)
}
inline PROTOBUF_NDEBUG_INLINE VlanInstance::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : id_(arena),
        _cached_size_{0} {}

inline void VlanInstance::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
VlanInstance::~VlanInstance() {
  // @@protoc_insertion_point(destructor:Net.VlanInstance)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void VlanInstance::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.id_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
VlanInstance::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(VlanInstance, _impl_._cached_size_),
              false,
          },
          &VlanInstance::MergeImpl,
          &VlanInstance::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void VlanInstance::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.VlanInstance)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.id_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* VlanInstance::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 27, 2> VlanInstance::_table_ = {
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
    &_VlanInstance_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::VlanInstance>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(VlanInstance, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string id = 1;
    {PROTOBUF_FIELD_OFFSET(VlanInstance, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\20\2\0\0\0\0\0\0"
    "Net.VlanInstance"
    "id"
  }},
};

::uint8_t* VlanInstance::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.VlanInstance)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    const std::string& _s = this->_internal_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Net.VlanInstance.id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.VlanInstance)
  return target;
}

::size_t VlanInstance::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.VlanInstance)
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


void VlanInstance::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<VlanInstance*>(&to_msg);
  auto& from = static_cast<const VlanInstance&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.VlanInstance)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void VlanInstance::CopyFrom(const VlanInstance& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.VlanInstance)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool VlanInstance::IsInitialized() const {
  return true;
}

void VlanInstance::InternalSwap(VlanInstance* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.id_, &other->_impl_.id_, arena);
}

::google::protobuf::Metadata VlanInstance::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_vlan_2eproto_getter,
                                   &descriptor_table_vlan_2eproto_once,
                                   file_level_metadata_vlan_2eproto[0]);
}
// ===================================================================

class VlanMember::_Internal {
 public:
  using HasBits = decltype(std::declval<VlanMember>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(VlanMember, _impl_._has_bits_);
};

void VlanMember::clear_members() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.members_.Clear();
}
VlanMember::VlanMember(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.VlanMember)
}
inline PROTOBUF_NDEBUG_INLINE VlanMember::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        members_{visibility, arena, from.members_} {}

VlanMember::VlanMember(
    ::google::protobuf::Arena* arena,
    const VlanMember& from)
    : ::google::protobuf::Message(arena) {
  VlanMember* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.lag_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::Net::VlanInstance>(
                              arena, *from._impl_.lag_)
                        : nullptr;

  // @@protoc_insertion_point(copy_constructor:Net.VlanMember)
}
inline PROTOBUF_NDEBUG_INLINE VlanMember::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        members_{visibility, arena} {}

inline void VlanMember::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.lag_ = {};
}
VlanMember::~VlanMember() {
  // @@protoc_insertion_point(destructor:Net.VlanMember)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void VlanMember::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  delete _impl_.lag_;
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
VlanMember::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(VlanMember, _impl_._cached_size_),
              false,
          },
          &VlanMember::MergeImpl,
          &VlanMember::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void VlanMember::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.VlanMember)
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

const char* VlanMember::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 2, 0, 2> VlanMember::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(VlanMember, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_VlanMember_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::VlanMember>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .Net.Port members = 2;
    {::_pbi::TcParser::FastMtR1,
     {18, 63, 1, PROTOBUF_FIELD_OFFSET(VlanMember, _impl_.members_)}},
    // .Net.VlanInstance lag = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(VlanMember, _impl_.lag_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .Net.VlanInstance lag = 1;
    {PROTOBUF_FIELD_OFFSET(VlanMember, _impl_.lag_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .Net.Port members = 2;
    {PROTOBUF_FIELD_OFFSET(VlanMember, _impl_.members_), -1, 1,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::Net::VlanInstance>()},
    {::_pbi::TcParser::GetTable<::Net::Port>()},
  }}, {{
  }},
};

::uint8_t* VlanMember::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.VlanMember)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // .Net.VlanInstance lag = 1;
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
  // @@protoc_insertion_point(serialize_to_array_end:Net.VlanMember)
  return target;
}

::size_t VlanMember::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.VlanMember)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Net.Port members = 2;
  total_size += 1UL * this->_internal_members_size();
  for (const auto& msg : this->_internal_members()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // .Net.VlanInstance lag = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.lag_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void VlanMember::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<VlanMember*>(&to_msg);
  auto& from = static_cast<const VlanMember&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.VlanMember)
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
          ::google::protobuf::Message::CopyConstruct<::Net::VlanInstance>(arena, *from._impl_.lag_);
    } else {
      _this->_impl_.lag_->MergeFrom(*from._impl_.lag_);
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void VlanMember::CopyFrom(const VlanMember& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.VlanMember)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool VlanMember::IsInitialized() const {
  return true;
}

void VlanMember::InternalSwap(VlanMember* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.members_.InternalSwap(&other->_impl_.members_);
  swap(_impl_.lag_, other->_impl_.lag_);
}

::google::protobuf::Metadata VlanMember::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_vlan_2eproto_getter,
                                   &descriptor_table_vlan_2eproto_once,
                                   file_level_metadata_vlan_2eproto[1]);
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
    (::_pbi::AddDescriptors(&descriptor_table_vlan_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"