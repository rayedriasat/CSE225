#include "timeStamp.h"

timeStamp::timeStamp()
{
    this->h = 0;
    this->m = 0;
    this->s = 0;
}

timeStamp::timeStamp(int h, int m, int s)
{
    this->h = h;
    this->m = m;
    this->s = s;
}

bool timeStamp::operator==(timeStamp t)
{
    return ((s == t.s) && (m == t.m) && (h == t.h));
}

bool timeStamp::operator!=(timeStamp t)
{
    return !((s == t.s) && (m == t.m) && (h == t.h));
}

bool timeStamp::operator<(timeStamp t)
{
    return ((h < t.h) || ((h == t.h) && (m < t.m)) || ((h == t.h) && (m == t.m) && (s < t.s)));
}

bool timeStamp::operator>(timeStamp t)
{
    return ((h > t.h) || ((h == t.h) && (m > t.m)) || ((h == t.h) && (m == t.m) && (s > t.s)));
}

ostream &operator<<(ostream &os, timeStamp &t)
{
    os << t.h << ":" << t.m << ":" << t.s;
    return os;
}

istream &operator>>(istream &is, timeStamp &t)
{
    is >> t.h >> t.m >> t.s;
    return is;
}
