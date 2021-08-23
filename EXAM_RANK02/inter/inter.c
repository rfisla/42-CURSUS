#include <unistd.h>

int main(int argc, char **argv)
{
    char inter[255] = {0};

    int num_arg;
    int str;
    if (argc == 3)
    {
        num_arg = 2;
        while (num_arg > 0)
        {
            str = 0;
            while (argv[num_arg][str])
            {
                if (num_arg == 2 && !inter[(unsigned char)argv[num_arg][str]])
                    inter[(unsigned char)argv[num_arg][str]] = 1;
                if (num_arg == 1 && inter[(unsigned char)argv[num_arg][str]] == 1)
                {
                    write (1, &argv[num_arg][str], 1);
                    inter[(unsigned char)argv[num_arg][str]] = 2;
                }
                str++;
            }
            num_arg--;
        }
    }
    write (1, "\n", 1);
    return (0);
}