#include<iostream>

using namespace std;

class Clock {
private:
	int minute;
	int hour;
public:
	// default constructor
	Clock() {
		//add code to initialize minute to 0  
		minute = 0;
		hour = 0;
	};

	// mutators
	bool setMinute(int min) {
		//add code here to  
		//	validate min (must be >=0 and < 60)  
		//	and use it to set minute  
		//	if min was valid, return true, else return false  
	};
	bool setHour(int hr) {
		if (hr >= 1 && hr <= 12) {
			hour = hr;
			return true;
		}
		return false;
	}

	// accessors
	int getMinute() {
		//add code to return the value in minute  
		return minute;
	};
	int getHour() {
		return hour;
	}
};

int main() {
	//add code there to:  
	//	declare a variable of type clock  
	Clock bigBen;

	// test setMinute with both valid and invalid values  
	bigBen.setHour(13);
	bigBen.setHour(12);

	//	test getMinute  
	bigBen.getHour();
	cout << bigBen.getHour();
}