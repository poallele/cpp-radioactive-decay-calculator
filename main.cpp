// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;



//=============================================================================================
// Task
//=============================================================================================
struct Timespan
{
	string			character;
	string			unit;
	int				divisorOfYearlySeconds;
};

struct Isotopes
{
	string			name;
	long double		halfLife;
};
//=============================================================================================



int main()
{
	//=============================================================================================
	// Task
	//=============================================================================================
	const
		int		GREGORIAN_CALENDAR_SECONDS		=	31556952;
		string	ERROR_MESSAGE		=	"Invalid character. ";


	bool
				exitLoop1			=	false,
				exitLoop2			=	false;


	string		response1{};		// controls exitLoop1 & responseIndex1


	int
				response2,			// controls exitLoop2 & responseIndex2
				responseIndex1{},
				responseIndex2{},
				downTheIsotopeNameList				=	0;


	long double
				decay{};
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	vector<Timespan> timespan =
	{
		{"s",	"second",	1},
		{"m",	"minute",	60},
		{"h",	"hour",		3600},
		{"d",	"day",		86400},
		{"y",	"year",		GREGORIAN_CALENDAR_SECONDS}
	};
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	cout
		<< "Select a timespan for measurement:"
		<< endl;

	for (const auto& currentTimespan:timespan)
	{
		cout
			<< '<'
			<< currentTimespan.character
			<< '>'
			<< ' ';
		
		cout
			<< currentTimespan.unit
			<< 's'
			<< endl;
	}
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	while (!exitLoop1)
	{									// 'exitLoop1' is initialized as false.
										// "while (exitLoop1)" means "while exitLoop1 is true..."
										// The (!) makes it negative.
										// exitLoop1 only becomes "true" by entering valid characters.
		
		cin >> response1;
		
		if												// 'If-else' conditionals are utilized instead of 'switch' statements
														// for their ability to use strings and logical comparisons.
			(response1 == timespan[0].character)
				{
					responseIndex1 = 0;
					exitLoop1 = true;
				}
		
		else if
			(response1 == timespan[1].character)
				{
					responseIndex1 = 1;
					exitLoop1 = true;
				}
		
		else if
			(response1 == timespan[2].character)
				{
					responseIndex1 = 2;
					exitLoop1 = true;
				}
		
		else if
			(response1 == timespan[3].character)
				{
					responseIndex1 = 3;
					exitLoop1 = true;
				}
		
		else if
			(response1 == timespan[4].character)
				{
					responseIndex1 = 4;
					exitLoop1 = true;
				}
		
		else
			{
				cout << ERROR_MESSAGE;
			}
	}
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	vector<Isotopes> isotopes =
	{
		{"Uranium-233",		1.592e5		*	(GREGORIAN_CALENDAR_SECONDS / timespan[responseIndex1].divisorOfYearlySeconds)},
		{"Uranium-235",		7.04e8		*	(GREGORIAN_CALENDAR_SECONDS / timespan[responseIndex1].divisorOfYearlySeconds)},
		{"Uranium-238",		4.463e9		*	(GREGORIAN_CALENDAR_SECONDS / timespan[responseIndex1].divisorOfYearlySeconds)},
		{"Plutonium-239",	2.411e4		*	(GREGORIAN_CALENDAR_SECONDS / timespan[responseIndex1].divisorOfYearlySeconds)},
		{"Thorium-232",		1.405e10	*	(GREGORIAN_CALENDAR_SECONDS / timespan[responseIndex1].divisorOfYearlySeconds)}
	};
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	// user prompt
	cout
		<< endl
		<< "Select a radioactive isotope:"
		<< endl;
	
	for (const auto & currentIsotope:isotopes)
	{
		downTheIsotopeNameList = downTheIsotopeNameList + 1;
		
		cout
			<< '<'
			<< downTheIsotopeNameList
			<< '>'
			<< ' ';
		
		cout
			<< currentIsotope.name
			<< endl;
	}
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	while (!exitLoop2)
	{
		cin >> response2;
		
		if (response2 == 1)
		{
			exitLoop2 = true;
		}
		else if (response2 == 2)
		{
			exitLoop2 = true;
		}
		else if (response2 == 3)
		{
			exitLoop2 = true;
		}
		else if (response2 == 4)
		{
			exitLoop2 = true;
		}
		else if (response2 == 5)
		{
			exitLoop2 = true;
		}
		
		else {
			cout << ERROR_MESSAGE;
		}
	}
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	
	/* since the index "[]" for a vector begins at 0, "-1" is used
	 * (since user responses begin at 1). if this was not used,
	 * then response2 would equal 6 instead of 5. since 6 is not
	 * present in the index, it would not return anything. */
	
	responseIndex2 = response2-1;

	/* decay constant | the natural logarithm of  2 divided by the half life.
	 * print the decay constant as a number with 20 decimal places. */
	
	decay = (log(2)) / isotopes[responseIndex2].halfLife;
	cout
		<< endl
		<< "Probability per"
		<< ' '
		<< timespan[responseIndex1].unit
		<< ' '
		<< "for a single"
		<< ' '
		<< isotopes[response2 - 1].name
		<< ' '
		<< "nucleus to decay:"
		<< ' '
		<< std::fixed
		<< std::setprecision(25)
		<< decay
		<< endl
		<< endl
		<< endl;

	
	
	return 0;
}
