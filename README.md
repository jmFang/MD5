# MD5
信息安全技术课程作业2-MD5 算法设计

## MD5 设计可以分为以下几个模块（方法）

A.	初始化输入的message，对其进行消息填充，以及添加原始消息长度的64位的二进制整数表示，以及初始值(IV)的初始化。

  	void init(const byte* input, size_t len);
      
B.	以512位的分组为单位对消息进行循环散列计算，得到最后的输出。

 	  void transform(const byte block[64]);
    
C.	将输入的message转换成整数表示

    void decode(const byte* input, bit32* output, size_t length);
      
D.	将整数表示的message换回string输出
      
      void encode(const bit32* input, byte* output, size_t length);


## Test case

![](https://github.com/jmFang/MD5/blob/master/test/image1.png)

*the test case is from wikipedia:https://en.wikipedia.org/wiki/MD5*

## MD5在密码保护上的工作原理

MD5在面保护上的安全性可以归结为Hash函数的安全性，而一个安全的Hash函数H至少满足以下几个条件：
H可以应用到任意长度的数据块，产生固定长度的散列值。

1.  对一个给定的输入m，计算H(m)是很容易的

2.  给定Hash函数的描述，对于给定的散列值h，找到满足H(m) = h的m在计算上是不可行的。
  
3.  给定Hash函数的描述，对于给定的消息m_1, 找到满足m_2≠ m_1, 且H(m_2 )=H(m_1)的m_2在计算上是不可行的。
  
4.  找到任何满足H(m_2 )=H(m_1 )且m_2≠ m_1的消息对(m_1,m_2)在计算上是不可行的。

  总结起来说，MD5具有压缩性、容易计算、抗修改性、强抗碰撞等特点，这些特点使得MD5在密码保护方面（密码登录验证）显得强大。
当用户第一次输入password时，MD5算法将计算出其散列值存储起来，当需要用到密码匹配时，系统根据用户的输入password2经过散列后去和已经储存的password散列值比较，从而确定合法性。MD5做到了不需要在系统保存密码的明文即可验证输入密码的合法性，如此防止了其他系统用户比如管理员窃取密码。
因为MD5将输入的字符串映射为128bits长的大整数，在数学原理上，从一盒大整数反推字符串是困难的。


## 参考资料：

1.  《信息安全原理与技术》（第2版），清华大学出版社，郭亚军等编著
  
2.  Wikipedia: https://en.wikipedia.org/wiki/MD5
