// This program demonstrates the getline function with
// a specified delimiter.

// https://manara.edu.sy/downloads/files/1681300155_Refrence.pdf (PAGE 714 WILL ADD LATER) (emplace_back PAGE 1083) (for loops PAGE 286)


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct IsotopeStruct
{
    string			name;
    string		halfLife;
};

int main()
{
    string input; // To hold file input
    string input2; // To hold file input

    vector<IsotopeStruct>IsotopeVector =
    {
        {"Uranium-233",		"1.592e5"},
        {"Uranium-235",		"7.04e8"},
        {"Uranium-238",		"4.463e9"},
    };
    //=====================================================================
    // Open the file for input.
    fstream dataFile("listOfIsotopes.txt", ios::in);

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
            
            IsotopeVector.emplace_back(input,input2);
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
    for (auto&currentIsotope:IsotopeVector)
    {
        cout
            << "Name: "
            << currentIsotope.name
            << endl
            << "Half life: "
            << currentIsotope.halfLife
            << endl;
    }

    return 0;
}