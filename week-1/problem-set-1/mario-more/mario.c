#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int);

int main(void)
{
    // Get size of pyramid
    int height = get_height();

    // Print pyramid of #'s and relevant spaces
    print_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 9);
    return height;
}

void print_pyramid(height)
{
    for (int i = 0; i < height; i++)
    {
        // Print left side
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");

        // Print right side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
