#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

struct Measurement  {
                        std::string character;
                        std::string unit;
                        int multiplier;
                    };
struct Isotopes {
                    std::string name;
                    long double value;
                };

int main()
{
	/* This is a multi-line comment.
	 * the matching asterisks to the left
	 * can make this easier to read
	 */
    
    /* if they choose 'seconds' then the half-lives (in the form of years,
     * scientific notation) are converted into seconds by multiplying
	 * them by the number of seconds in the gregorian calendar.
	 * dividing them by 3600 (amount of seconds in an hour)
	 * yields hours. */
    const int GREGORIAN_SECONDS = 31556952;
    std::vector<Measurement> measurement =  {
                                                {"s","second",GREGORIAN_SECONDS/1},
                                                {"m","minute",GREGORIAN_SECONDS/60},
                                                {"h","hour",GREGORIAN_SECONDS/3600},
                                                {"d","day",GREGORIAN_SECONDS/86400},
                                                {"y","year",GREGORIAN_SECONDS/GREGORIAN_SECONDS}
                                            };
	
	std::string errorMessage = "Invalid character. ";

	/* user prompt. 'print' = (std::cout <<). 'submit' = (std::cin >>).
	 * exitLoop1 is initialized as false. while (exitLoop1)
	 * means "while exitLoop1 is true". the (!) makes it negative.
	 * exitLoop1 only becomes "true" by entering valid characters.
	 * "if-else" conditionals are utilized instead of "switch" statements
	 * for their ability to use strings and logical comparisons. */
	bool exitLoop1 = false;
	std::string response1{};
	int responseIndex1{};
    int count1{};
    std::cout << "Would you like to measure in:\n";
    for (const auto & m:measurement) {
        std::cout << "<" << measurement[count1].character << "> " << measurement[count1].unit << "s\n";
        count1 += 1;
    }
	while (!exitLoop1) {
		std::cin >> response1;
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
			std::cout << errorMessage;
		}
	}
	
	std::vector<Isotopes> isotopes =
	    {
	        {"Uranium-233",1.592e5*measurement[responseIndex1].multiplier},
	        {"Uranium-235",7.04e8*measurement[responseIndex1].multiplier},
	        {"Uranium-238",4.463e9*measurement[responseIndex1].multiplier},
	        {"Plutonium-239",2.411e4*measurement[responseIndex1].multiplier},
	        {"Thorium-232",1.40e10*measurement[responseIndex1].multiplier}
	    };
    
    // user prompt
    bool exitLoop2 = false;
	int response2{};
	int count2 = 0;
	std::cout << "Select a fertile radioactive isotope:\n";
	for (const auto & i:isotopes) {
        count2 += 1;
        std::cout << "<" << count2 << "> " << i.name << '\n';
    }
    while (!exitLoop2) {
		std::cin >> response2;
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
			std::cout << errorMessage;
		}
	}
	/* since the index "[]" for a vector begins at 0, "-1" is used
	 * (since user responses begin at 1). if this was not used,
	 * then response2 would equal 6 instead of 5. since 6 is not 
	 * present in the index, it would not return anything. */
	int responseIndex2{response2-1};
	
	/* decay constant | the natural logarithm of  2 divided by the half life.
	 * print the decay constant as a number with 20 decimal places. */
	const double decay = (std::log(2)) / isotopes[responseIndex2].value;
	std::cout
	    << "Probability per " << measurement[responseIndex1].unit << " for a single " << isotopes[response2-1].name
	    << " nucleus to decay: " << std::fixed << std::setprecision(25) << decay;
	
	return 0;
}
