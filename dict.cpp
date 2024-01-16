#include <iostream>
#include "math.h"
using namespace std;

typedef struct entry{
    int key;
    int elemento;
}Entry;

typedef struct dictionary{
    int m;
    int cnt;
    Entry *H;
}Dictionary;

int hash1(int key, Dictionary* d) {
    int temp = (int) floor((((double) key) / ((double) d -> m)));
    return (key - (d -> m * temp));
}

Dictionary* create_dict(int size){
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    d -> m = size;
    d -> cnt = 0;
    d -> H = new Entry[size];
    return d;
}

int find(Dictionary* d, int k){
    int index = hash1(k, d);
    if (d -> H[index].key == k) return index;
    for (int i = index; i < d -> m; i++) {
        if (d -> H[i].key == k) return i;
    }
    for (int j = 0; j < index; j++) {
        if (d -> H[j].key == k) return j;
    }
    return -1;
}

void insert(Dictionary* d, int k, int e, int Perm[]){
    if (d -> cnt < d -> m and find(d, k) == -1){
        int pos = hash1(k, d);
        if (d -> H[pos].elemento != 0){
            int i = 0;
            int newPos = pos;
            while (d -> H[newPos].elemento != 0){
                i++;
                int offset = Perm[i - 1];
                newPos = (pos + offset) % d -> m;
            }
            pos = newPos;
        }
        d -> H[pos].key = k;
        d -> H[pos].elemento = e;
        d -> cnt++;
    }
}

int main() {
    int m, key, value;
    cin >> m;
    while (m != 0){
        if (m != 0){
            Dictionary* dicio = create_dict(m);
            int Perm[m - 1];
            for (int i = 0; i < m - 1; i++) {
                int numero;
                cin >> numero;
                Perm[i] = numero;
            }
            int n;
            cin >> n;
            string comando;
            for (int i = 0; i < n; i++) {
                cin >> comando;
                if (comando == "add"){
                    cin >> key >> value;
                    insert(dicio, key, value, Perm);
                }
                else if (comando == "find"){
                    cin >> key;
                    int index;
                    index = find(dicio, key);
                    cout << index << "\n";
                }
            }
            free(dicio);
            cin >> m;
        }
    }
    return 0;
}
