#include "Report.h"

#include<iostream>
#include<iomanip>
using namespace std;

//copy constructor
Report::Report(const Report& arg)
  : rep_date(arg.rep_date), rep_time(arg.rep_time), rep_desc(arg.rep_desc)
{
  cerr << "Report: Copy ctor" << endl;
}

// constructor with 6 arguments to create a report
Report::Report(int day, int month, int year, int hour, int minute, std::string desc)
  : rep_date(month, day, year), rep_time(hour, minute), rep_desc(desc)
{

}
// write Report's display function
void Report::display() const{
  rep_date.display();
  rep_time.display();
  cout << "Report description: " << rep_desc << endl;
}