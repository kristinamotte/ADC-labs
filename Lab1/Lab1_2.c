#include <stdio.h>
#include <math.h>

void removeElement(int, double[], int);

int main() {
    int size;

    printf("Please enter how many elements will be in the array:\n");
    scanf("%d", &size);

    double numbers[size];
    int toDelete[size];
    int deleteSize = 0;

    printf("Please enter numbers:\n");

    for (int i = 0; i < size; i++) {
        scanf("%lf", &numbers[i]);
    }
    
    for (int i = 0; i < size; i++) {
        double temp = floor(numbers[i]*10)/10;
        temp -= 0.5;

        if (numbers[i] >= 0.5 && (roundf(temp) == 0 || roundf(temp) == temp)) {
            printf("Will be removed %2f\n", numbers[i]);
            toDelete[deleteSize] = i;
            deleteSize += 1;
        }
    }

    for(int i = 0; i < deleteSize; i++) {
        removeElement(toDelete[i], numbers, size);
    }

    for (int i = 0; i < size - deleteSize; i++) {
        printf("%2f ", numbers[i]);
    }
    
    return 0;
}

void removeElement(int pos, double arr[], int size) {
    for(int i = pos-1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}