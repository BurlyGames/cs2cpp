#ifndef HEADER_System_Activator_STUBS
#define HEADER_System_Activator_STUBS
namespace CoreLib { namespace System { 
    
    // Method : System.Activator.CreateInstance<T>()
    template <typename T> 
    T Activator::CreateInstanceT1()
    {
		return __create_instance<T>();
    }
}}
#endif