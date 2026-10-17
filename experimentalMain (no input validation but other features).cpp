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
using namespace std;



//=============================================================================================
// Task
//=============================================================================================
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int               HCONSOLE_DEEP_BLUE = 1,
                        HCONSOLE_DEEP_GREEN = 2,
                        HCONSOLE_DEEP_AQUA = 3,
                        HCONSOLE_DEEP_RED = 4,
                        HCONSOLE_DEEP_MAGENTA = 5,
                        HCONSOLE_DEEP_YELLOW = 6,
            
                        HCONSOLE_LIGHT_BLUE = 9,
                        HCONSOLE_LIGHT_GREEN = 10,
                        HCONSOLE_LIGHT_AQUA = 11,
                        HCONSOLE_LIGHT_RED = 12,
                        HCONSOLE_LIGHT_MAGENTA = 13,
                        HCONSOLE_LIGHT_YELLOW = 14,
            
                        HCONSOLE_WHITE = 15,
                        HCONSOLE_LIGHT_GRAY = 7,
                        HCONSOLE_GRAY = 8,
                        HCONSOLE_BLACK = 0;
//=============================================================================================
// (FOREGROUND + (BACKGROUND * 16)) = COLOR
//==========================================
void COLOR_DEFAULT_TEXT (HANDLE hConsole)                   {SetConsoleTextAttribute(hConsole,
                        HCONSOLE_LIGHT_AQUA +
                        HCONSOLE_BLACK * 16);
}
void COLOR_DEFAULT_INVERTED (HANDLE hConsole)               {SetConsoleTextAttribute(hConsole,
                        HCONSOLE_BLACK +
                        HCONSOLE_LIGHT_AQUA * 16);
}
void COLOR_EXTERNAL_BORDER (HANDLE hConsole)                {SetConsoleTextAttribute(hConsole,
                        HCONSOLE_BLACK +
                        HCONSOLE_LIGHT_MAGENTA * 16);
}
//===============================================================================
void COLOR_MEASUREMENT (HANDLE hConsole)                    {SetConsoleTextAttribute(hConsole,
                        HCONSOLE_BLACK +
                        HCONSOLE_DEEP_BLUE * 16);
}
void COLOR_ISOTOPE (HANDLE hConsole)                        {SetConsoleTextAttribute(hConsole,
                        HCONSOLE_BLACK +
                        HCONSOLE_LIGHT_GREEN * 16);
}
//=============================================================================================
// Task
//=============================================================================================
struct MeasurementStruct
{
    string			    keystring;
    string			    name;
    long double		    seconds;
};

struct IsotopeStruct
{
    string              keystring;
    string			    name;
    long double		    halfLife;
};
//=============================================================================================

int main()
{
    //=============================================================================================
    // Task
    //=============================================================================================
    const int           OPTION_YES_SPACE = 120,
                        OPTION_NO_SPACE = 80,
                        NECESSARY_CONSTANT_FOR_BACKSPACING_NEAR_SCREEN_EDGE = -2;

    const char          YES = 'y',
                        NO = 'n',
                        LINE_BREAK_1_CHAR = '*',
                        LINE_BREAK_2_CHAR = '/',
                        FILE_DELIMITER = ':';
    
    const string        AT = "@",
                        BRACKET_1 = "[",
                        BRACKET_2 = "]",
                        BRACKET_3 = "<",
                        BRACKET_4 = ">",
                        BRACKET_5 = "(",
                        BRACKET_6 = ")",
                        INTERNAL_BORDER_1 = "|",
                        INTERNAL_BORDER_2 = " ",
                        EXTERNAL_BORDER = "/",
                        
                        BACKSPACE = "\b \b";
    
    
    
    //=============================================================================================
    // Task
    //=============================================================================================
    const string        ORIGINAL = "original: ",
                        ORIGINALLY_DEVELOPED_BY = "originally developed by ",
                        ORIGINAL_DEVELOPER_NAME = "poallele",
                        ORIGINAL_DEVELOPER_SITE = "github.com/",
                        ORIGINAL_DEVELOPER_REPO = "/cpp-radioactive-decay-calculator",
        
                        FORK = "fork: ",
                        MODIFIED_BY = "modified by ",
                        MODIFYING_DEVELOPER_NAME = "sampletext",
                        MODIFYING_DEVELOPER_SITE = "github.com/",
                        MODIFYING_DEVELOPER_REPO = "/sample-text",
        
                        ERROR_MESSAGE = "Invalid character. ",
                        FILE_ERROR_MESSAGE = "ERROR: Cannot open file.",
                        
                        MEASUREMENTS_FILE = "listOfMeasurements.txt",
                        ISOTOPES_FILE = "listOfIsotopes.txt",
                        OUTPUT_FILE = "copyPaste.txt";
    
    
    
    //=============================================================================================
    // Task
    //=============================================================================================
    const string        QUESTION_1 =    "Press " + BRACKET_1 + "key" + BRACKET_2 + ", then 'enter'."
                                        "\nAre you currently running Windows 11's 'Terminal' (not 'conhost.exe' or any other program)? Yes or no? "
                                        + BRACKET_1 + YES + "/" + NO + BRACKET_2 + " ",
                        
                        QUESTION_2 =    "You have selected a horizontal screen size of " + BRACKET_3,
                        
                        QUESTION_3 =    BRACKET_4 + " characters.\nYou can modify the values corresponding with "
                                        + BRACKET_3 + YES + BRACKET_4 + " or " + BRACKET_3 + NO + BRACKET_4 + " near line 100 in the source code.",
        
                        
        
                        HEADER_1_LEFT = "MEASUREMENT",
                        HEADER_1_RIGHT = BRACKET_5 + "per unit" + BRACKET_6 + " SECONDS",
                        HEADER_2_LEFT = "ISOTOPE",
                        HEADER_2_RIGHT = BRACKET_5 + "yrs" + BRACKET_6 + " HALF LIFE",
        
                        FINAL_PRINT_1 = "Decay constant: ",
                        FINAL_PRINT_2 = "This value is the probability per " + BRACKET_3,
                        FINAL_PRINT_3 = BRACKET_4 + " for a single " + BRACKET_3,
                        FINAL_PRINT_4 = BRACKET_4 + " nucleus to decay.",
                        FINAL_PRINT_5 = "Check " + BRACKET_3 + OUTPUT_FILE + BRACKET_4 + " to copy and paste it.";
    
    
    
    //=============================================================================================
    // Task
    //=============================================================================================
    const long double   GREGORIAN_CALENDAR_SECONDS = 31556952;
    vector<MeasurementStruct>MeasurementVector =
    {
                        {
                        "s",
                        "second",
                        1
                        },
                        

                        {
                        "m",
                        "minute",
                        60
                        },
                        

                        {
                        "h",
                        "hour",
                        3600
                        },
        

                        {
                        "d",
                        "day",
                        86400
                        },


                        {
                        "y",
                        "year",
                        GREGORIAN_CALENDAR_SECONDS
                        },
    };
    vector<IsotopeStruct>IsotopeVector =
    {
                        {
                        "U1",
                        "Uranium-233",
                        1.592e5
                        },
                        
        
                        {
                        "U2",
                        "Uranium-235",
                        7.04e8
                        },
                        
        
                        {
                        "U3",
                        "Uranium-238",
                        4.463e9
                        },
                        
        
                        {
                        "Pu1",
                        "Plutonium-239",
                        2.411e4
                        },
                        
        
                        {
                        "Th1",
                        "Thorium-232",
                        1.405e10
                        },
    };



    //=============================================================================================
    // Task
    //=============================================================================================
    char                CMDResponse;
    bool				exitQuestionLoop = false;
    int                 horizontalSpace;
    
    string				chosenMeasurement;
    int					chosenMeasurementVectorIndex = 0;
    bool				exitMeasurementsLoop = false;

    double				chosenIsotope;
    int					chosenIsotopeVectorIndex = 0;
    bool				exitIsotopesLoop = false;

    string              measurementInput1,
                        measurementInput2,
                        measurementInput3,
                        isotopeInput1,
                        isotopeInput2,
                        isotopeInput3;

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
            getline(dataFile, measurementInput1, FILE_DELIMITER);
            getline(dataFile, measurementInput2, FILE_DELIMITER);
            getline(dataFile, measurementInput3);

            long double measurementInput3LD = stold(string(measurementInput3));   // PAGE 612

            MeasurementVector.emplace_back(measurementInput1, measurementInput2, measurementInput3LD);     // PAGE 1080
        }

        // Close the file.
        dataFile.close();
    }
    else
    {
        cout << FILE_ERROR_MESSAGE << endl;
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
            getline(dataFile2, isotopeInput1, FILE_DELIMITER);
            getline(dataFile2, isotopeInput2, FILE_DELIMITER);
            getline(dataFile2, isotopeInput3);

            long double isotopeInput3LD = stold(string(isotopeInput3));   // PAGE 612

            IsotopeVector.emplace_back(isotopeInput1, isotopeInput2, isotopeInput3LD);     // PAGE 1080
        }

        // Close the file.
        dataFile2.close();
    }
    else
    {
        cout << FILE_ERROR_MESSAGE << endl;
    }



    //=============================================================================================
    // CMD Width prompt
    //=============================================================================================
    COLOR_DEFAULT_TEXT(hConsole);
    cout << QUESTION_1;
    while (exitQuestionLoop != true)
    {
        cin >> CMDResponse;
        if (CMDResponse == YES)
        {
            horizontalSpace = OPTION_YES_SPACE + NECESSARY_CONSTANT_FOR_BACKSPACING_NEAR_SCREEN_EDGE;
            exitQuestionLoop = true;
        }
        else if (CMDResponse == NO)
        {
            horizontalSpace = OPTION_NO_SPACE + NECESSARY_CONSTANT_FOR_BACKSPACING_NEAR_SCREEN_EDGE;
            exitQuestionLoop = true;
        }
        else
        {
            cout << ERROR_MESSAGE;
        }
    }
    const string LINE_BREAK_1(horizontalSpace, LINE_BREAK_1_CHAR);
    const string LINE_BREAK_2(horizontalSpace, LINE_BREAK_2_CHAR);

    cout
        << QUESTION_2
        << horizontalSpace - NECESSARY_CONSTANT_FOR_BACKSPACING_NEAR_SCREEN_EDGE
        << QUESTION_3
        << endl
        << LINE_BREAK_1
        << endl
        << endl
        << endl;
    
    
    
    //=============================================================================================
    // Prompt 1
    //=============================================================================================
    COLOR_EXTERNAL_BORDER(hConsole);
    cout << endl << LINE_BREAK_2;

    for (int x = 1; x <= MODIFIED_BY.length() + MODIFYING_DEVELOPER_NAME.length() + AT.length(); x++) {
        cout << BACKSPACE;
    }
    cout << MODIFIED_BY << AT << MODIFYING_DEVELOPER_NAME << endl << LINE_BREAK_2;




    for (int x = 1; x <= ORIGINALLY_DEVELOPED_BY.length() + ORIGINAL_DEVELOPER_NAME.length() + AT.length(); x++) {
        cout << BACKSPACE;
    }
    cout << ORIGINALLY_DEVELOPED_BY << AT << ORIGINAL_DEVELOPER_NAME << endl;
    



    COLOR_DEFAULT_INVERTED(hConsole);
    cout
        << HEADER_1_LEFT
        << setw(horizontalSpace - HEADER_1_LEFT.length() - EXTERNAL_BORDER.length())
        << HEADER_1_RIGHT;

    COLOR_EXTERNAL_BORDER(hConsole);
    cout << EXTERNAL_BORDER;
    COLOR_DEFAULT_INVERTED(hConsole);
    cout << endl;
    
    //=============================================================================================
    // Use an iterator to display the vector contents.
    //=============================================================================================
    for (auto& currentMeasurement:MeasurementVector)                 // PAGE 434
    {
        COLOR_DEFAULT_TEXT(hConsole);
        cout
            << endl
            << INTERNAL_BORDER_1
            << BRACKET_1
            << currentMeasurement.keystring
            << BRACKET_2
            << INTERNAL_BORDER_1
            << currentMeasurement.name
            << setw
            (
                horizontalSpace
                - currentMeasurement.name.length()
                - currentMeasurement.keystring.length()
                - to_string(currentMeasurement.seconds).length()
                - (BRACKET_1.length()) - (BRACKET_2.length()) - (EXTERNAL_BORDER.length()) - (INTERNAL_BORDER_1.length()) - (INTERNAL_BORDER_2.length())
            )
            << INTERNAL_BORDER_2;
        
        COLOR_MEASUREMENT(hConsole);
        cout << to_string(currentMeasurement.seconds);
        
        
        COLOR_EXTERNAL_BORDER(hConsole);
        cout << EXTERNAL_BORDER;
    }
    cout
        << BACKSPACE
        << flush;


    //=============================================================================================
    // Input Validation 1
    //=============================================================================================
    COLOR_EXTERNAL_BORDER(hConsole);
    cin >> chosenMeasurement;
    COLOR_DEFAULT_TEXT(hConsole);

    
    
    

    //while (exitMeasurementsLoop != true)
    //{
    //    cin >> chosenMeasurement;
    //
    //
    //    
    //    if (exitMeasurementsLoop == false)
    //    {
    //        cout << ERROR_MESSAGE;
    //    }
    //}


    
    //=============================================================================================
    // Prompt 2
    //=============================================================================================
    COLOR_EXTERNAL_BORDER(hConsole);
    cout
        << LINE_BREAK_2
        << endl;
    

    COLOR_DEFAULT_INVERTED(hConsole);
    cout
        << HEADER_2_LEFT
        << setw(horizontalSpace - HEADER_2_LEFT.length() - EXTERNAL_BORDER.length())
        << HEADER_2_RIGHT;

    COLOR_EXTERNAL_BORDER(hConsole);
    cout << EXTERNAL_BORDER;
    COLOR_DEFAULT_INVERTED(hConsole);
    cout << endl;



    //=============================================================================================
    // Use an iterator to display the vector contents.
    //=============================================================================================
    for (auto& currentIsotope : IsotopeVector)                 // PAGE 434
    {
        COLOR_DEFAULT_TEXT(hConsole);
        cout
            << endl
            << INTERNAL_BORDER_1
            << BRACKET_1
            << currentIsotope.keystring
            << BRACKET_2
            << INTERNAL_BORDER_1
            << currentIsotope.name
            << setw
            (
                horizontalSpace
                - currentIsotope.name.length()
                - currentIsotope.keystring.length()
                - to_string(currentIsotope.halfLife).length()
                - (BRACKET_1.length()) - (BRACKET_2.length()) - (EXTERNAL_BORDER.length()) - (INTERNAL_BORDER_1.length()) - (INTERNAL_BORDER_2.length())
            )
            << INTERNAL_BORDER_2;

        COLOR_ISOTOPE(hConsole);
        cout << to_string(currentIsotope.halfLife);


        COLOR_EXTERNAL_BORDER(hConsole);
        cout << EXTERNAL_BORDER;
    }
    cout
        << BACKSPACE
        << flush;


    //=============================================================================================
    // Input Validation 2
    //=============================================================================================
    COLOR_EXTERNAL_BORDER(hConsole);
    cin >> chosenIsotope;
    COLOR_DEFAULT_TEXT(hConsole);

    COLOR_EXTERNAL_BORDER(hConsole);
    cout << LINE_BREAK_2;

    COLOR_DEFAULT_INVERTED(hConsole);
    cout << endl << LINE_BREAK_1;



    //=============================================================================================
    // Print final output
    //=============================================================================================
    chosenIsotopeVectorIndex = 0;                               // since the index "[]" for a vector begins at 0, "-1" is used
                                                                // (since user responses begin at 1). if this was not used,
                                                                // then chosenIsotope would equal 6 instead of 5. since 6 is not
                                                                // present in the index, it would not return anything.

    
    decayConstant = // Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units
    (log(2) / IsotopeVector[chosenIsotopeVectorIndex].halfLife) *
    (MeasurementVector[chosenMeasurementVectorIndex].seconds / GREGORIAN_CALENDAR_SECONDS);

    
    //=============================================================================================
    // Print final output
    //=============================================================================================
    COLOR_DEFAULT_TEXT(hConsole);
    cout
        << endl
        << endl
        << FINAL_PRINT_1
        << fixed
        << scientific
        << setprecision(5)
        << decayConstant
        
        << endl
        << FINAL_PRINT_2
        << MeasurementVector[chosenMeasurementVectorIndex].name
        << FINAL_PRINT_3
        << IsotopeVector[chosenIsotopeVectorIndex].name
        << FINAL_PRINT_4
        << endl
        << FINAL_PRINT_5
        << endl
        << endl
        << endl
        
        << FORK
        << MODIFYING_DEVELOPER_SITE
        << MODIFYING_DEVELOPER_NAME
        << MODIFYING_DEVELOPER_REPO
        
        << endl
        << ORIGINAL
        << ORIGINAL_DEVELOPER_SITE
        << ORIGINAL_DEVELOPER_NAME
        << ORIGINAL_DEVELOPER_REPO
        
        << endl
        << LINE_BREAK_1;
    COLOR_DEFAULT_TEXT(hConsole);
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
