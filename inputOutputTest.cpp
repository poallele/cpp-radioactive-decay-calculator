// This program demonstrates the getline function with
// a specified delimiter.

// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct IsotopeStruct
{
    string			name;
    long double		halfLife;
};

int main()
{
    string input; // To hold file input
    string input2; // To hold file input

    vector<IsotopeStruct>IsotopeVector =
    {
        {"Uranium-233",		1.592e5},
        {"Uranium-235",		7.04e8},
        {"Uranium-238",		4.463e9},
    };
    //=====================================================================
    // Open the file for input.
    fstream dataFile("listOfIsotopes.txt", ios::in);                // PAGE 714

    // If the file was successfully opened, continue.
    if (dataFile)
    {
        // While the last read operation was successful, continue.
        while (dataFile)
        {
            // Display the last item read.
            cout << input << endl;
            
            // Read an item using ':' as a delimiter.
            getline(dataFile, input, ':');
            getline(dataFile, input2);
            
            long double input2LongDouble = stold(string(input2));   // PAGE 612

            IsotopeVector.emplace_back(input,input2LongDouble);     // PAGE 1080
        }

        // Close the file.
        dataFile.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }

    cout << endl;

    // Use an iterator to display the vector contents.
    for (auto & currentIsotope:IsotopeVector)                       // PAGE 434
    {
        cout
            << "Name: "
            << currentIsotope.name
            << endl
            << "Half life: "
            << currentIsotope.halfLife
            << endl
            << endl;
    }

    return 0;
}
