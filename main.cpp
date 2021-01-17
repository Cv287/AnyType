//
//  main.cpp
//  AnyType
//
//  Created by Олег Куколев on 06.01.2021.
//

#include <iostream>
#include <string>
#include "any-type.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
  
  AnyType any{ 3.2 };
  
  AnyType any2 = any;

  try {
    cout << any.ToFloat() << endl;
  } catch (const runtime_error& ex) {
    cerr << "Handled exception: " << ex.what() << endl;
  }

  cout << any2.ToDouble() << endl;
  
  return EXIT_SUCCESS;
}
