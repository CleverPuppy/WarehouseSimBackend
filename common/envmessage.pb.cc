// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: envmessage.proto

#include "envmessage.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace warehousesim {
class EnvSetupRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EnvSetupRequest> _instance;
} _EnvSetupRequest_default_instance_;
class EnvSetupResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EnvSetupResponse> _instance;
} _EnvSetupResponse_default_instance_;
}  // namespace warehousesim
static void InitDefaultsscc_info_EnvSetupRequest_envmessage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::warehousesim::_EnvSetupRequest_default_instance_;
    new (ptr) ::warehousesim::EnvSetupRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::warehousesim::EnvSetupRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EnvSetupRequest_envmessage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_EnvSetupRequest_envmessage_2eproto}, {}};

static void InitDefaultsscc_info_EnvSetupResponse_envmessage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::warehousesim::_EnvSetupResponse_default_instance_;
    new (ptr) ::warehousesim::EnvSetupResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::warehousesim::EnvSetupResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EnvSetupResponse_envmessage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_EnvSetupResponse_envmessage_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_envmessage_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_envmessage_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_envmessage_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_envmessage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, block_width_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, block_height_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, scale_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, project_id_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, obs_blocks_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupRequest, rack_blocks_),
  0,
  1,
  3,
  2,
  ~0u,
  ~0u,
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupResponse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupResponse, status_),
  PROTOBUF_FIELD_OFFSET(::warehousesim::EnvSetupResponse, project_id_),
  1,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::warehousesim::EnvSetupRequest)},
  { 17, 24, sizeof(::warehousesim::EnvSetupResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::warehousesim::_EnvSetupRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::warehousesim::_EnvSetupResponse_default_instance_),
};

const char descriptor_table_protodef_envmessage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020envmessage.proto\022\014warehousesim\"\210\001\n\017Env"
  "SetupRequest\022\023\n\013block_width\030\001 \001(\005\022\024\n\014blo"
  "ck_height\030\002 \001(\005\022\r\n\005scale\030\003 \001(\005\022\022\n\nprojec"
  "t_id\030\004 \001(\003\022\022\n\nobs_blocks\030\005 \003(\005\022\023\n\013rack_b"
  "locks\030\006 \003(\005\"T\n\020EnvSetupResponse\022,\n\006statu"
  "s\030\001 \002(\0162\034.warehousesim.EnvSetupStatus\022\022\n"
  "\nproject_id\030\002 \001(\003*9\n\023EnvSetupRequestType"
  "\022\n\n\006ATTACH\020\001\022\t\n\005CLEAR\020\002\022\013\n\007RETRIVE\020\003*)\n\016"
  "EnvSetupStatus\022\013\n\007SUCCESS\020\001\022\n\n\006FAILED\020\002"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_envmessage_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_envmessage_2eproto_sccs[2] = {
  &scc_info_EnvSetupRequest_envmessage_2eproto.base,
  &scc_info_EnvSetupResponse_envmessage_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_envmessage_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_envmessage_2eproto = {
  false, false, descriptor_table_protodef_envmessage_2eproto, "envmessage.proto", 359,
  &descriptor_table_envmessage_2eproto_once, descriptor_table_envmessage_2eproto_sccs, descriptor_table_envmessage_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_envmessage_2eproto::offsets,
  file_level_metadata_envmessage_2eproto, 2, file_level_enum_descriptors_envmessage_2eproto, file_level_service_descriptors_envmessage_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_envmessage_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_envmessage_2eproto)), true);
namespace warehousesim {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EnvSetupRequestType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_envmessage_2eproto);
  return file_level_enum_descriptors_envmessage_2eproto[0];
}
bool EnvSetupRequestType_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EnvSetupStatus_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_envmessage_2eproto);
  return file_level_enum_descriptors_envmessage_2eproto[1];
}
bool EnvSetupStatus_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void EnvSetupRequest::InitAsDefaultInstance() {
}
class EnvSetupRequest::_Internal {
 public:
  using HasBits = decltype(std::declval<EnvSetupRequest>()._has_bits_);
  static void set_has_block_width(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_block_height(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_scale(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_project_id(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

EnvSetupRequest::EnvSetupRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  obs_blocks_(arena),
  rack_blocks_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:warehousesim.EnvSetupRequest)
}
EnvSetupRequest::EnvSetupRequest(const EnvSetupRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      obs_blocks_(from.obs_blocks_),
      rack_blocks_(from.rack_blocks_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&block_width_, &from.block_width_,
    static_cast<size_t>(reinterpret_cast<char*>(&scale_) -
    reinterpret_cast<char*>(&block_width_)) + sizeof(scale_));
  // @@protoc_insertion_point(copy_constructor:warehousesim.EnvSetupRequest)
}

void EnvSetupRequest::SharedCtor() {
  ::memset(&block_width_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&scale_) -
      reinterpret_cast<char*>(&block_width_)) + sizeof(scale_));
}

EnvSetupRequest::~EnvSetupRequest() {
  // @@protoc_insertion_point(destructor:warehousesim.EnvSetupRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void EnvSetupRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void EnvSetupRequest::ArenaDtor(void* object) {
  EnvSetupRequest* _this = reinterpret_cast< EnvSetupRequest* >(object);
  (void)_this;
}
void EnvSetupRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EnvSetupRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EnvSetupRequest& EnvSetupRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EnvSetupRequest_envmessage_2eproto.base);
  return *internal_default_instance();
}


void EnvSetupRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:warehousesim.EnvSetupRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  obs_blocks_.Clear();
  rack_blocks_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    ::memset(&block_width_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&scale_) -
        reinterpret_cast<char*>(&block_width_)) + sizeof(scale_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EnvSetupRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 block_width = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_block_width(&has_bits);
          block_width_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 block_height = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_block_height(&has_bits);
          block_height_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 scale = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_scale(&has_bits);
          scale_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 project_id = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_project_id(&has_bits);
          project_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated int32 obs_blocks = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          ptr -= 1;
          do {
            ptr += 1;
            _internal_add_obs_blocks(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<40>(ptr));
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_obs_blocks(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated int32 rack_blocks = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          ptr -= 1;
          do {
            ptr += 1;
            _internal_add_rack_blocks(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<48>(ptr));
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_rack_blocks(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EnvSetupRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:warehousesim.EnvSetupRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 block_width = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_block_width(), target);
  }

  // optional int32 block_height = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_block_height(), target);
  }

  // optional int32 scale = 3;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_scale(), target);
  }

  // optional int64 project_id = 4;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_project_id(), target);
  }

  // repeated int32 obs_blocks = 5;
  for (int i = 0, n = this->_internal_obs_blocks_size(); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(5, this->_internal_obs_blocks(i), target);
  }

  // repeated int32 rack_blocks = 6;
  for (int i = 0, n = this->_internal_rack_blocks_size(); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(6, this->_internal_rack_blocks(i), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:warehousesim.EnvSetupRequest)
  return target;
}

size_t EnvSetupRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:warehousesim.EnvSetupRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 obs_blocks = 5;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->obs_blocks_);
    total_size += 1 *
                  ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_obs_blocks_size());
    total_size += data_size;
  }

  // repeated int32 rack_blocks = 6;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->rack_blocks_);
    total_size += 1 *
                  ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_rack_blocks_size());
    total_size += data_size;
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional int32 block_width = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_block_width());
    }

    // optional int32 block_height = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_block_height());
    }

    // optional int64 project_id = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_project_id());
    }

    // optional int32 scale = 3;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_scale());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EnvSetupRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:warehousesim.EnvSetupRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const EnvSetupRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EnvSetupRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:warehousesim.EnvSetupRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:warehousesim.EnvSetupRequest)
    MergeFrom(*source);
  }
}

void EnvSetupRequest::MergeFrom(const EnvSetupRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:warehousesim.EnvSetupRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  obs_blocks_.MergeFrom(from.obs_blocks_);
  rack_blocks_.MergeFrom(from.rack_blocks_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      block_width_ = from.block_width_;
    }
    if (cached_has_bits & 0x00000002u) {
      block_height_ = from.block_height_;
    }
    if (cached_has_bits & 0x00000004u) {
      project_id_ = from.project_id_;
    }
    if (cached_has_bits & 0x00000008u) {
      scale_ = from.scale_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void EnvSetupRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:warehousesim.EnvSetupRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EnvSetupRequest::CopyFrom(const EnvSetupRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:warehousesim.EnvSetupRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EnvSetupRequest::IsInitialized() const {
  return true;
}

void EnvSetupRequest::InternalSwap(EnvSetupRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  obs_blocks_.InternalSwap(&other->obs_blocks_);
  rack_blocks_.InternalSwap(&other->rack_blocks_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(EnvSetupRequest, scale_)
      + sizeof(EnvSetupRequest::scale_)
      - PROTOBUF_FIELD_OFFSET(EnvSetupRequest, block_width_)>(
          reinterpret_cast<char*>(&block_width_),
          reinterpret_cast<char*>(&other->block_width_));
}

::PROTOBUF_NAMESPACE_ID::Metadata EnvSetupRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void EnvSetupResponse::InitAsDefaultInstance() {
}
class EnvSetupResponse::_Internal {
 public:
  using HasBits = decltype(std::declval<EnvSetupResponse>()._has_bits_);
  static void set_has_status(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_project_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000002) ^ 0x00000002) != 0;
  }
};

EnvSetupResponse::EnvSetupResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:warehousesim.EnvSetupResponse)
}
EnvSetupResponse::EnvSetupResponse(const EnvSetupResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&project_id_, &from.project_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&status_) -
    reinterpret_cast<char*>(&project_id_)) + sizeof(status_));
  // @@protoc_insertion_point(copy_constructor:warehousesim.EnvSetupResponse)
}

void EnvSetupResponse::SharedCtor() {
  project_id_ = PROTOBUF_LONGLONG(0);
  status_ = 1;
}

EnvSetupResponse::~EnvSetupResponse() {
  // @@protoc_insertion_point(destructor:warehousesim.EnvSetupResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void EnvSetupResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void EnvSetupResponse::ArenaDtor(void* object) {
  EnvSetupResponse* _this = reinterpret_cast< EnvSetupResponse* >(object);
  (void)_this;
}
void EnvSetupResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EnvSetupResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EnvSetupResponse& EnvSetupResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EnvSetupResponse_envmessage_2eproto.base);
  return *internal_default_instance();
}


void EnvSetupResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:warehousesim.EnvSetupResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    project_id_ = PROTOBUF_LONGLONG(0);
    status_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EnvSetupResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .warehousesim.EnvSetupStatus status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::warehousesim::EnvSetupStatus_IsValid(val))) {
            _internal_set_status(static_cast<::warehousesim::EnvSetupStatus>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional int64 project_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_project_id(&has_bits);
          project_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EnvSetupResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:warehousesim.EnvSetupResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .warehousesim.EnvSetupStatus status = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_status(), target);
  }

  // optional int64 project_id = 2;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->_internal_project_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:warehousesim.EnvSetupResponse)
  return target;
}

size_t EnvSetupResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:warehousesim.EnvSetupResponse)
  size_t total_size = 0;

  // required .warehousesim.EnvSetupStatus status = 1;
  if (_internal_has_status()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_status());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional int64 project_id = 2;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_project_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EnvSetupResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:warehousesim.EnvSetupResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const EnvSetupResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EnvSetupResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:warehousesim.EnvSetupResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:warehousesim.EnvSetupResponse)
    MergeFrom(*source);
  }
}

void EnvSetupResponse::MergeFrom(const EnvSetupResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:warehousesim.EnvSetupResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      project_id_ = from.project_id_;
    }
    if (cached_has_bits & 0x00000002u) {
      status_ = from.status_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void EnvSetupResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:warehousesim.EnvSetupResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EnvSetupResponse::CopyFrom(const EnvSetupResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:warehousesim.EnvSetupResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EnvSetupResponse::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void EnvSetupResponse::InternalSwap(EnvSetupResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(project_id_, other->project_id_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata EnvSetupResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace warehousesim
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::warehousesim::EnvSetupRequest* Arena::CreateMaybeMessage< ::warehousesim::EnvSetupRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::warehousesim::EnvSetupRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::warehousesim::EnvSetupResponse* Arena::CreateMaybeMessage< ::warehousesim::EnvSetupResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::warehousesim::EnvSetupResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>