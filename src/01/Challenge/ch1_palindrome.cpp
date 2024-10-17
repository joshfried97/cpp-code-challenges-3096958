// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>

using namespace std;

bool isEqual(string::iterator a, string::iterator b) {
    // Do direct check first
    if (*a == *b)
    {
        return true;
    }

    // Now check if there a upper/lower case comparison i.e a = A
    const char a_chr = *a;
    const char b_chr = *b;

    if (a_chr == toupper(b_chr) || a_chr == tolower(b_chr))
    {
        return true;
    }

    if (b_chr == toupper(a_chr) || b_chr == tolower(a_chr))
    {
        return true;
    }

    return false;
}

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){

    // Set up iterators
    string::iterator first_it = str.begin();
    string::iterator last_it = str.end();

    // Move past the null character
    last_it--;

    while (first_it != str.end() && last_it !=str.begin())
    {
        if (!isEqual(first_it,last_it))
        {
            return false;
        }

        first_it++;
        last_it--;
    }
    
    return true;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s;
    cout << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
