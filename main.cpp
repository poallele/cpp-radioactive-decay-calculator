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
struct TimespanStruct
{
	string			firstCharacter;
	string			unit;
	long double		secondsInASingularUnit;
};

struct IsotopeStruct
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
	const long double	GREGORIAN_CALENDAR_SECONDS			=	31556952;
	const string		ERROR_MESSAGE						=	"Invalid character. ";


	string				chosenUnitResponse;
	int					vectorIndexOfChosenUnit{};
	bool				exitInputValidationLoopForUnits		=	false;


	int					chosenIsotopeResponse;
	int					vectorIndexOfChosenIsotope{};
	bool				exitInputValidationLoopForIsotopes	=	false;



	int					numberedOrderOfIsotopes				=	0;


	long double			decayConstant{};
	
	
	
	//=============================================================================================
	// Task
	//=============================================================================================
	vector<TimespanStruct> TimespanVector =
	{
		{"s",	"second",	1},
		{"m",	"minute",	60},
		{"h",	"hour",		3600},
		{"d",	"day",		86400},
		{"y",	"year",		GREGORIAN_CALENDAR_SECONDS}
	};
	
	
	vector<IsotopeStruct> IsotopeVector =
	{
		{"Uranium-233",		1.592e5},
		{"Uranium-235",		7.04e8},
		{"Uranium-238",		4.463e9},
		{"Plutonium-239",	2.411e4},
		{"Thorium-232",		1.405e10}
	};



	//=============================================================================================
	// Prompt 1
	//=============================================================================================
	cout
		<< "Select a timespan for measurement:"
		<< endl;

	for (const auto& currentTimespan:TimespanVector)
	{
		cout
			<< '<'
			<< currentTimespan.firstCharacter
			<< '>'
			<< ' '
			
			<< currentTimespan.unit
			<< 's'
			<< endl;
	}
	
	
	
	//=============================================================================================
	// Input Validation 1
	//=============================================================================================
	while (!exitInputValidationLoopForUnits)
	{									// 'exitInputValidationLoopForUnits' is initialized as false.
										// "while (exitInputValidationLoopForUnits)" means "while exitInputValidationLoopForUnits is true..."
										// The (!) makes it negative.
										// exitInputValidationLoopForUnits only becomes "true" by entering valid characters.
		
		cin >> chosenUnitResponse;
		
		if												// 'If-else' conditionals are utilized instead of 'switch' statements
														// for their ability to use strings and logical comparisons.
			(chosenUnitResponse == TimespanVector[0].firstCharacter)
				{
					vectorIndexOfChosenUnit = 0;
					exitInputValidationLoopForUnits = true;
				}
		
		else if
			(chosenUnitResponse == TimespanVector[1].firstCharacter)
				{
					vectorIndexOfChosenUnit = 1;
					exitInputValidationLoopForUnits = true;
				}
		
		else if
			(chosenUnitResponse == TimespanVector[2].firstCharacter)
				{
					vectorIndexOfChosenUnit = 2;
					exitInputValidationLoopForUnits = true;
				}
		
		else if
			(chosenUnitResponse == TimespanVector[3].firstCharacter)
				{
					vectorIndexOfChosenUnit = 3;
					exitInputValidationLoopForUnits = true;
				}
		
		else if
			(chosenUnitResponse == TimespanVector[4].firstCharacter)
				{
					vectorIndexOfChosenUnit = 4;
					exitInputValidationLoopForUnits = true;
				}
		
		else
			{
				cout << ERROR_MESSAGE;
			}
	}
	
	
	
	//=============================================================================================
	// Prompt 2
	//=============================================================================================
	cout
		<< endl
		<< "Select a radioactive isotope:"
		<< endl;
	
	for (const auto & currentIsotope:IsotopeVector)
	{
		numberedOrderOfIsotopes = numberedOrderOfIsotopes + 1;
		
		cout
			<< '<'
			<< numberedOrderOfIsotopes
			<< '>'
			<< ' '
			
			<< currentIsotope.name
			<< endl;
	}
	
	
	
	//=============================================================================================
	// Input Validation 2
	//=============================================================================================
	while (!exitInputValidationLoopForIsotopes)
	{
		cin >> chosenIsotopeResponse;
		
		if (chosenIsotopeResponse == 1)
			{
				exitInputValidationLoopForIsotopes = true;
			}
		
		else if (chosenIsotopeResponse == 2)
			{
				exitInputValidationLoopForIsotopes = true;
			}
		
		else if (chosenIsotopeResponse == 3)
			{
				exitInputValidationLoopForIsotopes = true;
			}
		
		else if (chosenIsotopeResponse == 4)
			{
				exitInputValidationLoopForIsotopes = true;
			}
		
		else if (chosenIsotopeResponse == 5)
			{
				exitInputValidationLoopForIsotopes = true;
			}
		
		else
			{
				cout << ERROR_MESSAGE;
			}
	}
	
	
	
	//=============================================================================================
	// Print final output
	//=============================================================================================
	
	/* since the index "[]" for a vector begins at 0, "-1" is used
	 * (since user responses begin at 1). if this was not used,
	 * then chosenIsotopeResponse would equal 6 instead of 5. since 6 is not
	 * present in the index, it would not return anything. */
	
	vectorIndexOfChosenIsotope = chosenIsotopeResponse-1;

	decayConstant =	// Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units
		
		(log(2) /
		IsotopeVector[vectorIndexOfChosenIsotope].halfLife)
		
		*

		(GREGORIAN_CALENDAR_SECONDS /
		TimespanVector[vectorIndexOfChosenUnit].secondsInASingularUnit);
	

	cout
		<< endl
		<< "Probability per"
		<< ' '
		<< TimespanVector[vectorIndexOfChosenUnit].unit
		<< ' '
		<< "for a single"
		<< ' '
		<< IsotopeVector[chosenIsotopeResponse - 1].name
		<< ' '
		<< "nucleus to decay:"
		<< ' '
		<< fixed
		<< setprecision(25)
		<< decayConstant
		<< endl
		<< endl
		<< endl;

	
	
	return 0;
}
