// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include <thread>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

void waitRandomTime(int minMilliseconds, int maxMilliseconds) {
    // Seed for the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define a uniform distribution between min and max milliseconds
    std::uniform_int_distribution<> distr(minMilliseconds, maxMilliseconds);
    
    // Generate a random duration in milliseconds
    int waitTime = distr(gen);

    std::cout << "Tactical pause..." << std::endl;
    
    // Sleep for the randomly generated time
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
}

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    do{
        // Pick random element from the list of strings
        int min = 0;
        int max = 9;
        int idx = min + (rand() % static_cast<int>(max - min + 1));
        std::string chosenWord = words[idx];

        // Wait a random time before printing the word they need to type
        waitRandomTime(4000, 10000);

        // Start timer
        auto start = std::chrono::high_resolution_clock::now();

        // Get the user input
        std::cout << "Type " << chosenWord << std::endl;
        std::string input;
        std::cout << "Please enter something: ";
        std::getline(std::cin, input);

        // Get the end time
        auto end = std::chrono::high_resolution_clock::now();
        
        // Calculate the duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        // Compared entered string to list of strings
        std::transform(input.begin(), input.end(), chosenWord.begin(), ::toupper);

        if (duration < 2000)
        {
            if (input.compare(chosenWord))
            {
                std::cout << "Well done! You wrote the right word under the time limit!" << std::endl;
            } else {
                std::cout << "You were quick but wrote the wrong word..!" << std::endl;
            }
        } else if (duration >= 2000)
        {
            if (input.compare(chosenWord))
            {
                std::cout << "You wrote the right word but took too long... be quicker!" << std::endl;
            } else {
                std::cout << "Are you ok?" << std::endl;
            }
        }
        
        std::cout << "You took " << duration << " milliseconds to enter input." << std::endl;

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
