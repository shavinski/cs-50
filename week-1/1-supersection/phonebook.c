#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string phone_number = get_string("Phone Number: ");

    printf("%s is my name \n", name);
    printf("I am %i years old\n", age);
    printf("%s is my phone number \n", phone_number);
}