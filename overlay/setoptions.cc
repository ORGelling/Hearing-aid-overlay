#include "main.ih"

void setOptions(int argc, char **argv, 
                size_t &count, double &angle, int &size)
{
    if (argc > 1)
    {
        count = stoul(argv[1]);
    }
    if (argc > 2)
    {
        angle = stod(argv[2]);
    }
    if (argc == 4)
        size = stoi(argv[3]);
}