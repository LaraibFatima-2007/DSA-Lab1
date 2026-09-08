#include <iostream>
#include <string>

using namespace std;

// Function prototype from task4.cpp
int findPattern(const string& text, const string& pattern);

int main() {
    cout << "=== TASK 4 TESTS ===" << endl;

    string text = "hello world data structures";

    // Test Case 1: Pattern at beginning
    cout << "Test 1 (Beginning - 'hello'): " << findPattern(text, "hello") 
         << " | Expected: 0" << endl;

    // Test Case 2: Pattern at end
    cout << "Test 2 (End - 'structures'): " << findPattern(text, "structures") 
         << " | Expected: 17" << endl;

    // Test Case 3: Pattern not present
    cout << "Test 3 (Not present - 'python'): " << findPattern(text, "python") 
         << " | Expected: -1" << endl;

    // Test Case 4: Empty pattern
    cout << "Test 4 (Empty pattern): " << findPattern(text, "") 
         << " | Expected: 0" << endl;

    return 0;
}