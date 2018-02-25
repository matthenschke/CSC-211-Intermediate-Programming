#include<iostream>
#include<ostream>
#include<iomanip>
using namespace std;
#ifndef TIME_H
#define TIME_H

class Time{
public:
	Time();
	Time(int a, int b);

	//accessors
	int getMin() const { return min; }
	int getHrs() const { return hrs; }
	void setMin(int m) { min = m; }
	void setHrs(int h){ hrs = h; }
	 

	//overloaded operators
	const double operator *(double &rhs);
	const Time operator -(const Time& rhs);
	friend const Time operator /(const Time& lhs, int& rhs);
	friend ostream& operator << (ostream & out,  const Time & t);
	friend istream& operator >> (istream& in, Time&t);
	
	
private:
	int hrs;
	int min;
};
const double operator *( Time& lhs,double& rhs);
const Time  operator -( const Time& rhs,  const Time &lhs);
 
 


int main(){
	{
		//Testing  time class * function
		double rate;
		Time t(3, 35);
		cout << "Class * function" << endl;
		cout << "Hours worked: " << t.getHrs() << endl;
		cout << "Minutes worked: " << t.getMin() << endl;
		cout << "What is the salary rate?" << endl;
		cin >> rate;
		cout << fixed << "Total salary: $" << setprecision(2) << t. operator*(rate) << endl;
	}
	{
	//Testing the global operating * function
	double rate;
	Time t;
	cout << "\n Global * function" << endl;
	cout << "Please enter the rate" << endl;
	cin >> rate;
	cout << fixed << "The total salary is: $" << setprecision(2) << operator*(t, rate) << endl;
}
	{
		//testing the class - function
		cout << "\n Class - function" << endl;
		Time t;
		t.setHrs(10);
		t.setMin(50);
		t.operator -(t);
	}
	
	{     //testing the global - function and ifstream function
		Time t, t2;
		cout << "\n Global - function and >> function" << endl;
		cout << "\nWorker 1" << endl;
		operator>> (cin, t);
		cout << "Worker 2" << endl;
		operator >>(cin, t2);
		operator-(t, t2);
	}
	{
		//testing the friend / function
		cout << "\n Friend / function" << endl;
		Time t;
		t.setHrs(5);
		t.setMin(30);
		int rate;
		cout << "Please enter a rate " << endl;
		cin >> rate;
		cout << t.getHrs() << " hours and " << t.getMin() << " minutes is " << rate
			<< " times slower than " << operator/(t, rate) << endl;

	}
	{
		//testing the >> and << function
		Time t;
		cout << "\n >> and << functions" << endl;
		cout << " >> function" << endl;
		operator >> (cin, t);
		cout << " << function" << endl;
		operator << (cout, t);
	}
	
	return 0;
	
}
Time::Time(){

	hrs = 0;
	min = 0;
	
}
Time::Time(int a, int b) : hrs(a), min(b){
	
}
const double Time:: operator *(double &rhs){
	 
	return (hrs*rhs) + ((min / 60.00)*rhs);
}
const double operator *(Time &lhs, double &rhs){
	operator >>(cin, lhs);	
	return (lhs.getHrs()* rhs) + ((lhs.getMin() / 60.0)*rhs);
}
const Time Time:: operator -(const Time &rhs){
	Time t, lhs;
	cout << " Enter Time for worker 2" << endl;
		operator >> (cin, lhs);
	int im1, im2, minutes;
	im1 = (rhs.getHrs() * 60) + rhs.getMin();
	im2 = (lhs.getHrs() * 60) + lhs.getMin();
	if (im1 > im2){
		minutes = im1 - im2;
		t.setHrs(minutes / 60);
		t.setMin(minutes % 60);
		t.getHrs();
		t.getMin();
		cout << "Worker 1 worked " << t.getHrs() << " hours and " << t.getMin() << " minutes more than Worker 2" << endl;
		return t;
	}
	else if (im1 == im2){
		cout << " Both workers worked  " << rhs.getHrs() << " hours and " << rhs.getMin() << " minutes " << endl;
		return rhs;
	}
	else{
		minutes = im2 - im1;
		t.setHrs(minutes / 60);
		t.setMin(minutes % 60);
		t.getHrs();
		t.getMin();
		cout << "Worker 2 worked " << t.getHrs() << " hours and " << t.getMin() << " minutes more than Worker 1" << endl;
		return t;
	}
	
	
}
const Time operator -(const Time& rhs, const Time &lhs){
	Time t;
	int tm1, tm2, minutes;
	tm1 = (rhs.getHrs() * 60) + rhs.getMin();
	tm2 = (lhs.getHrs() * 60) + lhs.getMin();
	if (tm1 > tm2){
		minutes = tm1 - tm2;
		t.setHrs(minutes / 60);
		t.setMin(minutes % 60);
		t.getHrs();
		t.getMin();
		cout << "Worker 1 worked" << t.getHrs() << " hours and " << t.getMin() << " minutes more than Worker 2" << endl;
	}
	else if (tm1 == tm2){
		cout << " Both workers worked " << rhs.getHrs() << " hours and " << rhs.getMin() << " minutes" << endl;
		return rhs;
	}
	else{
		minutes = tm2 - tm1;
		t.setHrs(minutes / 60);
		t.setMin(minutes % 60);
		t.getHrs();
		t.getMin();
		cout << "Worker 2 worked " << t.getHrs() << " hours and " << t.getMin() << " minutes more than Worker 1" << endl;
	}
		return t;
}

 const Time operator /(const Time& lhs, int& rhs){
	 Time t;
	 int total = (lhs.getHrs() * 60) + lhs.getMin();
	 total = total / rhs;
	 t.setHrs(total / 60);
	 t.setMin(total % 60);
	 return t;
	 }

istream& operator >>(istream& in, Time&t){
int h, m;
cout << "Please enter the hours" << endl;
in >> h;
cout << "Please enter the minutes" << endl;
in >> m;
 t.setHrs(h);
 t.setMin(m);
 return in;

}
ostream& operator <<(ostream& out, const Time& t ){
	
	out << t.getHrs() << " Hours and " << t.getMin() << " Minutes" << endl;
   
	return out;
}

#endif