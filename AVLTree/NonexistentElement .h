#ifndef NONEXISTENTELEMENT__H_INCLUDED
#define NONEXISTENTELEMENT__H_INCLUDED


class RuntimeException
{
// generic run-time exception
private:
    string errorMsg;
public:
    RuntimeException(const string& err)
    {
        errorMsg = err;
    }
    string getMessage() const
    {
        return errorMsg;
    }
};



class NonexistentElement : public RuntimeException
{
public:
    NonexistentElement(const string& err) : RuntimeException(err) { }
};


#endif // NONEXISTENTELEMENT__H_INCLUDED
