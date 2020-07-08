#ifndef DATETIME_H
#define DATETIME_H

#include "structs.h"
#include <iostream>
#include <string>

using namespace std;

class TimeDate {
public:
  TimeDate() {}
  TimeDate(const TimeDate &date_time);
  TimeDate(const Date &date, const Time &time);
  unsigned short get_day() const;
  unsigned short get_month() const;
  unsigned short get_year() const;
  unsigned short get_hours() const;
  unsigned short get_minutes() const;
  unsigned short get_seconds() const;
  bool set_day(unsigned short day);
  bool set_month(unsigned short month);
  bool set_year(int year);
  bool set_hours(unsigned short hours);
  bool set_minutes(unsigned short minutes);
  bool set_seconds(unsigned short seconds);
  void print(const string &format) const;
  static bool check(const Date &date, const Time &time);
  unsigned short current_time() const;
  string get_formatted(const string &format) const;
  Date date() const;
  Time time() const;
  static Date get_date_from_string(const string &str, const string &format);

private:
  Date _date{1, 1, 0};
  Time _time{0, 0, 0};
  static string replace(const string &str, const string &format,
                        const string &data);
};

inline unsigned short TimeDate::get_day() const { return _date.day; }
inline unsigned short TimeDate::get_month() const { return _date.month; }
inline unsigned short TimeDate::get_year() const { return _date.year; }
inline unsigned short TimeDate::get_hours() const { return _time.hours; }
inline unsigned short TimeDate::get_minutes() const { return _time.minutes; }
inline unsigned short TimeDate::get_seconds() const { return _time.seconds; }

inline bool TimeDate::set_day(unsigned short day) {
  if (!TimeDate::check({day, _date.month, _date.year}, _time))
    return false;
  _date.day = day;
  return true;
}

inline bool TimeDate::set_month(unsigned short month) {
  if (!TimeDate::check({_date.day, month, _date.year}, _time))
    return false;
  _date.month = month;
  return true;
}

inline bool TimeDate::set_year(int year) {
  if (!TimeDate::check({_date.day, _date.month, year}, _time))
    return false;
  _date.year = year;
  return true;
}

inline bool TimeDate::set_hours(unsigned short hours) {
  if (!TimeDate::check(_date, {hours, _time.minutes, _time.seconds}))
    return false;
  _time.hours = hours;
  return true;
}

inline bool TimeDate::set_minutes(unsigned short minutes) {
  if (!TimeDate::check(_date, {_time.hours, minutes, _time.seconds}))
    return false;
  _time.minutes = minutes;
  return true;
}

inline bool TimeDate::set_seconds(unsigned short seconds) {
  if (!TimeDate::check(_date, {_time.hours, _time.minutes, seconds}))
    return false;
  _time.seconds = seconds;
  return true;
}

#endif
