#include "Test.h"
#include "imgui/imgui.h"

namespace test {

	TestMenu::TestMenu(Test*& currentTestPointer)
		: m_CurrentTest(currentTestPointer)
	{

	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : m_Tests)
		{
			if (ImGui::Button(test.first.c_str()))
				m_CurrentTest = test.second(); // 表示会执行元组(pair)中的第二个,即std::function<Test* ()>
		}
	}
}
