#include <cstdio>
#include <cstring>

char a[110], b[110], c[110];
char poi = 'a';
char ans;
int a1 = 0, b1 = 0, c1 = 0;

bool nxt() {
    if (poi == 'a') {
        ans = 'A';
        if (a[a1] == '\0') return false;
        poi = a[a1++];
    } else if (poi == 'b') {
        ans = 'B';
        if (b[b1] == '\0') return false;
        poi = b[b1++];
    } else if (poi == 'c') {
        ans = 'C';
        if (c[c1] == '\0') return false;
        poi = c[c1++];
    }
    return true;
}

int main() {
    scanf("%s %s %s", a, b, c);
    while (nxt());
    printf("%c\n", ans);
    return 0;
}

