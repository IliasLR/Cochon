#include "utils.h"
// #include <bits/fcntl-linux.h>

const char* const red = "\033[31m";
const char* const yellow = "\033[33m";
const char* const blue = "\033[34m";
const char* const green = "\033[32m";
const char* const purple = "\033[35m";
const char* const cyan = "\033[36m";
const char* const white = "\033[37m";
const char* const bold = "\033[1m";
const char* const reset = "\033[0m";

int get_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function random avec le fichier /dev/urandom

// A DEBUGGER

// int get_random_number_secure(int min, int max) {
//     int randomData = open("/dev/urandom", O_RDONLY);
//     int myRandomNumber;
//     read(randomData, &myRandomNumber, sizeof myRandomNumber);
//     close(randomData);
//     return min + (myRandomNumber % (max - min + 1));
// }