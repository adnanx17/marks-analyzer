#include <iostream>
using namespace std;

int calculateTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }

    return total;
}


double calculateAverage(int total, int n)
{
    return (double)total / n;
}

// Find highest mark
int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}


int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}


char calculateGrade(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

int main()
{
    int n;

    cout << "Enter number of subjects: ";
    cin >> n;

    int* marks = new int[n];


    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter marks for subject " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid marks! Enter marks between 0 and 100.\n";
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }


    int total = calculateTotal(marks, n);
    double average = calculateAverage(total, n);
    int highest = findHighest(marks, n);
    int lowest = findLowest(marks, n);
    char grade = calculateGrade(average);

    cout << "\n----- Result -----\n";
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Grade: " << grade << endl;

    delete[] marks;

    return 0;
}