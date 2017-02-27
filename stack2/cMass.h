//---------------------------------------
//! @file main.cpp
//! Implements a cMass class
//!
//! @author Ruknez, 2017
//---------------------------------------

#ifndef cMASS_H_
#define cMASS_H_

#include <iostream>
#include <assert.h>

#include "const_guard_class.h"

using std::endl;
using std::cout;

/*!
        \brief class cMass

        it has constructor, distruction, show, Ok,
        and other function
*/

template <typename G> 
class cMass {
	public:
	
		cMass (int count_);
		~cMass ();
		
		void show () const;
		bool Ok ();
		
		bool push_number (G number_ , int iterator_);
		G take_number (int  iterator_);
		
	private:
                bool processing_error (const int namb_Of_error);
		bool internal_resize (int iterator_);
	
		G *m_mass;
		
                int MAX_MASS_SIZE;
                int m_counter_change_number;
	
};

//==========================
template <typename G> 
cMass <G>::cMass (int count_) {
	
	m_counter_change_number = 0;
	MAX_MASS_SIZE = count_;	
	
	//G *m_mass = new  G [count_];
	m_mass = (G*) malloc (count_*sizeof(G));

	for (int i = 0; i < count_; i++) {
		m_mass [i] = costruct_stack;
	}	
	
     //   show ();
}

//==========================
template <typename G>
cMass <G>::~cMass () {
	
	cout << "I am a distructor I delete cMass !!! \n";	
	delete [] m_mass;

}

//==========================
//---------------------------------------
//! The function add one more number in array
//! @param value is an element to be pushed
//! @return success of operation
//---------------------------------------
template <typename G>
bool cMass <G>::push_number (G number_, int iterator_) {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	internal_resize (iterator_);
	
	if (m_mass [iterator_] == -999 ) {
		m_counter_change_number++;
	}		
		
	m_mass [iterator_] = number_;

	return true;

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
}

//==========================
//---------------------------------------
//! The function return number from array
//! @param iterator to number
//! @return number from array
//---------------------------------------
template <typename G>
G cMass <G>::take_number (int iterator_) {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif	
        if (iterator_ < 0) {
           assert(("you are trying to access the negative element of the array", 0));
        }

	return m_mass [iterator_];

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
}

//==========================
/*!
  The function is showing all array
*/
template <typename G>
void cMass <G>::show () const {
	
        cout << "FILE NAME: " << __FILE__ << " FUNCTION NAME: "<< _FUNC_ << endl << endl;

	cout << "MAX_MASS_SIZE = " << MAX_MASS_SIZE << endl;
	cout << "m_mass [" << MAX_MASS_SIZE << "]" << endl;
	for (int i = 0; i < MAX_MASS_SIZE; i++ ) {
	
		if ( i < m_counter_change_number) { 
			cout << "    *";
		}
		else {cout << "    ";}		
		
		cout << "["<< i << "] =" << " " <<	 m_mass [i];
		if (m_mass [i] != costruct_stack && m_counter_change_number <= i)  
			cout << "  ERROR ";
			cout << "\n";
	}

}

//==========================
template <typename G>
bool cMass <G>::Ok () {

        if (m_counter_change_number < 0) {
            cout << "WARNING  m_counter_change_numbe < 0 !!!! \n";
            cout << __FILE__ << endl;
            cout << _FUNC_<< "   " << __LINE__ << endl;
            return false;
	}
	
	unsigned int counter = 0;
	for (int i = 0; i < MAX_MASS_SIZE; i++) {
            if (m_mass [i] == -999) {
                counter++;
            }
	}
	
	if ((MAX_MASS_SIZE - m_counter_change_number) != counter)	{
		cout << "!!!WARNING!!!  counter_change_number != counter /n";
	}
	
	return true;
}

//==========================
//---------------------------------------
//! The function work with array realloc new memory
//! @param iterator to number
//! @return saccess of operation
//---------------------------------------
template <typename G>
bool cMass <G>::internal_resize (int iterator_) {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	if (*m_mass == NULL) {	
            processing_error (null_pointer);
	}	

	if (iterator_ == (MAX_MASS_SIZE - 1)) {
			
            int new_size = MAX_MASS_SIZE*2;
            m_mass = (G*) realloc ((G*) m_mass, new_size*sizeof(G));

            for (int i = MAX_MASS_SIZE; i < new_size; i++) {
                m_mass [i] = costruct_stack;
            }

            MAX_MASS_SIZE = MAX_MASS_SIZE*2;
	} 
	
	if (*m_mass == NULL) {	
			processing_error (null_pointer);
	}

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	return true;
}

//==========================
template <typename G>
bool cMass <G>::processing_error (const int namb_Of_error) {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
	
#define IF_ERROR_NUMBER_MASS_(err, text) \
	if (namb_Of_error == err) {     \
                        cout << text << endl; \
                        return true; \
        }
	
	IF_ERROR_NUMBER_MASS_ (null_pointer, 
				"WARNING!!! The pointer to mass == NULL WARNING!!! \n");

        IF_ERROR_NUMBER_MASS_ (not_enouth_number,
                                "Not enough numbers in the mass \n");

        IF_ERROR_NUMBER_MASS_ (no_element,
                        "No numbers in the mass \n");

#undef IF_ERROR_NUMBER_MASS_

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
	
	return false;
}

#endif 
