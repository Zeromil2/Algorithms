#include "iostream"
#include "string.h"

using namespace std;

char bs(string A[], int l, int r, string K){
    if(r >= l){
        int m = (l + r) / 2;
        if (K == A[m]){
            return '+';
        }else if (K < A[m]){
            return bs(A, l, m - 1, K);
        } else {
            return bs(A, m + 1, r, K);
        }
    }
    else{
        return '-';
    }
}

int main(){
    int tamanho;
    cin >> tamanho;
    string array[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cin >> array[i];
    }

    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++) {
        string procurado;
        cin >> procurado;
        char resultado = bs(array, 0, tamanho - 1, procurado);
        cout << resultado << "\n";
    }

    return 0;
}