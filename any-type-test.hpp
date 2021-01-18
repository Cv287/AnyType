//
//  Header.h
//  AnyType
//
//  Created by Олег Куколев on 18.01.2021.
//

#ifndef any_type_test_h
#define any_type_test_h

#include <gtest/gtest.h>
#include "any-type.hpp"

/* If we pass a value of user-defined type to this constructor
 then compilation error will be caused, so we don't do this here. */
TEST(ConstructorTest, TakesFundamentalType) {
  AnyType any1{ 3.2 };
  ASSERT_EQ("DataType::Double", any1.GetDataType());
  
  AnyType any2{ false };
  ASSERT_EQ("DataType::Bool", any2.GetDataType());
}

TEST(ConstructorTest, CopyConstructor) {
  AnyType any1{ 1 };
  AnyType any2{ any1 };
  ASSERT_EQ(any1, any2);
  
  // long long is unsupported
  AnyType any3{ 13ll };
  AnyType any4{ any3 };
  ASSERT_EQ(any3, any4);
}

TEST(DatatypeCastTest, CastToBool) {
  AnyType any{ false };
  ASSERT_EQ(false, any.ToBool());
  ASSERT_ANY_THROW(any.ToDouble());
}

TEST(DatatypeCastTest, CastToChar) {
  AnyType any{ 'a' };
  ASSERT_EQ('a', any.ToChar());
  ASSERT_ANY_THROW(any.ToInt());
}

TEST(DatatypeCastTest, CastToInt) {
  AnyType any{ 1 };
  ASSERT_EQ(1, any.ToInt());
  ASSERT_ANY_THROW(any.ToDouble());
}

TEST(DatatypeCastTest, CastToFloat) {
  AnyType any{ 1.f };
  ASSERT_EQ(1.f, any.ToFloat());
  ASSERT_ANY_THROW(any.ToDouble());
}

TEST(DatatypeCastTest, CastToDouble) {
  AnyType any{ 1.0 };
  ASSERT_EQ(1.0, any.ToDouble());
  ASSERT_ANY_THROW(any.ToFloat());
}

TEST(DatatypeCastTest, CastToLongDouble) {
  AnyType any{ 1.3l };
  ASSERT_EQ(1.3l, any.ToLongDouble());
  ASSERT_ANY_THROW(any.ToDouble());
}

TEST(DatatypeCastTest, CastToUnsigned) {
  AnyType any{ 1u };
  ASSERT_EQ(1u, any.ToUnsignedInt());
  ASSERT_ANY_THROW(any.ToInt());
}

#endif /* any_type_test_h */
