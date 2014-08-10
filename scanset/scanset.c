#include <stdio.h>

void main(void)
{
    int i;
    char str[80], str2[80];

    //scanf("%d%[abcdef]%s", &i, str, str2);
    //printf("%d %s %s \n", i, str, str2);

    //if scanset received a ^ like a frist argument,
    //the clausule is "negative".
    //Ex: %[^A-Z] --This is casesensitive
    //Her search all char where diference of A-Z

    //With regular expersion
    scanf("%[A-F]", str);
    printf("%s \n", str);
}
