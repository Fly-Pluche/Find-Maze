

> https://blog.csdn.net/tham_/article/details/44733101
>
> https://www.cnblogs.com/huashanqingzhu/p/11040390.html



## 普通队列

```python
q.empty()               如果队列为空返回true，否则返回false
q.size()                返回队列中元素的个数
q.pop()                 删除队列首元素但不返回其值
q.front()               返回队首元素的值，但不删除该元素
q.push()                在队尾压入新元素
q.back()                返回队列尾元素的值，但不删除该元素
```



```python
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(void)
{
    stack<double> s; //定义一个栈
    queue<double> q;
    for (int i = 0; i < 10; i++)
        q.push(i);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << "队列内的元素的个数为：" << q.size() << endl;
    return 0;
}
```





## 优先队列

普通的队列是一种先进先出的数据结构，元素在队列尾追加，而从队列头删除。

在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征。

定义：priority_queue<Type, Container, Functional>
Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式。

```python
//升序队列，小顶堆
priority_queue <int,vector<int>,greater<int> > q;
//降序队列，大顶堆
priority_queue <int,vector<int>,less<int> >q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
```



> 和队列基本操作相同:
>
> - top 访问队头元素
> - empty 队列是否为空
> - size 返回队列内元素个数
> - push 插入元素到队尾 (并排序)
> - emplace 原地构造一个元素并插入队列
> - pop 弹出队头元素
> - swap 交换内容

```python
#include<iostream>
#include <queue>
using namespace std;
int main()
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a;
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    //      这里一定要有空格，不然成了右移运算符↓↓
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}
```

