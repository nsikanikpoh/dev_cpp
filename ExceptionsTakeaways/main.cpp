#include <iostream>




using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    try
    {
        openFile(filename);
        writeFile(filename, data);
        closeFile(filename);
    }
    catch (FileException &exception)
    {
        // Make sure file is closed
        closeFile(filename);
        // Then write error
        cerr << "Failed to write to file: " << exception.what() << '\n';
    }


    Person *john = nullptr;
    try
    {
        john { new Person("John", 18, PERSON_MALE) };
        processPerson(john);
        delete john;
    }
    catch (PersonException &exception)
    {
        delete john;
        cerr << "Failed to process person: " << exception.what() << '\n';
    }


#include <memory> // for std::unique_ptr

    try
    {
        Person *john { new Person("John", 18, PERSON_MALE) };
        unique_ptr<Person> upJohn { john }; // upJohn now owns john

        ProcessPerson(john);

        // when upJohn goes out of scope, it will delete john
    }
    catch (PersonException &exception)
    {
        cerr << "Failed to process person: " << exception.what() << '\n';
    }



    return 0;
}
