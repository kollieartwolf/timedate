#include "timedate.h"

TimeDate::TimeDate(const TimeDate &timeDate)
    : _date(timeDate._date), _time(timeDate._time) {}

TimeDate::TimeDate(const Date &date, const Time &time) {
  if (!check(date, time))
    return;
  _date = date;
  _time = time;
}

void TimeDate::print(const string &format) const {
  cout << get_formatted(format) << endl;
}

bool TimeDate::check(const Date &date, const Time &time) {
  if ((1 > date.day))
    return false;
  if (date.day > 31)
    return false;
  if ((date.day > 30) and ((date.month == 4) or (date.month == 6) or
                           (date.month == 9) or (date.month == 11)))
    return false;
  if ((date.day > 28) and (date.month == 2) and
      ((date.year % 4 != 0 or date.year % 100 == 0 or date.year % 400 != 0)))
    return false;
  if ((1 > date.month) or (12 < date.month))
    return false;
  if ((0 > time.hours) or (24 <= time.hours))
    return false;
  if ((0 > time.minutes) or (60 <= time.minutes))
    return false;
  if ((0 > time.seconds) or (60 <= time.seconds))
    return false;
  return true;
}

unsigned short TimeDate::current_time() const {
  return _time.hours * 60 * 60 + _time.minutes * 60 + _time.seconds;
}

string TimeDate::get_formatted(const string &format) const {
  string formatted;
  formatted = replace(format, "DD",
                      to_string(get_day() / 10) + to_string(get_day() % 10));
  formatted =
      replace(formatted, "MM",
              to_string(get_month() / 10) + to_string(get_month() % 10));
  formatted = replace(
      formatted, "YYYY",
      to_string(get_year() / 1000) + to_string(get_year() % 1000 / 100) +
          to_string(get_year() % 100 / 10) + to_string(get_year() % 10));
  formatted =
      replace(formatted, "YY",
              to_string((get_year() / 10) % 10) + to_string(get_year() % 10));
  formatted =
      replace(formatted, "HH",
              to_string(get_hours() / 10) + to_string(get_hours() % 10));
  formatted =
      replace(formatted, "MI",
              to_string(get_minutes() / 10) + to_string(get_minutes() % 10));
  formatted =
      replace(formatted, "SS",
              to_string(get_seconds() / 10) + to_string(get_seconds() % 10));
  return formatted;
}

Date TimeDate::date() const { return _date; }

Time TimeDate::time() const { return _time; }

Date TimeDate::get_date_from_string(const string &str, const string &format) {
  Date date;
  size_t pos = format.find("DD");
  if (pos != string::npos) {
    string tmp = "00";
    tmp[0] = str[pos];
    tmp[1] = str[pos + 1];
    date.day = std::stoi(tmp);
  }
  pos = string::npos;
  pos = format.find("MM");
  if (pos != string::npos) {
    string tmp = "00";
    tmp[0] = str[pos];
    tmp[1] = str[pos + 1];
    date.month = stoi(tmp);
  }
  pos = string::npos;
  pos = format.find("YYYY");
  if (pos != string::npos) {
    string tmp = "0000";
    tmp[0] = str[pos];
    tmp[1] = str[pos + 1];
    tmp[2] = str[pos + 2];
    tmp[3] = str[pos + 3];
    date.year = stoi(tmp);
  } else {
    pos = string::npos;
    pos = format.find("YY");
    if (pos != string::npos) {
      string tmp = "00";
      tmp[0] = str[pos];
      tmp[1] = str[pos + 1];
      int relative_year = stoi(tmp);
      date.year =
          relative_year >= 70 ? 1900 + relative_year : 2000 + relative_year;
    }
  }
  return date;
}

string TimeDate::replace(const string &str, const string &format,
                         const string &data) {
  string result(str);
  size_t pos = result.find(format);
  while (pos != string::npos) {
    result.replace(pos, format.size(), data);
    pos = result.find(format, pos);
  }
  return result;
}
