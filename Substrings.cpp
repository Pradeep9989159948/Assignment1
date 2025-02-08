#include <iostream>
#include <vector>
#include <cctype> 


std::string toUpperCase(const std::string& str) {
    std::string upperStr;
    for (char c : str) {
        upperStr += std::toupper(c);
    }
    return upperStr;
}

bool isAlphabetic(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

std::string longestCommonSubstr(const std::string& strA, const std::string& strB, int& maxLen) {
    int lenA = strA.length();
    int lenB = strB.length();

    std::vector<std::vector<int>> suffixLengths(lenA + 1, std::vector<int>(lenB + 1, 0));
    maxLen = 0; 
    int endIndex = 0; 

    
    for (int i = 1; i <= lenA; ++i) {
        for (int j = 1; j <= lenB; ++j) {
            if (strA[i - 1] == strB[j - 1]) {
                suffixLengths[i][j] = suffixLengths[i - 1][j - 1] + 1;
                if (suffixLengths[i][j] > maxLen) {
                    maxLen = suffixLengths[i][j];
                    endIndex = i - 1;
                }
            } else {
                suffixLengths[i][j] = 0;
            }
        }
    }

    
    std::cout << "Suffix Lengths Matrix:" << std::endl;
    for (int i = 0; i <= lenA; ++i) {
        for (int j = 0; j <= lenB; ++j) {
            std::cout << suffixLengths[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::string longestSubstring = strA.substr(endIndex - maxLen + 1, maxLen);

    return longestSubstring;
}

int main() {
    std::string inputStr1, inputStr2;
    while (true) {
        std::cout << "Enter the first string (or type 'quit' to exit): ";
        std::cin >> inputStr1;
        if (inputStr1 == "quit") break;

        std::cout << "Enter the second string (or type 'quit' to exit): ";
        std::cin >> inputStr2;
        if (inputStr2 == "quit") break;

        if (!isAlphabetic(inputStr1) || !isAlphabetic(inputStr2)) {
            std::cout << "Invalid input: Please enter alphabetic characters only." << std::endl;
            continue;
        }

        inputStr1 = toUpperCase(inputStr1);
        inputStr2 = toUpperCase(inputStr2);

        int lengthOfLongestCommonSubstring;
        std::string commonSubstr = longestCommonSubstr(inputStr1, inputStr2, lengthOfLongestCommonSubstring);

        std::cout << "Longest Common Substring: " << commonSubstr << std::endl;
        std::cout << "Length of the Longest Common Substring: " << lengthOfLongestCommonSubstring << std::endl;
    }

    return 0;
}
