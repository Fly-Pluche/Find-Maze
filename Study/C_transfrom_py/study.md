https://www.cnblogs.com/navysummer/p/10648520.html

https://blog.csdn.net/gaoxiang__/article/details/38094525

# C转python

## 将C转化为so文件

```python
gcc try.c -shared -fPIC -o try.so
```

- try.c C语言文件
- try.so转化后的文件
-  -shared选项说明编译成的文件为动态链接库，不使用该选项相当于可执行文件
-  -fPIC 表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的。所以动态载入时是通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码段共享的目的。
- -L. 表示链接的文件在当前目录下 

![image-20211104140628756](https://gitee.com/Black_Friday/blog/raw/master/image/202111041406835.png)

![image-20211104140643884](https://gitee.com/Black_Friday/blog/raw/master/image/202111041406965.png)

