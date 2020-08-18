// file: date.h
// author: Bernt A Oedegaard.

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <ctime>

using namespace std;

class date {
protected:
    int year_;
    int month_;
    int day_;
public:
    date();
    date(const long& d);
    date(const int& d, const int& m, const int& y);

    bool valid(void)  const;

    int day()   const;
    int month() const;
    int year()  const;

    void set_day   (const int& day   );
    void set_month (const int& month );
    void set_year  (const int& year  );

    date operator ++();    // prefix
    date operator ++(int); // postfix
    date operator --();    // prefix
    date operator --(int); // postfix
};

date operator +=(date&,const int&);
date operator -=(date&,const int&);
date operator +(const date&,const int&);
date operator -(const date&,const int&);

bool operator == (const date&, const date&);   // comparison operators
bool operator != (const date&, const date&);
bool operator <  (const date&, const date&);
bool operator >  (const date&, const date&);
bool operator <= (const date&, const date&);
bool operator >= (const date&, const date&);

ostream& operator << ( ostream& os, const date& d);  // output operator
long long_date(const date& d);
date next_date(const date& d);
date previous_date(const date& d);
date next_month(const date& d);
date add_months(const date& d,const int& no_months);

#endif
