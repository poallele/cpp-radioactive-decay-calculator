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
	const long double	GREGORIAN_CALENDAR_SECONDS = 31556952;
	const string		ERROR_MESSAGE = "Invalid character. ";

	// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf (PAGE 709 WILL ADD LATER)

	int AMOUNT_OF_MEASUREMENTS				= 5;	// default amount
	AMOUNT_OF_MEASUREMENTS					+= 1;	// How many more measurements do you want to add?
	vector<TimespanStruct>TimespanVector =
	{
		{"s",	"second",	1},
		{"m",	"minute",	60},
		{"h",	"hour",		3600},
		{"d",	"day",		86400},
		{"y",	"year",		GREGORIAN_CALENDAR_SECONDS},

		{"x",	"placeholder unit",	0.01}			// Add whatever new measurements you want down here
	};//===========================================================================================
	int AMOUNT_OF_ISOTOPES					= 5;	// default amount
	AMOUNT_OF_ISOTOPES						+= 1;	// How many more isotopes do you want to add?
	vector<IsotopeStruct>IsotopeVector =
	{
		{"Uranium-233",		1.592e5},
		{"Uranium-235",		7.04e8},
		{"Uranium-238",		4.463e9},
		{"Plutonium-239",	2.411e4},
		{"Thorium-232",		1.405e10},
		
		{"placeholder isotope",		1.47614e2},	// Add whatever new isotope you want down here
	};



	//=============================================================================================
	// Task
	//=============================================================================================
	string				chosenMeasurementUnitResponse;
	int					indexOfChosenMeasurementUnitsInVector{};
	bool				exitInputValidationLoopForMeasurementUnits = false;

	double				chosenIsotopeResponse;
	int					indexOfChosenIsotopeInVector{};
	bool				exitInputValidationLoopForIsotopes = false;

	int					numberedOrderOfIsotopes = 0;
	long double			decayConstant{};



	//=============================================================================================
	// Prompt 1
	//=============================================================================================
	cout
		<< "Select a timespan for measurement:"
		<< endl;

	for (const auto& currentTimespan : TimespanVector)
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
	while (!exitInputValidationLoopForMeasurementUnits)
	{									
		cin >> chosenMeasurementUnitResponse;

		for (int i = 0; i <= (AMOUNT_OF_MEASUREMENTS-1); i++)
		{
			if (chosenMeasurementUnitResponse == TimespanVector[i].firstCharacter)
			{
				indexOfChosenMeasurementUnitsInVector = i;
				exitInputValidationLoopForMeasurementUnits = true;
				break;
			}
		}
		
		if (exitInputValidationLoopForMeasurementUnits != true)
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

	for (const auto& currentIsotope : IsotopeVector)
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

		if
		(
			chosenIsotopeResponse == int(chosenIsotopeResponse / 1)
			&&
			chosenIsotopeResponse >= 1
			&&
			chosenIsotopeResponse <= AMOUNT_OF_ISOTOPES
			
		)
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

	indexOfChosenIsotopeInVector = chosenIsotopeResponse - 1;

	decayConstant =	// Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units

		(log(2) /
		IsotopeVector[indexOfChosenIsotopeInVector].halfLife)

		*

		(TimespanVector[indexOfChosenMeasurementUnitsInVector].secondsInASingularUnit /
		GREGORIAN_CALENDAR_SECONDS);

	cout
		<< endl
		<< "Probability per"
		<< ' '
		<< TimespanVector[indexOfChosenMeasurementUnitsInVector].unit
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
