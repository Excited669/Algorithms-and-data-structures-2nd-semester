#include "dsu.h"

DSU::DSU(int size) : _size(size), _parent(new int[size]), _rank(new int[size]) {
    for (int i = 0; i < size; ++i) {
        _parent[i] = i;
        _rank[i] = 0;
    }
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
}

void DSU::make_set(int elem) {
    _parent[elem] = elem;
    _rank[elem] = 0;
}

int DSU::find(int elem) {
    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]);
    }
    return _parent[elem];
}

void DSU::unite(int first, int second) {
    int rootFirst = find(first);
    int rootSecond = find(second);

    if (rootFirst != rootSecond) {
        if (_rank[rootFirst] > _rank[rootSecond]) {
            _parent[rootSecond] = rootFirst;
        } else if (_rank[rootFirst] < _rank[rootSecond]) {
            _parent[rootFirst] = rootSecond;
        } else {
            _parent[rootSecond] = rootFirst;
            _rank[rootFirst]++;
        }
    }
}

void DSU::clear() {
    delete[] _parent;
    delete[] _rank;
    _parent = nullptr;
    _rank = nullptr;
    _size = 0;
}
