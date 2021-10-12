#include<iostream>
#include<stdexcept>
#include "Nausea.h"

int main()
{

  Nausea::type=Nausea::default_ctor;
  Nausea::trigger=15;

  try {
  Nausea* np=new Nausea[30];
  }
  catch(std::exception& e){
    std::cout << e.what() << std::endl;
  }
  return 0;
}
