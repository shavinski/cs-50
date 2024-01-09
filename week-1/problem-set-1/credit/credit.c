#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_card_number(void);
string validate_card(long card_number);
void check_type_of_card(int sum_second_last, char card_to_str[256], int card_number_length);

int main(void)
{
    // Prompt user for card number
    long card_number = get_card_number();

    // Determine if card number is valid, if it is determine if AMEX, VISA, or Master
    string valid_card = validate_card(card_number);
}

long get_card_number(void)
{
    long card_number;
    do
        card_number = get_long("Number: ");
    while (!card_number);

    return card_number;
}

string validate_card(long card_number)
{
    // Covert card numbert to a string in order to loop over
    char card_to_str[256];
    sprintf(card_to_str, "%ld", card_number);
    int card_number_length = strlen(card_to_str);

    long temp_card_number = card_number;
    char second_last_every_other[256] = "";

    // Loop through string get every other from second to last
    for (int i = card_number_length - 2; i >= 0; i -= 2)
    {
        // Get every other digit starting with second to last and times by two
        int digit = (temp_card_number / 10 % 10) * 2;
        temp_card_number /= 100;

        char digit_str[256];
        sprintf(digit_str, "%d", digit);
        strcat(second_last_every_other, digit_str);
    }

    temp_card_number = card_number;
    char leftover_numbers[256] = "";

    // Loop through string to get leftover numbers not used
    for (int i = card_number_length - 1; i >= 0; i -= 2)
    {
        // Get every other digit starting with last
        int digit = (temp_card_number % 10);
        temp_card_number /= 100;

        char digit_str[256];
        sprintf(digit_str, "%d", digit);
        strcat(leftover_numbers, digit_str);
    }

    int second_last_every_other_length = strlen(second_last_every_other);
    int sum_second_last = 0;

    // Gets sum of the products of getting every second to last digit
    for (int i = 0; i < second_last_every_other_length; i++)
    {
        sum_second_last += second_last_every_other[i] - '0';
    }

    // Adds the sum with leftover numbers
    for (int i = 0; i < strlen(leftover_numbers); i++)
    {
        sum_second_last += leftover_numbers[i] - '0';
    }

    // printf("%i \n", sum_second_last);

    // Determines if card is invalid, if not then determines type of card
    if (sum_second_last % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        check_type_of_card(sum_second_last, card_to_str, card_number_length);
    }

    return 0;
}

void check_type_of_card(int sum_second_last, char card_to_str[256], int card_number_length)
{
    char first_two_chars[3];
    char first_char[2];

    first_two_chars[0] = card_to_str[0];
    first_two_chars[1] = card_to_str[1];
    first_char[0] = card_to_str[0];

    if ((strcmp(first_two_chars, "34") == 0 || strcmp(first_two_chars, "37")) == 0 && card_number_length == 15)
    {
        printf("AMEX\n");
    }
    else if ((strcmp(first_two_chars, "51") == 0 || strcmp(first_two_chars, "52") == 0 || strcmp(first_two_chars, "53") == 0 ||
              strcmp(first_two_chars, "54") == 0 || strcmp(first_two_chars, "55") == 0) &&
             card_number_length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (strcmp(first_char, "4") == 0 && (card_number_length == 13 || card_number_length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}