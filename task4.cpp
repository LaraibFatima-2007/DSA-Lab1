#include <iostream>
#include <string>

using namespace std;

/**
 * Author: Laraib Fatima
 * Date: 08-09-2026
 * Task 4: String Pattern Matching (Naive Algorithm)
 * Finds the starting index of the first occurrence of a pattern in a text string.
 */
int findPattern(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // For Empty pattern
    if (m == 0) {
        return 0;
    }

    // For Pattern longer than text
    if (m > n) {
        return -1;
    }

    // Slide pattern across text step-by-step
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        // If whole pattern matched
        if (j == m) {
            return i;
        }
    }

    return -1; // Pattern not found
}