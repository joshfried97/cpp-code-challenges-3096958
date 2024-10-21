// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// Return a vector of string components from the original string
std::vector<std::string> get_tokens(std::string ip){
    std::vector<std::string> tokens;
    std::string delimiter = ".";
    size_t pos = 0;
    std::string token;
    while ((pos = ip.find(delimiter)) != std::string::npos) {
        token = ip.substr(0, pos);
        tokens.push_back(token);
        ip.erase(0, pos + delimiter.length());
    }
    tokens.push_back(ip);
    return tokens;
}

bool is_num(std::string str){
    for (size_t j = 0; j < str.length(); j++)
    {
        if (!isdigit(str[j]))
        {
            return false;
        }
    } 
    return true;
}

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    // First we determine whether there are 4 components to the IP by spltting the string 
    std::vector<std::string> tokens = get_tokens(ip);    

    // Fail validation if there are not enough components
    if (tokens.size() != 4)
    {
        return false;
    }

    // Now check each component is a number and lies between 0-255
    for (std::string token : tokens)
    {
        // Check for letters
        if (!is_num(token))
        {
            return false;
        }    
    
        // Now we check the number is in the right range
        int val = stoi(token);
        if (val < 0 || val > 255)
        {
            return false;
        }        
    }
    
    // If it passes all the checks then it's grand
    return true;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
