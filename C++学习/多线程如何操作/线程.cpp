#include<iostream>
#include<thread>//这个头文件包括线程支持到这个文件中
#include<chrono>

static bool s_Finished = false;

void Dowork()//这个函数实际上会执行我们想要在另一个执行线程中发生的事情
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;//打印线程的id

	while (!s_Finished)
	{
		std::cout << "Working...\n" ;
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(Dowork);//这里传入了一个函数指针
//当我们写完这段代码后，它就会立即启动那个线程，它会做Dowork函数里的任何事情，它会一直运行，直到我们等待它退出

	std::cin.get();
	s_Finished = true;

//因此我们可以等待某件事完成，等待一个线程完成它的工作的方法是通过输入worker.join()	
	worker.join();//worker是线程对象，join函数本质上是要等待这个线程加入进来(在想C#这类更加现代化的语言中应该叫做wait)
	//它所做的只是说，嘿，你能在当前线程上等待这个线程完成它的工作中，因此阻塞当前线程直到另一个线程完成。
//因为这个东西是并行运行，我们的主线程开始一个工作线程，最后，我们写这个join调用的目的是在主线程上等待工作线程完成所有的执行之后，再继续执行主线程
//所以下面的cin.get()不会运行
	std::cout << "Finished." << std::endl;
	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

	std::cin.get();
}

//例如使用cin.get()当我们等待用户输入时，我们仍然希望可以做一些其他事情
//这里主要是展示如何在C++api中访问线程，并最终变成特定平台的代码，你需要包含thread，输入std::thread来创建一个线程对象，一个变量，然后你给这个构造函数传入一个函数
// 立即开始了这个线程做你让他做的事，这个线程将继续直到它完成，你可以使用这个线程的join方法等待当前线程启动的第二个线程结束运行，以防你需要做一些清理或等待工作，以便在所有线程完成后，结束整个程序

