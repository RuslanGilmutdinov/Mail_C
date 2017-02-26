#ifndef cSTACK_H_
#define cSTACK_H_	

#include <iostream>
#include <assert.h>

#include "cMass.h"
#include "const_guard_class.h"

//#define USE_SUPER_PUPER_GUARDS 

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

template <typename T> 
class cStack {
	
	public:
		cStack ();
		cStack ( T data [], const int n);
		~cStack ();
#ifdef COPY_CONSTRUCTOR
                cStack (cStack &copy_stack);
#endif
                cStack <T> &operator=(const cStack <T> &copy_stack ) {
                    // Почему это не работает ???
                    cout << "\n \n Not work \n \n";
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
                void processing_error (const int namb_Of_error);
};

//==========================
template <typename T> 
cStack <T>::cStack () : m_count (0), m_memory_guard_first (guard_first), m_memory_guard_second ( guard_second),
	
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

        //m_count = copy_stack.?????
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
	
	if (m_memory_guard_first != guard_first ||	
										m_memory_guard_second != guard_second ||	m_memory_guard_third != guard_third) {
		cout << "!!! boundary constants are change !!! \n";
		return false;			
	} 
	
	if (!m_mass->Ok ()) {
			return false;
	}
	
	return true;
}

//=======================
/*!
	The function add one more number in stack
	\param vell the new number
 */
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
            return tag;
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
template <typename T> 
int cStack <T>::size () {
		
	return m_count;
	
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

}

//========================
/*!
	THe function is showing the size of stack
	\param stack pointers 
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
template <typename T> 
T cStack <T>::show_last_element () const {

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif	
	
		T last_element = m_mass->take_number ((m_count) - 1); //m_data [(m_count) - 1];
		

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif		
	return last_element;
}

//==========================
template <typename T>
void cStack <T>::processing_error (const int namb_Of_error) {

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

