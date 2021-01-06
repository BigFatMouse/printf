#include <stdio.h>

int main (void)
{


    char    c = 'c';
    char    *str = "hello world";
    int     num = -42;
    int     num1 = 42;
    int     num2 = 123456789;
    float   num3 = 32.3;

    printf("\n-- conversions: cspdiuxX%% --\n");

    printf("c: %c\n", c);           //%c
    printf("s: %s\n", str);         //%s
    printf("p: %p\n", str);         //%p
    printf("d: %d\n", num);         //%d
    printf("i: %d\n", num);         //%i
    printf("u: %u\n", num);         //%u
    printf("x: %x\n", num1);         //%x
    printf("X: %X\n\n", num1);         //%X

    printf("\n-- width --\n");          //ширина - то, что перед точкой

    printf("  5d: %5d\n", num);
    printf(" 20X: %-20X\n", num1);
    printf(" 20c: %20c\n", c); 

    printf("\n-- flag '0' --\n");        //флаг '0' ставится перед шириной,               
                                        //применяется только к числам
    printf("  0d: %0d\n", num);         //если ширина не указана, он игнорируется
    //printf(" -05d: %-05d\n", num);      //флаг '0' игнорируется, когда он вместе с флагом '-'
    printf(" 05d: %05d\n", num);
    printf(" 05d: %05d\n", num1);

    printf("\n-- flag '-' --\n");       //флаг '-' ставится перед шириной, 
                                        //применяется ко всем форматам 
    printf("  -d: %-d\n", num1);        //если ширина не указана, он игнорируется   
    printf(" -5d: %-5d\n", num1);
    printf(" -5d: %-5d\n", num1);
    printf(" -5c: %-5c\n", c); 

    printf("\n-- flag '*' --\n");       //флаг '*' ставится вместо ширины 
                                        //ширина берется из первого аргумента
    printf(" *d: %*d\n", 10, num);
    printf(" 0*d: %0*d\n", 10, num);
    printf(" *.4d: %*.4d\n", 10, num);

    printf("\n-- precision --\n");      //точность - то, что после точки

    printf(" .8f: %.8f\n", num3);       
    printf(" .8d: %.8d\n", num);        //для целых чисел заполняет нулями слева
    printf(" .8d: %.8d\n", num);       //число не обрезает
    printf(" .8d: %.8d\n", num2); 
    printf(" .8s: %.8s\n", str);        //строку обрезает
	printf("-8.0d: |%-8.6d|\n", num);
    printf("08.0d: |%08.6d|\n", num);   //если точность ноль, то она не учитывается (кроме тех случаев, когда печатается 0)
	printf("8.0d:|%8.0d|\n", num);
    printf("8d:  |%8d|\n", num); 
    printf("8.0d: |%8.0d|\n", 0);          //если 0 с точностью ноль, то ничего не печатается
	printf("8d:   |%.8d|\n", 0); 
    
    printf("YES 010.4d: [%10.5d]\n", 228);     //точность вместе с шириной может быть только у чисел, игнорирует флаг '0'

    printf("%d\n", printf("\nreturn = ")); //возвращает кол-во напечатанных символов

    return (0);
}