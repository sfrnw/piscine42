#include <unistd.h> // Include the header for write function

// Function to solve the inter problem
void solve(char *str1, char *str2) {
    int i;                  // Index for iterating through strings
    int j;                  // Additional index (unused in this implementation)
    int ascii[256] = {0};   // Array to track character occurrences (initialized to 0)

    i = 0;
    while (str2[i])         // Iterate through the second string
    {
        if (ascii[(int)str2[i]] == 0)    // If character not seen before
            ascii[(int)str2[i]] = 1;     // Mark it as seen in the second string
        i++;
    }

    i = 0;
    j = 0;                  // j is initialized but not used
    while (str1[i])         // Iterate through the first string
    {
        if (ascii[(int)str1[i]] == 1)    // If character is in both strings
        {
            ascii[(int)str1[i]] = 2;     // Mark it as printed
            write(1, &str1[i], 1);       // Write the character to stdout
        }
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc == 3)          // Check if exactly two arguments are provided
        solve(argv[1], argv[2]);  // Call solve function with the two strings
    write(1, "\n", 1);      // Write a newline character
    return 0;               // Return 0 to indicate successful execution
}
