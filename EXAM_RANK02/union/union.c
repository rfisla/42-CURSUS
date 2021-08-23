#include <unistd.h>

int main(int argc, char **argv)
{
    char u[255] = {0};

    int num_arg;
    int pos_str;
    if (argc == 3)
    {
        num_arg = 1;
        while (num_arg < 3)
        {
            pos_str = 0;
            while(argv[num_arg][pos_str])
            {
                if (!u[(unsigned char)argv[num_arg][pos_str]])
                {
                   u[(unsigned char)argv[num_arg][pos_str]] = 1;
                   write (1, &argv[num_arg][pos_str], 1);
                }
                pos_str++;
            }
            num_arg++;
        } 
    }
    write (1, "\n",1);
    return (0);
}