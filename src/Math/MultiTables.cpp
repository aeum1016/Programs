#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::seconds;
using chrono::system_clock;

class Util
{
    public:
        static void printLines(int lines)
        {
            for(int i = 0; i < lines; i++)
            {
                cout << endl;
            }
        }
};

int main() 
{
    
    srand((unsigned) time(nullptr));

    int trials = 0;
    int maxNumber = 0;
    
    while (std::cout << "How many questions would you like to solve?\n" && !(std::cin >> trials)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(1000, '\n'); //discard input
        std::cout << "Please input a number\n";
    }

    while (std::cout << "Multiplication tables up to what number?\n" && !(std::cin >> maxNumber)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(1000, '\n'); //discard input
        std::cout << "Please input a number\n";
    }

    auto time1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int errors = 0;

    for(int i = 1; i <= trials; i++)
    {
        int first = rand() % maxNumber + 1;
        int second = rand() % maxNumber + 1;

        printf("%d: %d * %d\n", i, first, second);

        int answer = 0;

        while (!(cin >> answer) || !(answer == first * second)) {
            cin.clear(); //clear bad input flag
            cin.ignore(1000, '\n'); //discard input
            cout << "Incorrect\n";
            errors++;
        }
        Util::printLines(12);
    }
    
    auto time2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); 
    auto timeDelta = time2-time1; 
    
    Util::printLines(25);

    printf("%d Questions\n", trials);
    printf("Tables up to %d\n\n", maxNumber);
    printf("Time Taken: %.4f seconds\n", timeDelta / 1000.0);
    printf("Time Per Question: %.4f seconds\n", (timeDelta / 1000.0) / (double) trials);
    printf("Accuracy: %.2f%% %d/%d\n", (trials*100.0)/(trials+errors), trials, trials+errors);

    Util::printLines(2);

    return 0;

}