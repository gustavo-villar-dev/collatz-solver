#include <iostream>
#include <stdio.h>

using namespace std;
    
int steps = 0;

//tells you all values of n and how many steps until n = 1
void collatz(int n){

    //check if number n has reached last value ("1")
    if(n > 1){
        
        //if even
        if(n % 2 == 0){
            n = n / 2;
            steps++; 
            (steps < 10) ? printf("\ni = 0%d | n = %d",steps,n) : printf("\ni = %d | n = %d",steps,n);
            collatz(n);
        }

        //if odd
        else if(n % 2 != 0){
            n = 3*n + 1;
            steps++;
            (steps < 10) ? printf("\ni = 0%d | n = %d",steps,n) : printf("\ni = %d | n = %d",steps,n);
            collatz(n);
        }
    }
}

//main function
int main(){

    //variables
    int n, test, trash;
    char repeat = 'Y';

    //while user wants to run the program, run it
    while (repeat == 'Y' || repeat == 'y')
    {
        //counters reset
        steps = 0;
        test = 0;

        //input
        trash = system("cls"); 
        cout << "\n---------COLLATZ---------\n\n";
        cout << "Insert an integer N: ";
        cin >> n;
        cout << "\n---------STEPS---------\n";

        //first step
        printf("\ni = 00 | n = %d",n);

        //function call
        collatz(n);

        //separator
        cout << "\n\n-----------------------\n";

        //repeat?
        printf("\nDo you wish to run the program again? (y/n)\n");
        do{
            //show message if mistakes happen and ask for new input
            if(test > 0) printf("Please type a valid character. (y/n)\n");
            cin >> repeat;
            test++;
        } while (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y');
    }

    return 0;
}   
