## C++标准库STL

## 容器
哈希表
哈希函数
tuple 元组
可以包含不同类型和大小的元素
创建一个tuple的方法tuple<T1,T2,T3...Tn>  make_tuple()
tie()方法 tuple_size和tuple_element方法
自动继承直至到空tuple

萃取剂

type_traits

问对象问题

## 算法
## 分配器
### 仿函数（函数对象）
格式
用法：视为一种传递给算法的参数，为算法一个一种准则
算术类 
逻辑运算类
相对关系类
GNU独有的仿函数(非标准)
identify 
select1st(传递pair的第一个变量) 
select2ed(传递pair的第一个变量)
仿函数可适配条件
**仿函数继承Binary_function<T,T,T>()或者unary_function才能融入STL**
STL规定每一个Adaptable function 都需要挑选适当的父类继承，因为函数适配器会提问,确认类型，问题包括，参数类型，结果类型两类。adapter会首先把需要记录的的数据存起来。
### 适配器
![fsahjkfsd1565233390428](C:\Users\HAO6\AppData\Roaming\Typora\typora-user-images\1565233390428.png)
作用：转化改造，两种方式实现，继承和内含
#### 容器适配器
#### 迭代器适配器 
reverse_iterator逆向迭代器
inserter
![1565264965414](C:\Users\HAO6\AppData\Roaming\Typora\typora-user-images\1565264965414.png)
#### (仿)函数适配器
函数适配器 例如binder2nd（bind2nd）
note1仿函数
新型适配器 bind 可以绑定1 函数2 函数对象3 成员函数（_1必须是对象地址）4成员数据（ _1必须是对象地址）可以指定参数类型，目的是确定返回类型。
bind 的返回类型很复杂，在不确定的时候可以用auto
placeholders 占位符？？
#### 未知适配器
ostream_iterator适配器
istream_iterator适配器
# 设计模式
## 适配器模式
# 基础函数与格式
advance()
...表示任意多

类

搬移复制 搬移构造

拷贝复制 拷贝构造

=delete =default





