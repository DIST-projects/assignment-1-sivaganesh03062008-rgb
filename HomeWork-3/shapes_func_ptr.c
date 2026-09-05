#include <stdio.h>

/* Rectangle functions */
float rectangleArea(float length, float breadth)
{
    return length * breadth;
}

float rectanglePerimeter(float length, float breadth)
{
    return 2 * (length + breadth);
}

/* Triangle functions */
float triangleArea(float base, float height)
{
    return 0.5f * base * height;
}

float trianglePerimeter(float a, float b, float c)
{
    return a + b + c;
}

int main()
{
    int choice;
    float x, y, z;

    float (*areaFunction)(float, float);
    float (*perimeterFunction)(float, float);
    float (*trianglePerimeterFunction)(float, float, float);

    printf("1. Rectangle\n");
    printf("2. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter length and breadth: ");
        scanf("%f %f", &x, &y);

        areaFunction = rectangleArea;
        perimeterFunction = rectanglePerimeter;

        printf("\nArea = %.2f\n", areaFunction(x, y));
        printf("Perimeter = %.2f\n",
               perimeterFunction(x, y));
    }
    else if (choice == 2)
    {
        printf("Enter three sides and height (base height side): ");
        scanf("%f %f %f", &x, &y, &z);

        areaFunction = triangleArea;
        trianglePerimeterFunction = trianglePerimeter;

        printf("\nArea = %.2f\n",
               areaFunction(x, y));

        printf("Perimeter = %.2f\n",
               trianglePerimeterFunction(x, y, z));
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}