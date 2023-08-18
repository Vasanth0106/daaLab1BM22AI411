//cpp program to implement Horspool Algorithm @ 18/08/2023
#include <iostream>
#include <string>
#include <unordered_map>

class Horspool {
private:
    std::unordered_map<char, int> shiftTable;

public:
    Horspool(const std::string& pattern) {
        for (int i = 0; i < pattern.length() - 1; ++i) {
            shiftTable[pattern[i]] = pattern.length() - 1 - i;
        }
    }

    int search(const std::string& text, const std::string& pattern) {
        int textLength = text.length();
        int patternLength = pattern.length();
        int i = patternLength - 1;

        while (i < textLength) {
            int k = 0;
            while (k < patternLength && pattern[patternLength - 1 - k] == text[i - k]) {
                ++k;
            }

            if (k == patternLength) {
                return i - patternLength + 1; // Pattern found starting at index i - patternLength + 1
            } else {
                char mismatchChar = text[i - k];
                i += shiftTable.find(mismatchChar) != shiftTable.end() ? shiftTable[mismatchChar] : patternLength;
            }
        }

        return -1; // Pattern not found
    }
};

int main() {
    std::string text, pattern;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::cout << "Enter the pattern: ";
    std::getline(std::cin, pattern);

    Horspool horspool(pattern);
    int position = horspool.search(text, pattern);

    if (position != -1) {
        std::cout << "Pattern found at position: " << position << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }

    return 0;
}
