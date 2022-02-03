#include <stdio.h>
int main()

{

       FILE *fp, *ft;

       fp = fopen("a.txt", "r");

       ft = fopen("b.txt", "r");

       fclose(fp,ft);
       return 0;

}
