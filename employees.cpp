/**
    @author Anish Patel
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double minValue(double [], int);
int findIndex(int [], int, int);

int main()
{
    // Change this variable to change the number of employees
    const int NUM_EMPLOYEES = 5;

    // Declares parallel arrays to hold employee ids and salaries
    int employeeIds [NUM_EMPLOYEES];
    double employeeSalaries [NUM_EMPLOYEES];

    // Initialize employee arrays
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Enter employee ID #: ";
        cin >> employeeIds[i] ;
        cout << "Enter salary for employee #" << employeeIds[i] << ": ";
        cin >> employeeSalaries[i];
    }

    // Print employee ids and salaries for all employees
    cout << endl << "All Employees: " << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "ID #: " << employeeIds[i] << "\t";
        cout << "Salary: $" << employeeSalaries[i] << endl;
    }

    // Get the lowest salary
    int minSalary = minValue(employeeSalaries, NUM_EMPLOYEES);
    cout << "Minimum Salary: $" << minSalary << endl;

    // Get the salary of the specified employee
    // Asks 2 times
    for (int i = 0; i < 2; i++) {
        int id;
        cout << endl << "Enter the employee's ID# of whose salary you want: ";
        cin >> id;
        int index = findIndex(employeeIds, NUM_EMPLOYEES, id);
        if (index == -1) {
            cout << "Employee not found." << endl;
        } else {
            cout << "Salary: $" << employeeSalaries[index] << endl;
        }
    }

    return 0;
}

// Input: array of numbers, length of array
// Output: index of the value found or -1 if not found
double minValue(double arr [], int length)
{
    double minValue = numeric_limits<double>::max(); // maximum double value
    // NOTE: A for loop is used because we must traverse the entire array to find the minimum value.
    for (int i = 0; i < length; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

// Input: array of numbers, length of array, value to find
// Output: index of the value found or -1 if not found
int findIndex(int arr [], int length, int value)
{
    int i = 0;
    // NOTE: A while loop is used because we stop searching once we find a match.
    while (i < length && value != arr[i]) i++;
    if (i == length) {
        // value not found in array
        return -1;
    }
    return i;
}
