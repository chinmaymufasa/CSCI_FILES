#include<cassert>
#include<iostream>
#include<iomanip>
#include<stdexcept>
#include "Nausea.h"

int Nausea::serial_counter=1;
Nausea::throw_where Nausea::type=Nausea::nowhere;
unsigned int Nausea::trigger=0;

Nausea::~Nausea()
{
  std::cerr << "X";
#ifndef NOIDS
  std::cerr  << '<' << std::setw(2) << std::setfill('0');
  std::cerr << serial_number << '>';
  std::cerr << std::setfill(' ');
#endif

  delete fake_data;
}

Nausea::Nausea(const Nausea& arg) : serial_number(serial_counter++), progenitor(arg.serial_number)
{
  if(type==copy_ctor && --trigger==0)
  {
    std::cerr << "c";
    --serial_counter;
  }
  else
    std::cerr << "C";
#ifndef NOIDS
  assert(progenitor>=0);
  std::cerr << "<" << std::setw(2) << std::setfill('0');
  if(type==copy_ctor && trigger==0)
    std::cerr << "..";
  else
    std::cerr << serial_number;
  std::cerr << '-' << std::setw(2);
  std::cerr << progenitor << '>';
  std::cerr << std::setfill(' ');
#endif
  if(type==copy_ctor && trigger==0)
    throw std::runtime_error("Copy ctor thrown");
  fake_data=new int;
}

Nausea::Nausea() :  serial_number(serial_counter++), progenitor(-1)
{
  if(type==default_ctor && --trigger==0)
  {
      std::cerr << "d";
      --serial_counter;
  }
  else 
    std::cerr << "D";
#ifndef NOIDS
  std::cerr << "<" << std::setw(2) << std::setfill('0');
  if(type==default_ctor && trigger==0)
    std::cerr << "..";
  else
    std::cerr << serial_number;
  std::cerr << '>' << std::setfill(' ');
#endif
  if(type==default_ctor && trigger==0)
    throw std::runtime_error("Default ctor thrown");
  fake_data=new int;
}

Nausea& Nausea::operator=(const Nausea& arg)
{
  if(this==&arg)
    return *this;
  progenitor=arg.serial_number;
  if(type==assignment_op && --trigger==0)
    std::cerr << "a";
  else
    std::cerr << "A";
#ifndef NOIDS
  assert(progenitor>=0);
  std::cerr << "<" << std::setw(2) << std::setfill('0');
  std::cerr << serial_number << '-' << std::setw(2);
  std::cerr << progenitor << '>';
  std::cerr << std::setfill(' ');
#endif
  if(type==assignment_op && trigger==0)
    throw std::runtime_error("Assignment operator thrown");
  assert(fake_data!=nullptr); //catches uninitialized memory
  delete fake_data; //will segfault if memory is not initialized
  fake_data=new int(*arg.fake_data);
  return *this;
}
