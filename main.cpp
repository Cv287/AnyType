//
//  main.cpp
//  AnyType
//
//  Created by Олег Куколев on 06.01.2021.
//

#include <iostream>
#include <string>
#include "any-type.hpp"
#include "any-type-test.hpp"
using namespace std;

#define RUN_TESTS

int main(int argc, char * argv[]) {
#ifdef RUN_TESTS
  ::testing::InitGoogleTest(&argc, argv);
  [[maybe_unused]] const auto _ = RUN_ALL_TESTS();
#endif
  
  return EXIT_SUCCESS;
}
