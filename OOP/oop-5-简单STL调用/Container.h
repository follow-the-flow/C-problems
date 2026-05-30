#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
    bool operator<(const Point<A>& o) const {
        return pos < o.pos;
    }
};//这个结构体用来存储一个点的信息，包括它的位置和它的值


template<class A, class C>//
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};//这个函数用来插入一个点的信息，包括它的位置和它的值
    A* find(Pos p) { return NULL; };//用来查询名字 
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {//

    vector< Point<A> > base;//这个vector用来存储所有的点的信息，包括它们的位置和它们的值
    bool sorted=false;
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
        sorted = false;
    }

    A* find(Pos p) {
        if(!sorted){
            std::sort(base.begin(),base.end());
            sorted=true;
        }
        //binary search
        Point<A> target(p,A());
        auto it=std::lower_bound(base.begin(),base.end(),target);
        if(it!=base.end()&&it->pos==p){
            return&(it->value);
        }
        return NULL;
        }
    };

template <class A>
class Container<A, map<Pos,A> > : public BasicContainer<A> {
    map< Pos,A > base;
    
public:
    void insert(const Pos &p, const A &v) {
        base[p]=v;
    }

    A* find(Pos p) {
        auto it=base.find(p);
            if(it != base.end()) return &(it->second);
        
        return NULL;
    }
    
};
#endif
