#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);
        total_sum += val;
    }

    long long ans = llabs(total_sum);

    printf("%lld\n", ans);
    return 0;
}
