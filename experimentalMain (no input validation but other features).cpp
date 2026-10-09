// This program demonstrates the getline function with
// a specified delimiter.

// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf
// For Windows users: go on Visual Studio and do CTRL F, then CTRL H. Replace '///' with nothing (aka 'Replace...')

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
// Task
//=============================================================================================
const int HCONSOLE_DEEP_BLUE = 1;
const int HCONSOLE_DEEP_GREEN = 2;
const int HCONSOLE_DEEP_AQUA = 3;
const int HCONSOLE_DEEP_RED = 4;
const int HCONSOLE_DEEP_MAGENTA = 5;
const int HCONSOLE_DEEP_YELLOW = 6;

const int HCONSOLE_LIGHT_BLUE = 9;
const int HCONSOLE_LIGHT_GREEN = 10;
const int HCONSOLE_LIGHT_AQUA = 11;
const int HCONSOLE_LIGHT_RED = 12;
const int HCONSOLE_LIGHT_MAGENTA = 13;
const int HCONSOLE_LIGHT_YELLOW = 14;

const int HCONSOLE_WHITE = 15;
const int HCONSOLE_LIGHT_GRAY = 7;
const int HCONSOLE_GRAY = 8;
const int HCONSOLE_BLACK = 0;

// (FOREGROUND + (BACKGROUND * 16)) = COLOR
//===============================================================================
void DEFAULT // DEFAULT DISPLAY TEXT
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_LIGHT_AQUA + // CYAN FOREGROUND
        HCONSOLE_BLACK * 16); // BLACK BACKGROUND
}
void INVERTED
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_BLACK +
        HCONSOLE_LIGHT_AQUA * 16);
}
void FLAIR
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_BLACK +
        HCONSOLE_LIGHT_MAGENTA * 16);
}
//===============================================================================
void MEASUREMENT_COLOR_THICK
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_BLACK +
        HCONSOLE_DEEP_BLUE * 16);
}
void MEASUREMENT_COLOR_THIN
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_DEEP_BLUE +
        HCONSOLE_BLACK * 16);
}
void ISOTOPE_COLOR_THICK
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_BLACK +
        HCONSOLE_LIGHT_GREEN * 16);
}
void ISOTOPE_COLOR_THIN
    (HANDLE hConsole) {SetConsoleTextAttribute(hConsole,
        HCONSOLE_LIGHT_GREEN +
        HCONSOLE_BLACK * 16);
}
//=============================================================================================

int main()
{
    const char          YES = 'y';
    const char          NO = 'n';
    const string        WHITESPACE = " ";
    const string        BACKSPACE = "\b \b";

    const string        BORDER = "|";
    const string        BRACKET = "<";
    const string        BRACKET_2 = ">";
    const char          LINE_BREAK_CHAR = '=';

    const char          FILE_DELIMITER = ':';

    const string        MEASUREMENTS_FILE = "listOfMeasurements.txt";
    const string        ISOTOPES_FILE = "listOfIsotopes.txt";
    const string        OUTPUT_FILE = "copyPaste.txt";

    const string        DEVELOPER_NAME = "poallele";
    const string        DEVELOPER_LINK_1 = "https://github.com/";
    const string        DEVELOPER_LINK_2 = "/cpp-radioactive-decay-calculator";
    //=============================================================================================
    // Task
    //=============================================================================================
    const long double   GREGORIAN_CALENDAR_SECONDS = 31556952;
    
    const string		ERROR_MESSAGE = "Invalid character. ";
    const string		FILE_ERROR_MESSAGE = "ERROR: Cannot open file.\n";
    const string        CMDQuestion =
                                        "Press " + BRACKET + "key" + BRACKET_2 + ", then 'enter'."
                                        "\nAre you currently running Windows 11's 'Terminal' (not 'conhost.exe' or any other program)? " + BRACKET + YES + "/" + NO + BRACKET_2 + WHITESPACE;
    
    const string        instruction1 = "MEASUREMENT (replacethistextwithoutbreakingtheprogram)";
    const string        instruction1Specs = " (per unit) SECONDS";
    const string        instruction2 = "ISOTOPE (replacethistextwithoutbreakingtheprogram)";
    const string        instruction2Specs = "(yrs) HALF LIFE";

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
    
    string              print1 = "Decay constant: ";
    string              print4 = "This value is the probability per [";
    string              print5 = "] for a single [";
    string              print6 = "] nucleus to decay.";
    string              print7 = "Check" + OUTPUT_FILE + "to copy and paste it.";

    int                 spaceTaken;

    int                 numberedOrderOfIsotopes = 0;

    long double			decayConstant;



    //=============================================================================================
    // File retrieval 1
    //=============================================================================================
    // Open the file for input.
    fstream dataFile(MEASUREMENTS_FILE, ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile)
    {
        // While the last read operation was successful, continue.
        while (dataFile)
        {
            // Read an item using ':' as a delimiter.
            getline(dataFile, input1, FILE_DELIMITER);
            getline(dataFile, input2, FILE_DELIMITER);
            getline(dataFile, input3);

            long double input3LongDouble = stold(string(input3));   // PAGE 612

            TimespanVector.emplace_back(input1, input2, input3LongDouble);     // PAGE 1080
        }

        // Close the file.
        dataFile.close();
    }
    else
    {
        cout << FILE_ERROR_MESSAGE;
    }



    //=============================================================================================
    // File retrieval 2
    //=============================================================================================
    // Open the file for input.
    fstream dataFile2(ISOTOPES_FILE, ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile2)
    {
        // While the last read operation was successful, continue.
        while (dataFile2)
        {
            // Read an item using ':' as a delimiter.
            getline(dataFile2, input4, FILE_DELIMITER);
            getline(dataFile2, input5);

            long double input5LongDouble = stold(string(input5));   // PAGE 612

            IsotopeVector.emplace_back(input4, input5LongDouble);     // PAGE 1080
        }

        // Close the file.
        dataFile2.close();
    }
    else
    {
        cout << FILE_ERROR_MESSAGE;
    }



    //=============================================================================================
    // CMD Width prompt
    //=============================================================================================
    DEFAULT(hConsole);
    cout << CMDQuestion;
    

    DEFAULT(hConsole);
    while (exitInputValidationLoopForCMD != true)
    {
        INVERTED(hConsole);
        cin >> CMDResponse;
        

        DEFAULT(hConsole);
        if (CMDResponse == YES)
        {
            defaultNonFullscreenHorizontalSpaceWin10CMDPrompt = 120 - 2;
            exitInputValidationLoopForCMD = true;
        }
        else if (CMDResponse == NO)
        {
            defaultNonFullscreenHorizontalSpaceWin10CMDPrompt = 80 - 2;
            exitInputValidationLoopForCMD = true;
        }
        else
        {
            cout << ERROR_MESSAGE;
        }
    }
    cout << endl;
    cout << setw(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt - DEVELOPER_NAME.length() - 1);
    cout << WHITESPACE;

    FLAIR(hConsole);
    cout << '@' << DEVELOPER_NAME;
    
    string LINE_BREAK(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt, LINE_BREAK_CHAR);
    //=============================================================================================
    // Prompt 1
    //=============================================================================================
    DEFAULT(hConsole);
    cout << endl;

    
    cout << LINE_BREAK << endl;
    
    
    
    INVERTED(hConsole);
    cout << instruction1 << setw(defaultNonFullscreenHorizontalSpaceWin10CMDPrompt - instruction1.length()) << instruction1Specs << endl;
    


    // Use an iterator to display the vector contents.
    for (auto& currentMeasurement : TimespanVector)                 // PAGE 434
    {
        cout << endl;
        spaceTaken = currentMeasurement.unit.length();

        INVERTED(hConsole);
        cout << BRACKET;
        DEFAULT(hConsole);
        cout << currentMeasurement.firstCharacter;
        INVERTED(hConsole);
        cout << BRACKET_2;

        DEFAULT(hConsole);
        cout
            << WHITESPACE
            << currentMeasurement.unit

            << setw(
                defaultNonFullscreenHorizontalSpaceWin10CMDPrompt
                - currentMeasurement.unit.length()
                - currentMeasurement.firstCharacter.length()
                - to_string(currentMeasurement.secondsInASingularUnit).length()
                - (BRACKET.length()) - (BRACKET_2.length()) - (BORDER.length()) - (WHITESPACE.length())
            );

        cout << WHITESPACE;
        
        MEASUREMENT_COLOR_THICK(hConsole);
        cout << to_string(currentMeasurement.secondsInASingularUnit);
        
        
        FLAIR(hConsole);
        cout << BORDER;
    }
    cout << BACKSPACE << flush;


    //=============================================================================================
    // Input Validation 1
    //=============================================================================================
    FLAIR(hConsole);
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



    // Use an iterator to display the vector contents.
    for (auto& currentIsotope : IsotopeVector)                      // PAGE 434
    {
        numberedOrderOfIsotopes = numberedOrderOfIsotopes + 1;
        spaceTaken = currentIsotope.name.length();


        INVERTED(hConsole);
        cout << endl << BRACKET;
        DEFAULT(hConsole);
        cout << numberedOrderOfIsotopes;
        INVERTED(hConsole);
        cout << BRACKET_2;
        
        DEFAULT(hConsole);
        cout
            << WHITESPACE
            << currentIsotope.name

            << setw(
                defaultNonFullscreenHorizontalSpaceWin10CMDPrompt
                - currentIsotope.name.length()
                - to_string(numberedOrderOfIsotopes).length()       // 613
                - to_string(currentIsotope.halfLife).length()
                - (BRACKET.length()) - (BRACKET_2.length()) - (BORDER.length()) - (WHITESPACE.length())
            );

        cout << WHITESPACE;
        
        ISOTOPE_COLOR_THICK(hConsole);
        cout << to_string(currentIsotope.halfLife);
        
        
        FLAIR(hConsole);
        cout << BORDER;
    }
    cout << BACKSPACE << flush;


    //=============================================================================================
    // Input Validation 2
    //=============================================================================================
    FLAIR(hConsole);
    cin >> chosenIsotopeResponse;
    DEFAULT(hConsole);


    cout << LINE_BREAK << endl;



    //=============================================================================================
    // Print final output
    //=============================================================================================
    indexOfChosenIsotopeInVector = chosenIsotopeResponse - 1;   // since the index "[]" for a vector begins at 0, "-1" is used
                                                                // (since user responses begin at 1). if this was not used,
                                                                // then chosenIsotopeResponse would equal 6 instead of 5. since 6 is not
                                                                // present in the index, it would not return anything.

    
    decayConstant = // Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units
    (log(2) / IsotopeVector[indexOfChosenIsotopeInVector].halfLife) *
    (TimespanVector[indexOfChosenMeasurementUnitsInVector].secondsInASingularUnit / GREGORIAN_CALENDAR_SECONDS);

    
    //=============================================================================================
    // Print final output
    //=============================================================================================
    DEFAULT(hConsole);
    cout << print1;
    
    
    
    INVERTED(hConsole);
    cout << fixed << scientific << setprecision(5) << decayConstant;
    DEFAULT(hConsole);

    cout << endl;
    //=============================================================================================
    // Print final output
    //=============================================================================================
    cout << print4;

    MEASUREMENT_COLOR_THIN(hConsole);
    cout << TimespanVector[indexOfChosenMeasurementUnitsInVector].unit;
        
    DEFAULT(hConsole);
    cout << print5;
        
    ISOTOPE_COLOR_THIN(hConsole);
    cout << IsotopeVector[indexOfChosenIsotopeInVector].name;
        
    DEFAULT(hConsole);
    cout << print6 << endl;
    cout << print7 << endl << endl;
    
    INVERTED(hConsole);
    cout << DEVELOPER_LINK_1;
    cout << DEVELOPER_NAME;
    cout << DEVELOPER_LINK_2;

    DEFAULT(hConsole);
    cout << endl << LINE_BREAK;
    //=============================================================================================
    // Print final output
    //=============================================================================================
    fstream dataFile3(OUTPUT_FILE, ios::out);
    dataFile3
        << fixed
        << setprecision(25)
        << decayConstant;
    dataFile3.close();

    return 0;
}
