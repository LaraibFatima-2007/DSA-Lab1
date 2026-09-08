#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Author: Laraib Fatima
 * Date: 08-09-2026
 * Task 6: Histogram Analysis (Mode of Array)
 * Finds all modes in an array.
 */

vector<int> findMode(const vector<int>& arr) {
    vector<int> modes;
    if (arr.empty()) {
        return modes;
    }

    // Count frequencies using hash map
    unordered_map<int, int> frequencyMap;
    int maxFrequency = 0;

    for (int num : arr) {
        frequencyMap[num]++;
        if (frequencyMap[num] > maxFrequency) {
            maxFrequency = frequencyMap[num];
        }
    }

    // Collect all elements of max frequency
    for (const auto& pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}