#include <iostream>
#include <math.h>
// gdy C=0 generator multiplikatywny, gdy C=1 generator mieszany
#define C 1
#define N 100000
#define A 69069
using ll = long long;
const ll M = pow(2, 31) - 1;
const int arrLength = 20;

// Generator zwracajacy randomowa liczbę long long za pomoca algorytmu 2.2 z pdfa
ll random(ll prev) { return (A * prev + C) % M; };

// Funkcja przeksztalcajaca 31-elementowy array na liczbe całkowita
ll toLL(bool bin[31]) {
    ll temp = 0;
    for (int i = 0; i < 31; i++) if (bin[i] == 1) temp += pow(2, 30 - i);
    return temp;
};

int main() {
    printf("Task 2.2\n");
    ll x = 15;
    ll probabilityArray[arrLength];
    int index, sum = 0;
    for (int i = 0; i < arrLength; i++) probabilityArray[i] = 0;
    for (int i = 0; i < N; i++) {
        x = random(x);
        index = arrLength * x / M;
        probabilityArray[index]++;
    }

    for (int i = 0; i < arrLength; i++) {
        sum += probabilityArray[i];
        printf("%d %lld\n", i, probabilityArray[i]);
    }
    printf("Sum: %d\n\n", sum);


    printf("Task 2.6\n");
    const int p = 7, q = 3;
    for (int i = 0; i < arrLength; i++) probabilityArray[i] = 0;
    bool bin[32] = { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
                    1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                    0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1 };
    
    for (int i = 0; i < N; i++) {
        // 7+24 = 31 czyli maksymalne miejsce w bin[32]
        for (int j = 0; j < 25; j++) bin[j] = bin[j + p] ^ bin[j + q];
        ll temp = toLL(bin);
        // Dodaj wylosowana liczbę do tablicy
        index = arrLength * temp / M;
        probabilityArray[index]++;
        // Przesuniecie ostatnich 7 bitow na pierwsze 7 bitow
        for (int k = 0; k < 7; k++) bin[k + 25] = bin[k];
    }
    sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += probabilityArray[i];
        printf("%d %lld\n", i, probabilityArray[i]);
    }
    printf("Sum: %d\n\n", sum);
    return 0;
};
