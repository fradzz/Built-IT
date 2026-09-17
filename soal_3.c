#include <stdio.h>
#include <stdlib.h>

long long koin[1000005];

void tukar(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void urutkan(int kiri, int kanan) {
    if (kiri >= kanan) return;
    
    long long pivot = koin[(kiri + kanan) / 2];
    int i = kiri;
    int j = kanan;

    while (i <= j) {
        while (koin[i] < pivot) i++;
        while (koin[j] > pivot) j--;
        if (i <= j) {
            tukar(&koin[i], &koin[j]);
            i++;
            j--;
        }
    }
    
    urutkan(kiri, j);
    urutkan(i, kanan);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &koin[i]);
    }

    urutkan(0, n - 1);

    long long total = (long long)n * (n - 1) / 2;

    long long kembar = 1;
    for (int i = 1; i < n; i++) {
        if (koin[i] == koin[i - 1]) {
            kembar++;
        } else {
            total -= (kembar * (kembar - 1)) / 2;
            kembar = 1;
        }
    }
    total -= (kembar * (kembar - 1)) / 2;

    long long hasil = (total % 1000000007 + 1000000007) % 1000000007;

    printf("%lld\n", hasil);

    return 0;
}
