#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{
    int total_hours = hours + other.hours;
    int total_minutes = minutes + other.minutes;
    
    // Handle overflow of minutes
    if (total_minutes >= 60) {
        total_hours += total_minutes / 60;
        total_minutes %= 60;
    }
    
    return Time(total_hours, total_minutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{
    hours += other.hours;
    minutes += other.minutes;
    
    // Handle overflow of minutes
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (hours == other.hours) && (minutes == other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << " hours and " << tm.minutes << " minutes";
    return os;
}