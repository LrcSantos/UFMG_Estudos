#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "../include/tipoNo.hpp"

class SegTree {
public:
    SegTree(int size);
    ~SegTree();

    void update(int idx, const Matrix& val);
    Matrix query(int l, int r);

private:
    int n;
    TipoNo* tree;

    void build(int node, int start, int end);
    void update(int node, int start, int end, int idx, const Matrix& val);
    Matrix query(int node, int start, int end, int l, int r);
};

#endif