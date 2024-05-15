#include <iostream>
#include "../include/segtree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    SegTree segtree(n);

    for (int i = 0; i < q; ++i) {
        char op;
        std::cin >> op;

        if (op == 'u') {
            int t;
            std::cin >> t;
            Matrix newMatrix;
            std::cin >> newMatrix.a >> newMatrix.b >> newMatrix.c >> newMatrix.d;
            segtree.update(t, newMatrix);
        } else if (op == 'q') {
            int t0, td, x, y;
            std::cin >> t0 >> td >> x >> y;
            Matrix result = segtree.query(t0, td);
            int newX = (1LL * result.a * x + 1LL * result.b * y) % 100000000;
            int newY = (1LL * result.c * x + 1LL * result.d * y) % 100000000;
            std::cout << newX << " " << newY << std::endl;
        }
    }

    return 0;
}