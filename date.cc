#include "date.h"
#include <sstream>
#include <time.h>
///////////////////////////// construction //////////

date::date(const int& d, const int& m, const int& y) 
: day_(d), month_(m), year_(y)
{
   
};

date::date(const long& d){
  year_=d/10000;
  if(year_<100){ year_=1900+year_;};
  month_=(d%10000)/100;
  day_=d%100;
}
///////////////////////////// inline definitions //////////

date::date(){ //year_ = 0; month_ = 0; day_ = 0;};
// get current date from system
  time_t cur_time;
  struct tm* pTime;
  time(&cur_time);
  pTime=localtime(&cur_time);

  year_=pTime->tm_year+1900;
  month_=pTime->tm_mon+1;
  day_=pTime->tm_mday;
};


int date::day()   const { return day_;   };
int date::month() const { return month_; };
int date::year()  const { return year_;  };

void date::set_day  (const int& day)  { date::day_   = day;   };
void date::set_month(const int& month){ date::month_ = month; };
void date::set_year (const int& year) { date::year_  = year;  };

bool date::valid() const {
// This function will check the given date is valid or not.
//  If the date is not valid then it will return the value false.
//   Need some more checks on the year, though
  if (year_ <0) return false;
  if (month_>12 || month_<1) return false;
  if (day_>31 || day_<1) return false;
  if ((day_==31 &&
      ( month_==2 || month_==4 || month_==6 || month_==9 || month_==11) ) )
          return false;
  if ( day_==30 && month_==2) return false;
  if ( year_<2000){
      if ((day_==29 && month_==2) && !((year_-1900)%4==0)) return false;
  };
  if ( year_>2000){
      if ((day_==29 && month_==2) && !((year_-2000)%4==0)) return false;
  };
  return true;
};

bool operator == (const date& d1,const  date& d2){
// check  for  equality
  if (!d1.valid()) { return false; };
  if (!d2.valid()) { return false; };
  if ((d1.day()==d2.day())
      && (d1.month()==d2.month())
          && (d1.year()==d2.year())){
      return true;
  };
  return false;
}

bool operator !=(const date& d1,  const date& d2){
  return !(d1==d2);
}

bool operator < (const date& d1, const date& d2){
  if(!d1.valid()){ return false;}; // not  meaningful, return anything
  if(!d2.valid()){ return false;}; // should  really be an  exception, but  ?
  if(d1.year()<d2.year()){ return true;}
  else if(d1.year()>d2.year()){ return false;}
  else {                                              // same  year
      if(d1.month()<d2.month()) { return true;}
      else if(d1.month()>d2.month()) { return false;}
      else { // same  month
          if ( d1.day()<d2.day()) { return true;}
          else { return false; }
      };
  };
  return false;
};

bool operator > (const date& d1, const date& d2)  {
  if (d1==d2) { return false;}; // this  is  strict inequality
  if (d1<d2)  { return false;};
  return true;
}

bool operator <=(const date& d1, const date& d2){
  if (d1==d2) { return true;};
  return (d1<d2);
}

bool operator >=(const date& d1, const date& d2)  {
  if (d1==d2) { return true;};
  return (d1>d2);
};

date next_date(const date& d){
  date ndat;
  if (!d.valid()) { return ndat; };
  ndat = date((d.day()+1),d.month(),d.year()); if (ndat.valid()) return ndat;
  ndat = date(1,(d.month()+1),d.year()); if (ndat.valid()) return ndat;
  ndat = date(1,1,(d.year()+1)); return ndat;
}

date previous_date(const date& d){
  date ndat;
  if(!d.valid()) { return ndat; }; // return zero
  ndat = date((d.day()-1),d.month(),d.year()); if (ndat.valid()) return ndat;
  ndat = date(31,(d.month()-1),d.year()); if (ndat.valid()) return ndat;
  ndat = date(30,(d.month()-1),d.year()); if (ndat.valid()) return ndat;
  ndat = date(29,(d.month()-1),d.year()); if (ndat.valid()) return ndat;
  ndat = date(28,(d.month()-1),d.year()); if (ndat.valid()) return ndat;
  ndat = date(31,12,(d.year()-1)); return ndat;
};

date date::operator ++(int){  // postfix  operator
  date d = *this;
  *this = next_date(d);
  return d;
}

date date::operator ++(){  // prefix  operator
  *this = next_date(*this);
  return *this;
}

date date::operator --(int){  // postfix  operator, return current value
  date d = *this;
  *this = previous_date(*this);
  return d;
}

date date::operator --(){  // prefix  operator, return new  value
  *this = previous_date(*this);
  return *this;
};

date operator +(const date& d,const int& days){
  if(!d.valid()){return date();}
  if(days<0){return (d-(-days));}
  date d1=d;
  for(int day=0;day<days;++day){d1=next_date(d1);}
  return d1;
};

date operator -(const date& d,const int& days){
  if(!d.valid()){return date();}
  if(days<0){return (d+(-days));}
  date d1=d;
  for(int day=0;day<days;++day){d1=previous_date(d1);}
  return d1;
};

date operator +=(date& d,const int& days){
  d=(d+days);
  return d;
}

date operator -=(date& d,const int& days){
  d=(d-days);
  return d;
}

long long_date(const  date& d) {
//    long yyyymmdd;
//    if (d.valid()){
//        yyyymmdd=d.year() * 10000 + d.month() * 100 + d.day();
//        //std::string s=(string)yyyymmdd;
//        std::stringstream strst;
//        std::string s;
//        strst<<yyyymmdd;
//        strst>>s;
//        cout<<"called"<<endl;
//        return s.substr(0,4)+"-"+s.substr(4,2)+"-"+s.substr(6,2);
//    };
//    return "";
  if(d.valid()){ return d.year()*10000+d.month()*100+d.day(); };
  return -1;
};

ostream & operator << (ostream& os,  const date& d){
  if (d.valid()) { os << " " << long_date(d) << " " ; }
  else { os << " invalid date "; };
  return os;
}

date add_months(const date& indate,const int& no_months){
  date d=indate;
  date ndat;
  
  if(!d.valid()) return indate;
  if(no_months==0) return indate;
  int no_years=no_months/12;
  if(no_years!=0){d.set_year(indate.year()+no_years);}
  int nmonths=no_months%12;
  if(nmonths==0) return d;  
  
  if(no_months>0){
    if(d.month()+nmonths<=12){
      ndat=date(d.day(),d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-1,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-2,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-3,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
    }
    else{
      ndat=date((d.day()),d.month()+nmonths-12,d.year()+1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-1,d.month()+nmonths-12,d.year()+1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-2,d.month()+nmonths-12,d.year()+1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-3,d.month()+nmonths-12,d.year()+1);
      if(ndat.valid()) return ndat;
    }
  }
  else{
    if(d.month()+nmonths>=1){
      ndat=date(d.day(),d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-1,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-2,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-3,d.month()+nmonths,d.year());
      if(ndat.valid()) return ndat;
    }
    else{
      ndat=date((d.day()),d.month()+nmonths+12,d.year()-1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-1,d.month()+nmonths+12,d.year()-1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-2,d.month()+nmonths+12,d.year()-1);
      if(ndat.valid()) return ndat;
      ndat=date(d.day()-3,d.month()+nmonths+12,d.year()-1);
      if(ndat.valid()) return ndat;
    };
  };
  cerr<<"Error in Add month"<<endl;
  return indate;
}

date next_month(const date& d){
  return add_months(d,1);
}
