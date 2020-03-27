#include <iostream>

Database* createDatabase(std::string filename)
{
    try
    {
        Database *d = new Database(filename);
        d->open(); // assume this throws an int exception on failure
        return d;
    }
    catch (int exception)
    {
        // Database creation failed
        // Write an error to some global logfile
        g_log.logError("Creation of Database failed");
    }

    return nullptr;
}




int getIntValueFromDatabase(Database *d, std::string table, std::string key)
{
    assert(d);

    try
    {
        return d->getIntValue(table, key); // throws int exception on failure
    }
    catch (int exception)
    {
        // Write an error to some global logfile
        g_log.logError("doSomethingImportant failed");

        throw 'q'; // throw char exception 'q' up the stack to be handled by caller of getIntValueFromDatabase()
    }
}
