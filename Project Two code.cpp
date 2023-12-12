#include <iostream>
#include <iomanip>

// Include the use of the default namespace
using namespace std;

int main()
{
    // declare the variables
    float initInv, monDep, AnuInt, months, years;
    float totalAm, intAmt, yearTotInt;

    // show the input section's header
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    // To provide time to read the header, halt the program.
    system("PAUSE");

    // once more display the input heading along with prompts
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initInv; 
    cout << "Monthly Deposit: $";
    cin >> monDep; 
    cout << "Annual Interest: %";
    cin >> AnuInt; 
    cout << "Number of years: ";
    cin >> years; 
    months = years * 12; 

    // To allow time for the software to read the input, pause it.
    system("PAUSE");

    // set the overall sum to the amount you invested initially.
    totalAm = initInv;

    // display the first table's header.
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // loop through each year
    for (int i = 0; i < years; i++) {
        // Determine the annual interest amount.
        intAmt = (totalAm) * ((AnuInt / 100));
        // To the total sum, add the interest.
        totalAm = totalAm + intAmt;
        // output the outcomes to the table.
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";
    }
    // return the entire sum back the amount that was invested initially.
    totalAm = initInv;
    // show the second table's header.
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";
    // loop through each year
    for (int i = 0; i < years; i++) {
        // the year's total interest was reset.
        yearTotInt = 0;
        // cycle through every month
        for (int j = 0; j < 12; j++) {

            // find the monthly interest amount.
            intAmt = (totalAm + monDep) * ((AnuInt / 100)/12);
            yearTotInt = yearTotInt + intAmt;
            totalAm = totalAm + monDep + intAmt;
        }
        //Print results to table 
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n";
    }
    return 0;
}