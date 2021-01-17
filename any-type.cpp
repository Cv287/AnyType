//
//  any-type.cpp
//  AnyType
//
//  Created by Олег Куколев on 17.01.2021.
//

#include "any-type.hpp"

void AnyType::ValidateTypeOrRaise(DataType castDataType) const {
  if (dataType != castDataType) {
    std::ostringstream os;
    os << "Unable to cast from " << ToString(dataType);
    os << " to " << ToString(castDataType);
    throw std::runtime_error{ os.str() };
  }
}

#define DT_CASE(datatype)  \
case datatype:             \
  return #datatype;        \
  break;

const char* AnyType::ToString(DataType dt) {
  switch (dt) {
    DT_CASE(DataType::Bool)
    DT_CASE(DataType::Int)
    DT_CASE(DataType::LongInt)
    DT_CASE(DataType::Double)
    DT_CASE(DataType::UnsignedLongInt)
    DT_CASE(DataType::LongDouble)
    DT_CASE(DataType::Char)
    DT_CASE(DataType::UnsignedChar)
    DT_CASE(DataType::UnsignedInt)
    DT_CASE(DataType::Float)
    DT_CASE(DataType::None)
    default:
      [](){}();
  }
}

AnyType::AnyType() : dataType{ DataType::None } {

}

AnyType::DataType AnyType::GetDataType() const {
  return dataType;
}

void AnyType::Clear() {
  dataType = DataType::None;
}

bool AnyType::ToBool() const {
  ValidateTypeOrRaise(DataType::Bool);
  return value.m_bool;
}

char AnyType::ToChar() const {
  ValidateTypeOrRaise(DataType::Char);
  return value.m_char;
}

unsigned char AnyType::ToUnsignedChar() const {
  ValidateTypeOrRaise(DataType::UnsignedChar);
  return value.m_uchar;
}

int AnyType::ToInt() const {
  ValidateTypeOrRaise(DataType::Int);
  return value.m_int;
}

unsigned AnyType::ToUnsignedInt() const {
  ValidateTypeOrRaise(DataType::UnsignedInt);
  return value.m_uint;
}

long int AnyType::ToLongInt() const {
  ValidateTypeOrRaise(DataType::LongInt);
  return value.m_lint;
}

unsigned long int AnyType::ToUnsignedLongInt() const {
  ValidateTypeOrRaise(DataType::UnsignedLongInt);
  return value.m_ulint;
}

float AnyType::ToFloat() const {
  ValidateTypeOrRaise(DataType::Float);
  return value.m_float;
}

double AnyType::ToDouble() const {
  ValidateTypeOrRaise(DataType::Double);
  return value.m_double;
}

long double AnyType::ToLongDouble() const {
  ValidateTypeOrRaise(DataType::LongDouble);
  return value.m_ldouble;
};
