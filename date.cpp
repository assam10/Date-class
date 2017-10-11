#include<iostream>
#include "Date.h"
using namespace std;
//int day =0 ,  month =0,  year =0;

date::date(int day,  int month,  int year){
	if(valid(day, month, year)==true){
		setday(day, month, year);
		setmonth(month);
		setyear(year);
	}
	else{
		cout << "Invalid date\n";
	}
}

void date::setmonth(int mon){
	if(mon > 0 && mon <=12) {month=mon;}
	else{cout << "\nInvalid month\n";}
}

void date::setyear(int yr){
	if(yr > 0) {year=yr;}
	else{cout << "\nInvalid year\n";}
}

bool is_leapyear(int y)
	{
		return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
	}

int days_in_month(int month, int year){
	if((month ==4 || month ==6 || month ==9 || month ==11) ){
		return 30;
	}
	if((month == 1 || month == 3 || month==5 || month==7 || month==8 || month==10 ||month==12 )){
		return 31;
		}
	if (month == 2){

		if(is_leapyear(year)==true){
			return 29;
		}
		else{return 28;}
	}
}

void date::setday(int dy, int month, int year)
{
	if (dy > 0 && dy <= days_in_month(month, year))
		day = dy;
}


date date::operator ++(int){
	date nd = *this;
	++*this;
	return nd;
}

date date::operator ++(){
	this->day++;
	if(this->day > days_in_month(this->month, this->year)){
		this->month++;
		if(this->month>12){
			this->year++;
			this->month =1;
		}
		this->day=1;
	}
	return *this;
}


bool date::valid(int day, int month, int year)const{
	if (year <=0) return false;
	if (month >12 || month <1) return false;
	if(day > 0 && day<=(days_in_month(month, year)))return true;
	return false;
}

bool date::valid()const{
	return valid(this->day, this->month, this->year);
}

bool operator == (const date& d1,const date& d2){
	if (!d1.valid()) { return false; };
	if (!d2.valid()) { return false; };
	if ( (d1.getday()==d2.getday())&& (d1.getmonth()==d2.getmonth())&& (d1.getyear()==d2.getyear())) {
		return true;
	}
	return false;
}

bool operator !=(const date& d1, const date& d2){
	return !(d1==d2);
}

bool operator < (const date& d1, const date& d2){
	if (!d1.valid()) { return false; }
	if (!d2.valid()) { return false; }
	if (d1.getyear()<d2.getyear()) { return true;}
	else if (d1.getyear()>d2.getyear()) { return false;}
	else { // same year
		if (d1.getmonth()<d2.getmonth()) { return true;}
		else if (d1.getmonth()>d2.getmonth()) { return false;}
		else { // same month
			if ( d1.getday()<d2.getday()) { return true;}
			else { return false; }
		}
	}
	return false;
}

bool operator > (const date& d1, const date& d2) {
	if (d1==d2) { return false;}
	if (d1<d2) { return false; }
	return true;
}

bool operator <=(const date& d1, const date& d2){
	if (d1==d2) { return true; }
	return (d1<d2);
}

bool operator >=(const date& d1, const date& d2) {
	if (d1==d2) { return true;};
	return (d1>d2);
}


date previousdate(const date& d){
	date ndat;
	if (!d.valid()) { return ndat; }; // return zero
	ndat = date((d.getday()-1),d.getmonth(),d.getyear()); if (ndat.valid()) return ndat;
	ndat = date(31,(d.getmonth()-1),d.getyear()); if (ndat.valid()) return ndat;
	ndat = date(30,(d.getmonth()-1),d.getyear()); if (ndat.valid()) return ndat;
	ndat = date(29,(d.getmonth()-1),d.getyear()); if (ndat.valid()) return ndat;
	ndat = date(28,(d.getmonth()-1),d.getyear()); if (ndat.valid()) return ndat;
	ndat = date(31,12,(d.getyear()-1)); return ndat;
}

date date::operator --(int){ // postfix operator
	date d = *this;
	*this = previousdate(*this);
	return d;
}

date date::operator --(){ // prefix operator
	*this = previousdate(*this);
	return *this;
}

long longdate(const date& d) {
	if (d.valid()){ return d.getyear() * 10000 + d.getmonth() * 100 + d.getday(); };
	return -1;
}

date& date::operator+=(int x){
	for(int i=0;i<x;i++){
		++*this;
	}
	return *this;
}

/*ostream& operator<<(ostream& os, const date& d){
	if (d.valid()) { os << longdate(d) << " " << endl;}
	else { os << " invalid date "; }
	return os;
}*/

ostream& operator<<(ostream& os, const date& d){
	if (d.valid()) { 
	os << d.getday() << "."<< d.getmonth() << "."<< d.getyear();
	return os;}
	else { os << "Invalid Date\n"; }
}

void date::set(int dy, int mon, int yr){
	if(valid(dy, mon, yr)==true){
		this->day=dy;
		this->month=mon;
		this->year=yr;
	}
	else {
	cout << "\nInvalid date(setdate)"<< dy << " " << mon << " "<< yr<<endl;
	}
	
}
date::date(const date& x){
	set(x.getday(),x.getmonth(),x.getyear());
}

date& date::operator=(const date& x){
	if(this == &x){
		return *this;
	}

	this->day=x.getday();
	this->month=x.getmonth();
	this->year=x.getyear();

	return *this;
}

istream& operator>>(istream& is, date& d){								
	int day, month, year;
	char ch1, ch2;
	is >> day >> ch1 >> month >> ch2 >> year;
	//cout << day << ch1 << month << ch2 << year;
	if (d.valid(day, month, year)==true){
		d.set(day, month, year);
	}
	else{cout << "Invalid Date or No Date Exists\n";
	}
	return is;
}
