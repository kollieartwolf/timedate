#ifndef TIMEDATE_H
#define TIMEDATE_H

#include <iostream>
#include <string>

struct Date {
  unsigned short day;
  unsigned short month;
  int year;
};

struct Time {
  unsigned short hours;
  unsigned short minutes;
  unsigned short seconds;
};

class TimeDate {
public:
  TimeDate() {}
  TimeDate(const TimeDate &timeDate);
  TimeDate(unsigned short day = 1, unsigned short month = 1, int year = 1,
           unsigned short hours = 0, unsigned short minutes = 0,
           unsigned short seconds = 0);
  void printByTemplate(const std::string &tmpl);
  unsigned short getDay();
  unsigned short getMonth();
  unsigned short getYear();
  unsigned short getHours();
  unsigned short getMinutes();
  unsigned short getSeconds();
  bool setDay(unsigned short day);
  bool setMonth(unsigned short month);
  bool setYear(int year);
  bool setHours(unsigned short hours);
  bool setMinutes(unsigned short minutes);
  bool setSeconds(unsigned short seconds);
  int currentTime();
  const Time getTime();
  const Date getDate();
  bool setTime(const Time &time);
  bool setDate(const Date &date);
  std::string fillTemplate(const std::string &tmpl);
  static bool isCorrect(unsigned short day, unsigned short month, int year,
                        unsigned short hours, unsigned short minutes,
                        unsigned short seconds);
  static const TimeDate loadDateFromString(const std::string &str,
                                 const std::string &format);

private:
  Time m_time{0, 0, 0};
  Date m_date{1, 1, 1};
  static std::string stringReplacer(const std::string &inputStr,
                                    const std::string &src,
                                    const std::string &dst);
};

inline unsigned short TimeDate::getDay() { return m_date.day; }
inline unsigned short TimeDate::getMonth() { return m_date.month; }
inline unsigned short TimeDate::getYear() { return m_date.year; }
inline unsigned short TimeDate::getHours() { return m_time.hours; }
inline unsigned short TimeDate::getMinutes() { return m_time.minutes; }
inline unsigned short TimeDate::getSeconds() { return m_time.seconds; }

inline bool TimeDate::setDay(unsigned short day) {
  if (not TimeDate::isCorrect(day, m_date.month, m_date.year, m_time.hours,
                              m_time.minutes, m_time.seconds))
    return false;
  m_date.day = day;
  return true;
}

inline bool TimeDate::setMonth(unsigned short month) {
  if (not TimeDate::isCorrect(m_date.day, month, m_date.year, m_time.hours,
                              m_time.minutes, m_time.seconds))
    return false;
  m_date.month = month;
  return true;
}

inline bool TimeDate::setYear(int year) {
  if (not TimeDate::isCorrect(m_date.day, m_date.month, year, m_time.hours,
                              m_time.minutes, m_time.seconds))
    return false;
  m_date.year = year;
  return true;
}

inline bool TimeDate::setHours(unsigned short hours) {
  if (not TimeDate::isCorrect(m_date.day, m_date.month, m_date.year, hours,
                              m_time.minutes, m_time.seconds))
    return false;
  m_time.hours = hours;
  return true;
}

inline bool TimeDate::setMinutes(unsigned short minutes) {
  if (not TimeDate::isCorrect(m_date.day, m_date.month, m_date.year,
                              m_time.hours, minutes, m_time.seconds))
    return false;
  m_time.minutes = minutes;
  return true;
}

inline bool TimeDate::setSeconds(unsigned short seconds) {
  if (not TimeDate::isCorrect(m_date.day, m_date.month, m_date.year,
                              m_time.hours, m_time.minutes, seconds))
    return false;
  m_time.seconds = seconds;
  return true;
}

inline const Time TimeDate::getTime() { return m_time; }
inline const Date TimeDate::getDate() { return m_date; }

inline bool TimeDate::setTime(const Time &time) {
  if (not TimeDate::isCorrect(m_date.day, m_date.month, m_date.year, time.hours,
                              time.minutes, time.seconds))
    return false;
  m_time = time;
  return true;
}

inline bool TimeDate::setDate(const Date &date) {
  if (not TimeDate::isCorrect(date.day, date.month, date.year, m_time.hours,
                              m_time.minutes, m_time.seconds))
    return false;
  m_date = date;
  return true;
}

#endif
