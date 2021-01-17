//
//  any-type.hpp
//  AnyType
//
//  Created by Олег Куколев on 17.01.2021.
//

//
//  TEMPLATED METHODS IMPLEMENTATION
//

template <
    typename Integral,
    std::enable_if_t<std::is_integral<Integral>::value, int>
>
void AnyType::SetValue(const Integral& v) {
  if (std::is_same_v<Integral, bool>) {
    dataType = DataType::Bool;
    value.m_bool = v;
  }
  else if (std::is_signed<Integral>::value) {
    if (std::is_same_v<Integral, char>) {
      dataType = DataType::Char;
      value.m_char = v;
    }
    else if (std::is_same_v<Integral, int>) {
      dataType = DataType::Int;
      value.m_int = v;
    }
    else if (std::is_same_v<Integral, long int>) {
      dataType = DataType::LongInt;
      value.m_lint = v;
    }
  }
  else if (std::is_unsigned<Integral>::value) {
    if (std::is_same_v<Integral, unsigned char>) {
      dataType = DataType::UnsignedChar;
      value.m_uchar = v;
    }
    else if (std::is_same_v<Integral, unsigned int>) {
      dataType = DataType::UnsignedInt;
      value.m_uint = v;
    }
    else if (std::is_same_v<Integral, unsigned long int>) {
      dataType = DataType::UnsignedLongInt;
      value.m_ulint = v;
    }
  }
}

template <
    typename Floating,
    std::enable_if_t<std::is_floating_point<Floating>::value, int>
>
void AnyType::SetValue(const Floating& v) {
  if (std::is_same_v<Floating, float>) {
    dataType = DataType::Float;
    value.m_float = v;
  }
  else if (std::is_same_v<Floating, double>) {
    dataType = DataType::Double;
    value.m_double = v;
  }
  else if (std::is_same_v<Floating, long double>) {
    dataType = DataType::LongDouble;
    value.m_ldouble = v;
  }
}

template <typename FundamentalType>
AnyType::AnyType(const FundamentalType& value) {
  SetValue(value);
}

template <typename FundamentalType>
AnyType& AnyType::operator=(const FundamentalType& value) {
  SetValue(value);
  return *this;
}

template <typename FundamentalType>
AnyType& AnyType::operator=(FundamentalType&& value) {
  SetValue(value);
  return *this;
}
