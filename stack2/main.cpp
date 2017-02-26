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

using std::cout;
using std::endl;

unsigned int number_of_comand_in_array (const char array_[][44]);
void abstract ();

typedef cStack<double> stackDouble;

int main () {

    //stackDouble my_first_stack = stackDouble (); /*Почему так не работае при наличии конструктора копирования*/
    stackDouble my_first_stack2; /* почему без пустых скобочек?? */
    stackDouble my_first_stack;
    abstract ();

#ifdef COPY_CONSTRUCTOR
//    stackDouble my_first_stack1 (my_first_stack); /* конструктор копирования */
#endif
    my_first_stack.push(13);
    my_first_stack.push(14);
    my_first_stack.push(15);
    my_first_stack.push(16);
    my_first_stack.push(17);
    my_first_stack.push(18);
    my_first_stack.push(19);

    my_first_stack2.push(44);
    my_first_stack2.push(45);
    my_first_stack2.push(46);
    my_first_stack2.push(47);
    my_first_stack2.push(48);
    my_first_stack2.push(49);
    my_first_stack2.push(50);

    my_first_stack.show();
    my_first_stack2.show();


    my_first_stack = my_first_stack2;

    my_first_stack2.push(500);
    my_first_stack.show();
    my_first_stack2.show();

 //   stackDouble my_first_stack3 (my_first_stack);

    bool end_of_while = true;

    const char analogue [][44] = {"push", "pop", "last", "show", "exit","\0"};

    int comand_in_array = 0;

    for (auto s: analogue) {
        comand_in_array++;
    }
    if (comand_in_array <= 0) { assert (("NO COMMAND in ARRAY",0));}

 //   unsigned const int NUMBER_OF_COMAND = comand_in_array;

    unsigned const int NUMBER_OF_COMAND = number_of_comand_in_array (analogue);
    return 0;
    /*
    for (int i = 0; (0 != strcmp(analogue [i], "\0")); ++i ) {

        cout << "i= " << i << endl;
    }
*/

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


std::vector<double> temporary_storage;

    while ( !(my_first_stack.show_last_element () != my_first_stack.show_last_element ()) ) {
        temporary_storage.push_back (my_first_stack.pop ());
        cout << "XOXOXOXOXOX" << endl;
    }

    int size = temporary_storage.size ();
    cout << "size " << size << endl;
    for (int i = 0; i < size; i++) {
        cout << "temporary_storage " << temporary_storage.back () << endl;
         temporary_storage.pop_back ();
    }
    return 0;
}

unsigned int number_of_comand_in_array (const char array_[][44]) {
  unsigned int comand_in_array = 0;
    for (int i = 0; i < 4; i ++) {
        cout << "array_ = " << array_ [i] << endl;
    }
    for (auto s: array_) {
        comand_in_array++;
        cout << "comand_in_array =  " << comand_in_array << endl;
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
