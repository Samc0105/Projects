/*
Name: Sam Casas
Date: 10/16/2024

Purpose:
This program assists a scientist in tracking the resistances of products from various batches.
It collects resistance measurements, classifies them, and calculates averages for acceptable resistances.

Input:
- Batch name (string, may contain spaces)
- Number of resistors (integer, must be at least 1)
- Resistance measurements (double, must be greater than 0)

Output:
- Batch name
- Total number of resistors
- Number of resistances that are too low (< 3.0 ohms)
- Number of resistances that are too high (> 3.5 ohms)
- Average resistance of acceptable resistors (>= 3.0 and <= 3.5 ohms)

Processing:
- Validate inputs using while loops without selection structures.
- Use loops to process each resistor's resistance.
- Keep counts and sums to classify resistances and calculate averages.
- Allow processing of multiple batches using a do-while loop.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // for std::numeric_limits

int main() {
    std::string batchName;
    int numResistors;
    char anotherBatch;

    do {
        // Step 1: Prompt for batch name and number of resistors
        std::cout << "What is the name of the batch of resistors? ";
        std::getline(std::cin, batchName); // No need to ignore at the start since no leftover input

        std::cout << "How many resistors are in " << batchName << "? ";
        std::cin >> numResistors;

        // Input validation for number of resistors without if statement
        while (numResistors < 1) {
            std::cout << "There must be at least 1 resistor in the batch.\n";
            std::cout << "How many resistors are in " << batchName << "? ";
            std::cin >> numResistors;
        }

        int tooLow = 0, tooHigh = 0, validCount = 0;
        double resistance, totalValidResistance = 0.0;

        // Step 2: Input resistor resistances and classify
        std::cout << "Now enter the measured resistances for batch " << batchName << ".\n";
        for (int i = 0; i < numResistors; ++i) {
            std::cout << "Enter the resistance in ohms. ";
            std::cin >> resistance;

            // Input validation for resistance without if statement
            while (resistance <= 0) {
                std::cout << "The resistance cannot be zero or less.\n";
                std::cout << "Enter the resistance in ohms. ";
                std::cin >> resistance;
            }

            // Step 3: Categorize resistance
            if (resistance < 3.0) {
                tooLow++;
            }
            else if (resistance > 3.5) {
                tooHigh++;
            }
            else {
                totalValidResistance += resistance;
                validCount++;
            }
        }

        // Step 4: Output batch summary
        std::cout << "There were " << numResistors << " resistors in this batch. Of these "
            << tooLow << " were below 3.00 ohms and "
            << tooHigh << " were above 3.50 ohms.\n";

        // Display average of valid resistors with dynamic precision
        if (validCount > 0) {
            double averageResistance = totalValidResistance / validCount;
            std::cout << "The average of the " << validCount
                << " good resistors is " << std::setprecision(5)
                << averageResistance << ".\n";
        }

        // Step 5: Ask if user wants to enter another batch
        std::cout << "Do you have another batch to be analyzed (y/n)? ";
        std::cin >> anotherBatch;

        // Clear the input buffer before the next batch
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (anotherBatch == 'y' || anotherBatch == 'Y');

    return 0;
}

