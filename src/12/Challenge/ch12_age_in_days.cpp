// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    // Read in birth date from user
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1){
        birth_m = 1;
    }
        
    if(birth_m > 12) {
        birth_m = 12;
    }

    time_t timestamp = time(NULL);

    // Create ctime instance for birth date
    struct tm birthDate;
    birthDate = *localtime(&timestamp);
    birthDate.tm_mday = birth_d;
    birthDate.tm_mon = birth_m - 1;
    birthDate.tm_year = birth_y - 1900;

    // Retrieve time now
    struct tm datetime = *localtime(&timestamp);
    
    today_d = datetime.tm_mday;
    today_m = datetime.tm_mon + 1;
    today_y = datetime.tm_year + 1900;
    std::cout << "Today's date: " << today_d << "/" << today_m << "/" << today_y << std::endl;

    // Calculate difference in seconds using built-in function
    float age_sec = difftime(mktime(&datetime), mktime(&birthDate));

    // Convert from seconds to days
    age = (int)age_sec/(60*60*24);

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
