#include <iostream>

#include <stdexcept>

class Except: virtual public std::runtime_error
{

protected:

    int error_number;               ///< Error number
    int error_offset;               ///< Error offset

public:

    /** Constructor (C++ STL string, int, int).
     *  @param msg The error message
     *  @param err_num Error number
     *  @param err_off Error offset
     */
    explicit
    Except(const std::string& msg, int err_num, int err_off):
        std::runtime_error(msg)
    {
        error_number = err_num;
        error_offset = err_off;

    }

    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~Except() throw () {}

    /** Returns error number.
     *  @return #error_number
     */
    virtual int getErrorNumber() const throw()
    {
        return error_number;
    }

    /**Returns error offset.
     * @return #error_offset
     */
    virtual int getErrorOffset() const throw()
    {
        return error_offset;
    }

};



int main()
{
    try
    {
        throw(Except("Couldn't do what you were expecting", -12, -34));
    }
    catch (const Except& e)
    {
        std::cout<<e.what()
                 <<"\nError number: "<<e.getErrorNumber()
                 <<"\nError offset: "<<e.getErrorOffset();
    }
    return 0;
}
