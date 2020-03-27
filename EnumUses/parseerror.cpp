enum ParseResult
{
    SUCCESS = 0,
    ERROR_OPENING_FILE = -1,
    ERROR_READING_FILE = -2,
    ERROR_PARSING_FILE = -3
};

ParseResult readFileContents()
{
    if (!openFile())
        return ERROR_OPENING_FILE;
    if (!readFile())
        return ERROR_READING_FILE;
    if (!parsefile())
        return ERROR_PARSING_FILE;

    return SUCCESS;
}

if (readFileContents() == SUCCESS)
    {
    // do something
    }
else
    {
    // print error message
    }


   // alternatively, if you were writing a function to sort a bunch of values:


enum SortType
{
    SORTTYPE_FORWARD,
    SORTTYPE_BACKWARDS
};

void sortData(SortType type)
{
    if (type == SORTTYPE_FORWARD)
        // sort data in forward order
    else if (type == SORTTYPE_BACKWARDS)
        // sort data in backwards order
}
