// This program demonstrates the getline function with
// a specified delimiter.

// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

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

int main()
{
    const long double GREGORIAN_CALENDAR_SECONDS = 31556952;
    string input1; // To hold file input
    string input2; // To hold file input
    string input3; // To hold file input
    string input4; // To hold file input
    string input5; // To hold file input
    int numberedOrderOfIsotopes = 0;
    int spaceTaken;

    vector<TimespanStruct>TimespanVector =
    {
        {"s",	"second",	1},
        {"m",	"minute",	60},
        {"h",	"hour",		3600},
        {"d",	"day",		86400},
        {"y",	"year",		GREGORIAN_CALENDAR_SECONDS},
    };
    vector<IsotopeStruct>IsotopeVector =
    {
        {"Uranium-233",		1.592e5},
        {"Uranium-235",		7.04e8},
        {"Uranium-238",		4.463e9},
        {"Plutonium-239",	2.411e4},
        {"Thorium-232",		1.405e10},
    };
    //=============================================================================================
    // Task
    //=============================================================================================
    // Open the file for input.
    fstream dataFile("listOfMeasurements.txt", ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile)
    {
        // While the last read operation was successful, continue.
        while (dataFile)
        {
            // Display the last item read.
            cout << input1 << endl;

            // Read an item using ':' as a delimiter.
            getline(dataFile, input1, ':');
            getline(dataFile, input2, ':');
            getline(dataFile, input3);

            long double input3LongDouble = stold(string(input3));   // PAGE 612

            TimespanVector.emplace_back(input1, input2, input3LongDouble);     // PAGE 1080
        }

        // Close the file.
        dataFile.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }
    cout << endl;
    //=============================================================================================
    // Task
    //=============================================================================================
    // Use an iterator to display the vector contents.
    for (auto& currentMeasurement : TimespanVector)                 // PAGE 434
    {
        spaceTaken = currentMeasurement.unit.length();

        cout
            << '<'
            << currentMeasurement.firstCharacter
            << '>'
            << ' '

            << currentMeasurement.unit
            << ':'

            << setw(50 - spaceTaken)
            << "Seconds in a singular unit: "
            << currentMeasurement.secondsInASingularUnit
            << endl;
    }
    //=============================================================================================
    // Task
    //=============================================================================================
    // Open the file for input.
    fstream dataFile2("listOfIsotopes.txt", ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile2)
    {
        // While the last read operation was successful, continue.
        while (dataFile2)
        {
            // Display the last item read.
            cout << input4 << endl;

            // Read an item using ':' as a delimiter.
            getline(dataFile2, input4, ':');
            getline(dataFile2, input5);

            long double input5LongDouble = stold(string(input5));   // PAGE 612

            IsotopeVector.emplace_back(input4, input5LongDouble);     // PAGE 1080
        }

        // Close the file.
        dataFile2.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }
    cout << endl;
    //=============================================================================================
    // Task
    //=============================================================================================
    // Use an iterator to display the vector contents.
    for (auto& currentIsotope : IsotopeVector)                      // PAGE 434
    {
        numberedOrderOfIsotopes = numberedOrderOfIsotopes + 1;
        spaceTaken = currentIsotope.name.length();
        
        cout
            << '<'
            << numberedOrderOfIsotopes
            << '>'
            << ' '

            << currentIsotope.name
            << ':'
            
            << setw(33 - spaceTaken)
            << "Half life: "
            << currentIsotope.halfLife
            << endl;
    }

    return 0;
}
