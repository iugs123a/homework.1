/******************************************************************************
** 计算机高级语言课程设计
**
** Example: 通讯录信息管理系统
**
** 作者: 是冰哥不是冰姐
**
** 时间: 2023.12.23
**
** All rights reserved. Copyright (c) 2023-2024.
**
** 思路: 用一个向量容器s存放所有联系人的相关信息，除了在main启动时从原始的通讯录
		 文件中读取数据填入s，以及在退出程序前将s的数据写入通讯录文件以外，其
		 他的操作都不直接操作文件，仅需操作向量s即可。比如浏览、查询、修改、增加、
		 删除等操作，都是对向量s进行运算。
******************************************************************************/



#include <iostream>		// 输入输出流 
#include <iomanip>		// 流格式 
#include <vector>		// 标准模板库-向量容器 
#include <fstream>		// 文件流 
#include <string>		// 字符串 
#include <algorithm>	// 标准模板库-算法库 
using namespace std;
class tongxun;
class person;
//定义个人信息的类
class person
{
protected:
	long long m_number;
	string m_email;
	string m_name;
	string m_workplace;


	friend  class tongxun;
};
//定义通讯录的类
class tongxun
{
public:
	tongxun(string szFileName);
	void ShowMainMenu();	// 显示主界面（提供各功能模块的入口）
	void Read_File(string szFileName);	// 从文件中读入数据
	void Write_File(string szFileName);	// 将数据保存到文件里
	~tongxun();
public://功能函数
	int Quit();		// 退出程序 
	void Append();	// 增加模块	
	void Modify();	// 修改模块	
	int Query();	// 查询模块
	void Delete();	// 删除模块
	void Display();//浏览模块

protected:
	vector<person> s;	// 存放联系人的相关信息数据
	string m_szFileName;// 联系人相关信息文件名（读和写文件的目标文件） 
};





//tongxun类实现
//构造函数
tongxun::tongxun(string szFileName) {
	m_szFileName = szFileName;
	Read_File(szFileName);	// 从文件中读入数据 
}
// 析构函数(将s写入工资信息文件) 
tongxun::~tongxun()
{
	// 退出系统前，先保存好数据
	Write_File(m_szFileName);
}


// 功能模块函数的定义  ---------------------------------------------------
// 从工资信息文件中读入职工的工资信息数据
void tongxun::Read_File(string szFileName)
{
	// 打开文件读数据 
	//std::ifstream in("通讯录.txt");	// 注意: 如果不用全路径，则要求该文件和源程序文件在同一路径下
	std::ifstream in(szFileName.c_str());

	if (!in)
	{
		std::cout << "\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n" << endl;
		exit(0);
	}

	s.clear();	// 清空向量 
	// 如果文件顺利打开，则开始一行行地读数据
	// 每行数据依次是联系人的姓名、电话号码、电子邮件、工作地点
	while (!in.eof())
	{
		person a;
		if (in >> a.m_name >> a.m_number >> a.m_email >> a.m_workplace)// 如读入成功(true)，则添加到向量容器中 
			s.push_back(a);
		else
		{
			in.clear();	// 如果状态为无效时，则使其恢复为有效状态 ，并停止读文件 
			break;
		}
	}
	in.close();
}

// 将联系人的相关信息数据保存到通讯录文件里
void tongxun::Write_File(string szFileName)
{
	int i = 0, N = s.size();
	// 打开文件写数据 
	//ofstream out("通讯录.txt");	// 在源程序文件的同一路径下写入联系人相关信息数据
	ofstream out(szFileName.c_str());	// 在源程序文件的同一路径下写入职工工资信息数据
	if (!out)
	{
		std::cout << "\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n" << endl;
		exit(0);
	}

	// 如果文件顺利打开，则开始一行行地写数据
	// 每行数据依次是联系人的相关信息：姓名、电话号码、电子邮件、工作地点
	for (i = 0; i < N; i++)
	{
		out << s[i].m_name << "\t" << s[i].m_number << "\t" << s[i].m_email << "\t" << s[i].m_workplace << endl;
	}
	out.close();
}
// 退出程序 
int tongxun::Quit()
{
	char c;
	std::cout << ("您真的要退出本系统吗?(⊙_⊙)?(Y/N) [ ]\b\b");
	std::cin >> c;
	if (c == 'Y' || c == 'y')
	{
		std::cout << "\n谢谢惠顾，欢迎再来! (≧﹀≦) \n" << endl;
		system("pause");
		return 0;
	}
	else
	{
		std::cout << "感谢您的大力支持!\n" << endl;
		return -1;
	}
}


// 增加模块
void tongxun::Append()
{
	int n, i;
	std::cout << "请输入需增加的联系人数: ";
	std::cin >> n;

	std::cout << "请输入需增加的每位联系人的详细信息:\n" << endl;
	for (i = 0; i < n; i++)
	{
		std::cout << "\n第" << (i + 1) << "位联系人的相关信息 --------------" << endl;
		person a;
		std::cout << "\t姓名: ";
		std::cin >> a.m_name;
		std::cout << "\t电话号码: ";
		std::cin >> a.m_number;
		std::cout << "\t电子邮件: ";
		std::cin >> a.m_email;
		std::cout << "\t工作地点: ";
		std::cin >> a.m_workplace;
		s.push_back(a);
	}
}

// 浏览模块 
void tongxun::Display()
{
	int i = 0, N = s.size();
	system("cls");	// 清屏
	cout << "姓名\t电话号码\t电子邮件\t工作地点" << endl;
	for (i = 0; i < N; i++)
	{
		cout << s[i].m_name << "\t" << s[i].m_number << "\t" << s[i].m_email << "\t" << s[i].m_workplace << endl;
		if (i % 10 == 9)	// 分屏显示 
		{
			cout << "\n按任意键继续浏览\n";
			system("pause");
		}
	}
}


// 修改模块
void tongxun::Modify()
{
	int j = -1, number = 0, option = 0;
	char c;

	// 在修改之前，进行联系人查询
	j = Query();
	if (j >= 0)
	{// 针对查找到的联系人，对其相关信息进行修改 
		option = 0;
		while (!option)
		{
			cout << "\n可修改联系人的如下项的信息:\n";
			cout << "\n\t***     1: 姓名             2: 电话号码\n";
			cout << "\n\t***     3: 电子邮件         4: 工作地点\n";
			cout << "\n\t------------------------------------------------------------------\n";

			while (!option)
			{
				cout << "\n\t请选择功能序号: [ ]\b\b";
				cin >> option;

				if (option == 1)	// 修改姓名 
				{
					cout << "\n姓名改为: ";
					cin >> s[j].m_name;
				}
				else if (option == 2)	// 修改工号 
				{
					cout << "\n电话号码改为: ";
					cin >> s[j].m_number;
				}
				else if (option == 3)	// 修改基本工资
				{
					cout << "\n电子邮件改为: ";
					cin >> s[j].m_email;
				}
				else if (option == 4)	// 修改奖金
				{
					cout << "\n工作地点改为: ";
					cin >> s[j].m_workplace;
				}

				else
				{
					cout << "\n 您输入了错误的序号，请重新输入!\n";
					option = 0;
					system("pause");
				}
			}

			// 是否继续修改该职工的工资信息
			std::cout << "是否继续修改该联系人的相关信息?(Y/N) [ ]\b\b";
			std::cin >> c;
			if (c == 'Y' || c == 'y')
			{
				option = 0;
			}
		}
	}
}

// 查询模块
int tongxun::Query()
{
	int i = 0, j = -1, number = 0, option = 0, N = s.size();
	string name;

	// 先显示所有联系人个人信息 
	Display();

	// 再通过按姓名或者号码，查找到要修改的联系人
	cout << "\n\n";
	cout << "\n\t请按以下方式查询联系人的个人信息\n";
	cout << "\n\t***     1: 姓名\n";
	cout << "\n\t***     2: 电话号码\n";
	cout << "\n\t------------------------------------------------------------------\n";
	while (!option)
	{
		cout << "\n\t请选择功能序号: [ ]\b\b";
		cin >> option;

		if (option == 1)	// 按姓名查询 
		{
			cout << "\n请输入姓名: ";
			cin >> name;

			for (i = 0; i < N; i++)
			{
				if (name == s[i].m_name)
				{
					j = i;
					break;
				}
			}
			break;
		}
		else if (option == 2)	// 按电话号码查询 
		{
			cout << "\n请输入电话号码: ";
			cin >> number;

			for (i = 0; i < N; i++)
			{
				if (number == s[i].m_number)
				{
					j = i;
					break;
				}
			}
			break;
		}
		else
		{
			cout << "\n 您输入了错误的序号，请重新输入!\n";
			option = 0;
			system("pause");
		}
	}

	if (j < 0)
	{
		cout << "查无此人!\n";
		system("pause");
	}
	else
	{
		// 查看该联系人的相关信息 
		cout << "该联系人的相关信息如下:\n";
		cout << "姓名    号码      电子邮件  工作地点\n";
		cout << s[j].m_name << "\t" << s[j].m_number << "\t" << s[j].m_email << "\t" << s[j].m_workplace << endl;
	}
	return j;
}

// 删除模块
void tongxun::Delete()
{
	int  j = -1;

	// 在删除前，进行联系人查询
	j = Query();
	if (j >= 0)
	{// // 针对查找到的联系人，进行删除
		char c;
		cout << "\n您确认要删除该联系人的联系方式吗?(Y/N) [ ]\b\b";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			s.erase(s.begin() + j);
		}
	}
}


// 主界面 
void tongxun::ShowMainMenu()
{
	int option = -1;	// 选项

	do
	{
		system("cls");	// 清屏
		system("color 3f");	// 设置屏幕的前景（字）和背景的颜色

		// 主界面
		cout << "\n\t******************************************\n";
		cout << "\n\t**********欢迎使用通讯录管理系统**********\n";
		cout << "\n\t**************0.退出管理程序 *************\n";
		cout << "\n\t**************1.增加通讯信息 *************\n";
		cout << "\n\t**************2.显示通讯信息 *************\n";
		cout << "\n\t**************3.删除通讯信息 *************\n";
		cout << "\n\t**************4.修改通讯信息 *************\n";
		cout << "\n\t**************5.查询通讯信息 *************\n";
		cout << "\n\t******************************************\n";
		cout << "\n\t请选择功能序号(0-5): [ ]\b\b";
		cin >> option;

		switch (option)
		{
		case 0:	// 退6出模块 
			option = Quit();// 0: 确实退出 
			break;
		case 1:	//  增加模块
			Append();
			break;
		case 2:	// 浏览模块
			Display();
			break;
		case 3:	// 删除模块
			Delete();
			break;
		case 4:	// 修改模块
			Modify();
			break;
		case 5:	//  查询模块
			Query();
			break;

		default:
			cout << "\n 您输入了错误的序号，请重新输入!";
			option = -1;
			break;
		}

		if (option)	// 如果不是退出，则返回到主界面 
		{
			cout << "\n请按任意键返回主菜单界面!\n";
			system("pause"); // 等待按任意键
		}

	} while (option);
}

int main()
{
	// 定义一个通讯录管理对象 
	tongxun oMan("通讯录.txt");
	// 剩下的事情全交给oMan对象去做
	oMan.ShowMainMenu();

	return 0;
}




