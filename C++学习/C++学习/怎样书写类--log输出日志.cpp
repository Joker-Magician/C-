#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Log
{
public:
	enum Level
	{
		LevelError=0,LevelWarning,LevelInfo
	};

/*public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;可以使用枚举使其更简洁*/

private:
	int m_LogLevel = LevelInfo;
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]:" << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(log.LevelError);
	log.Warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");
	std::cin.get();
}
