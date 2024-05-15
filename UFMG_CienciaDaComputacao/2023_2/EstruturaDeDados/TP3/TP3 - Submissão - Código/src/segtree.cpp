#include "../include/segtree.hpp"

SegTree::SegTree(int size) {
    n = size;
    tree = new TipoNo[4 * n];
    build(1, 0, n - 1);
}

SegTree::~SegTree() {
    delete[] tree;
}

void SegTree::build(int node, int start, int end) {
    if (start == end) {
        tree[node].matriz = Matrix{1, 0, 0, 1}; // Matriz identidade
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node].matriz = Matrix{1, 0, 0, 1}; // Matriz identidade
}

void SegTree::update(int idx, const Matrix& val) {
    update(1, 0, n - 1, idx, val);
}

void SegTree::update(int node, int start, int end, int idx, const Matrix& val) {
    if (start == end) {
        tree[node].matriz = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node].matriz = multiply(tree[2 * node].matriz, tree[2 * node + 1].matriz);
}

Matrix SegTree::query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

Matrix SegTree::query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return Matrix{1, 0, 0, 1};
    }

    if (start >= l && end <= r) {
        return tree[node].matriz;
    }

    int mid = (start + end) / 2;
    Matrix left = query(2 * node, start, mid, l, r);
    Matrix right = query(2 * node + 1, mid + 1, end, l, r);

    return multiply(left, right);
}