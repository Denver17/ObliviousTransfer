// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NonInteractiveOT.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_NonInteractiveOT_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_NonInteractiveOT_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_NonInteractiveOT_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_NonInteractiveOT_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_NonInteractiveOT_2eproto;
namespace NonInteractiveOT {
class Param;
struct ParamDefaultTypeInternal;
extern ParamDefaultTypeInternal _Param_default_instance_;
class Reply;
struct ReplyDefaultTypeInternal;
extern ReplyDefaultTypeInternal _Reply_default_instance_;
}  // namespace NonInteractiveOT
PROTOBUF_NAMESPACE_OPEN
template <>
::NonInteractiveOT::Param* Arena::CreateMaybeMessage<::NonInteractiveOT::Param>(Arena*);
template <>
::NonInteractiveOT::Reply* Arena::CreateMaybeMessage<::NonInteractiveOT::Reply>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace NonInteractiveOT {

// ===================================================================


// -------------------------------------------------------------------

class Param final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:NonInteractiveOT.Param) */ {
 public:
  inline Param() : Param(nullptr) {}
  ~Param() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Param(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Param(const Param& from);
  Param(Param&& from) noexcept
    : Param() {
    *this = ::std::move(from);
  }

  inline Param& operator=(const Param& from) {
    CopyFrom(from);
    return *this;
  }
  inline Param& operator=(Param&& from) noexcept {
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
  static const Param& default_instance() {
    return *internal_default_instance();
  }
  static inline const Param* internal_default_instance() {
    return reinterpret_cast<const Param*>(
               &_Param_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Param& a, Param& b) {
    a.Swap(&b);
  }
  inline void Swap(Param* other) {
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
  void UnsafeArenaSwap(Param* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Param* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Param>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Param& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Param& from) {
    Param::MergeImpl(*this, from);
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
  void InternalSwap(Param* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "NonInteractiveOT.Param";
  }
  protected:
  explicit Param(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAlpha0FieldNumber = 1,
    kAlpha1FieldNumber = 2,
    kR0FieldNumber = 3,
    kR1FieldNumber = 4,
  };
  // string alpha0 = 1;
  void clear_alpha0() ;
  const std::string& alpha0() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_alpha0(Arg_&& arg, Args_... args);
  std::string* mutable_alpha0();
  PROTOBUF_NODISCARD std::string* release_alpha0();
  void set_allocated_alpha0(std::string* ptr);

  private:
  const std::string& _internal_alpha0() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_alpha0(
      const std::string& value);
  std::string* _internal_mutable_alpha0();

  public:
  // string alpha1 = 2;
  void clear_alpha1() ;
  const std::string& alpha1() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_alpha1(Arg_&& arg, Args_... args);
  std::string* mutable_alpha1();
  PROTOBUF_NODISCARD std::string* release_alpha1();
  void set_allocated_alpha1(std::string* ptr);

  private:
  const std::string& _internal_alpha1() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_alpha1(
      const std::string& value);
  std::string* _internal_mutable_alpha1();

  public:
  // string r0 = 3;
  void clear_r0() ;
  const std::string& r0() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_r0(Arg_&& arg, Args_... args);
  std::string* mutable_r0();
  PROTOBUF_NODISCARD std::string* release_r0();
  void set_allocated_r0(std::string* ptr);

  private:
  const std::string& _internal_r0() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_r0(
      const std::string& value);
  std::string* _internal_mutable_r0();

  public:
  // string r1 = 4;
  void clear_r1() ;
  const std::string& r1() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_r1(Arg_&& arg, Args_... args);
  std::string* mutable_r1();
  PROTOBUF_NODISCARD std::string* release_r1();
  void set_allocated_r1(std::string* ptr);

  private:
  const std::string& _internal_r1() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_r1(
      const std::string& value);
  std::string* _internal_mutable_r1();

  public:
  // @@protoc_insertion_point(class_scope:NonInteractiveOT.Param)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr alpha0_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr alpha1_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr r0_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr r1_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_NonInteractiveOT_2eproto;
};// -------------------------------------------------------------------

class Reply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:NonInteractiveOT.Reply) */ {
 public:
  inline Reply() : Reply(nullptr) {}
  ~Reply() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Reply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Reply(const Reply& from);
  Reply(Reply&& from) noexcept
    : Reply() {
    *this = ::std::move(from);
  }

  inline Reply& operator=(const Reply& from) {
    CopyFrom(from);
    return *this;
  }
  inline Reply& operator=(Reply&& from) noexcept {
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
  static const Reply& default_instance() {
    return *internal_default_instance();
  }
  static inline const Reply* internal_default_instance() {
    return reinterpret_cast<const Reply*>(
               &_Reply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Reply& a, Reply& b) {
    a.Swap(&b);
  }
  inline void Swap(Reply* other) {
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
  void UnsafeArenaSwap(Reply* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Reply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Reply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Reply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Reply& from) {
    Reply::MergeImpl(*this, from);
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
  void InternalSwap(Reply* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "NonInteractiveOT.Reply";
  }
  protected:
  explicit Reply(::PROTOBUF_NAMESPACE_ID::Arena* arena);
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
  // @@protoc_insertion_point(class_scope:NonInteractiveOT.Reply)
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
  friend struct ::TableStruct_NonInteractiveOT_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Param

// string alpha0 = 1;
inline void Param::clear_alpha0() {
  _impl_.alpha0_.ClearToEmpty();
}
inline const std::string& Param::alpha0() const {
  // @@protoc_insertion_point(field_get:NonInteractiveOT.Param.alpha0)
  return _internal_alpha0();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Param::set_alpha0(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.alpha0_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:NonInteractiveOT.Param.alpha0)
}
inline std::string* Param::mutable_alpha0() {
  std::string* _s = _internal_mutable_alpha0();
  // @@protoc_insertion_point(field_mutable:NonInteractiveOT.Param.alpha0)
  return _s;
}
inline const std::string& Param::_internal_alpha0() const {
  return _impl_.alpha0_.Get();
}
inline void Param::_internal_set_alpha0(const std::string& value) {
  ;


  _impl_.alpha0_.Set(value, GetArenaForAllocation());
}
inline std::string* Param::_internal_mutable_alpha0() {
  ;
  return _impl_.alpha0_.Mutable( GetArenaForAllocation());
}
inline std::string* Param::release_alpha0() {
  // @@protoc_insertion_point(field_release:NonInteractiveOT.Param.alpha0)
  return _impl_.alpha0_.Release();
}
inline void Param::set_allocated_alpha0(std::string* value) {
  _impl_.alpha0_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.alpha0_.IsDefault()) {
          _impl_.alpha0_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:NonInteractiveOT.Param.alpha0)
}

// string alpha1 = 2;
inline void Param::clear_alpha1() {
  _impl_.alpha1_.ClearToEmpty();
}
inline const std::string& Param::alpha1() const {
  // @@protoc_insertion_point(field_get:NonInteractiveOT.Param.alpha1)
  return _internal_alpha1();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Param::set_alpha1(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.alpha1_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:NonInteractiveOT.Param.alpha1)
}
inline std::string* Param::mutable_alpha1() {
  std::string* _s = _internal_mutable_alpha1();
  // @@protoc_insertion_point(field_mutable:NonInteractiveOT.Param.alpha1)
  return _s;
}
inline const std::string& Param::_internal_alpha1() const {
  return _impl_.alpha1_.Get();
}
inline void Param::_internal_set_alpha1(const std::string& value) {
  ;


  _impl_.alpha1_.Set(value, GetArenaForAllocation());
}
inline std::string* Param::_internal_mutable_alpha1() {
  ;
  return _impl_.alpha1_.Mutable( GetArenaForAllocation());
}
inline std::string* Param::release_alpha1() {
  // @@protoc_insertion_point(field_release:NonInteractiveOT.Param.alpha1)
  return _impl_.alpha1_.Release();
}
inline void Param::set_allocated_alpha1(std::string* value) {
  _impl_.alpha1_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.alpha1_.IsDefault()) {
          _impl_.alpha1_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:NonInteractiveOT.Param.alpha1)
}

// string r0 = 3;
inline void Param::clear_r0() {
  _impl_.r0_.ClearToEmpty();
}
inline const std::string& Param::r0() const {
  // @@protoc_insertion_point(field_get:NonInteractiveOT.Param.r0)
  return _internal_r0();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Param::set_r0(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.r0_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:NonInteractiveOT.Param.r0)
}
inline std::string* Param::mutable_r0() {
  std::string* _s = _internal_mutable_r0();
  // @@protoc_insertion_point(field_mutable:NonInteractiveOT.Param.r0)
  return _s;
}
inline const std::string& Param::_internal_r0() const {
  return _impl_.r0_.Get();
}
inline void Param::_internal_set_r0(const std::string& value) {
  ;


  _impl_.r0_.Set(value, GetArenaForAllocation());
}
inline std::string* Param::_internal_mutable_r0() {
  ;
  return _impl_.r0_.Mutable( GetArenaForAllocation());
}
inline std::string* Param::release_r0() {
  // @@protoc_insertion_point(field_release:NonInteractiveOT.Param.r0)
  return _impl_.r0_.Release();
}
inline void Param::set_allocated_r0(std::string* value) {
  _impl_.r0_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.r0_.IsDefault()) {
          _impl_.r0_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:NonInteractiveOT.Param.r0)
}

// string r1 = 4;
inline void Param::clear_r1() {
  _impl_.r1_.ClearToEmpty();
}
inline const std::string& Param::r1() const {
  // @@protoc_insertion_point(field_get:NonInteractiveOT.Param.r1)
  return _internal_r1();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Param::set_r1(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.r1_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:NonInteractiveOT.Param.r1)
}
inline std::string* Param::mutable_r1() {
  std::string* _s = _internal_mutable_r1();
  // @@protoc_insertion_point(field_mutable:NonInteractiveOT.Param.r1)
  return _s;
}
inline const std::string& Param::_internal_r1() const {
  return _impl_.r1_.Get();
}
inline void Param::_internal_set_r1(const std::string& value) {
  ;


  _impl_.r1_.Set(value, GetArenaForAllocation());
}
inline std::string* Param::_internal_mutable_r1() {
  ;
  return _impl_.r1_.Mutable( GetArenaForAllocation());
}
inline std::string* Param::release_r1() {
  // @@protoc_insertion_point(field_release:NonInteractiveOT.Param.r1)
  return _impl_.r1_.Release();
}
inline void Param::set_allocated_r1(std::string* value) {
  _impl_.r1_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.r1_.IsDefault()) {
          _impl_.r1_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:NonInteractiveOT.Param.r1)
}

// -------------------------------------------------------------------

// Reply

// string message = 1;
inline void Reply::clear_message() {
  _impl_.message_.ClearToEmpty();
}
inline const std::string& Reply::message() const {
  // @@protoc_insertion_point(field_get:NonInteractiveOT.Reply.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Reply::set_message(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:NonInteractiveOT.Reply.message)
}
inline std::string* Reply::mutable_message() {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:NonInteractiveOT.Reply.message)
  return _s;
}
inline const std::string& Reply::_internal_message() const {
  return _impl_.message_.Get();
}
inline void Reply::_internal_set_message(const std::string& value) {
  ;


  _impl_.message_.Set(value, GetArenaForAllocation());
}
inline std::string* Reply::_internal_mutable_message() {
  ;
  return _impl_.message_.Mutable( GetArenaForAllocation());
}
inline std::string* Reply::release_message() {
  // @@protoc_insertion_point(field_release:NonInteractiveOT.Reply.message)
  return _impl_.message_.Release();
}
inline void Reply::set_allocated_message(std::string* value) {
  _impl_.message_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:NonInteractiveOT.Reply.message)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace NonInteractiveOT


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_NonInteractiveOT_2eproto_2epb_2eh
