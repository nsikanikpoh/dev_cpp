#ifdef INT_2_BYTES
typedef char int8_t;
typedef int int16_t;
typedef long int32_t;
#else
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
#endif

// typedefs allow you to take complex types and give them a simple name, which makes those types easier to work with and understand

typedef std::vector<std::pair<std::string, int> > pairlist_t; // make pairlist_t an alias for this crazy type

pairlist_t pairlist; // instantiate a pairlist_t

bool hasDuplicates(pairlist_t pairlist) // use pairlist_t in a function parameter
{
    // some code here
}


typedef double distance_t; // define distance_t as an alias for type double
//In C++11, this can be declared as:

using distance_t = double; // define distance_t as an alias for type double
