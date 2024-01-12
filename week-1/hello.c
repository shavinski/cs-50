#include <stdio.h>;
#include <cs50.h>;

// need to compile doing this: gcc hello.c -o hello -lcs50 

int main(void)
{
    string name = get_string("What's your name? ");
    string last = get_string("What's your last name? ");
    printf("hello, %s %s\n", name, last);
}


