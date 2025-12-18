#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUF_SIZE 40960

int main(int argc, const char** argv)
{
    size_t buf_sz = DEFAULT_BUF_SIZE;
    char* buf = calloc(buf_sz, sizeof(char));

    size_t off = 0;
    while(fgets(buf + off, buf_sz - off, stdin) != NULL && !feof(stdin))
    {
        size_t len = strnlen(buf, buf_sz);
        if (len == buf_sz - 1 && buf[len - 1] != '\n')
        {
            buf = realloc(buf, buf_sz * 2);
            off = buf_sz - 1;
            buf_sz *= 2;
            continue;
        }

        for(size_t c = len - 1; c-- > 0;)
        {
            fputc(buf[c], stdout);
        }
        fputc('\n', stdout);

        off = 0;
    }
    
    free(buf);
    return 0;
}
