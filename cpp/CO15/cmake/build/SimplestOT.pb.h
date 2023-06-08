// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SimplestOT.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_SimplestOT_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_SimplestOT_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4023000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4023001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_SimplestOT_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_SimplestOT_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_SimplestOT_2eproto;
namespace SimplestOT {
class ARequest;
struct ARequestDefaultTypeInternal;
extern ARequestDefaultTypeInternal _ARequest_default_instance_;
class BReply;
struct BReplyDefaultTypeInternal;
extern BReplyDefaultTypeInternal _BReply_default_instance_;
class CTReply;
struct CTReplyDefaultTypeInternal;
extern CTReplyDefaultTypeInternal _CTReply_default_instance_;
class CTRequest;
struct CTRequestDefaultTypeInternal;
extern CTRequestDefaultTypeInternal _CTRequest_default_instance_;
}  // namespace SimplestOT
PROTOBUF_NAMESPACE_OPEN
template <>
::SimplestOT::ARequest* Arena::CreateMaybeMessage<::SimplestOT::ARequest>(Arena*);
template <>
::SimplestOT::BReply* Arena::CreateMaybeMessage<::SimplestOT::BReply>(Arena*);
template <>
::SimplestOT::CTReply* Arena::CreateMaybeMessage<::SimplestOT::CTReply>(Arena*);
template <>
::SimplestOT::CTRequest* Arena::CreateMaybeMessage<::SimplestOT::CTRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace SimplestOT {

// ===================================================================


// -------------------------------------------------------------------

class ARequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SimplestOT.ARequest) */ {
 public:
  inline ARequest() : ARequest(nullptr) {}
  ~ARequest() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ARequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ARequest(const ARequest& from);
  ARequest(ARequest&& from) noexcept
    : ARequest() {
    *this = ::std::move(from);
  }

  inline ARequest& operator=(const ARequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline ARequest& operator=(ARequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ARequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const ARequest* internal_default_instance() {
    return reinterpret_cast<const ARequest*>(
               &_ARequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ARequest& a, ARequest& b) {
    a.Swap(&b);
  }
  inline void Swap(ARequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ARequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ARequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ARequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ARequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ARequest& from) {
    ARequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ARequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "SimplestOT.ARequest";
  }
  protected:
  explicit ARequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAFieldNumber = 1,
  };
  // string A = 1;
  void clear_a() ;
  const std::string& a() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_a(Arg_&& arg, Args_... args);
  std::string* mutable_a();
  PROTOBUF_NODISCARD std::string* release_a();
  void set_allocated_a(std::string* ptr);

  private:
  const std::string& _internal_a() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_a(
      const std::string& value);
  std::string* _internal_mutable_a();

  public:
  // @@protoc_insertion_point(class_scope:SimplestOT.ARequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr a_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_SimplestOT_2eproto;
};// -------------------------------------------------------------------

class CTRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SimplestOT.CTRequest) */ {
 public:
  inline CTRequest() : CTRequest(nullptr) {}
  ~CTRequest() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR CTRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CTRequest(const CTRequest& from);
  CTRequest(CTRequest&& from) noexcept
    : CTRequest() {
    *this = ::std::move(from);
  }

  inline CTRequest& operator=(const CTRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline CTRequest& operator=(CTRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CTRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const CTRequest* internal_default_instance() {
    return reinterpret_cast<const CTRequest*>(
               &_CTRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(CTRequest& a, CTRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(CTRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CTRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CTRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CTRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CTRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const CTRequest& from) {
    CTRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CTRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "SimplestOT.CTRequest";
  }
  protected:
  explicit CTRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCtFieldNumber = 1,
  };
  // bytes ct = 1;
  void clear_ct() ;
  const std::string& ct() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_ct(Arg_&& arg, Args_... args);
  std::string* mutable_ct();
  PROTOBUF_NODISCARD std::string* release_ct();
  void set_allocated_ct(std::string* ptr);

  private:
  const std::string& _internal_ct() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ct(
      const std::string& value);
  std::string* _internal_mutable_ct();

  public:
  // @@protoc_insertion_point(class_scope:SimplestOT.CTRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ct_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_SimplestOT_2eproto;
};// -------------------------------------------------------------------

class BReply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SimplestOT.BReply) */ {
 public:
  inline BReply() : BReply(nullptr) {}
  ~BReply() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR BReply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BReply(const BReply& from);
  BReply(BReply&& from) noexcept
    : BReply() {
    *this = ::std::move(from);
  }

  inline BReply& operator=(const BReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline BReply& operator=(BReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const BReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const BReply* internal_default_instance() {
    return reinterpret_cast<const BReply*>(
               &_BReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(BReply& a, BReply& b) {
    a.Swap(&b);
  }
  inline void Swap(BReply* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BReply* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  BReply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<BReply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const BReply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const BReply& from) {
    BReply::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BReply* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "SimplestOT.BReply";
  }
  protected:
  explicit BReply(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBFieldNumber = 1,
  };
  // string B = 1;
  void clear_b() ;
  const std::string& b() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_b(Arg_&& arg, Args_... args);
  std::string* mutable_b();
  PROTOBUF_NODISCARD std::string* release_b();
  void set_allocated_b(std::string* ptr);

  private:
  const std::string& _internal_b() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_b(
      const std::string& value);
  std::string* _internal_mutable_b();

  public:
  // @@protoc_insertion_point(class_scope:SimplestOT.BReply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr b_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_SimplestOT_2eproto;
};// -------------------------------------------------------------------

class CTReply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SimplestOT.CTReply) */ {
 public:
  inline CTReply() : CTReply(nullptr) {}
  ~CTReply() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR CTReply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CTReply(const CTReply& from);
  CTReply(CTReply&& from) noexcept
    : CTReply() {
    *this = ::std::move(from);
  }

  inline CTReply& operator=(const CTReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline CTReply& operator=(CTReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CTReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const CTReply* internal_default_instance() {
    return reinterpret_cast<const CTReply*>(
               &_CTReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(CTReply& a, CTReply& b) {
    a.Swap(&b);
  }
  inline void Swap(CTReply* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CTReply* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CTReply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CTReply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CTReply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const CTReply& from) {
    CTReply::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CTReply* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "SimplestOT.CTReply";
  }
  protected:
  explicit CTReply(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 1,
  };
  // string message = 1;
  void clear_message() ;
  const std::string& message() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_message(Arg_&& arg, Args_... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* ptr);

  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(
      const std::string& value);
  std::string* _internal_mutable_message();

  public:
  // @@protoc_insertion_point(class_scope:SimplestOT.CTReply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_SimplestOT_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ARequest

// string A = 1;
inline void ARequest::clear_a() {
  _impl_.a_.ClearToEmpty();
}
inline const std::string& ARequest::a() const {
  // @@protoc_insertion_point(field_get:SimplestOT.ARequest.A)
  return _internal_a();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void ARequest::set_a(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.a_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SimplestOT.ARequest.A)
}
inline std::string* ARequest::mutable_a() {
  std::string* _s = _internal_mutable_a();
  // @@protoc_insertion_point(field_mutable:SimplestOT.ARequest.A)
  return _s;
}
inline const std::string& ARequest::_internal_a() const {
  return _impl_.a_.Get();
}
inline void ARequest::_internal_set_a(const std::string& value) {
  ;


  _impl_.a_.Set(value, GetArenaForAllocation());
}
inline std::string* ARequest::_internal_mutable_a() {
  ;
  return _impl_.a_.Mutable( GetArenaForAllocation());
}
inline std::string* ARequest::release_a() {
  // @@protoc_insertion_point(field_release:SimplestOT.ARequest.A)
  return _impl_.a_.Release();
}
inline void ARequest::set_allocated_a(std::string* value) {
  _impl_.a_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.a_.IsDefault()) {
          _impl_.a_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SimplestOT.ARequest.A)
}

// -------------------------------------------------------------------

// CTRequest

// bytes ct = 1;
inline void CTRequest::clear_ct() {
  _impl_.ct_.ClearToEmpty();
}
inline const std::string& CTRequest::ct() const {
  // @@protoc_insertion_point(field_get:SimplestOT.CTRequest.ct)
  return _internal_ct();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void CTRequest::set_ct(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.ct_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SimplestOT.CTRequest.ct)
}
inline std::string* CTRequest::mutable_ct() {
  std::string* _s = _internal_mutable_ct();
  // @@protoc_insertion_point(field_mutable:SimplestOT.CTRequest.ct)
  return _s;
}
inline const std::string& CTRequest::_internal_ct() const {
  return _impl_.ct_.Get();
}
inline void CTRequest::_internal_set_ct(const std::string& value) {
  ;


  _impl_.ct_.Set(value, GetArenaForAllocation());
}
inline std::string* CTRequest::_internal_mutable_ct() {
  ;
  return _impl_.ct_.Mutable( GetArenaForAllocation());
}
inline std::string* CTRequest::release_ct() {
  // @@protoc_insertion_point(field_release:SimplestOT.CTRequest.ct)
  return _impl_.ct_.Release();
}
inline void CTRequest::set_allocated_ct(std::string* value) {
  _impl_.ct_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.ct_.IsDefault()) {
          _impl_.ct_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SimplestOT.CTRequest.ct)
}

// -------------------------------------------------------------------

// BReply

// string B = 1;
inline void BReply::clear_b() {
  _impl_.b_.ClearToEmpty();
}
inline const std::string& BReply::b() const {
  // @@protoc_insertion_point(field_get:SimplestOT.BReply.B)
  return _internal_b();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void BReply::set_b(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.b_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SimplestOT.BReply.B)
}
inline std::string* BReply::mutable_b() {
  std::string* _s = _internal_mutable_b();
  // @@protoc_insertion_point(field_mutable:SimplestOT.BReply.B)
  return _s;
}
inline const std::string& BReply::_internal_b() const {
  return _impl_.b_.Get();
}
inline void BReply::_internal_set_b(const std::string& value) {
  ;


  _impl_.b_.Set(value, GetArenaForAllocation());
}
inline std::string* BReply::_internal_mutable_b() {
  ;
  return _impl_.b_.Mutable( GetArenaForAllocation());
}
inline std::string* BReply::release_b() {
  // @@protoc_insertion_point(field_release:SimplestOT.BReply.B)
  return _impl_.b_.Release();
}
inline void BReply::set_allocated_b(std::string* value) {
  _impl_.b_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.b_.IsDefault()) {
          _impl_.b_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SimplestOT.BReply.B)
}

// -------------------------------------------------------------------

// CTReply

// string message = 1;
inline void CTReply::clear_message() {
  _impl_.message_.ClearToEmpty();
}
inline const std::string& CTReply::message() const {
  // @@protoc_insertion_point(field_get:SimplestOT.CTReply.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void CTReply::set_message(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SimplestOT.CTReply.message)
}
inline std::string* CTReply::mutable_message() {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:SimplestOT.CTReply.message)
  return _s;
}
inline const std::string& CTReply::_internal_message() const {
  return _impl_.message_.Get();
}
inline void CTReply::_internal_set_message(const std::string& value) {
  ;


  _impl_.message_.Set(value, GetArenaForAllocation());
}
inline std::string* CTReply::_internal_mutable_message() {
  ;
  return _impl_.message_.Mutable( GetArenaForAllocation());
}
inline std::string* CTReply::release_message() {
  // @@protoc_insertion_point(field_release:SimplestOT.CTReply.message)
  return _impl_.message_.Release();
}
inline void CTReply::set_allocated_message(std::string* value) {
  _impl_.message_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SimplestOT.CTReply.message)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace SimplestOT


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_SimplestOT_2eproto_2epb_2eh