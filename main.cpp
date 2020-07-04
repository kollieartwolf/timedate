#include <iostream>
#include <fstream>
#include "timedate.h"

int main()
{
  TimeDate td(3, 7, 2020, 1, 37, 35);
  td.printByTemplate("MM/YY/DD");
  std::ofstream f("file.txt");
  f << td.fillTemplate("MM/YY/DD HH:MI:SS");
  f.close();
  TimeDate td2(td);
  td2.setHours(2);
  td2.setMinutes(5);
  td2.setSeconds(16);
  td2.printByTemplate("HH:MI:SS");
  return 0;
}
