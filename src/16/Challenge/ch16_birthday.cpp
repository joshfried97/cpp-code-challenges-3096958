// C++ Code Challenges, LinkedIn Learning

// Challenge #16: The Birthday Problem
// The birthday problem consists in finding the probability of having at least two people with the same birthday in a group of n people.
// Create an application that simulates the Birthday Problem 1 million times, with the number of people specified by the user.
// Use this application to prove (empirically) that the probability of having at least 2 people with the same birthday is approximately 0.5 for a group of 23 people. 
// https://en.wikipedia.org/wiki/Birthday_problem 

#include <iostream>
#include <chrono>

bool isLeapYear(int year) {
    // A year is a leap year if it's divisible by 4, except for century years not divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2: // February
            return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

void generateRandomBirthday(int birthdays[][3], int n) {
    // Define a range for the year (e.g., 1950 to 2023)
    const int minYear = 1950;
    const int maxYear = 2023;

    // Initialize random seed
    std::srand(std::time(0));

    for (size_t i = 0; i < n; i++)
    {
        // Generate random year, month, and day
        birthdays[i][2] = minYear + std::rand() % (maxYear - minYear + 1);
        birthdays[i][1] = 1 + std::rand() % 12; // Month between 1 and 12
        birthdays[i][0] = 1 + std::rand() % getDaysInMonth(birthdays[i][1], birthdays[i][2]); // Day based on the month and year
    }
}

bool findSharedBirthdays(int birthdays[][3], int n){
    int dayQuery = 0;
    int monthQuery = 0;
    for (size_t i = 0; i < n; i++)
    {
        dayQuery = birthdays[i][0];
        monthQuery = birthdays[i][1];
        for (size_t j = i + 1; j < n; j++)
        {
            if (birthdays[j][0] == dayQuery && birthdays[j][1] == monthQuery)
            {
                return true;
            }
            
        }
        
    }

    return false;
    
}

// The Birthday Problem, main()
// Summary: This application simulates the birthday problem a large number of times to reveal the probability of a birthday match in a groupd of a given number of people.
int main(){    
    const int total = 1000000;
    int n, matches;

    std::cout << "Enter the number of people in the group: " << std::flush;
    std::cin >> n;

    if(n > 366)
        matches = total;
    else{
        int birthdays[n][3]; 

        for (size_t i = 0; i < total; i++)
        {
            birthdays[n][3] = {0};
            generateRandomBirthday(birthdays, n);

            if (findSharedBirthdays(birthdays, n))
            {
                matches++;
            }

            if (i % 100000 == 0)
            {
                std::cout << i << " runs complete" << std::endl;
            }
        }
    }

    std::cout << "The probability of a birthday match is " << (double)matches/total << "\n\n" << std::flush;  

    return 0;
}
