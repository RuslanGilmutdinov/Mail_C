#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <vector>
#include <assert.h>

#include "cStack.h"
#include "const_guard_class.h"

using std::cout;
using std::endl;

//int number_of_comand_in_array (const char *);


typedef cStack<double> stackDouble;

int main () {

    stackDouble my_first_stack = stackDouble (); /*Почему так не работае при наличии конструктора копирования*/
    stackDouble my_first_stack2; /* почему без пустых скобочек?? */

#ifdef COPY_CONSTRUCTOR
    stackDouble my_first_stack1 (my_first_stack); /* конструктор копирования */
#endif
  //  my_first_stack1 = my_first_stack;
  //  my_first_stack.push(4.3);
 //   my_first_stack.show();

    bool end_of_while = true;

    const char analogue [][44] = {"push", "pop", "last", "show", "exit","\0"};

    int comand_in_array = 0;

    for (auto s: analogue) {
        comand_in_array++;
        cout << "comand_in_array =  " << comand_in_array << endl;
    }
    if (comand_in_array <= 0) { assert (("NO COMMAND in ARRAY",0));}

    unsigned const int NUMBER_OF_COMAND = comand_in_array;

//  unsigned const int NUMBER_OF_COMAND = number_of_comand_in_array (&analogue[0][0]) ;
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


    return 0;
}
/*
int number_of_comand_in_array (const char *array_) {
    int comand_in_array = 0;

    for (auto s: array_) {
        comand_in_array++;
        cout << "comand_in_array =  " << comand_in_array << endl;
    }
    if (comand_in_array <= 0) { assert (("NO COMMAND in ARRAY",0));}
    return comand_in_array;
}
*/
