//
//  any-type.hpp
//  AnyType
//
//  Created by Олег Куколев on 06.01.2021.
//

#ifndef any_type_hpp
#define any_type_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <typeinfo>

//
//  The main idea is that we can store fundamental type values
//  via constructors and assignment operators and then cast it.
//  Exception (std::runtime_error) raises if there's type mismatch.
//
//  The list of supported fundamental types:
//    * bool, char, int, unsigned int, long int, unsigned long int,
//    * float, double, long double, char, unsigned char
//

class AnyType {
  /* dataType contains value corresponding to value stored in union.
   Can be used as watchlist of supported fundamental types. */
  enum class DataType {
    None, Bool, Int, LongInt, Double, UnsignedLongInt,
    LongDouble, Char, UnsignedChar, UnsignedInt, Float,
  } dataType;
  
  /* The main data is stored here. */
  union {
    bool m_bool;
    char m_char;
    unsigned char m_uchar;
    int m_int;
    unsigned int m_uint;
    long int m_lint;
    unsigned long int m_ulint;
    float m_float;
    double m_double;
    long double m_ldouble;
  } value;

private /* methods */:
  /* Raise an exception std::runtime_error if dataType != castDataType */
  void ValidateTypeOrRaise(DataType castDataType) const;
  
  /*--------------------------------------------------------------------------
   SetValue<T> is the most important asset in this class.
   Built on the SFINAE principle.
   It takes a fundamental type value as an argument and
   causes substitution failure if it's
   not included in the list of supported types.
   This function template is used in constructors and assignment operators (AO).
   If we'll pass a value of an non-fundamental type to a constructor or AO then
   compilation error will be caused.
   */
  template <typename Integral,
            std::enable_if_t<std::is_integral<Integral>::value, int> = 0
  >
  void SetValue(const Integral& v);
  
  template <typename Floating,
            std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0
  >
  void SetValue(const Floating& v);
  /*--------------------------------------------------------------------------*/

private /* static methods */:
  /* Takes DataType enum variable as an argument,
   converts it to c-string and returns it. */
  static const char* ToString(DataType dt);

public:
  /* Constructors and assignment operators take fundamental type values
   as arguments. Compilation error will be caused if value isn't fundamental. */
  /*---------------Constructors---------------*/
  AnyType();
  
  template <typename FundamentalType>
  AnyType(const FundamentalType& value);

  AnyType(const AnyType& other) = default;

  AnyType(AnyType&& other) = default;
  /*------------------------------------------*/
  /* //////////////////////////////////////// */
  /*-----------Assignment operators-----------*/
  AnyType& operator=(const AnyType& other) = default;
  
  AnyType& operator=(AnyType&& other) = default;

  template <typename FundamentalType>
  AnyType& operator=(const FundamentalType& value);
  
  template <typename FundamentalType>
  AnyType& operator=(FundamentalType&& value);
  /*------------------------------------------*/
  
  /* Returns current data type. */
  std::string GetDataType() const;
  /* Sets current data type (in enum) to None.
   It means all casts will raise an exception. */
  void Clear();
  
  /* Different cast methods. */
  bool ToBool() const;
  char ToChar() const;
  unsigned char ToUnsignedChar() const;
  int ToInt() const;
  unsigned ToUnsignedInt() const;
  long int ToLongInt() const;
  unsigned long int ToUnsignedLongInt() const;
  float ToFloat() const;
  double ToDouble() const;
  long double ToLongDouble() const;
  
  friend int main(int argc, const char*argv[]);
};

#include "any-type.inl"

#endif /* any_type_hpp */
