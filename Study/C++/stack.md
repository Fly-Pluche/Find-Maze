> https://blog.csdn.net/tham_/article/details/44733101

栈

```python
s.empty()               如果栈为空返回true，否则返回false
s.size()                返回栈中元素的个数
s.pop()                 删除栈顶元素但不返回其值
s.top()                 返回栈顶的元素，但不删除该元素
s.push()                在栈顶压入新元素
```



```python
#include <iostream>
#include <stack>

using namespace std;
typedef double DateType;
int main()
{
    stack<DateType> s;
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
```





队列

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

