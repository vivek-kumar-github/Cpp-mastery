
// Return by Value
std::string greet() {
    return "Hello, World!"; // Returns a string
}

// Return by reference

// when a function concludes, it discards local variables any reference that points to these variables now references reclaimed memory
// This becomes 'dangling reference,' and access or modify the variable can trigger erratic outcomes, crashes, or memory corruption.
int &getLarger(int &a, int &b) {
    return (a > b) ? a : b;
}

// Return by Pointer
int *findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return &arr[i];
        }
    }
    return nullptr; // If element is not found
}
