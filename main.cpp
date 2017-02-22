/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 2.17.2017
 *
 * Description: This file hosts a function known as "findMode"
 * that allows the user to provide an array and the size of
 * that array and the function will return a vector holding
 * the mode(s} that the array holds.  In addition to this it
 * will sort the values from lowest to highest value and will
 * only show a value once (no repetition).
 *
 * There is a secondary function called printMode that allows
 * the user to print the results of the function findMode to
 * the console. The user must provide the initial array and
 * size of the array, just like they did in the findMode
 * function.
**************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findMode(int array[], int arraySize);
void printMode(int inputArray[], int arraySize);

int main() {
    /***************************
     * TESTS THAT NEED TO PASS *
     ***************************/

    // All unique values (one of each)
    int testArrayA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,};

    // One double value
    int testArrayB[10] = {1, 2, 3, 4, 1, 6, 7, 8, 9, 10,};

    // Two triple values
    int testArrayC[10] = {1, 1, 2, 4, 1, 6, 2, 8, 2, 10,};

    // All double values
    int testArrayD[10] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5,};

    // Run the tests using the "printMode" function
    std::cout << "{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,}" << " Mode = ";
    printMode(testArrayA, 10);

    std::cout << "{1, 2, 3, 4, 1, 6, 7, 8, 9, 10,}" << " Mode = ";
    printMode(testArrayB, 10);

    std::cout << "{1, 1, 2, 4, 1, 6, 2, 8, 2, 10,}" << " Mode = ";
    printMode(testArrayC, 10);

    std::cout << "{1, 1, 2, 2, 3, 3, 4, 4, 5, 5,}" << "  Mode = ";
    printMode(testArrayD, 10);

    return 0;

}

/**************************************************************
 *                      findMode
 *  Description: This function takes in two parameters (an array,
 *  and array size).  The function will then scan through and
 *  find the highest frequency inside of the array and return
 *  any values matching that frequency, and it will only show
 *  one of each value, no duplicates
 **************************************************************/

std::vector<int> findMode(int inputArray[], int arraySize)
{
    // Variable used to hold the highest frequency in the array
    int maxFreq = 0;

    // Temporary array to hold value and frequency
    int tempArray[arraySize][2];

    // Vector used to hold the array values that match the highest frequency
    std::vector<int> modeVec;

    // Loop through entire array and find the highest frequency
    for (int i = 0; i < arraySize; i++)
    {
        int currentFreq = 0;
        int currentVal;

        // Set the current value we are looking to count in the array
        currentVal = inputArray[i];

        // Loop through rest of remaining loop
        for (int j = i; j < arraySize; j++)
        {
            // Check to see if any other numbers match the current value
            // that we are looking for.
            if (inputArray[j] == currentVal)
            {
                // Add to current frequency counter
                currentFreq++;
            }
        }
        // If the counter is higher than the highest counted number, set it to maxFreq
        if (currentFreq >= maxFreq)
        {
            maxFreq = currentFreq;

            // Save the frequency value and store the number and frequency value in an array.
            tempArray[i][0] = inputArray[i];
            tempArray[i][1] = currentFreq;
        }
    }

    // Loop through entire array again and compare max frequency to other number frequencies
    for (int i = 0; i < arraySize; i++)
    {
        if (tempArray[i][1] == maxFreq)
        {
            modeVec.push_back(tempArray[i][0]);
        }
    }

    // Sort and return the vector value to the function call
    std::sort(modeVec.begin(), modeVec.end());
    return modeVec;
}

/**************************************************************
 *                      printMode
 *  Description: This function is used to print out the vector
 *  values in an easy to read format.  It takes in an array and
 *  the size of the array as its parameters.
 **************************************************************/

void printMode(int inputArray[], int arraySize)
{
    std::vector<int> modeOutput = findMode(inputArray, arraySize);

    for(int i = 0; i < modeOutput.size(); i++)
    {
        std::cout << modeOutput[i] << " ";
    }
    std::cout << std::endl;
}