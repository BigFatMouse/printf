#include <stdio.h>

void func(int num, int num1, int num2, int num3)
{
int *ptr;
ptr = &num;
printf("%p\n", &num);
printf("%p\n", &num1);
printf("%p\n", &num2);
printf("%p\n", &num3);
/*
printf("%d\n", *(ptr--));
printf("%d\n", *(ptr--));
printf("%d\n", *(ptr--));*/
}

int main (void)
{
    func(3, 2, 1, 0);
}
