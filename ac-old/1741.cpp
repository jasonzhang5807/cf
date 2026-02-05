#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct Node {
    char data;
    int lchild;
    int rchild;
};

Node p[2100];
int nodeCount = 1;

char fbi(const string& a) {
    char cmp = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (cmp != a[i]) return 'F';
    }
    return (cmp == '1') ? 'I' : 'B';
}

int create(const string& s) {
    int current = nodeCount++;
    p[current].data = fbi(s);
    if (s.size() > 1) {
        int mid = s.size() / 2;
        p[current].lchild = create(s.substr(0, mid));
        p[current].rchild = create(s.substr(mid));
    }
    return current;
}

void rorder(int index) {
    if (index == 0) return;
    if (p[index].lchild != 0) rorder(p[index].lchild);
    if (p[index].rchild != 0) rorder(p[index].rchild);
    printf("%c", p[index].data);
}
int main() {
    int n;
    char s[1025];
    scanf("%d %s", &n, s);
    string input = s;
    create(input);
    rorder(1);
    printf("\n");
    return 0;
}
