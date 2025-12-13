#include "main.ih"

void setOptions(int argc, char **argv, 
                int &size, double &angle, size_t &count)
{
    if (argc > 1)
    {
        size = stoi(argv[1]);
    }
    if (argc > 2)
    {
        angle = stod(argv[2]);
    }
    if (argc == 4)
        count = stoul(argv[3]);
}
