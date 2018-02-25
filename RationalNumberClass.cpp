#include<iostream>
#include<ostream>
using namespace std;
#ifndef RAT_H
#define RAT_H


class Rat{

public:
	Rat();
	Rat(int n);
	Rat(int n, int d);
	~Rat();
	void setRat(int nu, int de);
	int getNum() const{ return num; }
	int getDen() const{ return den; }
	static int gCnt();
	double getAsDouble();
	const Rat operator *(const Rat& rhs);
	const Rat operator /(const Rat& rhs);
	bool operator <(const Rat &rhs);
	bool operator > (const Rat& rhs);
	bool operator >= (const Rat & rhs);
	bool operator <= (const Rat &rhs);
	Rat operator -(); //negates rational number
	Rat operator ++(); //pre-increment
	Rat operator ++ (int); //post decrement
	Rat operator --(); //pre-decrement
	Rat operator-- (int); //post-decrement
	friend istream& operator >> (istream & in, Rat & f);
	friend ostream & operator << (ostream & out, const Rat & f);
	
private:
	int num;
	int den;
	static int cnt;
	int gcd(); //greatest common divisor 
	void lowestTerm(); //changed to lowest term of fractions

}; 



int Rat::cnt = 0;


const Rat operator +(const Rat & lhs, const Rat & rhs);
const Rat operator -(const Rat & lhs, const Rat & rhs);
bool operator ==(const Rat & lhs, const Rat & rhs);
bool operator !=(const Rat & lhs, const Rat & rhs);

     int main(){
	
	cout << "Welcome to the Rational Fraction Class Simulator" << endl;
	{  //testing getAsDouble, >>, << and all mathematical operator functions including the 

		cout << "\nAll mathematical operation functions including the operators >> and <<" << endl;
		Rat r, t;

		cin >> r;
 		cout << "cnt is " << Rat::gCnt() << endl;
		cout << "Main Rational fraction simplified is " << r;
		cout << "Double value is " << r.getAsDouble() << endl;
		cout << "When both fractions are multiplied, the product is: " << r * r<<  endl;
		cout << "When both fractions are divided, the quotient is: " << r / r << endl;
		cout << "\nPlease enter fraction that you want to add and subract the Main fraction by" << endl;
		cin >> t;
		cout << " Simplified Fraction that you inputted is ";
		cout << t;
		cout << endl;
		cout << "When both fractions are added, the sum is: " <<  r + t << endl;
		cout << "When second fraction is subtracted from the first, the difference is: " << r - t << endl;
		
	}
	cout << "cnt is now " << Rat::gCnt();

	
		{	//testing all boolean returning functions and logical operators
			cout << endl;
			
			cout << "Logical Operator Functions" << endl;
			
			Rat r(5), r1;	
			cout << "cnt is now " << Rat::gCnt()<< endl;
			cout << "Rational fraction is " << r;
			//if statements for logical functions
		   if (r<r)
			cout << "Main fraction is less than inputted fraction " << endl;
		else cout << "Main fraction is not less than inputted fraction " << endl;
		if (r>r)
			cout << "Main fraction is greater than inputted fraction " << endl;
		else
			cout << "Main fraction is not greater than inputted fraction " << endl;
		if (r >=r)
			cout << "Main fraction is greater than or equal to the inputted fraction " << endl;
		else 
			cout << "Main fraction is not greater than or equal to the inputted fraction " << endl;
		if (r <=r)
			cout << "Main fraction is less than or equal to the inputted fraction " << endl;
		else
			cout << "Main fraction is not less than or equal to the inputted fraction " << endl;
		     //== operators and != operator functions
		cout << "\nPlease enter another main fraction" << endl;
		cin >> r1;
				if (r == r1)
					cout << "Both main fractions are equal to one another" << endl;
				else if (r!=r1)
					cout << "The main fractions are not equal to each other" << endl;
				
		
	}
		cout << "cnt is now " << Rat::gCnt();
		
	{
		//testing all unary operators
		cout << endl;
		cout << "Unary operator functions" << endl;
		Rat r (100,100);
		int rat = r.getDen();
		cout << "cnt is now " << Rat::gCnt() << endl;
		cout << "Main fraction is " << r;
		cout << "Main fraction after pre incremented is " << ++r << endl;
		cout << "Main function after post increment is " << r.operator ++(rat) << endl;
		cout << "Main function after pre-decrement is " << --r << endl;
		cout << "Main function after post-decrment is " << r.operator--(rat) << endl;
		cout << "Negative value of main rational fraction is " << -r << endl;
		     
	}
	
	cout << "\nEnd of Rational Fraction Class Simulation " << endl;
			return 0;
}


	 //Rational Number Method Implementations
Rat::Rat(){
	++cnt;
	num = 0;
	den = 1;
	cout << "Default Constructor Called" << endl;
	
	
}
Rat::Rat(int n){
	++cnt;
	num = n;
	den = 1;
	cout << "Constructor with one paramter called" << endl;
	 lowestTerm();
	 
	
	

}
Rat::Rat(int n, int d) : num(n), den(d){
	
	cout << "Constructor with two paramters called" << endl;

lowestTerm();
	 ++cnt;
	
	
}
Rat::~Rat(){
	
	cout << "Destructor called" << endl;
	--cnt;
	
}
void Rat::setRat(int nu, int de){
	
	num = nu;                                                                                                                                                                                                                                       
	den = de;
	lowestTerm();
}

 int Rat:: gCnt(){
	return cnt;
}
 double Rat::getAsDouble(){
	 if (den == 0)
		 return 1;
	 else
	 return (double)num / (double)den;
 }
 const Rat Rat:: operator * (const Rat& rhs){
	 Rat r, lhs;
	 cout << "\nPlease enter a rational fraction that you want to multiply by" << endl;
	 cin >> lhs;
	 r.setRat(rhs.num*lhs.num, rhs.den*lhs.den);
	 return r;
	 
 }
 const Rat Rat:: operator / (const Rat &rhs){
	 Rat lhs, r;
	 cout << " \nPlease enter a number that you want to divide by" << endl;
	 cin >> lhs;
	 r.setRat(rhs.den* lhs.num, rhs.num*lhs.den);
		 return r;
 }
 bool Rat:: operator < (const Rat &rhs){
	 Rat lhs;
	 double r;
	 cout << "\nPlease enter a fraction that you would like to compare the main fraction with" << endl;
	 cin >> lhs;
	 double l = lhs.getAsDouble();
	 if (rhs.den == 0)
		  r = 1;
	 else 
		 r = rhs.num / rhs.den;
	 if (r < l)
		 return true;
	 else 
		 return false;

 }
 bool Rat:: operator >(const Rat & rhs){
	 Rat lhs;
	 double r;
	 cout << "\nPlease enter a fraction that you would like to compare the main fraction with" << endl;
	  cin >> lhs;
	 double l = lhs.getAsDouble();
	 if (rhs.den == 0)
		 r = 1;
	 else
		 r = rhs.num / rhs.den;
	 if (l < r)
		 return true;
	 else
		 return false;
 }
 bool Rat :: operator >=(const Rat & rhs){
	 Rat lhs;
	 double r;
	 cout << "\nPlease enter a fraction that you would like to compare the main fraction with" << endl;
	 cin >> lhs;
	 double l = lhs.getAsDouble();
	 if (rhs.den == 0)
		 r = 1;
	 else
		 r = rhs.num / rhs.den;
	 if (l <= r)
		 return true;
	 else
		 return false;
 }
 bool Rat :: operator <= (const Rat & rhs){
	 Rat lhs;
	 double r;
	 cout << "\nPlease enter a fraction that you would like to compare the main fraction with" << endl;
	 cin >> lhs;
	 double l = lhs.getAsDouble();
	 if (rhs.den == 0)
		 r = 1;
	 else
		 r = rhs.num / rhs.den;
	 if (l >= r)
		 return true;
	 else
		 return false;
 }
 Rat Rat:: operator -(){
	 Rat r;
	 int n, d;
	 if (num == 0){
		 n = num;
		 d = den*(-1);
		 r.setRat(n, d);
		 return r;
	 }
	 else if (den == 0){
		 n = num*(-1);
		 d = den;
		 r.setRat(n, d);
		 return r;
	 }
	 else{
		 d = den;
		 n = (-1)*num;
		 r.setRat(n, d);
		 return r;
	 }
 }
 Rat Rat:: operator ++(){ //pre-increment
	 Rat r;
	 int n, d;
	 n = ++num;
	 d = den;
	 r.setRat(n, d);
	 return r;

 }
 Rat Rat :: operator ++(int){ //post-increment
	 Rat r;
	 int n, d;
	 d = den;
	 num= num++;
	 n = num;
	 r.setRat(n, d);
	 return r;
	 
 }
 Rat Rat :: operator --(){ //pre-decrement
	 Rat r;
	 int n, d;
	 if (num <= 0)
		 n = num - 1;
	 else 
	n= --num;
	 d = den;
	 r.setRat(n, d);
	 return r;
 }
 Rat Rat :: operator --(int){ //post decrement
	 Rat r;
	 int n, d;
	 if (num <= 0)
		 n = num - 1;
	 else {
	num= num--;
	n = num;

	 }
	 d = den;
	 r.setRat(n, d);
	 return r;
 }
 istream & operator >> (istream & in,  Rat & f){
	 int n, d;
	 cout << "Please enter a numerator " << endl;
	 in >> n;
	 cout << "Please enter a denominator " << endl;
	 in >> d;
	 f.setRat(n, d);
	
	 return in;
	 

 }
 ostream & operator << (ostream & out, const Rat & f){
	 out << f.getNum() << "/" << f.getDen() << endl;
	 return out;

 }
 int Rat:: gcd(){
	 int g;
	 int n = num;
	 int d = den;
	 
	 if (n > d){
		 while (d != 0){
			 g = d;
			 d = n%d;
			 n = g;




		 }
		 return n;
	 }
	 else {
		 while (n != 0){
			 g = n;
			 n = d%n;
			 d = g;
		 }
		 		
	 return d;
	 }
 }
 void Rat::lowestTerm(){
	 
	int g= gcd();
	num = num / g;
	den = den / g;
 }
 const Rat operator +(const Rat& lhs, const Rat & rhs){
	 Rat r;
	 if (lhs.getDen() == rhs.getDen()){
		 r.setRat(rhs.getNum() + lhs.getNum(), lhs.getDen());
		 return r;
	 }
	 else {
		 r.setRat((lhs.getNum()*rhs.getDen()) + (lhs.getDen()*rhs.getNum()), lhs.getDen()*rhs.getDen());
		 return r;
	 }
		 
 }
 const Rat operator - (const Rat& lhs, const Rat & rhs){
	 Rat r;
	 if (lhs.getDen() == rhs.getDen()){
		 r.setRat(rhs.getNum() - lhs.getNum(), lhs.getDen());
		 return r;
	 }
	 else {
		 r.setRat((lhs.getNum()*rhs.getDen()) - (lhs.getDen()*rhs.getNum()), lhs.getDen()*rhs.getDen());
		 return r;
	 }

 }

  bool operator ==(const Rat& lhs, const Rat & rhs){
	  double l, r;
	  l = lhs.getNum() / lhs.getDen();
	  r = rhs.getNum() / rhs.getDen();
	  if (l == r)
		  return true;
	  else return false;
 }
  bool operator !=(const Rat& lhs, const Rat & rhs){
	  double l, r;
	  l = lhs.getNum() / lhs.getDen();
	  r = rhs.getNum() / rhs.getDen();
	  if (l != r)
		  return true;
	  else return false;
 }
#endif