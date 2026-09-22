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

void DEFAULT(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 7);}
void INVERTED(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 112);}

void GFG_BBG(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 2);}
void MFG_BBG(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 5);}
void WFG_GBG(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 39);}

void POALLELE(HANDLE hConsole) {SetConsoleTextAttribute(hConsole, 71);}
//=============================================================================================

int main()
{
    //=============================================================================================
    // Task
    //=============================================================================================
    const long double   GREGORIAN_CALENDAR_SECONDS = 31556952;
    const string		ERROR_MESSAGE = "Invalid character. ";

    const string        CMDQuestion = "Are you currently running Windows 11's 'Terminal' (not 'conhost.exe' or any other program)? <y/n>";
    const string        instruction1 = "SELECT A MEASUREMENT";
    const string        instruction2 = "SELECT AN ISOTOPE";
    const string        instruction1Specs = "SECONDS PER UNIT";
    const string        instruction2Specs = "HALF LIFE IN YEARS";

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
    char                CMDResponse;
    bool				exitInputValidationLoopForCMD = false;
    int                 defaultNonFullscreenHorizontalSpaceWin10CMDPrompt;
    
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
    // CMD Width prompt
    //=============================================================================================
    cout << CMDQuestion << endl;
    
    while (exitInputValidationLoopForCMD != true)
    {
        cin >> CMDResponse;

        if (CMDResponse == 'y')
        {
            defaultNonFullscreenHorizontalSpaceWin10CMDPrompt = 120;
            exitInputValidationLoopForCMD = true;
        }
        else if (CMDResponse == 'n')
        {
            defaultNonFullscreenHorizontalSpaceWin10CMDPrompt = 80;
            exitInputValidationLoopForCMD = true;
        }
        else
        {
            cout << ERROR_MESSAGE;
        }
    }
    
    
    
    //=============================================================================================
    // Prompt 1
    //=============================================================================================
    string LINE_BREAK(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt, '_');
    cout << LINE_BREAK << endl;
    
    INVERTED(hConsole);
    cout << instruction1 << setw(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt - instruction1.length()) << instruction1Specs << endl;
    DEFAULT(hConsole);

    
    
    
    // Use an iterator to display the vector contents.
    for (auto& currentMeasurement : TimespanVector)                 // PAGE 434
    {
        spaceTaken = currentMeasurement.unit.length();

        INVERTED(hConsole);
        cout << '<' << currentMeasurement.firstCharacter << '>';
        DEFAULT(hConsole);

        cout
            << ' '
            << currentMeasurement.unit
            << "(s)"
            << ':'

            << setw(
                defaultNonFullscreenHorizontalSpaceWin10CMDPrompt
                - instruction1.length()
                - currentMeasurement.unit.length()
                - currentMeasurement.firstCharacter.length()
                + 12
            );

        MFG_BBG(hConsole);
        cout << currentMeasurement.secondsInASingularUnit;
        DEFAULT(hConsole);
        cout << '|' << endl;
    }



    //=============================================================================================
    // Input Validation 1
    //=============================================================================================
    INVERTED(hConsole);
    cin >> chosenMeasurementUnitResponse;
    DEFAULT(hConsole);

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


    
    //=============================================================================================
    // Prompt 2
    //=============================================================================================
    cout << LINE_BREAK << endl;
    
    INVERTED(hConsole);
    cout << instruction2 << setw(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt - instruction2.length()) << instruction2Specs << endl;
    DEFAULT(hConsole);



    // Use an iterator to display the vector contents.
    for (auto& currentIsotope : IsotopeVector)                      // PAGE 434
    {
        numberedOrderOfIsotopes = numberedOrderOfIsotopes + 1;
        spaceTaken = currentIsotope.name.length();

        INVERTED(hConsole);
        cout << '<' << numberedOrderOfIsotopes << '>';
        DEFAULT(hConsole);

        cout
            << ' '
            << currentIsotope.name
            << ':'

            << setw(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt
                - instruction2.length()
                - currentIsotope.name.length()
                - to_string(numberedOrderOfIsotopes).length()       // 613
                + 12
            );

        GFG_BBG(hConsole);
        cout << currentIsotope.halfLife;
        DEFAULT(hConsole);
        cout << '|' << endl;
    }



    //=============================================================================================
    // Input Validation 2
    //=============================================================================================
    INVERTED(hConsole);
    cin >> chosenIsotopeResponse;
    DEFAULT(hConsole);


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

    INVERTED(hConsole);
    cout
        << "The decay constant of"
        << ' '
        << IsotopeVector[chosenIsotopeResponse - 1].name
        << ' '
        << "(when measuring in"
        << ' '
        << TimespanVector[indexOfChosenMeasurementUnitsInVector].unit
        << "s)"
        << ' '
        << "is";
    DEFAULT(hConsole);

    cout << ' ';

    WFG_GBG(hConsole);
    cout
        << fixed
        << setprecision(25)
        << decayConstant;
    DEFAULT(hConsole);

    cout << '.';
    
    INVERTED(hConsole);
    cout
        << endl
        << "In other words, this value is the probability per"
        << ' '
        << TimespanVector[indexOfChosenMeasurementUnitsInVector].unit
        << ' '
        << "for a single"
        << ' '
        << IsotopeVector[chosenIsotopeResponse - 1].name
        << ' '
        << "nucleus to decay.";
    DEFAULT(hConsole);

    cout
        << endl
        << endl
        << endl;
    
    POALLELE(hConsole);
    cout << "@poallele";
    DEFAULT(hConsole);

    fstream dataFile3("copyPaste.txt", ios::out);
    dataFile3
        << fixed
        << setprecision(25)
        << decayConstant;
    dataFile3.close();

    return 0;
}
