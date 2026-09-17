#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 0;

    long long kecil = a, tengah = b, besar = c;

    if (kecil > tengah) { long long t = kecil; kecil = tengah; tengah = t; }
    if (tengah > besar) { long long t = tengah; tengah = besar; besar = t; }
    if (kecil > tengah) { long long t = kecil; kecil = tengah; tengah = t; }

    long long kiri = tengah - kecil;
    long long kanan = besar - tengah;

    long long total_ronde = (kiri < kanan) ? kiri : kanan;

    printf("%lld\n", total_ronde);
    return 0;
}
