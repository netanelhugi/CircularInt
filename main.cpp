
#include <iostream>
using namespace std;

#include "CircularInt.hpp"


void ArithmeticOperatorsTest(){

	CircularInt hour {1, 12};
	CircularInt c1 {20,25};
	int i = 15;
	
	hour = 13; 
	cout << hour << endl;//1
	hour = c1;
	cout << hour << endl;//8
	
	cout << hour++ << endl;//8
	cout << hour << endl;//9
	cout << ++hour << endl;//10

	cout << hour-- << endl;//10
	cout << hour << endl;//9
	cout << --hour << endl;//8

	//hour=8//
	cout << -hour << endl;//4
	cout << hour+i << endl;//11(8+15=23)
	cout << hour-i << endl;//5(8-15=-7)
	cout << hour*i << endl;//12(8*15=120)
	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=8"
	}

	cout << i+hour << endl;//11
	cout << i-hour << endl;//7(15-8=7)
	cout << i*hour << endl;//12(15*8=120)
	try {
		cout << 3/hour;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=8"
	}

	//hour=8
	//c1=20
	cout << hour+c1 << endl;//7
	cout << hour-c1 << endl;//12
	cout << hour*c1 << endl;//4
	try {
		cout << c1/hour;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {20,25} such that x*8=20"
	}

	cout << hour%c1 << endl;//8
	cout << hour%3 << endl;//2
	cout << 20%hour << endl;//4

}

void ComparisonOperatorsTest(){

	CircularInt hour {1, 12};
	CircularInt c1 {1,12};
	int i = 15;
	
	bool a = hour==10;
	cout << a << endl;//0
	a = hour==c1;
	cout << a << endl;//1
	a = hour!=c1;
	cout << a << endl;//0
	a = hour!=10;
	cout << a << endl;//1
	a = hour>10;
	cout << a << endl;//0
	a = hour>c1;
	cout << a << endl;//0
	a = hour<10;
	cout << a << endl;//1
	a = hour<c1;
	cout << a << endl;//0
	a = hour>=10;
	cout << a << endl;//0
	a = hour>=c1;
	cout << a << endl;//1
	a = hour<=10;
	cout << a << endl;//1
	a = hour<=c1;
	cout << a << endl;//1

}


void LogicalOperatorsTest(){

	CircularInt hour {1, 12};
	CircularInt c1 {1,12};
	int i = 15;
	
	cout << !hour << endl;//12

	cout << endl;

	hour = hour&&0;
	cout << hour << endl;//12
	hour = i&&c1;
	cout << hour << endl;//1
	hour = hour&&c1;
	cout << hour << endl;//1

	cout << endl;

	hour = hour||0;
	cout << hour << endl;//1
	hour = i||c1;
	cout << hour << endl;//1
	hour = hour||c1;
	cout << hour << endl;//1
}

void BitwiseOperatorsTest(){

	CircularInt hour {1, 12};
	CircularInt c1 {1,12};
	int i = 15;

	hour = 7;
	
	cout << ~hour << endl;//4

	cout << endl;

	hour = hour&10;
	cout << hour << endl;//2
	hour = 5&hour;
	cout << hour << endl;//12
	hour = hour&c1;
	cout << hour << endl;//12

	cout << endl;

	hour = hour|10;
	cout << hour << endl;//2
	hour = 5|hour;
	cout << hour << endl;//7
	hour = hour|c1;
	cout << hour << endl;//7

	cout << endl;

	hour = hour^10;
	cout << hour << endl;//1
	hour = 5^hour;
	cout << hour << endl;//4
	hour = hour^c1;
	cout << hour << endl;//5

	cout << endl;

	hour = hour<<10;
	cout << hour << endl;//8
	hour = 5<<hour;
	cout << hour << endl;//8
	hour = hour<<c1;
	cout << hour << endl;//4

	cout << endl;

	hour = hour>>10;
	cout << hour << endl;//12
	hour = 5>>hour;
	cout << hour << endl;//12
	hour = hour>>c1;
	cout << hour << endl;//6
	
}

void CompoundOperatorsTest(){

	CircularInt hour {1, 12};
	CircularInt c1 {1,12};
	int i = 15;

	hour += 7;
	cout << hour << endl;//8
	hour += c1;
	cout << hour << endl;//9

	cout << endl;

	hour -= 7;
	cout << hour << endl;//2
	hour -= c1;
	cout << hour << endl;//1

	cout << endl;

	hour *= 7;
	cout << hour << endl;//7
	hour *= c1;
	cout << hour << endl;//7

	cout << endl;

	hour = 12;

	try {
		cout << hour/3 << endl;//4
	} catch (const string& message) {
		cout << message << endl; 
	}

	c1 = 5;

	try {
		cout << hour/c1 << endl;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*5=12"
	}


	cout << endl;

	hour %= 7;
	cout << hour << endl;//5
	hour %= c1;
	cout << hour << endl;//12


	cout << endl;

	hour &= 7;
	cout << hour << endl;//4
	hour &= c1;
	cout << hour << endl;//4

	cout << endl;

	hour |= 7;
	cout << hour << endl;//7
	hour |= c1;
	cout << hour << endl;//7

	cout << endl;

	hour ^= 7;
	cout << hour << endl;//12
	hour ^= c1;
	cout << hour << endl;//9

	cout << endl;

	hour <<= 7;
	cout << hour << endl;//12
	hour <<= c1;
	cout << hour << endl;//12

	cout << endl;

	hour >>= 3;
	cout << hour << endl;//1
	hour >>= c1;
	cout << hour << endl;//12


}


int main() {

	// ArithmeticOperatorsTest();
	// ComparisonOperatorsTest();
	// LogicalOperatorsTest();
	// BitwiseOperatorsTest();
	// CompoundOperatorsTest();

	CircularInt cii;
	
	cout << cii << " t" << endl;

	cin >> cii;

	cout << endl;

	cout << cii << " t" << endl;

	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	// CircularInt hour2 {5,25};

	// hour += hour2;

	// hour2 = hour;

	// bool a = hour==hour2;

	// hour = 10;
	// hour2 = 10;
	// int a0 = 4;
	// int a2 = 0;
	// int a1 = a2&&a0;

	// cout << hour << endl;


	// CircularInt ci = hour2&hour;

	// cout << a1 << endl;

	// 	cout << hour << endl;                     // 1

	
	// hour += 4;  cout << hour << endl;         // 5
	// (hour += 2)++;  cout << hour << endl;     // 8
	// hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	// cout << -hour << endl;                    // 10  (2 hours before midnight)
	// hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	// cout << hour+hour << endl;                // 10 (11 hours after 11)
	// hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	// cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	// try {
	// 	cout << hour/3;
	// } catch (const string& message) {
	// 	cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	// }

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}