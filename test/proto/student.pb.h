// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: student.proto

#ifndef PROTOBUF_INCLUDED_student_2eproto
#define PROTOBUF_INCLUDED_student_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_student_2eproto 

namespace protobuf_student_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_student_2eproto
namespace tutorial {
class Student;
class StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class Student_PhoneNumber;
class Student_PhoneNumberDefaultTypeInternal;
extern Student_PhoneNumberDefaultTypeInternal _Student_PhoneNumber_default_instance_;
}  // namespace tutorial
namespace google {
namespace protobuf {
template<> ::tutorial::Student* Arena::CreateMaybeMessage<::tutorial::Student>(Arena*);
template<> ::tutorial::Student_PhoneNumber* Arena::CreateMaybeMessage<::tutorial::Student_PhoneNumber>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace tutorial {

enum Student_PhoneType {
  Student_PhoneType_MOBILE = 0,
  Student_PhoneType_HOME = 1
};
bool Student_PhoneType_IsValid(int value);
const Student_PhoneType Student_PhoneType_PhoneType_MIN = Student_PhoneType_MOBILE;
const Student_PhoneType Student_PhoneType_PhoneType_MAX = Student_PhoneType_HOME;
const int Student_PhoneType_PhoneType_ARRAYSIZE = Student_PhoneType_PhoneType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Student_PhoneType_descriptor();
inline const ::std::string& Student_PhoneType_Name(Student_PhoneType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Student_PhoneType_descriptor(), value);
}
inline bool Student_PhoneType_Parse(
    const ::std::string& name, Student_PhoneType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Student_PhoneType>(
    Student_PhoneType_descriptor(), name, value);
}
// ===================================================================

class Student_PhoneNumber : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tutorial.Student.PhoneNumber) */ {
 public:
  Student_PhoneNumber();
  virtual ~Student_PhoneNumber();

  Student_PhoneNumber(const Student_PhoneNumber& from);

  inline Student_PhoneNumber& operator=(const Student_PhoneNumber& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Student_PhoneNumber(Student_PhoneNumber&& from) noexcept
    : Student_PhoneNumber() {
    *this = ::std::move(from);
  }

  inline Student_PhoneNumber& operator=(Student_PhoneNumber&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Student_PhoneNumber& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Student_PhoneNumber* internal_default_instance() {
    return reinterpret_cast<const Student_PhoneNumber*>(
               &_Student_PhoneNumber_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Student_PhoneNumber* other);
  friend void swap(Student_PhoneNumber& a, Student_PhoneNumber& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Student_PhoneNumber* New() const final {
    return CreateMaybeMessage<Student_PhoneNumber>(NULL);
  }

  Student_PhoneNumber* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Student_PhoneNumber>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Student_PhoneNumber& from);
  void MergeFrom(const Student_PhoneNumber& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student_PhoneNumber* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string number = 1;
  bool has_number() const;
  void clear_number();
  static const int kNumberFieldNumber = 1;
  const ::std::string& number() const;
  void set_number(const ::std::string& value);
  #if LANG_CXX11
  void set_number(::std::string&& value);
  #endif
  void set_number(const char* value);
  void set_number(const char* value, size_t size);
  ::std::string* mutable_number();
  ::std::string* release_number();
  void set_allocated_number(::std::string* number);

  // optional .tutorial.Student.PhoneType type = 2 [default = HOME];
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::tutorial::Student_PhoneType type() const;
  void set_type(::tutorial::Student_PhoneType value);

  // @@protoc_insertion_point(class_scope:tutorial.Student.PhoneNumber)
 private:
  void set_has_number();
  void clear_has_number();
  void set_has_type();
  void clear_has_type();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr number_;
  int type_;
  friend struct ::protobuf_student_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Student : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tutorial.Student) */ {
 public:
  Student();
  virtual ~Student();

  Student(const Student& from);

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(Student&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Student& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Student* other);
  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Student* New() const final {
    return CreateMaybeMessage<Student>(NULL);
  }

  Student* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Student& from);
  void MergeFrom(const Student& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Student_PhoneNumber PhoneNumber;

  typedef Student_PhoneType PhoneType;
  static const PhoneType MOBILE =
    Student_PhoneType_MOBILE;
  static const PhoneType HOME =
    Student_PhoneType_HOME;
  static inline bool PhoneType_IsValid(int value) {
    return Student_PhoneType_IsValid(value);
  }
  static const PhoneType PhoneType_MIN =
    Student_PhoneType_PhoneType_MIN;
  static const PhoneType PhoneType_MAX =
    Student_PhoneType_PhoneType_MAX;
  static const int PhoneType_ARRAYSIZE =
    Student_PhoneType_PhoneType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  PhoneType_descriptor() {
    return Student_PhoneType_descriptor();
  }
  static inline const ::std::string& PhoneType_Name(PhoneType value) {
    return Student_PhoneType_Name(value);
  }
  static inline bool PhoneType_Parse(const ::std::string& name,
      PhoneType* value) {
    return Student_PhoneType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // repeated .tutorial.Student.PhoneNumber phone = 4;
  int phone_size() const;
  void clear_phone();
  static const int kPhoneFieldNumber = 4;
  ::tutorial::Student_PhoneNumber* mutable_phone(int index);
  ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >*
      mutable_phone();
  const ::tutorial::Student_PhoneNumber& phone(int index) const;
  ::tutorial::Student_PhoneNumber* add_phone();
  const ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >&
      phone() const;

  // required string name = 2;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string email = 3;
  bool has_email() const;
  void clear_email();
  static const int kEmailFieldNumber = 3;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // required uint64 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:tutorial.Student)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_name();
  void clear_has_name();
  void set_has_email();
  void clear_has_email();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber > phone_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::uint64 id_;
  friend struct ::protobuf_student_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Student_PhoneNumber

// required string number = 1;
inline bool Student_PhoneNumber::has_number() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Student_PhoneNumber::set_has_number() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Student_PhoneNumber::clear_has_number() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Student_PhoneNumber::clear_number() {
  number_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_number();
}
inline const ::std::string& Student_PhoneNumber::number() const {
  // @@protoc_insertion_point(field_get:tutorial.Student.PhoneNumber.number)
  return number_.GetNoArena();
}
inline void Student_PhoneNumber::set_number(const ::std::string& value) {
  set_has_number();
  number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:tutorial.Student.PhoneNumber.number)
}
#if LANG_CXX11
inline void Student_PhoneNumber::set_number(::std::string&& value) {
  set_has_number();
  number_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:tutorial.Student.PhoneNumber.number)
}
#endif
inline void Student_PhoneNumber::set_number(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_number();
  number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:tutorial.Student.PhoneNumber.number)
}
inline void Student_PhoneNumber::set_number(const char* value, size_t size) {
  set_has_number();
  number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:tutorial.Student.PhoneNumber.number)
}
inline ::std::string* Student_PhoneNumber::mutable_number() {
  set_has_number();
  // @@protoc_insertion_point(field_mutable:tutorial.Student.PhoneNumber.number)
  return number_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Student_PhoneNumber::release_number() {
  // @@protoc_insertion_point(field_release:tutorial.Student.PhoneNumber.number)
  if (!has_number()) {
    return NULL;
  }
  clear_has_number();
  return number_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Student_PhoneNumber::set_allocated_number(::std::string* number) {
  if (number != NULL) {
    set_has_number();
  } else {
    clear_has_number();
  }
  number_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), number);
  // @@protoc_insertion_point(field_set_allocated:tutorial.Student.PhoneNumber.number)
}

// optional .tutorial.Student.PhoneType type = 2 [default = HOME];
inline bool Student_PhoneNumber::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Student_PhoneNumber::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Student_PhoneNumber::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Student_PhoneNumber::clear_type() {
  type_ = 1;
  clear_has_type();
}
inline ::tutorial::Student_PhoneType Student_PhoneNumber::type() const {
  // @@protoc_insertion_point(field_get:tutorial.Student.PhoneNumber.type)
  return static_cast< ::tutorial::Student_PhoneType >(type_);
}
inline void Student_PhoneNumber::set_type(::tutorial::Student_PhoneType value) {
  assert(::tutorial::Student_PhoneType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:tutorial.Student.PhoneNumber.type)
}

// -------------------------------------------------------------------

// Student

// required uint64 id = 1;
inline bool Student::has_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Student::set_has_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Student::clear_has_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Student::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 Student::id() const {
  // @@protoc_insertion_point(field_get:tutorial.Student.id)
  return id_;
}
inline void Student::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:tutorial.Student.id)
}

// required string name = 2;
inline bool Student::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Student::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Student::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Student::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Student::name() const {
  // @@protoc_insertion_point(field_get:tutorial.Student.name)
  return name_.GetNoArena();
}
inline void Student::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:tutorial.Student.name)
}
#if LANG_CXX11
inline void Student::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:tutorial.Student.name)
}
#endif
inline void Student::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:tutorial.Student.name)
}
inline void Student::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:tutorial.Student.name)
}
inline ::std::string* Student::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:tutorial.Student.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Student::release_name() {
  // @@protoc_insertion_point(field_release:tutorial.Student.name)
  if (!has_name()) {
    return NULL;
  }
  clear_has_name();
  return name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Student::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:tutorial.Student.name)
}

// optional string email = 3;
inline bool Student::has_email() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Student::set_has_email() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Student::clear_has_email() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Student::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_email();
}
inline const ::std::string& Student::email() const {
  // @@protoc_insertion_point(field_get:tutorial.Student.email)
  return email_.GetNoArena();
}
inline void Student::set_email(const ::std::string& value) {
  set_has_email();
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:tutorial.Student.email)
}
#if LANG_CXX11
inline void Student::set_email(::std::string&& value) {
  set_has_email();
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:tutorial.Student.email)
}
#endif
inline void Student::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_email();
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:tutorial.Student.email)
}
inline void Student::set_email(const char* value, size_t size) {
  set_has_email();
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:tutorial.Student.email)
}
inline ::std::string* Student::mutable_email() {
  set_has_email();
  // @@protoc_insertion_point(field_mutable:tutorial.Student.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Student::release_email() {
  // @@protoc_insertion_point(field_release:tutorial.Student.email)
  if (!has_email()) {
    return NULL;
  }
  clear_has_email();
  return email_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Student::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    set_has_email();
  } else {
    clear_has_email();
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:tutorial.Student.email)
}

// repeated .tutorial.Student.PhoneNumber phone = 4;
inline int Student::phone_size() const {
  return phone_.size();
}
inline void Student::clear_phone() {
  phone_.Clear();
}
inline ::tutorial::Student_PhoneNumber* Student::mutable_phone(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.Student.phone)
  return phone_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >*
Student::mutable_phone() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.Student.phone)
  return &phone_;
}
inline const ::tutorial::Student_PhoneNumber& Student::phone(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.Student.phone)
  return phone_.Get(index);
}
inline ::tutorial::Student_PhoneNumber* Student::add_phone() {
  // @@protoc_insertion_point(field_add:tutorial.Student.phone)
  return phone_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::tutorial::Student_PhoneNumber >&
Student::phone() const {
  // @@protoc_insertion_point(field_list:tutorial.Student.phone)
  return phone_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tutorial

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::tutorial::Student_PhoneType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::tutorial::Student_PhoneType>() {
  return ::tutorial::Student_PhoneType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_student_2eproto
