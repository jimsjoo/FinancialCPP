#include <iostream>
#include "dated.h"

using namespace std;

void examples_date();
void example_date_simple();
void example_date_comparisons();
inline void dates_comparisons(date d1, date d2);

void examples_dated();

int main()
{
    examples_date();
    cout<<"------------------------------------"<<endl;
    examples_dated();
    return 0;
}

void examples_date() {
   cout << "TESTING DATE " << endl;
   example_date_simple();
   cout<<"------------------------------------"<<endl;
   example_date_comparisons();
   cout << "DONE TESTING DATE " << endl;
};

void example_date_simple(){
   cout << "TESTING DATE SIMPLE " << endl;
   cout << " construction: date(1,1,1998):" << date(1,1,1998) <<endl;
   cout << " increment: ++date(1,1,1998):" << ++date(1,1,1998) << endl;
   cout << " decrement: --date(1,1,1998):" << --date(1,1,1998) << endl;
   date d(1,1,2006);
   cout << "valid date(1,1,2006) ?" << date(1,1,2006).valid() << endl;
   cout << "valid date(33,1,2006) ?" << date(33,1,2006).valid() << endl;
   cout << "DONE TESTING DATE SIMPLE " << endl;
}

void example_date_comparisons(){
   cout << "TESTING DATE COMPARISONS " << endl;
   date d1(25,7,1993);
   date d2(8,10,1993);
   dates_comparisons (d1,d2);
   dates_comparisons (d1,d1);
   cout << "DONE TESTING DATE COMPARISONS " << endl;
};

inline void dates_comparisons(date d1, date d2) {
    cout <<"COMPARISON TEST" << endl;
    cout << " Comparing " << d1 << "and" << d2 << endl;
    cout << "  is" << d1 <<"equal to      "  << d2 ;
    if (d1==d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"different from"  << d2 ;
    if (d1!=d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"less than     "  << d2 ;
    if (d1<d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"greater than  "  << d2 ;
    if (d1>d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
};

void examples_dated(){
   cout << "TESTING dated<> simple " << endl;
   
   dated<double> dd;
   date d=date(1,1,1998);
   dd.insert(d,1);
   d = date(1,2,1998);
   dd.insert(d,2);
   cout << dd.size() << " elements " << endl;
   cout << dd ;
   cout << " inserting at 1/1 and 1/3 " << endl;
   dd.insert(date(1,1,1998),0.5);
   dd.insert(date(1,3,1998),3);
   cout << dd;
   cout << " deleting 1/2" << endl;
   dd.remove(date(1,2,1998));
   cout << dd;
   
   cout << " dated<string> " << endl;
   dated<string> ds;
   ds.insert(date(1,1,1998),"A");
   ds.insert(date(1,2,1998),"B");
   cout << ds;
   cout << "DONE test dated<>"  << endl;
};


