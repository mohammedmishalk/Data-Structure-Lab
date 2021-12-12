#include <stdio.h> 

#include <string.h> 

void str(char *str);
void str(char *str) 

{ 

    int l, i; 

    char *beg, *end, ch; 

    l = strlen(str); 

    beg= str; 

    end= str; 


    for (i = 0; i < l - 1; i++) 

        end++; 


    for (i = 0; i < l / 2; i++) { 

        ch = *end; 

        *end = *beg; 

        *beg= ch; 


        beg++; 

        end--; 

    } 

} 

 
void main() 

{ 

    char str1[100] ;

    printf("Enter a string:"); 
    gets(str1);
    str(str1); 
    printf("Reverse of the string: %s\n", str1);  
    getch();
}
