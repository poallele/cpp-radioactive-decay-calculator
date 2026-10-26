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
#include <functional>

#include <Windows.h>
using namespace std;



//=============================================================================================
// Task
//=============================================================================================
struct BaselineStruct
{
    string			    keystring;
    string			    name;
    long double		    secondsOrHalfLife;
};



//=============================================================================================
// Task
//=============================================================================================
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

                        HCONSOLE_LIGHT_GRAY = 7,
                        HCONSOLE_DEEP_GRAY = 8,
                        HCONSOLE_BLACK = 0,
                        HCONSOLE_WHITE = 15;



//=============================================================================================
// THEME COLORS // MODIFY THESE VALUES
//==========================================
const int   MAIN_COLOR = HCONSOLE_LIGHT_AQUA;                                   // Modify this

const int   HCONSOLE_COLOR_INTERNAL_WINDOW_FOREGROUND = HCONSOLE_LIGHT_GRAY,    // Modify this
            HCONSOLE_COLOR_INTERNAL_WINDOW_BACKGROUND = HCONSOLE_DEEP_GRAY;     // Modify this

const int   HCONSOLE_COLOR_MEASUREMENT_FOREGORUND = HCONSOLE_LIGHT_BLUE,        // Modify this
            HCONSOLE_COLOR_MEASUREMENT_BACKGROUND = HCONSOLE_DEEP_BLUE;         // Modify this

const int   HCONSOLE_COLOR_ISOTOPE_FOREGROUND = HCONSOLE_LIGHT_GREEN,           // Modify this
            HCONSOLE_COLOR_ISOTOPE_BACKGROUND = HCONSOLE_DEEP_GREEN;            // Modify this


//=============================================================================================
// (FOREGROUND + (BACKGROUND * 16)) = COLOR
//==========================================
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void COLOR_DEFAULT_TEXT(HANDLE hConsole)                    {SetConsoleTextAttribute(hConsole,
                        
                        MAIN_COLOR +
                        (HCONSOLE_BLACK * 16)
                        );
}
void COLOR_DEFAULT_INVERTED(HANDLE hConsole)                {SetConsoleTextAttribute(hConsole,
                        
                        HCONSOLE_BLACK +
                        (MAIN_COLOR * 16)
                        );
}
void COLOR_BORDER(HANDLE hConsole)                          {SetConsoleTextAttribute(hConsole,
                        
                        (MAIN_COLOR - 8) +
                        (MAIN_COLOR * 16)
                        );
}

const int HCONSOLE_FUNC_COLOR_INTERNAL_WINDOW = HCONSOLE_COLOR_INTERNAL_WINDOW_FOREGROUND + HCONSOLE_COLOR_INTERNAL_WINDOW_BACKGROUND * 16;
void COLOR_INTERNAL_WINDOW(HANDLE hConsole){SetConsoleTextAttribute(hConsole,HCONSOLE_FUNC_COLOR_INTERNAL_WINDOW);}

const int HCONSOLE_FUNC_COLOR_MEASUREMENT = HCONSOLE_COLOR_MEASUREMENT_FOREGORUND + HCONSOLE_COLOR_MEASUREMENT_BACKGROUND * 16;
void COLOR_MEASUREMENT(HANDLE hConsole){SetConsoleTextAttribute(hConsole,HCONSOLE_FUNC_COLOR_MEASUREMENT);}

const int HCONSOLE_FUNC_COLOR_ISOTOPE = HCONSOLE_COLOR_ISOTOPE_FOREGROUND + HCONSOLE_COLOR_ISOTOPE_BACKGROUND * 16;
void COLOR_ISOTOPE(HANDLE hConsole){SetConsoleTextAttribute(hConsole,HCONSOLE_FUNC_COLOR_ISOTOPE);}



//=============================================================================================
// Task
//=============================================================================================
void fileRetrieval
(
    string                  MISC_FILE,
    char                    FILE_DELIMITER,
    vector<BaselineStruct>  & MiscVector,           // '&' is EXTREMELY NECESSARY. Without it, a LOCAL COPY is created and immediately destroyed when exiting the function. This makes changes to the actual vector
    string                  FILE_ERROR_MESSAGE,
    int                     defaultVectorItems
)

{
    fstream dataFile(MISC_FILE, ios::in);                // PAGE 714
    string input1;
    string input2;
    string input3;
    int count = 0;

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

            long double input3LD = stold(string(input3));   // PAGE 612

            MiscVector.emplace_back(input1, input2, input3LD);     // PAGE 1080
            //MiscVector[defaultVectorItems + count] = {input1, input2, input3LD};     // PAGE 1080

            count += 1;
        }

        // Close the file.
        dataFile.close();

    }
    else
    {
        cout << FILE_ERROR_MESSAGE << endl;
    }
}



//=============================================================================================
// Task
//=============================================================================================
void embedDeveloperNames
(
    string                      LINE_BREAK_2,
    string                      BY,
    string                      DEVELOPER_NAME,
    string                      AT,
    string                      BACKSPACE
)

{
    cout << LINE_BREAK_2;
    for (int x = 1; x <= BY.length() + DEVELOPER_NAME.length() + AT.length(); x++) {
        cout << BACKSPACE;
    }
    cout << BY << AT << DEVELOPER_NAME << endl;
}

//=============================================================================================
// Task
//=============================================================================================
void obtainProperFormattingConstants
(
    vector<BaselineStruct>      MiscVector,
    string keystring
)

{
    // var largestLength
    //get keystring value
    // get the .length() of it
    // largestLength = keystring.length()
    //go through vector keystrings
    // if the current keystrings length is greater than largestLength, largestLength = that
    // keep doing that until done
    // finished
    // get the delta of largestLength and keystring.length()
    // return this value
    // it will be used for adding space at the beginning. it is supposed to be used in a loop
}

//=============================================================================================
// Task
//=============================================================================================
void displayVectorContents
(
    vector<BaselineStruct>      MiscVector,

    string                      HEADER_NUMBER_LEFT,
    string                      HEADER_NUMBER_RIGHT,

    string                      INTERNAL_SEPARATOR_1,
    string                      INTERNAL_SEPARATOR_2,
    string                      INTERNAL_SEPARATOR_3,
    string                      BORDER,
    string                      BRACKET_1,
    string                      BRACKET_2,
    string                      BACKSPACE,
    int                         horizontalSpace,
    int                         HCONSOLE_FUNC_COLOR
)

{
    COLOR_DEFAULT_INVERTED(hConsole);
    cout
        << HEADER_NUMBER_LEFT
        << setw(horizontalSpace - HEADER_NUMBER_LEFT.length() - BORDER.length())
        << HEADER_NUMBER_RIGHT;

    COLOR_BORDER(hConsole);
    cout << BORDER;
    COLOR_DEFAULT_INVERTED(hConsole);
    cout << endl;

    
    int count = -1;
    for (auto& currentVectorSelection:MiscVector)                               // PAGE 434
    {
        count += 1; if (count != 0) {cout << endl;}
        
        
        COLOR_DEFAULT_INVERTED(hConsole);
        cout
            << INTERNAL_SEPARATOR_1                                             //1
            << BRACKET_1                                                        //2
            << MiscVector[count].keystring                                      //3
            << BRACKET_2;                                                       //4
        
        COLOR_INTERNAL_WINDOW(hConsole);
        cout    
            << INTERNAL_SEPARATOR_2                                             //5
            << MiscVector[count].name                                           //6
            << setw
            (
                horizontalSpace
                - INTERNAL_SEPARATOR_1.length()                                 //1
                - BRACKET_1.length()                                            //2
                - MiscVector[count].keystring.length()                          //3
                - BRACKET_2.length()                                            //4
                - INTERNAL_SEPARATOR_2.length()                                 //5
                - MiscVector[count].name.length()                               //6

                - to_string(MiscVector[count].secondsOrHalfLife).length()       //1
                - BORDER.length()                                               //2
            )
            << INTERNAL_SEPARATOR_3;                                            //3

        SetConsoleTextAttribute(hConsole, HCONSOLE_FUNC_COLOR);
        cout << to_string(MiscVector[count].secondsOrHalfLife);                 //1


        COLOR_BORDER(hConsole);
        cout << BORDER;                                                         //2
    }
    cout
        << BACKSPACE
        << flush;
}



//=============================================================================================
int main()
{
    //=============================================================================================
    // Task
    //=============================================================================================
    const int           OPTION_YES_SPACE = 120,
                        OPTION_NO_SPACE = 80,
                        NECESSARY_CONSTANT_FOR_BACKSPACING_NEAR_SCREEN_EDGE = -2,
                        NECESSARY_CONSTANT_FOR_LENGTH_OPERATION_ON_UNICODE_CHARACTERS = 2,
                        NUMBER_OF_INDIVIDUAL_UNICODE_CHARACTERS_USED_BELOW = 2; // Modify this

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
                        INTERNAL_SEPARATOR_1 = "|",
                        INTERNAL_SEPARATOR_2 = " ",
                        INTERNAL_SEPARATOR_3 = " ",
                        BORDER = "//",

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
    const string        QUESTION_1 = "Press " + BRACKET_1 + "key" + BRACKET_2 + ", then 'enter'."
                        "\nAre you currently running Windows 11's 'Terminal' (not 'conhost.exe' or any other program)? Yes or no? "
                        + BRACKET_1 + YES + "/" + NO + BRACKET_2 + " ",

                        QUESTION_2 = "You have selected a horizontal screen size of " + BRACKET_3,

                        QUESTION_3 = BRACKET_4 + " characters.\nYou can modify the values corresponding with "
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
    
    int defaultMeasurementVectorItems = 5;
    vector<BaselineStruct>MeasurementVector =
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
    
    int defaultIsotopeVectorItems = 5;
    vector<BaselineStruct>IsotopeVector =
    {
                        {
                        "U233",
                        "Uranium-233",
                        1.592e5
                        },


                        {
                        "U235",
                        "Uranium-235",
                        7.04e8
                        },


                        {
                        "U238",
                        "Uranium-238",
                        4.463e9
                        },


                        {
                        "Pu239",
                        "Plutonium-239",
                        2.411e4
                        },


                        {
                        "Th232",
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

    long double			decayConstant;



    //=============================================================================================
    // File retrieval 1
    //=============================================================================================
    fileRetrieval(MEASUREMENTS_FILE, FILE_DELIMITER, MeasurementVector, FILE_ERROR_MESSAGE, defaultIsotopeVectorItems);



    //=============================================================================================
    // File retrieval 2
    //=============================================================================================
    fileRetrieval(ISOTOPES_FILE, FILE_DELIMITER, IsotopeVector, FILE_ERROR_MESSAGE, defaultMeasurementVectorItems);



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
        << endl
        << endl;



    //=============================================================================================
    // Prompt 1
    //=============================================================================================
    COLOR_BORDER(hConsole);
    embedDeveloperNames(LINE_BREAK_2, MODIFIED_BY, MODIFYING_DEVELOPER_NAME, AT, BACKSPACE);
    embedDeveloperNames(LINE_BREAK_2, ORIGINALLY_DEVELOPED_BY, ORIGINAL_DEVELOPER_NAME, AT, BACKSPACE);



    //=============================================================================================
    // Use an iterator to display the vector contents.
    //=============================================================================================
    displayVectorContents   (
                            MeasurementVector, HEADER_1_LEFT, HEADER_1_RIGHT, INTERNAL_SEPARATOR_1, INTERNAL_SEPARATOR_2, INTERNAL_SEPARATOR_3,
                            BORDER, BRACKET_1, BRACKET_2, BACKSPACE, horizontalSpace, HCONSOLE_FUNC_COLOR_MEASUREMENT
                            );


    //=============================================================================================
    // Input Validation 1
    //=============================================================================================
    COLOR_BORDER(hConsole);
    cin >> chosenMeasurement;
    
    COLOR_BORDER(hConsole);
    cout << LINE_BREAK_2 << endl;


    //=============================================================================================
    // Use an iterator to display the vector contents.
    //=============================================================================================
    displayVectorContents   (
                            IsotopeVector, HEADER_2_LEFT, HEADER_2_RIGHT, INTERNAL_SEPARATOR_1, INTERNAL_SEPARATOR_2, INTERNAL_SEPARATOR_3,
                            BORDER, BRACKET_1, BRACKET_2, BACKSPACE, horizontalSpace, HCONSOLE_FUNC_COLOR_ISOTOPE
                            );


    //=============================================================================================
    // Input Validation 2
    //=============================================================================================
    COLOR_BORDER(hConsole);
    cin >> chosenIsotope;
    
    COLOR_BORDER(hConsole);
    cout << LINE_BREAK_2 << endl;



    //=============================================================================================
    // Print final output
    //=============================================================================================
    COLOR_DEFAULT_INVERTED(hConsole);
    cout << LINE_BREAK_1;
    
    chosenIsotopeVectorIndex = 0;                               // since the index "[]" for a vector begins at 0, "-1" is used
                                                                // (since user responses begin at 1). if this was not used,
                                                                // then chosenIsotope would equal 6 instead of 5. since 6 is not
                                                                // present in the index, it would not return anything.


    decayConstant = // Decay constant is the (natural logarithm of 2) divided by the half life. It can be multiplied by the amount of units
        (log(2) / IsotopeVector[chosenIsotopeVectorIndex].secondsOrHalfLife) *
        (MeasurementVector[chosenMeasurementVectorIndex].secondsOrHalfLife / GREGORIAN_CALENDAR_SECONDS);


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
