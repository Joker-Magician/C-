#include<iostream>
#include<string>
//#是预编译指令,预处理是在编译运行前预处理器会先过一遍你的代码

#define LOG_1(x) std::cout << x << std::endl//宏可以传递参数

//宏还可以用到游戏引擎的日志系统中，使其在Debug模式(用于调试)可以生成日志输出记录信息，在release模式则不会输出日志记录信息
//设置方法:1.右击该项目->属性->C/C++->预处理器->在确保配置为debug下在预处理器定义输入"PR_DEBUG;"(PR两字可以来自我们的项目)
//		   2.右击该项目->属性->C/C++->预处理器->在确保配置为release下在预处理器定义输入"PR_RELEASE"

//#ifdef PR_DEBUG这样写并不好
//#define PR_DEBUG 0可以直接定义通过这里控制下面的PR_DEBUGE，也可以直接在配置管理器里直接定义"PR_DEBUG=1"
//注意，不要写成"PR_DEBUG = 1"有空格的形式，这样在release版本下一切正常，但在debug版本下会显示报错

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl //当切换为release版本是该部分会被隐藏
//#else
#elif defined(PR_RELEASE)//可以将else改成elif的形式
#define LOG(x)	
#endif

#if 0

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl 
#elif defined(PR_RELEASE)
#define LOG(x)	
#endif

#endif//可以使用"#if 0"和"#endif"将代码折叠

//使用define如果想要换行需要在每行最后加上 "\"

int main()
{

	LOG("Hello");//x可以粘贴这里的东西然后放到后面
	
	std::cin.get();
}