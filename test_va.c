#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void func(int num, ...)
{
    va_list args;
    int i;
    int sum;
    char *str;

    va_start(args, num);
    if (num >= 10 && num <= 19)
    {
        i = num % 10;
        while (i != 0)
        {
            sum = va_arg(args, int);
            write(1, &sum, 1);
            --i;
        }
    }
    if (num >= 20 && num <= 29)
    {
        i = num % 10;
        while (i != 0)
        {
            str = va_arg(args, char *);
            printf("\n%s", str);
            --i;
        }
    }
    va_end(args);    
}

int main(void)
{
    func(14, 75, 68, 78, 79);
    func(22, "gkd", "geger");
}

// 10 - print char .0-9 - size
// 20 - print str .0-9 size