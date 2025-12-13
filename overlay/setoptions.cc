#include "main.ih"

void setOptions(int argc, char **argv, 
                int &size, double &angle, size_t &count)
{
    if (argc > 2)
    {
        size = stoi(argv[1]);
        angle = stod(argv[2]);
    }
    if (argc == 4)
        count = stoul(argv[3]);
}
