#include <stdio.h> 
#include <string.h> 
void main() 
{ 
    char text[20],pat[20];
    int a,b;
    printf("Enter the string : ");
    gets(text);
    printf("Enter the pattern to find : ");
    gets(pat);
    clrscr();
    
    a = strlen(pat); 
    b = strlen(text); 
  
    for (int i = 0; i <= b - a; i++) { 
        int j; 
  
        for (j = 0; j < a; j++) 
            if (text[i + j] != pat[j]) 
                break; 
  
        if (j == a)
            printf("Pattern found at position %d \n", i+1); 
    } 

    getch();
}