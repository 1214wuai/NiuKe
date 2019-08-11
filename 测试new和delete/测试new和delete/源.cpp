#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<mutex>
#include<thread>
#include"源1.hpp"
using namespace std;

class My_String {
private:
	char * _p;
	size_t _sz;
	void copy(const char* p)
	{
		_p = new char[_sz + 1];
		memcpy(_p, p, _sz);
		_p[_sz] = '\0';
	}
public:
	My_String()
	{
		_p = nullptr;
		_sz = 0;
	}
	My_String(const char* p)
	{
		_sz = strlen(p);
		copy(p);
	}
	My_String(My_String& str)
	{
		_sz = str._sz;
		copy(str._p);
		cout << "Lvalue" << endl;
	}
	My_String(My_String&& str)
	{
		_sz = str._sz;
		_p = str._p;
		str._p = nullptr;
		str._sz = 0;
		cout << "Rvalue" << endl;
	}
	~My_String()
	{
		if (_p)
			delete[] _p;
	}
};
template<typename T>
void PrinT(T &t)
{
	cout << "Lvalue" << endl;
}

template<typename T>
void PrinT(T &&t)
{
	cout << "Rvalue" << endl;
}

template<typename T>
void TestForward(T && v)
{
	PrinT(v);
	PrinT(std::forward<T>(v));
	PrinT(std::move(v));
}

void Test()
{
	TestForward(1);// L R R
	int x = 1;
	TestForward(x);// L L R
	TestForward(std::forward<int>(x));// L R R
	int y = x;
	TestForward(std::forward<int>(y));// L L R

}
void Test2()
{
	//My_String str1("asd");
	//My_String str2(move(str1));

	//string s1("asdfgh");
	//string s2(s1);
	//cout << s1 << endl;
	//cout << s2 << endl;
	//string s3(move(s1));
	//cout << s3 << endl;
	//cout << s1 << endl;
}

//class Singleton {
//public:
//	Singleton * GetInsTance()
//	{
//		if (m_PInstance == nullptr)
//		{
//			m_tex.lock();
//			if (m_PInstance == nullptr)
//				m_PInstance = new Singleton();
//			m_tex.unlock();
//		}
//		return m_PInstance;
//	}
//
//	//实现一个内嵌垃圾回收类
//	class CGarbo {
//		~CGarbo()
//		{
//			if (m_PInstance != nullptr)
//				delete Singleton::m_PInstance;
//		}
//	};
//	//定义一个静态变量，程序结束时，系统会自动调用它的析构函数，从而释放单例
//	static CGarbo cgarbo;
//private:
//	//构造函数私有，防拷贝
//	Singleton(){}
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton&) = delete;
//
//private:
//	static Singleton* m_PInstance;
//	static mutex m_tex;
//};
//Singleton* Singleton::m_PInstance = nullptr;
//mutex Singleton::m_tex;
//Singleton::CGarbo cgarbo;

//template <typename T>
//class Singleton {
//public:
//	template<typename...Args>
//	static T* Instance(Args&&...args)
//	{
//		if (m_pInstance == nullptr)
//			m_pInstance = new T(std::forward<Args>(args)...);//完美转发
//		return m_pInstance;
//	}
//	//获取单例
//	static T* GetInstance()
//	{
//		if (m_pInstance == nullptr)
//			throw std::logic_error("the instance is not init,please initialzer the instance first!");
//		return m_pInstance;
//	}
//	static void DestoryInstance()
//	{
//		delete m_pInstance;
//		m_pInstance = nullptr;
//	}
//private:
//	Singleton(void);
//	 ~Singleton(void);
//	 Singleton(const Singleton&) = delete;
//	 Singleton&operator = (const Singleton &) = delete;
//
//private:
//	static Singleton * m_pInstance;
//};

int main()
{
	
	Pint();
	system("pause");
	return 0;
}