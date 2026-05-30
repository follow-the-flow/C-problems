
#pragma once
#include <vector>

template<typename T>
class MyQueriable {
    std::vector<T> data;

public:
    // 构造：从 vector 初始化
    MyQueriable(std::vector<T> d) : data(std::move(d)) {}
    //这里使用move是移动构造函数，复杂度o1.减少时间和空间开销

    // 支持范围 for
    // 不用 auto，需要写出完整类型，很繁琐：
    //std::vector<T>::iterator。只需要返回迭代器
    auto begin() { return data.begin(); }
    auto end()   { return data.end();   }

    // 过滤，返回类型不变
    template<typename F>
    MyQueriable<T> where(const F f){
        std::vector<T> filtered;
        for(const auto& item: data){
            if(f(item)){
                filtered.push_back(item);
            }
        }
        return MyQueriable<T>(std::move(filtered));
    };

    // 变换，返回类型可能改变
    template<typename F>
    MyQueriable<T> apply(const F f) {
        std::vector<T> transformed;
        for(const auto& item: data){
            transformed.push_back(f(item));
        }
        return MyQueriable<T>(std::move(transformed));
    };

    // 求和
    T sum(){
        T total = T(); // 默认构造，适用于数值类型
        for(const auto& item: data){
            total += item;
        }
        return total;
    };
};


// 重载1：普通数组
template<typename T, std::size_t N>
MyQueriable<T> from(T (&arr)[N]) {
    return MyQueriable<T>(std::vector<T>(arr, arr + N));
}

// 重载2：容器（vector、list等）
template<typename Container>
auto from(const Container& c) {
    using T = typename Container::value_type;
    return MyQueriable<T>(std::vector<T>(c.begin(), c.end()));
}