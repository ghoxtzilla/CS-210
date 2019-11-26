/**
    CS-210 Course Audit Clock.cpp
    Purpose: Create a stopped clock that allows user
    to enter in seconds, minutes, and hours in 12-hour
    and 24-hour format

    @author Aaron Guyett
    @version 1.0 11/25/19
*/
#include<iostream>

using namespace std;

// Class declaration

class _24HourTime;

// Definition of enum which tracks AM or PM in 12 hour clock

enum AMPM {

	AM , PM

}ampm;

// Abstract class used to track time

class Time {

	public:

	int hour;

	int minute;

	int second;

	virtual void addOneHour() = 0;

	virtual void addOneMinute() = 0;

	virtual void addOneSecond() = 0;

};

// _12HourTime class which inherits the Time class

class _12HourTime : public Time {

	// Method to manage the 12 hour time

public:

_12HourTime(int h , int m , int s) {

	hour = h;

	minute = m;

	second = s;

	ampm = AM;

}

// Method to add one hour to the clock

void addOneHour() {

	if(hour == 11) {

		hour = 0;

		ampm = ampm == AM ? PM : AM;

	}else {

		hour += 1;

	}

}

// Method to add one minute to the clock

void addOneMinute() {

	if(minute == 59) {

		minute = 0;

		addOneHour();

	}else {

		minute += 1;

	}

}

// Method to add one second to the clock

void addOneSecond() {

	if(second == 59) {

		second = 0;

		addOneMinute();

	}else {

		second += 1;

	}

}

// Declare friend to give proper access

friend void displayTime(const _12HourTime& ,const _24HourTime&);

};

// _24HourTime class which inherits the Time class

class _24HourTime : public Time {

	// Method to manage 24 hour time

	public:

	_24HourTime(int h , int m , int s) {

		hour = h;

		minute = m;

		second = s;

	}

	// Method to add one hour to the clock

	void addOneHour() {

		if(hour == 23) {

			hour = 0;

		}else {

			hour += 1;

		}

	}

	// Method to add one minute to the clock

	void addOneMinute() {

		if(minute == 59) {

			minute = 0;

			addOneHour();

		}else {

			minute += 1;

		}

	}

	// Method to add one second to the clock

	void addOneSecond() {

		if(second == 59) {

			second = 0;

			addOneMinute();

		}else {

			second += 1;

		}

	}

	// Declaring friend to give proper access

	friend void displayTime(const _12HourTime& ,const _24HourTime&);

	};

	// Displaytime will be able to display time with appropriate formatting

	void displayTime(const _12HourTime& time12 ,const _24HourTime& time24) {

		cout << "*************************** ***************************\n";

		cout << "*     12-Hour Clock       * *      24-Hour Clock      *\n";

		cout << "*     "; if(time12.hour < 10) cout << "0"; cout << time12.hour << ":";

		if(time12.minute < 10 ) cout << "0" ; cout << time12.minute << ":";

		if(time12.second < 10) cout << "0"; cout << time12.second;

		if(ampm == AM ) cout << " A M"; else cout << " P M";

		cout << "        * *         ";

		if(time24.hour < 10) cout << "0"; cout << time24.hour << ":";

		if(time24.minute < 10 ) cout << "0" ; cout << time24.minute << ":";

		if(time24.second < 10) cout << "0"; cout << time24.second;

		cout << "        *\n";

		cout << "*************************** ***************************\n";

	}

	// Create the interface

	void displayMenu() {

		cout << "***************************\n";

		cout << "* 1 - Add One Hour        *\n";

		cout << "* 2 - Add One Minute      *\n";

		cout << "* 3 - Add One Second      *\n";

		cout << "* 4 - Exit Program        *\n";

		cout << "***************************\n";
	}

	// Declare main method

	int main() {

		//Create clocks

		_12HourTime time_12_Clock(11 , 59 , 59 );

		_24HourTime time_24_Clock(23,59,59);

		displayTime(time_12_Clock , time_24_Clock);

		while(true) {

			displayMenu();

			int choice;

			cin >> choice;

			// Add interface functionality

			switch (choice) {

			case 1:

				time_12_Clock.addOneHour();

				time_24_Clock.addOneHour();

				displayTime(time_12_Clock , time_24_Clock);

				break;

			case 2:

				time_12_Clock.addOneMinute();

				time_24_Clock.addOneMinute();

				displayTime(time_12_Clock , time_24_Clock);

				break;

			case 3:

				time_12_Clock.addOneSecond();

				time_24_Clock.addOneSecond();

				displayTime(time_12_Clock , time_24_Clock);

				break;

			case 4:

				cout << "Now exiting program.";

				exit(1);

				break;

			default:

				// Put an error check in place

				cout << "Error: Invalid choice. Please try again.\n";

				break;

		}
	}
}
