#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main() {
    int v[10];
    for(int i=0; i<10; i++) {
        v[i] = i + 1;
    }

    printf("%d\n", binsearch(6, v, 10));
    printf("%d\n", binsearch2(6, v, 10));

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(v[low] == x)
        return low;
    else
        return -1;
}
