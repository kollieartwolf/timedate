#include "timedate.h"

TimeDate::TimeDate(const TimeDate &timeDate)
    : m_time(timeDate.m_time), m_date(timeDate.m_date) {}

TimeDate::TimeDate(unsigned short day, unsigned short month, int year,
                   unsigned short hours, unsigned short minutes,
                   unsigned short seconds) {
  if (not TimeDate::isCorrect(day, month, year, hours, minutes, seconds))
    return;
  setDay(day);
  setMonth(month);
  setYear(year);
  setHours(hours);
  setMinutes(minutes);
  setSeconds(seconds);
}

void TimeDate::printByTemplate(const std::string &tmpl) const {
  std::cout << fillTemplate(tmpl) << std::endl;
}

int TimeDate::currentTime() const {
  return m_time.hours * 60 * 60 + m_time.minutes * 60 + m_time.seconds;
}

std::string TimeDate::fillTemplate(const std::string &templ) const {
  std::string result;
  result = TimeDate::stringReplacer(templ, "DD",
                                    std::to_string(getDay() / 10) +
                                        std::to_string(getDay() % 10));
  result = TimeDate::stringReplacer(result, "MM",
                                    std::to_string(getMonth() / 10) +
                                        std::to_string(getMonth() % 10));
  result = TimeDate::stringReplacer(result, "YYYY",
                                    std::to_string(getYear() / 1000) +
                                        std::to_string(getYear() % 1000 / 100) +
                                        std::to_string(getYear() % 100 / 10) +
                                        std::to_string(getYear() % 10));
  result = TimeDate::stringReplacer(result, "YY",
                                    std::to_string((getYear() / 10) % 10) +
                                        std::to_string(getYear() % 10));
  result = TimeDate::stringReplacer(result, "HH",
                                    std::to_string(getHours() / 10) +
                                        std::to_string(getHours() % 10));
  result = TimeDate::stringReplacer(result, "MI",
                                    std::to_string(getMinutes() / 10) +
                                        std::to_string(getMinutes() % 10));
  result = TimeDate::stringReplacer(result, "SS",
                                    std::to_string(getSeconds() / 10) +
                                        std::to_string(getSeconds() % 10));
  return result;
}

bool TimeDate::isCorrect(unsigned short day, unsigned short month, int year,
                         unsigned short hours, unsigned short minutes,
                         unsigned short seconds) {
  if ((1 > day))
    return false;
  if (day > 31)
    return false;
  if ((day > 30) and
      ((month == 4) or (month == 6) or (month == 9) or (month == 11)))
    return false;
  if ((day > 28) and (month == 2) and
      ((year % 4 != 0 or year % 100 == 0 or year % 400 != 0)))
    return false;
  if ((1 > month) or (12 < month))
    return false;
  if ((0 > hours) or (24 <= hours))
    return false;
  if ((0 > minutes) or (60 <= minutes))
    return false;
  if ((0 > seconds) or (60 <= seconds))
    return false;
  return true;
}

const TimeDate TimeDate::loadDateFromString(const std::string &str,
                                            const std::string &format) {
  Date date;
  size_t pos = format.find("DD");
  if (pos != std::string::npos) {
    std::string tmp;
    tmp += str[pos] + str[pos + 1];
    date.day = std::stoi(tmp);
  }
  pos = std::string::npos;
  pos = format.find("MM");
  if (pos != std::string::npos) {
    std::string tmp;
    tmp += str[pos] + str[pos + 1];
    date.month = std::stoi(tmp);
  }
  pos = std::string::npos;
  pos = format.find("YYYY");
  if (pos != std::string::npos) {
    std::string tmp;
    tmp += str[pos] + str[pos + 1] + str[pos + 2] + str[pos + 3];
    date.year = std::stoi(tmp);
  }
  pos = std::string::npos;
  pos = format.find("YY");
  if (pos != std::string::npos) {
    std::string tmp;
    tmp += str[pos] + str[pos + 1];
    date.year = std::stoi(tmp);
  }
  return TimeDate(date.day, date.month, date.year, 0, 0, 0);
}

std::string TimeDate::stringReplacer(const std::string &inputStr,
                                     const std::string &src,
                                     const std::string &dst) {
  std::string result(inputStr);
  size_t pos = result.find(src);
  while (pos != std::string::npos) {
    result.replace(pos, src.size(), dst);
    pos = result.find(src, pos);
  }
  return result;
}
