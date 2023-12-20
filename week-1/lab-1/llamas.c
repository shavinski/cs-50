#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    if (start_size == end_size)
    {
        printf("Years: %i \n", years);
        return 0;
    }

    do
    {
        int pop_increase = (start_size / 3);
        int pop_decrease = (start_size / 4);

        start_size += pop_increase;
        start_size -= pop_decrease;

        years++;
    }
    while (start_size < end_size);

    // TODO: Print number of years
    printf("Years: %i \n", years);
}
