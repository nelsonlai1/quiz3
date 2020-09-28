#include <stdio.h>
#include <stdint.h>

uint64_t gcd64(uint64_t u, uint64_t v) {
    if (!u || !v) return u | v;
    int ctzu = __builtin_ctz(u);
    int ctzv = __builtin_ctz(v);
    int shift = ctzv ^ ((ctzu ^ ctzv) & -(ctzu < ctzv));
    u = u >> ctzu;
    v = v >> ctzv;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int main()
{
    uint64_t ans = gcd64(4217256861456742389, 7514445744571296447);
    printf("%ld\n", ans);
    return 0;
}
