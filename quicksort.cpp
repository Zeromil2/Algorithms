#include <iostream>

using namespace std;

int hoare(int A[], int l, int r){
    int p = A[l], i = l, j = r + 1;
    do{
        do {
            i++;
        } while (A[i] < p and i < r);
        do{
            j--;
        } while (A[j] > p);
        swap(A[i], A[j]);
    } while (i < j);

    swap(A[i], A[j]);
    swap(A[l], A[j]);
    return j;
}

void quicksort(int A[], int l, int r){
    if (l < r){
        int s = hoare(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

int main() {

    int tamanho;
    cin >> tamanho;
    int array[tamanho];
    for (int i = 0; i < tamanho; i++) {
        cin >> array[i];
    }
    quicksort(array,0, tamanho - 1);
    for (int i = 0; i < tamanho; i++) {
        cout << array[i] << "\n";
    }
    return 0;
}
