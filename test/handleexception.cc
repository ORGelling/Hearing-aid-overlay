#include "main.ih"

int handleExceptions()
try
{
    rethrow_exception(current_exception());
}
catch (const invalid_argument &except) 
{
    cerr << "Argument parsing error: " << except.what() << '\n';
    return 1;
}
catch (const out_of_range &except)
{
    cerr << "Argument value out of range: " << except.what() << '\n';
    return 2;
}
catch (const bad_alloc &except)
{
    cerr << "Memory allocation failure: " << except.what() << '\n';
    return 3;
}
catch (const runtime_error &except)
{
    cerr << "Runtime error: " << except.what() << '\n';
    return 4;
}
catch (const exception &except)
{
    cerr << "Standard exception: " << except.what() << '\n';
    return 5;
}
catch (...)
{
    cerr << "Unknown fatal error!" << '\n';
    return 7;
}
