// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

using namespace std;

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    // Flags tracking multiples of 3 & 5
    bool div3 = false;
    bool div5 = false;

    // Write your code here
    cout << "Fizz Buzz sequence: ";
    for (int i = 1; i <= n; i++)
    {
        div3 = i % 3 == 0;
        div5 = i % 5 == 0;

        if (!div3 && !div5)
        {
            cout << i << " ";
            continue;
        }

        if (div3)
        {
            cout << "Fizz";
        }
        
        if (div5)
        {
            cout << "Buzz";
        }

        cout << " ";        
    }    
    
    std::cout << std::endl << std::flush;
    return 0;
}
