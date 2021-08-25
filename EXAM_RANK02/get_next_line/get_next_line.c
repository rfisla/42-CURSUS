#include "get_next_line.h"

int get_next_line(char **line)
{
    char buf;
    int flag;
    char *aux;
    int i;
    int size;
    
    flag = 0;
    size = 1;
    if (!line || !(*line = malloc(1)))
        return (-1);
    *line[0] = '\0';
    while ((flag = read(0, &buf, 1))  && buf != '\n')
    {
        size ++;
        if (!(aux = malloc(size)))
        {
            free(*line);
            return (-1);
        }
        i = 0;
        while(i < size - 2 )
        {
            aux[i] = (*line)[i];
            i++;
        }
        aux[i] = buf;
        aux[i + 1] = '\0';
        free(*line);
        *line = aux;  
    }
    return(flag);
}
