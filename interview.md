## Java 与 C++ 区别？

- Java 是纯粹的面向对象的语言，所有的对象都继承于 `java.lang.Object`，C++ 为了兼容 C，既支持面向对象也支持面向过程。
- Java 通过虚拟机从而实现跨平台特性，但是 C++ 依赖于特定的平台。
- Java 没有指针，它的引用可以理解为安全的指针，而 C++ 具有和 C 一样的指针。
- Java 支持自动垃圾回收，而 C++ 需要手动回收。
- Java 不支持多重继承，只能通过接口来达到相同的目的，而 C++ 支持多重继承。
- Java 不支持操作符重载，虽然可以对两个 String 对象支持加法操作，但是这是语言内置的操作，不属于操作符重载，而 C++ 可以。
- Java 的 goto 是保留字，但是不可用，C++ 可以使用 goto。
- Java 不支持条件编译，C++ 通过 #ifdef #ifndef 等预处理命令从而实现条件编译。

### References

- [What are the main differences between Java and C++?](http://cs-fundamentals.com/tech-interview/java/differences-between-java-and-cpp.php)

----

## Java 创建对象的几种方式

- new
- 反射。`Class.forName()` ，`User.class.newInstance()` / `java.lang.reflect.Constructor` 里的 `newInstance`
- clone
- 序列化

----

## Object 类的方法

- clone()
- equals()
- finalize()
- getClass()
- hashCode()
- notify()
- notifyAll()
- toString()
- wait()

----

## 线程间通信

- synchronized，volatile + while（共享内存）
- wait/notify
- 管道通信（消息传递）

----

## Java Bean

- Must implement Serializable
- It should have a public no-args constructor
- All properties in java bean must be private with public getters and setters methods

----

## 为什么 Java 的引用是安全的指针？

- 因为 Java 的引用虽然本质上还是指针，但是限制了一些行为，比如不能定义向前向后的行为; 当对象不在了，就不能访问这块内存; 对象移动了，对应的引用也会移动（内存整理）; 指针还能做运算，引用不能...

----

## 什么是冯诺依曼体系结构

- 计算机处理的数据和指令一律用二进制表示
- 顺序执行程序。程序首先 dump 到内存中，在自动地从内存中取出指令一条一条执行
- 运算器 + 控制器 + 存储器 + 输入设备 + 输出设备 => （控制器例如程序计数器，指令寄存器... 运算器和控制器统称为中央处理器

### References

- [冯诺依曼型计算机的五大组成部分及各部分的功能](https://zhidao.baidu.com/question/981698397758617659.html)

----

## Java 的多态

- 编译时多态：`@Overload`
- 运行时多态：`extends` || `implements`

----

### 多态的实现机制

JVM 执行 Java 字节码时，**类型信息被存放在方法区中**，为了优化调用方法的速度，方法区的类型信息中增加一个指针，该指针指向一张记录该类方法入口的表（称为方法表），**表中的每一项都是相应方法的指针**。

因为 Java 是单继承，表中是按顺序存放的， Object -> parent class - > subclass，只有非私有的实例方法才会出现。

- 静态方法 -> invokestatic
- 私有方法和构造函数 -> invokespecial
- 只有被 invokevirtual, invokeinterface 指令调用的方法才会在方法表中出现

----

- [Java 多态的实现机制](https://www.cnblogs.com/crane-practice/p/3671074.html)

----

## String， StringBuffer， StringBuilder

- String
    ```java
    public final class String
        implements java.io.Serializable, Comparable<String>, CharSequence {
        /** The value is used for character storage. */
        private final char value[];
    ```
    
    1. 是 final 修饰 2. 并且内部的 char[] 也用 final 3. 内部没有可以改变 char[] 的方法 => 保证了 String 不可变
- StringBuffer extends AbstractStringBuilder，用 synchronized 保证线程安全
- StringBuilder extends AbstractStringBuilder

----

## 接口和抽象类

- ~~抽象类可以有非抽象的方法~~ 现在 接口也可以有 default 实现了
- 接口中的实例变量默认是 final，抽象类不一定
- Java 中只能单继承，用抽象类代价比较高
- 一个类要实现接口的话，要实现全部方法，而抽象类不一定

----

## 四种引用

- 强引用（Strong Reference）
    - 如果一个对象具有强引用，垃圾回收器绝不会回收它
- 软引用（Soft Reference）
    - 一个对象只具有软引用，只要内存空间足够，垃圾回收器就不会回收它
    - 设计 Cache
- 弱引用（Weak Reference）
    - 垃圾回收器一旦发现一个对象只具有弱引用，不管内存是否足够，都会回收它的内存，不过由于垃圾回收器是一个优先级很低的线程，因此不会很快发现它们
    - 和引用队列联合使用，如果要被垃圾回收，就会加入到与之关联的引用队列
    - 因为不干扰对象被 GC 回收，通常用于 Debug，内存监视工具程序当中
- 虚引用（Plantom Reference）
    - 任何时候都会被回收
    - 必须与引用队列联合使用，如果要被垃圾回收，就会加入到与之关联的引用队列
    - 用来跟踪垃圾回收器活动

----

## Integer 问题

- Integer 类型 -128-127 会有优化，有一个常量池一样的东西
- 如果使用 new 关键字会忽略这种优化
- Integer 和 int 比较，因为自动拆箱装箱得到理想的结果，两个 Integer 类型数值比较时需要把其中一个转换成 int。

### References

- [java中两个Integer类型的值相比较的问题](https://www.cnblogs.com/xh0102/p/5280032.html)


----

## Spring boot

- Spring 是一个 Java 开发框架，核心是 IoC 和 AOP。
- Spring MVC 是一个 MVC 框架（解耦）。
- Spring boot 是发现每次开发都要写很多配置文件，样本代码，为了简化工作流程，这套就是 Spring boot
    - 自动配置
    - 不需要单独安装 Tomcat 这类容器服务器
    - 专注业务逻辑

----

## 深拷贝和浅拷贝

### 浅拷贝（shallow 

1. 一个拷贝构造函数就可以实现浅拷贝
2. 重写 clone() 方法， Cloneable 接口

浅拷贝中对于基本数据类型，也就是非引用类型（这里把 String 看作非引用类型，其实 String 的定义是引用类型。因为在 Java 中 String 对象的值不能被改变，如果改变会生成一个新的对象，所以 String 可以被深克隆）的值直接赋给新的实例。但是对引用类型，如数组，一个类的对象是引用复制，在内存中并没有多一个新的数组。所以克隆的实例要是修改引用类型的值，会影响到原来实例。

### 深拷贝（deep copy)

1. 序列化
2. 递归遍历所有的属性，把每个都浅拷贝了，就实现了把整个都深拷贝了（数组拷贝用 `Arrays.copyOf()`)

### References about copy

- [Java 浅拷贝和深拷贝的理解和实现方式](https://www.cnblogs.com/shakinghead/p/7651502.html)

------

## 序列化和持久化

### 持久化（Persistence)

持久化是为了让对象可持久保存在储存介质上（由于内存的缺陷），**目标是保存数据，并提供查询修改的手段**。为了实现持久化，通常要使用持久化框架，如 Hibernate 等。 

### 序列化（Serialization)

序列化是为了**数据的传输和交换**，可以是二进制，XML，JSON。

Java 中序列化通常需要显式指定 `SerialieId`（不指定 JVM 也会自动生成，但不同版本的 JVM 生成不同）。有了这个 Id，下次类有改动也能序列化回来。

### References

- [什么是对象持久化，与数据序列化有何联系？ zhihu](https://www.zhihu.com/question/20706270)
- [序列化和持久化的区别与联系](https://blog.csdn.net/shixiaoguo90/article/details/22433245)


----

## Java 中的 NIO，BIO，AIO

- BIO，同步并阻塞，一个连接一个线程
- NIO，同步非阻塞，一个请求一个线程，聊天服务器
- AIO，异步非阻塞，一个有效请求一个线程，比如相册服务器

----

## 常见设计模式

- 工厂模式，一个用于创建对象的接口，让子类决定实例化哪个类，`Factory Method` 使一个类的实例化延迟到子类。
- 单例模式
- 适配器模式
- 装饰器模式
- 代理模式
- 迭代器模式

----

## 数据库三范式

- 1NF，不可分
- 2NF，非主属性必须完全函数依赖主键（一般只有一个主键就不会发生这种情况）
    - {学号，姓名，课程，成绩}，{学号，课程} 为主键，成绩完全函数依赖，但是姓名部分函数依赖
- 3NF，不存在非主属性依赖其它非主属性


----

## Concurrent 包下常用的类

- `Executor` 创建线程池
- `ConcurrentHashMap` 线程安全的 HashMap
- `Callable` 和 `Future`
- `Semaphore` 控制多线程对共享资源的访问
- `ReentrantLock` 和 `Conditon`
- `BlockingQueue`
    - `ArrayBlockingQueue`
    - `LinkedBlockingQueue`
    - `DelayQueue`
    - `PriorityBlockingQueue`
    - `SynchronousQueue`
- `CountDownLatch`
- `CycliBarrier`
- `Exchanger`

----

## sychronized 的优化

- 适应自旋
- 锁消除
- 锁粗化
- 轻量锁
- 偏向锁
- 等等...

----

## 轻量级锁和偏向锁

- 重量级锁需要使用操作系统的互斥量（常常使用一个整型量，0表示解锁，而其他所有的值则表示加锁。通过互斥量使同一资源同时只允许一个访问者对其进行访问）来实现
- 轻量级锁依据大部分的锁在同步周期内不存在竞争，使用CAS操作避免使用互斥量的开销
- 偏向锁的则是在无竞争的情况下，连CAS操作都不做


----

## MyISAM 和 InnoDB 

主要区别

- MyISAM 是非事务安全型的 / 是
- MyISAM 锁的粒度是表级的 / 行
- MyISAM 支持全文索引 / 不支持（InooDB 在 MySQL5.6.24 后的版本中也支持了）
- MyISAM 相对简单，效率相对较高
- MyISAM 保存成文件，跨平台迁徙方便
- **MyISAM 是非聚集索引 / 聚集索引**

应用场景

- MyISAM, 高速存储和快速查询，大量 SELECT
- InnoDB, 支持 ACID, 需要大量 INSERT，UPDATE，提高用户并发操作的性能

----

## 哪些可作为 GC Roots 的对象

- JVM 栈中的对象
- 方法区的静态成员
- 方法区的常量应用对象
- 本地方法区的 JNI（Native 方法）引用的对象

----

## 垃圾收集器

Serial

- 单线程收集器，在垃圾收集的时候必须暂停其他所有的工作线程  
- 新生代：复制
- 老年代：标记整理
- 简单高效，Client 模式下默认的新生代收集器

ParNew New

- Serial 的多线程版本
- 新生代：复制
- 老年代：标记整理
- 运行在 Server 模式下首选的新生代收集器
- 除了 Serial，只有它能配合 CMS

ParNew Scanvenge / ParNew Old

- 类似 ParNew，但更关注吞吐量

G1

- 优先级区域
- 结合了空间整合，不会产生大量的碎片
- 让使用者明确指定停顿时间

CMS（Concurrent Mark Sweep：标记清除老年代收集器）

- 一种以最短停顿时间为目标的收集器，适合于 B/S 系统的服务器
- 初始标记，根可以关联到的对象
- 并发标记
- 重新标记
- 并发清除
- 并发重置

----

## JVM 内存的划分

- 程序计数器（执行本地方法时其值为 undefined）
- 虚拟机栈
- 本地方法栈（没有作强制规定，HotSpot 把虚拟机栈和本地方法栈合而为一）
- Java 堆
- 方法区（类信息，常量，静态变量等）
- 运行时常量池

----

## 双亲委派

- 启动（Bootstrap）类加载器，加载 `<Java Runtime Home>/lib` 下面的类库，开发者无法获取
- 标准扩展（Extension）类加载器，加载 `<Java Runtime Home>/lib/ext` 或者由系统变量 `java.ext.dir` 指定位置
- 系统（System）类加载器，加载 `CLASSPATH` 中指定的类库加载到内存
- 线程上下文类加载器

----

## `Student s = new Student()` 过程

- 加载 Student.class
- 在栈内存中为 s 开辟空间
- 在堆内存为学生开辟空间
- 默认初始化
- 显示初始化
- 构造方法
- 对象地址赋给 s

----

## Spring IoC

- 反射 + 工厂创建实例
- 获取需要注入的接口实现类注入给该接口

----

## Spring AOP

- 动态代理
    - JDK 动态代理，目标类所实现接口的另一个实现版本
    - CGLibProxy 返回的动态代理类，目标代理类的子类

----

## JDK 动态代理 vs CGLib

- JDK 动态代理只能对实现了接口的类生成代理，不能针对类
- CGLib 是针对类实现代理，生成一个子类（继承）
- JDK 动态代理不需要第三方，CGLib 必须依赖 CGLib 的类库

----

## Spring MVC 工作原理

- 所有请求交给前端控制器 DispathcherServlet 来处理
- 找到对应的 Handler
- 通过 HandlerAdapter 封装
- HandlerAdapter 调用 Handler
- 返回 ModelAndView 逻辑视图
- DispatcherServlet 借助 ViewResolver 解析为真实视图
- DispatcherServlet 渲染
- 返回

----

## 死锁的必要条件

- 互斥（临界资源）
- 不可抢占
- 占有且等待
- 循环等待条件（环路）

----

## 进程间通信有哪些方式

- 管道
- 信号
- 消息队列
- 共享内存，结合信号量使用，可以达到进程间同步与互斥
- 信号量
- 套接字

----

## 分布式 hash 要注意什么

DHT

- 分布均匀
- 增减节点后，cache 迁徙做到最少

----

## [智力题]50 红球和 50 黑球问题

给你 50 个红球和 50 个黑球，有两个一模一样的桶，往桶里放球，什么策略可以让朋友抽到红球的概率更高？

**一个桶 1 个红，剩下的全放另一个桶。**

0.5 * 1 + 0.5 * 0.5 = 0.75

----

## TCP报头格式

![tcp-header](https://i.loli.net/2018/06/24/5b2fbfdc6c291.png)

- 源端口，2byte
- 目的端口，2byte
- 序号，4byte
- 确认号，4byte
- 数据偏移，4bit，单位是 4byte
- 保留，6bit，全部置为 0
- URG
- ACK
- PSH
- RST  
- SYN
- FIN
- 窗口，2byte
- 检验和，2byte
- 紧急指针，2byte
- 选项，40byte

----

## UDP报头格式

![udp-header](https://i.loli.net/2018/06/25/5b2fc000f3111.jpg)

- 源端口，2byte
- 目的端口，2byte
- 长度，2byte
- 检验和，2byte

----

## HTTP状态码

- 100, Continue
- 101, Switching Protocols
- 200, OK
- 201, Created (GET)
- 202, Accepted (but unfinished)
- 203, Non-Authoritative Information
- 204, Not Content
- 205, Reset Content (reset form content)
- 206, Partial Content
- 300, Multiple Choices
- 301, Moved Permanently
- 302, Found
- 304, Not Modified
- 305, Use Proxy
- 400, Bad Request (Server cannot process the request due to something that is perceived to be a client error)
- 401, Unauthorized
- 402, Payment Required (reserved for future use)
- 403, Forbidden
- 404, Not Found
- 405, Method Not Allowed
- 406, Not Acceptable
- 407, Proxy Authentication Required
- 408, Request Times-Out
- 409, Conflict (Conflicts are most likely to occur in response to a PUT request)
- 410, Gone
- 411, Length Required
- 412, Precondition Failed
- 414, Request Entity Too Large
- 415, Unsupported Media Type
- 416, Requested Ranged not satisfiable
- 417, Expectation Failed
- 500, Internal Server Error
- 501, Not Implement
- 502, Bad Gateway
- 503, Service Unavailable
- 504, Gateway Time-out
- 505, HTTP Version not supported

----

## HTTP Method

- CONNECT
- DELETE
- GET
- HEAD, 在下载一个大文件前先获取其大小再决定是否要下载
- OPTIONS
- PATCH，局部更新，但是是非幂等的([某些情况](https://stackoverflow.com/questions/41390997/why-patch-is-neither-safe-nor-idempotent))
- POST
- PUT
- TRACE

----

## 僵尸进程和孤儿进程

孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作。

僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。


----

## HTTP field



### References

- [HTTP头字段](https://zh.wikipedia.org/wiki/HTTP%E5%A4%B4%E5%AD%97%E6%AE%B5)