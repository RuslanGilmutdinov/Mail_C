#ifndef CONST_GUARD_CLASS_H_
#define CONST_GUARD_CLASS_H_

//=============================================		

	#ifdef _MSC_VER
		#define _FUNC_  __FUNCTION__
	#elif __GNUC__
		#define _FUNC_  __PRETTY_FUNCTION__
	#endif	

	#define _DEBUG_ASSERT_(msg) cout << _FUNC_ << ":" << msg; assert(0);
	#define _ASSERT_OK_() if (!this->Ok ()) { \
						this->show (); \
						_DEBUG_ASSERT_("Not Ok!") \
					} 

	#define  USE_SUPER_PUPER_GUARDS 
//============================================

	unsigned const int MAX_STACK_SIZE = 2;

       // unsigned const int NUMBER_OF_COMAND = 4;

        const int guard_first  = -100800;
	
	const int guard_second = -100500;
	
        const int guard_third  = 100500;
	
        const double costruct_stack   = -999;
	
	const double destructor_stack = -100500;
	
	const int not_enouth_number   = -333;
	const int no_element          = -444;
	const int zero_in_denominator = -555;
	
	const int null_pointer = -666;

#endif

