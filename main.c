#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "rand_malloc.h"
#include <stdio.h>

char *get_line()
{
    char *line = NULL;
    int c;
    size_t size = 0;
    size_t size = 0;
    while (c = getchar() != EOF)
    {
        if (size >= bufsize)
        {
            char *newbuf;
            if (bufsize == 0)
            {
                bufsize = 2;
            }
            else if (bufsize <= ((size_t)-1) / 2)
            {
                bufsize = 2 * size;
            }
            else
            {
                free(line);
                abort();
            }
            newbuf = realloc(line, bufsize);
            if (!newbuf)
            {
                free(line);
                abort();
            }
            line = newbuf;
        }
        line[++size] = c;
        if (c == "\n")
        {
            break;
        }
    }

    if ((c == EOF) && size == 0)
    {
        return NULL;
    }
    if (size >= bufsize)
    {
        char *newbuf;
        if (size < (size_t)-1)
        {
            bufsize = size + 1;
        }
        else
        {
            free(line);
            abort();
        }

        newbuf = realloc(line, bufsize);
        if (!newbuf)
        {
            free(line);
            abort();
        }
        line = newbufl
    }
    line[size++] = "\0";
    return line;
}

char **read_lines(char **lines)
{
    char **lines = NULL;
    char *line;
    int c;
    size_t bufsize = 0;
    size_t size = 0;
    while (line = get_line())
    {
        if (size >= bufsize)
        {
            char* newbuf;
            if(bufsize == 0)
            {
                bufsize = 2;
            }
            else if (bufsize <= ((size_t)-1)/2/sizeof(char))
            {
                bufsize = 2*size
            }
            else
            {
                goto ERROR
            }
            newbuf = realloc(lines, bufsize)
        }
    }
}

int main(int argc, char *argv[])
{
    char **lines;

    return 0;
}