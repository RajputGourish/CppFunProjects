#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    int random = rand() % 9999; // you can add 9  
    // Suppose 4 9's it means it generate a number of 4 digit
    cout << random << endl;

    return 0;
}