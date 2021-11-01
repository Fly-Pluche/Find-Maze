> https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
>
> https://blog.csdn.net/ly_6699/article/details/88668289

## 什么是适配器
适配器是一种设计模式（设计模式是一套被反复使用的、多数人知晓的、经过分类编目的、代码设计经验的总结），该中模式是将一个类的接口转换成客户希望的另外一个接口。
故适配器就是接口转换装置，让我们能通过特定的方法去操作原本自己不能直接操作的数据。
举个生活中的例子：电脑一般都用标准的交流的插头（USB接口），但我们平时用的欧洲壁式插座一般都是三孔的插座，这个时候我们就需要提供一个交流电适配器将插座的接口转换成USB的接口供我们使用。

## 什么是容器适配器
容器是对类模板的封装，而容器适配器是对容器的一种再封装。不同的容器适配器提供不同的函数，使容器的功能得到全新的特定的扩展。（但它和容器是有区别的：容器适配器不支持迭代器和算法，使用起来限制比较大）。标准库提供了三种容器适配器：queue（先进先出），stack（后进先出）和priority_queue（通过自己制定的规则进行排列，默认“<”比较即大数优先极高）。

## 为什么将stack，queue和priority_queue称为容器适配器
虽然以上三种也可以存放元素，但我们并没有将其划分在容器的行列，这是因为每个容器在底层都有自己的实现方式，可是stack，queue和priority_queue只是在底层将其他容器进行了一个封装，并没有自己的实现方式。如下图所示：

![在这里插入图片描述](https://gitee.com/Black_Friday/blog/raw/master/image/202110281145248.png)

# Vector

## 一、什么是vector？

向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放`任意类型`的动态数组。

------

## 二、容器特性

### 1.顺序序列

顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素。

### 2.动态数组

支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。提供了在序列末尾相对快速地添加/删除元素的操作。

### 3.能够感知内存分配器的（Allocator-aware）

容器使用一个内存分配器对象来动态地处理它的存储需求。

------

## 三、基本函数实现



> https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html

调用

```python
#include < vector> 
using namespace std;
```

构造函数

- vector():创建一个空vector
- vector(int nSize):创建一个vector,元素个数为nSize
- vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
- vector(const vector&):复制构造函数
- vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中



### 常用基操

```python
1.push_back 在数组的最后添加一个数据

2.pop_back 去掉数组的最后一个数据

3.at 得到编号位置的数据

4.begin 得到数组头的指针

5.end 得到数组的最后一个单元+1的指针

6．front 得到数组头的引用

7.back 得到数组的最后一个单元的引用

8.max_size 得到vector最大可以是多大

9.capacity 当前vector分配的大小

10.size 当前使用数据的大小

11.resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值

12.reserve 改变当前vecotr所分配空间的大小

13.erase 删除指针指向的数据项

14.clear 清空当前的vector

15.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)

16.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)

17.empty 判断vector是否为空

18.swap 与另一个vector交换数据
```

