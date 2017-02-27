//---------------------------------------
//! @file main.cpp
//! Tests a stack class
//!
//! @author Ruknez, 2017
//---------------------------------------
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <vector>
#include <assert.h>
#include <math.h>

#include "cStack.h"
#include "const_guard_class.h"
//---------------------------------------
//! A simple unit-test
//! @param manual tests
//---------------------------------------
using std::cout;
using std::endl;

template <int N> unsigned int number_of_comand_in_array (const char (&array_) [N][44]);
void abstract ();

typedef cStack<double> stackDouble;

//---------------------------------------
//! main
//---------------------------------------

int main () {

    abstract (); /*Show abstract*/
//==============РУЧНЫЕ ТЕСТЫ НА ОПЕРАТОР '=' И КОНСТРУКТОР КОПИРОВАНИЯ==========
{
    //stackDouble my_first_stack = stackDouble (); /*Почему так не работае при наличии конструктора копирования*/
    stackDouble my_first_stack2; /* почему без пустых скобочек?? */

    stackDouble my_first_stack;

    stackDouble my_first_stack1 (my_first_stack); /* конструктор копирования */

    for (int i = 13; i < 20; i++) {
        my_first_stack.push ((double) i);
    }

    for (int i = 44; i < 51; i++) {
        my_first_stack2.push ((double) i);
    }
    my_first_stack.show();
    my_first_stack2.show();


    my_first_stack = my_first_stack2;

    my_first_stack2.push(500);
    my_first_stack.show();
    my_first_stack2.show();

    stackDouble my_first_stack3 (my_first_stack);
    my_first_stack.show();
    my_first_stack3.show();
}
//==========END OF TESTS=========
    abstract (); /*Show abstract*/

    stackDouble my_first_stack;

    bool end_of_while = true;

    const char analogue [][44] = {"push", "pop", "last", "show", "exit"};

    unsigned const int NUMBER_OF_COMAND = number_of_comand_in_array (analogue);

    while (end_of_while) {

        char comand [12];
        double number = 0;

        scanf ("%s", comand);

        if (0 == strcmp(analogue [0], comand)) {
                scanf ("%le", &number);
        }

        for (int i = 0; i < NUMBER_OF_COMAND; i++) {

            if (0 == strcmp(analogue [i], comand)) {

                switch (i) {
                    case 0:
                            my_first_stack.push (number);
                    break;

                    case 1:
                            my_first_stack.pop ();
                    break;

                    case 2:
                            cout << "The last element is: " << my_first_stack.show_last_element () << endl;
                    break;

                    case 3:
                            my_first_stack.show ();
                    break;

                    case 4:
                            end_of_while = false;
                    break;
                } // end of switch
            } // end of if
        } // end of for
    }	// end of while
    return 0;
} // end of main ()

//==========================
/*!
    Counts the number of elements in the array
*/
 template <int N> unsigned int number_of_comand_in_array (const char (&array_) [N][44]) {
   int comand_in_array = 0;
   /* for (int i = 0; i < 4; i ++) {
        cout << "array_ = " << array_ [i] << endl;
    }*/
    for (auto &&s: array_) {
        comand_in_array++;
    }
    if (comand_in_array <= 0) { assert (("NO COMMAND in ARRAY",0));}
    return comand_in_array;
}


//==========================
/*!
        Gide to comand
*/
void abstract () {
        cout << "Hellow ! \n"
                         << "Comand Enter like \n"
                         << "push 232 \n"
                         << "pop  \n"
                         << "show \n"
                         << "last \n"
                         << "exit" << endl;
}
