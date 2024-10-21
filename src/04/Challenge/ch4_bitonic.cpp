// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

using namespace std;

enum state {
    increasing,
    decreasing,
    mono
}; 

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    enum state currState;

    // Compare first pair of values
    int a = v[0];
    int b = v[1];
    if (b > a)
    {
        currState = increasing; 
    } else if (b < a) {
        currState = decreasing;
    } else {
        currState = mono;
    }
    

    int dirChanges = 0;
    
    for (size_t i = 2; i < v.size(); i++)
    {
        // Compare subsequent pairs
        a = v[i - 1];
        b = v[i];

        if (b > a)
        {
            if (currState == decreasing)
            {
                // If it was decreasing before and now increasing then direction change
                dirChanges++;
            }

            currState = increasing;
        } else if (b < a)
        {
            if (currState == increasing)
            {
                // If it was increasing before and now decreasing then direction change
                dirChanges++;
            }

            currState = decreasing;
        } else {
            currState = mono;
        }
        
        if (dirChanges > 1)
        {
            // If the sequence switches between increasing/decreasing more than once then it is 
            // not bitonic
            return false;
        }
    }
    
    // If it escapes the for loop then the sequence is bitonic
    return true;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<std::vector<int>> testCases = {
        {1, 2, 5, 4, 3},  // Yes
        {1, 1, 1, 1, 1},  // Yes
        {3, 4, 5, 2, 2},  // Yes
        {3, 4, 5, 2, 4},  // No
        {1, 2, 3, 4, 5},  // Yes
        {1, 2, 3, 1, 2},  // No
        {5, 4, 6, 2, 6},  // No
        {5, 4, 3, 2, 1},  // Yes
        {5, 4, 3, 2, 6},  // Yes
        {5, 4, 6, 5, 4},  // No
        {5, 4, 6, 5, 5}   // No
    };

    for (size_t i = 0; i < testCases.size(); i++)
    {
        std::cout << (is_bitonic(testCases[i]) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
        cout << endl;
    }
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}