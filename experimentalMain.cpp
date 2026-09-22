// This program demonstrates the getline function with
// a specified delimiter.

// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>

#include <Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
    const long double   GREGORIAN_CALENDAR_SECONDS = 31556952;
    const string		ERROR_MESSAGE = "Invalid character. ";
    const string        LINE_BREAK = "__________________________________________________________";

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
    string				chosenMeasurementUnitResponse;
    int					indexOfChosenMeasurementUnitsInVector{};
    bool				exitInputValidationLoopForMeasurementUnits = false;

    double				chosenIsotopeResponse;
    int					indexOfChosenIsotopeInVector{};
    bool				exitInputValidationLoopForIsotopes = false;

    string              input1; // To hold file input
    string              input2; // To hold file input
    string              input3; // To hold file input
    string              input4; // To hold file input
    string              input5; // To hold file input
    
    string              promptStarter = "Select a";
    string              prompt1         = " Measurement.";
    string              prompt2         = "n Isotope.";
    
    int                 spaceTaken;
    
    int                 numberedOrderOfIsotopes = 0;

    long double			decayConstant;
    
    
    
    //=============================================================================================
    // File retrieval 1
    //=============================================================================================
    // Open the file for input.
    fstream dataFile("listOfMeasurements.txt", ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile)
    {
        // While the last read operation was successful, continue.
        while (dataFile)
        {
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
    
    
    
    //=============================================================================================
    // File retrieval 2
    //=============================================================================================
    // Open the file for input.
    fstream dataFile2("listOfIsotopes.txt", ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile2)
    {
        // While the last read operation was successful, continue.
        while (dataFile2)
        {
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
    
    
    
    //=============================================================================================
    // Prompt 1
    //=============================================================================================
    SetConsoleTextAttribute(hConsole, 112);
    spaceTaken = prompt1.length();
    cout << promptStarter << prompt1 << setw(50 - spaceTaken) << "SECONDS IN A SINGULAR UNIT:" << endl;
    SetConsoleTextAttribute(hConsole, 7);
    
    // Use an iterator to display the vector contents.
    for (auto& currentMeasurement : TimespanVector)                 // PAGE 434
    {
        spaceTaken = currentMeasurement.unit.length();

        SetConsoleTextAttribute(hConsole, 112);
        cout << '<' << currentMeasurement.firstCharacter << '>';
        SetConsoleTextAttribute(hConsole, 7);
        
        cout
            << ' '
            << currentMeasurement.unit
            << "(s)"
            << ':'

            << setw(50 - 1 - spaceTaken);


        SetConsoleTextAttribute(hConsole, 5);
        cout << currentMeasurement.secondsInASingularUnit;
        SetConsoleTextAttribute(hConsole, 7);
        cout << '|' << endl;
    }
    

    
    //=============================================================================================
    // Input Validation 1
    //=============================================================================================
    SetConsoleTextAttribute(hConsole, 112);
    cin >> chosenMeasurementUnitResponse;
    SetConsoleTextAttribute(hConsole, 7);
    
    //while (exitInputValidationLoopForMeasurementUnits != true)
    //{
    //    cin >> chosenMeasurementUnitResponse;
    //
    //
    //    
    //    if (exitInputValidationLoopForMeasurementUnits == false)
    //    {
    //        cout << ERROR_MESSAGE;
    //    }
    //}


    cout << LINE_BREAK << endl;
    //=============================================================================================
    // Prompt 2
    //=============================================================================================
    SetConsoleTextAttribute(hConsole, 112);
    spaceTaken = prompt2.length();
    cout << promptStarter << prompt2 << setw(50 - spaceTaken) << "HALF LIFE IN YEARS:" << endl;
    SetConsoleTextAttribute(hConsole, 7);
    
    // Use an iterator to display the vector contents.
    for (auto& currentIsotope : IsotopeVector)                      // PAGE 434
    {
        numberedOrderOfIsotopes = numberedOrderOfIsotopes + 1;
        spaceTaken = currentIsotope.name.length();

        SetConsoleTextAttribute(hConsole, 112);
        cout << '<' << numberedOrderOfIsotopes << '>';
        SetConsoleTextAttribute(hConsole, 7);
        
        cout
            << ' '
            << currentIsotope.name
            << ':'

            << setw(50 + 2 - spaceTaken);

        SetConsoleTextAttribute(hConsole, 2);
        cout << currentIsotope.halfLife;
        SetConsoleTextAttribute(hConsole, 7);
        cout << '|' << endl;
    }
    
    
    
    //=============================================================================================
    // Input Validation 2
    //=============================================================================================
    SetConsoleTextAttribute(hConsole, 112);
    cin >> chosenIsotopeResponse;
    SetConsoleTextAttribute(hConsole, 7);
    

    cout << LINE_BREAK << endl;
    //=============================================================================================
    // Print final output
    //=============================================================================================

    /* since the index "[]" for a vector begins at 0, "-1" is used
     * (since user responses begin at 1). if this was not used,
     * then chosenIsotopeResponse would equal 6 instead of 5. since 6 is not
     * present in the index, it would not return anything. */

    indexOfChosenIsotopeInVector = chosenIsotopeResponse - 1;

    decayConstant =	// Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units

            (log(2)
            
            /
            
            IsotopeVector[indexOfChosenIsotopeInVector].halfLife)

            *

            (TimespanVector[indexOfChosenMeasurementUnitsInVector].secondsInASingularUnit
                
            /
            
            GREGORIAN_CALENDAR_SECONDS);

    SetConsoleTextAttribute(hConsole, 112);
    cout
        << "Probability per"
        << ' '
        << TimespanVector[indexOfChosenMeasurementUnitsInVector].unit
        << ' '
        << "for a single"
        << ' '
        << IsotopeVector[chosenIsotopeResponse - 1].name
        << ' '
        << "nucleus to decay:";
    SetConsoleTextAttribute(hConsole, 7);
        
    cout
        << ' '
        << fixed
        << setprecision(25)
        << decayConstant
        
        << endl
        << endl
        << endl;
    
    SetConsoleTextAttribute(hConsole, 71);
    cout << "@poallele";
    SetConsoleTextAttribute(hConsole, 7);

    fstream dataFile3("copyPaste.txt", ios::out);
    dataFile3
        << fixed
        << setprecision(25)
        << decayConstant;
    dataFile3.close();

    return 0;
}
