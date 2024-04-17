// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: interface.proto
// Protobuf C++ Version: 5.26.1

#include "interface.pb.h"

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

inline constexpr Iface::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        type_{static_cast< ::Net::IfaceType >(0)},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Iface::Iface(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct IfaceDefaultTypeInternal {
  PROTOBUF_CONSTEXPR IfaceDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~IfaceDefaultTypeInternal() {}
  union {
    Iface _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 IfaceDefaultTypeInternal _Iface_default_instance_;
}  // namespace Net
static ::_pb::Metadata file_level_metadata_interface_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_interface_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_interface_2eproto = nullptr;
const ::uint32_t
    TableStruct_interface_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Net::Iface, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Net::Iface, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::Net::Iface, _impl_.type_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Net::Iface)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::Net::_Iface_default_instance_._instance,
};
const char descriptor_table_protodef_interface_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\017interface.proto\022\003Net\"1\n\005Iface\022\n\n\002id\030\001 "
    "\001(\t\022\034\n\004type\030\002 \001(\0162\016.Net.IfaceType*\032\n\tIfa"
    "ceType\022\r\n\tIFACE_ETH\020\000b\006proto3"
};
static ::absl::once_flag descriptor_table_interface_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_interface_2eproto = {
    false,
    false,
    109,
    descriptor_table_protodef_interface_2eproto,
    "interface.proto",
    &descriptor_table_interface_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_interface_2eproto::offsets,
    file_level_metadata_interface_2eproto,
    file_level_enum_descriptors_interface_2eproto,
    file_level_service_descriptors_interface_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_interface_2eproto_getter() {
  return &descriptor_table_interface_2eproto;
}
namespace Net {
const ::google::protobuf::EnumDescriptor* IfaceType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_interface_2eproto);
  return file_level_enum_descriptors_interface_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t IfaceType_internal_data_[] = {
    65536u, 0u, };
bool IfaceType_IsValid(int value) {
  return 0 <= value && value <= 0;
}
// ===================================================================

class Iface::_Internal {
 public:
};

Iface::Iface(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Net.Iface)
}
inline PROTOBUF_NDEBUG_INLINE Iface::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : id_(arena, from.id_),
        _cached_size_{0} {}

Iface::Iface(
    ::google::protobuf::Arena* arena,
    const Iface& from)
    : ::google::protobuf::Message(arena) {
  Iface* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.type_ = from._impl_.type_;

  // @@protoc_insertion_point(copy_constructor:Net.Iface)
}
inline PROTOBUF_NDEBUG_INLINE Iface::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : id_(arena),
        _cached_size_{0} {}

inline void Iface::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.type_ = {};
}
Iface::~Iface() {
  // @@protoc_insertion_point(destructor:Net.Iface)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Iface::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.id_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Iface::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Iface, _impl_._cached_size_),
              false,
          },
          &Iface::MergeImpl,
          &Iface::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Iface::Clear() {
// @@protoc_insertion_point(message_clear_start:Net.Iface)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.id_.ClearToEmpty();
  _impl_.type_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Iface::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 20, 2> Iface::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Iface_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Net::Iface>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // .Net.IfaceType type = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Iface, _impl_.type_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(Iface, _impl_.type_)}},
    // string id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Iface, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string id = 1;
    {PROTOBUF_FIELD_OFFSET(Iface, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // .Net.IfaceType type = 2;
    {PROTOBUF_FIELD_OFFSET(Iface, _impl_.type_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
  }},
  // no aux_entries
  {{
    "\11\2\0\0\0\0\0\0"
    "Net.Iface"
    "id"
  }},
};

::uint8_t* Iface::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Net.Iface)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    const std::string& _s = this->_internal_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Net.Iface.id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // .Net.IfaceType type = 2;
  if (this->_internal_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        2, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Net.Iface)
  return target;
}

::size_t Iface::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Net.Iface)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (!this->_internal_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_id());
  }

  // .Net.IfaceType type = 2;
  if (this->_internal_type() != 0) {
    total_size += 1 +
                  ::_pbi::WireFormatLite::EnumSize(this->_internal_type());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Iface::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Iface*>(&to_msg);
  auto& from = static_cast<const Iface&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Net.Iface)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _this->_internal_set_id(from._internal_id());
  }
  if (from._internal_type() != 0) {
    _this->_impl_.type_ = from._impl_.type_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Iface::CopyFrom(const Iface& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Net.Iface)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Iface::IsInitialized() const {
  return true;
}

void Iface::InternalSwap(Iface* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.id_, &other->_impl_.id_, arena);
  swap(_impl_.type_, other->_impl_.type_);
}

::google::protobuf::Metadata Iface::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_interface_2eproto_getter,
                                   &descriptor_table_interface_2eproto_once,
                                   file_level_metadata_interface_2eproto[0]);
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
    (::_pbi::AddDescriptors(&descriptor_table_interface_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"