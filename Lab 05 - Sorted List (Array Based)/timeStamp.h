#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
#include <iostream>
using namespace std;

class timeStamp
{

public:
    timeStamp();
    timeStamp(int, int, int);
    bool operator==(timeStamp);
    bool operator!=(timeStamp);
    bool operator>(timeStamp);
    bool operator<(timeStamp);
    friend ostream &operator<<(ostream &, timeStamp &);
    friend istream &operator>>(istream &, timeStamp &);

private:
    int h, m, s;
};

#endif // TIMESTAMP_H_INCLUDED
