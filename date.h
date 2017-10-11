#include<iostream>
#ifndef DATE_H
#define DATE_H

using namespace std;

class date {
	private:
		int year, month, day;
	public:
		date(){ year = 0;month = 1; day = 1;}
		date( int d, int m, int y);
		date(const date& x);
		bool valid() const;
		bool valid(int day,  int month,  int year) const;
		int getday() const { return day ; };
		int getmonth() const { return month ; };
		int getyear() const { return year ; };
		void setday (int dy, int month, int year);
		void setmonth( int mon);//{ month = mon; };
		void setyear ( int yr);//{ year = yr; };
		void set(int dy, int mon, int yr);
		date operator ++(); // prefix
		date operator ++(int); // postfix
		date operator --(); // prefix
		date operator --(int); // postfix
		date& operator=(const date& x);
		date& operator+=(int x);
};
  
bool operator == (const date&, const date&); 
bool operator != (const date&, const date&);
bool operator < (const date&, const date&);
bool operator > (const date&, const date&);
bool operator <= (const date&, const date&);
bool operator >= (const date&, const date&);
ostream& operator<<(ostream& os, const date& d);
istream& operator>>(istream& is, date& d);

#endif
