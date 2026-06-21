#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

template<class T>
struct AgentRecord {
    int id;
    string role;
    T content;
    int tokens;
};
/*AgentTrace()：生成一个空执行轨迹。
AgentTrace(const vector<string> &roles, const vector<T> &contents = vector<T>(), const vector<int> &tokens = vector<int>())：按顺序生成若干条记录，记录编号从 0 开始递增。
roles[i] 表示第 i 条记录的角色。
若 contents 为空，则所有内容初始化为 T()；否则保证 contents.size() == roles.size()。
若 tokens 为空，则每条记录 token 数为 1；否则保证 tokens.size() == roles.size()。
int add(const string &role, const T &content, int tokens = 1)：在末尾添加一条记录，并返回新记录的编号。
void set(int id, const T &content)：修改编号为 id 的记录内容。
T& get(int id)：返回编号为 id 的记录内容引用。
vector<int> ids(const string &role) const：返回指定角色的所有记录编号，顺序为加入顺序。
int token_sum() const：返回当前所有记录的 token 总和。*/
template<class T, int W>
class AgentTrace {
    vector<string>r;
vector<T> c;
vector<int>t;
public:
    AgentTrace(){};
    AgentTrace(const vector<string>& roles,
               const vector<T>& contents = vector<T>(),
               const vector<int>& tokens = vector<int>()){
                    int n=roles.size();
                
                //v.reserve(n);
                for(int i=0;i<n;i++){
                    r[i]=roles[i];
                    c[i]=contents[i];
                    t[i]=tokens[i];
                }
                /*if(contents.size()!=0){
                    contents.size()=n;
                }
                if(tokens.size()!=0){
                    tokens.size()=n;
                }
                else if(tokens.size()==0){
                    tokens.size()=1;
                }*/
               };

    int add(const string& role, const T& content, int tokens = 1){
        r.reserve(1);
        c.reserve(1);
        t.reserve(1);
        int n=r.size();
        r[n]=role;
        c[n]=content;
        t[n]=1;

    };
    void set(int id, const T& content){
        c[id]=content;
    };
    T& get(int id){
        return c[id];
    };
    vector<int> ids(const string& role) const{
        vector<int> haverole;
        int n=r.size();
        for(int i=0;i<n;i++){
            if(r[i]==role){
                haverole.push_back(i);
            }
        }
        return haverole;
    }
    int token_sum() const{
        int n=r.size();
        int num=0;
        for(int i=0;i<n;i++){
            num+=t[i];
        }
        return num;
    };

    bool operator==(const AgentTrace& other) const;
    bool operator!=(const AgentTrace& other) const;
    AgentTrace& operator=(const AgentTrace& other);

    class Iterator {
    public:
        Iterator();
        T& operator*() const;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Iterator& operator=(const Iterator& other);
    };

    Iterator begin();
    Iterator end();

    T& operator[](int id);

    class RoleView {
    public:
        T& operator[](int index);
    };

    RoleView operator[](const string& role);

    void compact();

    template<class ScoreFunc>
    vector<T> retrieve(int k, ScoreFunc score) const;

    map<string, int> tool_stats() const;
};

template<class T, int W>
ostream& operator<<(ostream& os, const AgentTrace<T, W>& trace);
