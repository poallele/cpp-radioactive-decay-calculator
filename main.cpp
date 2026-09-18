// CPPRadioactiveDecayCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Measurement
{
	string character;
	string unit;
	int multiplier;
};

struct Isotopes
{
	string name;
	long double value;
};

int main()
{
	//=============================================================================================
	// Task
	//=============================================================================================
	const int GREGORIAN_SECONDS = 31556952;
	vector<Measurement> measurement =
	{
		{"s","second",GREGORIAN_SECONDS / 1},
		{"m","minute",GREGORIAN_SECONDS / 60},
		{"h","hour",GREGORIAN_SECONDS / 3600},
		{"d","day",GREGORIAN_SECONDS / 86400},
		{"y","year",GREGORIAN_SECONDS / GREGORIAN_SECONDS}
	};
	//=============================================================================================
	// Task
	//=============================================================================================
	string errorMessage = "Invalid character. ";

	/* user prompt. 'print' = (std::cout <<). 'submit' = (std::cin >>).
	 * exitLoop1 is initialized as false. while (exitLoop1)
	 * means "while exitLoop1 is true". the (!) makes it negative.
	 * exitLoop1 only becomes "true" by entering valid characters.
	 * "if-else" conditionals are utilized instead of "switch" statements
	 * for their ability to use strings and logical comparisons. */
	bool exitLoop1 = false;
	string response1{};
	int responseIndex1{};
	int count1{};
	cout << "Would you like to measure in:\n";

	for (const auto& m : measurement)
	{
		cout
			<< "<"
			<< measurement[count1].character
			<< "> "
			<< measurement[count1].unit
			<< "s\n";
		count1 += 1;
	}
	//=============================================================================================
	// Task
	//=============================================================================================
	while (!exitLoop1)
	{
		cin >> response1;
		if (response1 == measurement[0].character) {
			responseIndex1 = 0;
			exitLoop1 = true;
		}
		else if (response1 == measurement[1].character) {
			responseIndex1 = 1;
			exitLoop1 = true;
		}
		else if (response1 == measurement[2].character) {
			responseIndex1 = 2;
			exitLoop1 = true;
		}
		else if (response1 == measurement[3].character) {
			responseIndex1 = 3;
			exitLoop1 = true;
		}
		else if (response1 == measurement[4].character) {
			responseIndex1 = 4;
			exitLoop1 = true;
		}
		else {
			cout << errorMessage;
		}
	}
	//=============================================================================================
	// Task
	//=============================================================================================
	vector<Isotopes> isotopes =
	{
		{"Uranium-233",1.592e5 * measurement[responseIndex1].multiplier},
		{"Uranium-235",7.04e8 * measurement[responseIndex1].multiplier},
		{"Uranium-238",4.463e9 * measurement[responseIndex1].multiplier},
		{"Plutonium-239",2.411e4 * measurement[responseIndex1].multiplier},
		{"Thorium-232",1.40e10 * measurement[responseIndex1].multiplier}
	};
	//=============================================================================================
	// Task
	//=============================================================================================
	// user prompt
	bool exitLoop2 = false;
	int response2{};
	int count2 = 0;
	cout << "Select a fertile radioactive isotope:\n";
	for (const auto& i : isotopes)
	{
		count2 += 1;
		cout << "<" << count2 << "> " << i.name << '\n';
	}
	//=============================================================================================
	// Task
	//=============================================================================================
	while (!exitLoop2)
	{
		cin >> response2;
		if (response2 == 1) {
			exitLoop2 = true;
		}
		else if (response2 == 2) {
			exitLoop2 = true;
		}
		else if (response2 == 3) {
			exitLoop2 = true;
		}
		else if (response2 == 4) {
			exitLoop2 = true;
		}
		else if (response2 == 5) {
			exitLoop2 = true;
		}
		else {
			cout << errorMessage;
		}
	}
	//=============================================================================================
	// Task
	//=============================================================================================
	/* since the index "[]" for a vector begins at 0, "-1" is used
	 * (since user responses begin at 1). if this was not used,
	 * then response2 would equal 6 instead of 5. since 6 is not
	 * present in the index, it would not return anything. */
	int responseIndex2{ response2 - 1 };

	/* decay constant | the natural logarithm of  2 divided by the half life.
	 * print the decay constant as a number with 20 decimal places. */
	const double decay = (log(2)) / isotopes[responseIndex2].value;
	cout
		<< "Probability per " << measurement[responseIndex1].unit
		<< " for a single "
		<< isotopes[response2 - 1].name
		<< " nucleus to decay: "
		<< std::fixed
		<< std::setprecision(25)
		<< decay;

	return 0;
}
