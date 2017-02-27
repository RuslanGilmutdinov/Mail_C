//---------------------------------------
//! @file main.cpp
//! Implements a cStack class
//!
//! @author Ruknez, 2017
//---------------------------------------

#ifndef cSTACK_H_
#define cSTACK_H_	

#include <iostream>
#include <assert.h>
#include <vector>
#include <math.h>

#include "cMass.h"
#include "const_guard_class.h"

using std::cout;
using std::cin;
using std::endl;

// --------------------------
/*!
	\brief class stack
	
	it has constructor, distruction, show, Ok,
	pop, push and other function
*/

typedef cMass<double> MassDouble;

//---------------------------------------
//! Stack class
//---------------------------------------

template <typename T> 
class cStack {

    public:
        cStack ();
        cStack ( T data [], const int n); /*Not realizd */
        ~cStack ();
    #ifdef COPY_CONSTRUCTOR
            cStack (cStack &copy_stack);
    #endif
            cStack <T> &operator=(cStack <T> &copy_stack ) {
                std::vector<T> temporary_storage;
                /*Заполняем вектор всеми элементами из копируемого стека */
                while ( !(copy_stack.show_last_element () != copy_stack.show_last_element ()) ) {
                    temporary_storage.push_back (copy_stack.pop ());
                }

                while ( !(this->show_last_element () != this->show_last_element ()) ) {
                    this->pop ();
                }

                int size = temporary_storage.size ();
                cout << "size = " << size << endl;
                for (int i = 0; i < size; i++) {
                   this->push (temporary_storage.back ());
                   copy_stack.push (temporary_storage.back ());
                   temporary_storage.pop_back ();
                }

            }

        bool Ok () const;
        void show () const;

        bool push (T valua);
        T pop ();

        int size ();
        T show_last_element () const;

    private:
        int m_memory_guard_first;
        int m_count;
        int m_memory_guard_second;
        int m_memory_guard_third;
        MassDouble *m_mass;
            void processing_error (const int namb_Of_error) const;
};

//==========================
template <typename T> 
cStack <T>::cStack () : m_count (0), m_memory_guard_first (guard_first), m_memory_guard_second (guard_second),
	
	m_memory_guard_third (guard_third) {
	
	m_mass = new MassDouble (MAX_STACK_SIZE);
		
}

//==========================
template <typename T> 
cStack <T>::cStack (  T data [], int n) : m_count (n)/*, m_data ({data}) */{}

//==========================
#ifdef COPY_CONSTRUCTOR
template <typename T>
cStack <T>::cStack (cStack <T> &copy_stack) {
    cout << "\n \n \n cStack (cStack <T> &copy_stack) \n \n \n";
    m_count = 0;
    m_memory_guard_first  = guard_first;
    m_memory_guard_second = guard_second;
    m_memory_guard_third  = guard_third;
    m_mass = new MassDouble (MAX_STACK_SIZE);

    std::vector<T> temporary_storage;
/*Заполняем вектор всеми элементами из копируемого стека */
    while ( !(copy_stack.show_last_element () != copy_stack.show_last_element ()) ) {
        temporary_storage.push_back (copy_stack.pop ());
    }
    while ( !(this->show_last_element () != this->show_last_element ()) ) {
        this->pop ();
    }

    int size = temporary_storage.size ();
    cout << "size " << size << endl;
    for (int i = 0; i < size; i++) {
        this->push (temporary_storage.back ());
        copy_stack.push (temporary_storage.back ());
        temporary_storage.pop_back ();
    }

}
#endif


//==========================
template <typename T> 
cStack <T>::~cStack () {
	
	cout << "I am a distructor I delete cStack !!! \n";	
	m_count = -100;
	
	if (m_mass != NULL) {
            delete m_mass;
	}
	
	/*
	for (double k = 0: m_data) {
			k = -100500;
	}
	*/
}

//=========================
/*!
	The function Check stack
	\return bool parameter true if all OK
 */
template <typename T> 
bool cStack <T>::Ok () const {
	
	
	if ((m_count < 0) ) {
		cout << "WARNING m_count < 0 !!!! \n";
		cout << __FILE__ << endl;
		cout << _FUNC_<< "   " << __LINE__ << endl;
		return false;
	}
	
        if (m_memory_guard_first != guard_first || m_memory_guard_second != guard_second ||
                                                    m_memory_guard_third != guard_third) {
		cout << "!!! boundary constants are change !!! \n";
		return false;			
	} 
	
	if (!m_mass->Ok ()) {
			return false;
	}
	
	return true;
}

//=======================
//---------------------------------------
//! The function add one more number in stack
//! @param value is an element to be pushed
//! @return success of operation
//---------------------------------------
template <typename T> 
bool cStack <T>::push (T valua) {
	
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	m_mass->push_number (valua , m_count++);
	
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
	
	return true;		
}

//======================
/*!
    The function return the last element in stack
    \return the last element in stack
 */
template <typename T> 
T cStack <T>::pop () {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
        if (m_count == 0) {
            processing_error (no_element);
            T tag = 1./0.;
            return NAN;
        }
	T last_element = m_mass->take_number ((m_count) - 1); 

	m_mass->push_number (0,(m_count) - 1);
	m_count--;

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	return last_element;
		
}

//======================
//---------------------------------------
//! The function show the size of stack
//! @return the size of stack
//---------------------------------------
template <typename T> 
int cStack <T>::size () {
		
	return m_count;
	
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

}

//========================
/*!
  The function is showing the size of stack
*/
//#define SHOW(object) {object.show (#object) } 
 //SHOW (cStack <T>)
template <typename T> 
void cStack <T>::show () const {
	
	cout << "count = " << m_count << endl;
	m_mass->show();

	cout << endl;
		
}

//=====================
//---------------------------------------
//! The function show the last number in the stack
//! @return the last number
//---------------------------------------
template <typename T> 
T cStack <T>::show_last_element () const {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif	
        if (m_count == 0) {
            processing_error (no_element);
            T tag = 1./0.;
            return NAN;
        }
        T last_element = m_mass->take_number ((m_count) - 1); //m_data [(m_count) - 1];
		

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif		
	return last_element;
}

//==========================
//---------------------------------------
//! The function handles errors
//! @param code of errors
//---------------------------------------
template <typename T>
void cStack <T>::processing_error (const int namb_Of_error) const {

#ifdef USE_SUPER_PUPER_GUARDS
        _ASSERT_OK_()
#endif

#define IF_ERROR_NUMBER_(err, text) \
        if (namb_Of_error == err) {     \
                        cout << text << endl; \
        }

        IF_ERROR_NUMBER_ (null_pointer,
                          "WARNING!!! The pointer to mass == NULL WARNING!!! \n");

        IF_ERROR_NUMBER_ (not_enouth_number,
                           "Not enough numbers in the mass \n");

        IF_ERROR_NUMBER_ (no_element,
                        "No numbers in the stack \n");

#undef IF_ERROR_NUMBER_MASS_

#ifdef USE_SUPER_PUPER_GUARDS
        _ASSERT_OK_()
#endif

}

#endif

