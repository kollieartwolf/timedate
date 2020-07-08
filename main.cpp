#include "timedate.h"
#include "structs.h"
#include <fstream>
#include <iostream>

int main() {
  TimeDate today({7, 7, 2020}, {11, 45, 19});
  cout << today.get_formatted("Now is HH:MI, today is DD.MM, YYYY.") << endl;
  if (!today.set_day(32))
    cout << "It's impossible to set day 32." << endl;
  if (!today.set_minutes(94))
    cout << "And to set minutes 94. Y'all know why." << endl;
  cout << "Attempt to write date and time in file \"datetime.txt\"." << endl;
  ofstream file("datetime.txt");
  file << today.get_formatted("DD.MM.YYYY HH:MI:SS");
  file.close();
  TimeDate someday(TimeDate::get_date_from_string("07.07.2021", "DD.MM.YYYY"),
                   today.time());
  cout << someday.get_formatted("And someday is HH:MI, DD.MM, YY. Of course!")
       << endl;
  return 0;
}
