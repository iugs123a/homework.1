/******************************************************************************
** ������߼����Կγ����
**
** Example: ͨѶ¼��Ϣ����ϵͳ
**
** ����: �Ǳ��粻�Ǳ���
**
** ʱ��: 2023.12.23
**
** All rights reserved. Copyright (c) 2023-2024.
**
** ˼·: ��һ����������s���������ϵ�˵������Ϣ��������main����ʱ��ԭʼ��ͨѶ¼
		 �ļ��ж�ȡ��������s���Լ����˳�����ǰ��s������д��ͨѶ¼�ļ����⣬��
		 ���Ĳ�������ֱ�Ӳ����ļ��������������s���ɡ������������ѯ���޸ġ����ӡ�
		 ɾ���Ȳ��������Ƕ�����s�������㡣
******************************************************************************/



#include <iostream>		// ��������� 
#include <iomanip>		// ����ʽ 
#include <vector>		// ��׼ģ���-�������� 
#include <fstream>		// �ļ��� 
#include <string>		// �ַ��� 
#include <algorithm>	// ��׼ģ���-�㷨�� 
using namespace std;
class tongxun;
class person;
//���������Ϣ����
class person
{
protected:
	long long m_number;
	string m_email;
	string m_name;
	string m_workplace;


	friend  class tongxun;
};
//����ͨѶ¼����
class tongxun
{
public:
	tongxun(string szFileName);
	void ShowMainMenu();	// ��ʾ�����棨�ṩ������ģ�����ڣ�
	void Read_File(string szFileName);	// ���ļ��ж�������
	void Write_File(string szFileName);	// �����ݱ��浽�ļ���
	~tongxun();
public://���ܺ���
	int Quit();		// �˳����� 
	void Append();	// ����ģ��	
	void Modify();	// �޸�ģ��	
	int Query();	// ��ѯģ��
	void Delete();	// ɾ��ģ��
	void Display();//���ģ��

protected:
	vector<person> s;	// �����ϵ�˵������Ϣ����
	string m_szFileName;// ��ϵ�������Ϣ�ļ���������д�ļ���Ŀ���ļ��� 
};





//tongxun��ʵ��
//���캯��
tongxun::tongxun(string szFileName) {
	m_szFileName = szFileName;
	Read_File(szFileName);	// ���ļ��ж������� 
}
// ��������(��sд�빤����Ϣ�ļ�) 
tongxun::~tongxun()
{
	// �˳�ϵͳǰ���ȱ��������
	Write_File(m_szFileName);
}


// ����ģ�麯���Ķ���  ---------------------------------------------------
// �ӹ�����Ϣ�ļ��ж���ְ���Ĺ�����Ϣ����
void tongxun::Read_File(string szFileName)
{
	// ���ļ������� 
	//std::ifstream in("ͨѶ¼.txt");	// ע��: �������ȫ·������Ҫ����ļ���Դ�����ļ���ͬһ·����
	std::ifstream in(szFileName.c_str());

	if (!in)
	{
		std::cout << "\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n" << endl;
		exit(0);
	}

	s.clear();	// ������� 
	// ����ļ�˳���򿪣���ʼһ���еض�����
	// ÿ��������������ϵ�˵��������绰���롢�����ʼ��������ص�
	while (!in.eof())
	{
		person a;
		if (in >> a.m_name >> a.m_number >> a.m_email >> a.m_workplace)// �����ɹ�(true)������ӵ����������� 
			s.push_back(a);
		else
		{
			in.clear();	// ���״̬Ϊ��Чʱ����ʹ��ָ�Ϊ��Ч״̬ ����ֹͣ���ļ� 
			break;
		}
	}
	in.close();
}

// ����ϵ�˵������Ϣ���ݱ��浽ͨѶ¼�ļ���
void tongxun::Write_File(string szFileName)
{
	int i = 0, N = s.size();
	// ���ļ�д���� 
	//ofstream out("ͨѶ¼.txt");	// ��Դ�����ļ���ͬһ·����д����ϵ�������Ϣ����
	ofstream out(szFileName.c_str());	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
	if (!out)
	{
		std::cout << "\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n" << endl;
		exit(0);
	}

	// ����ļ�˳���򿪣���ʼһ���е�д����
	// ÿ��������������ϵ�˵������Ϣ���������绰���롢�����ʼ��������ص�
	for (i = 0; i < N; i++)
	{
		out << s[i].m_name << "\t" << s[i].m_number << "\t" << s[i].m_email << "\t" << s[i].m_workplace << endl;
	}
	out.close();
}
// �˳����� 
int tongxun::Quit()
{
	char c;
	std::cout << ("�����Ҫ�˳���ϵͳ��?(��_��)?(Y/N) [ ]\b\b");
	std::cin >> c;
	if (c == 'Y' || c == 'y')
	{
		std::cout << "\nлл�ݹˣ���ӭ����! (�R��Q) \n" << endl;
		system("pause");
		return 0;
	}
	else
	{
		std::cout << "��л���Ĵ���֧��!\n" << endl;
		return -1;
	}
}


// ����ģ��
void tongxun::Append()
{
	int n, i;
	std::cout << "�����������ӵ���ϵ����: ";
	std::cin >> n;

	std::cout << "�����������ӵ�ÿλ��ϵ�˵���ϸ��Ϣ:\n" << endl;
	for (i = 0; i < n; i++)
	{
		std::cout << "\n��" << (i + 1) << "λ��ϵ�˵������Ϣ --------------" << endl;
		person a;
		std::cout << "\t����: ";
		std::cin >> a.m_name;
		std::cout << "\t�绰����: ";
		std::cin >> a.m_number;
		std::cout << "\t�����ʼ�: ";
		std::cin >> a.m_email;
		std::cout << "\t�����ص�: ";
		std::cin >> a.m_workplace;
		s.push_back(a);
	}
}

// ���ģ�� 
void tongxun::Display()
{
	int i = 0, N = s.size();
	system("cls");	// ����
	cout << "����\t�绰����\t�����ʼ�\t�����ص�" << endl;
	for (i = 0; i < N; i++)
	{
		cout << s[i].m_name << "\t" << s[i].m_number << "\t" << s[i].m_email << "\t" << s[i].m_workplace << endl;
		if (i % 10 == 9)	// ������ʾ 
		{
			cout << "\n��������������\n";
			system("pause");
		}
	}
}


// �޸�ģ��
void tongxun::Modify()
{
	int j = -1, number = 0, option = 0;
	char c;

	// ���޸�֮ǰ��������ϵ�˲�ѯ
	j = Query();
	if (j >= 0)
	{// ��Բ��ҵ�����ϵ�ˣ����������Ϣ�����޸� 
		option = 0;
		while (!option)
		{
			cout << "\n���޸���ϵ�˵����������Ϣ:\n";
			cout << "\n\t***     1: ����             2: �绰����\n";
			cout << "\n\t***     3: �����ʼ�         4: �����ص�\n";
			cout << "\n\t------------------------------------------------------------------\n";

			while (!option)
			{
				cout << "\n\t��ѡ�������: [ ]\b\b";
				cin >> option;

				if (option == 1)	// �޸����� 
				{
					cout << "\n������Ϊ: ";
					cin >> s[j].m_name;
				}
				else if (option == 2)	// �޸Ĺ��� 
				{
					cout << "\n�绰�����Ϊ: ";
					cin >> s[j].m_number;
				}
				else if (option == 3)	// �޸Ļ�������
				{
					cout << "\n�����ʼ���Ϊ: ";
					cin >> s[j].m_email;
				}
				else if (option == 4)	// �޸Ľ���
				{
					cout << "\n�����ص��Ϊ: ";
					cin >> s[j].m_workplace;
				}

				else
				{
					cout << "\n �������˴������ţ�����������!\n";
					option = 0;
					system("pause");
				}
			}

			// �Ƿ�����޸ĸ�ְ���Ĺ�����Ϣ
			std::cout << "�Ƿ�����޸ĸ���ϵ�˵������Ϣ?(Y/N) [ ]\b\b";
			std::cin >> c;
			if (c == 'Y' || c == 'y')
			{
				option = 0;
			}
		}
	}
}

// ��ѯģ��
int tongxun::Query()
{
	int i = 0, j = -1, number = 0, option = 0, N = s.size();
	string name;

	// ����ʾ������ϵ�˸�����Ϣ 
	Display();

	// ��ͨ�����������ߺ��룬���ҵ�Ҫ�޸ĵ���ϵ��
	cout << "\n\n";
	cout << "\n\t�밴���·�ʽ��ѯ��ϵ�˵ĸ�����Ϣ\n";
	cout << "\n\t***     1: ����\n";
	cout << "\n\t***     2: �绰����\n";
	cout << "\n\t------------------------------------------------------------------\n";
	while (!option)
	{
		cout << "\n\t��ѡ�������: [ ]\b\b";
		cin >> option;

		if (option == 1)	// ��������ѯ 
		{
			cout << "\n����������: ";
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
		else if (option == 2)	// ���绰�����ѯ 
		{
			cout << "\n������绰����: ";
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
			cout << "\n �������˴������ţ�����������!\n";
			option = 0;
			system("pause");
		}
	}

	if (j < 0)
	{
		cout << "���޴���!\n";
		system("pause");
	}
	else
	{
		// �鿴����ϵ�˵������Ϣ 
		cout << "����ϵ�˵������Ϣ����:\n";
		cout << "����    ����      �����ʼ�  �����ص�\n";
		cout << s[j].m_name << "\t" << s[j].m_number << "\t" << s[j].m_email << "\t" << s[j].m_workplace << endl;
	}
	return j;
}

// ɾ��ģ��
void tongxun::Delete()
{
	int  j = -1;

	// ��ɾ��ǰ��������ϵ�˲�ѯ
	j = Query();
	if (j >= 0)
	{// // ��Բ��ҵ�����ϵ�ˣ�����ɾ��
		char c;
		cout << "\n��ȷ��Ҫɾ������ϵ�˵���ϵ��ʽ��?(Y/N) [ ]\b\b";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			s.erase(s.begin() + j);
		}
	}
}


// ������ 
void tongxun::ShowMainMenu()
{
	int option = -1;	// ѡ��

	do
	{
		system("cls");	// ����
		system("color 3f");	// ������Ļ��ǰ�����֣��ͱ�������ɫ

		// ������
		cout << "\n\t******************************************\n";
		cout << "\n\t**********��ӭʹ��ͨѶ¼����ϵͳ**********\n";
		cout << "\n\t**************0.�˳�������� *************\n";
		cout << "\n\t**************1.����ͨѶ��Ϣ *************\n";
		cout << "\n\t**************2.��ʾͨѶ��Ϣ *************\n";
		cout << "\n\t**************3.ɾ��ͨѶ��Ϣ *************\n";
		cout << "\n\t**************4.�޸�ͨѶ��Ϣ *************\n";
		cout << "\n\t**************5.��ѯͨѶ��Ϣ *************\n";
		cout << "\n\t******************************************\n";
		cout << "\n\t��ѡ�������(0-5): [ ]\b\b";
		cin >> option;

		switch (option)
		{
		case 0:	// ��6��ģ�� 
			option = Quit();// 0: ȷʵ�˳� 
			break;
		case 1:	//  ����ģ��
			Append();
			break;
		case 2:	// ���ģ��
			Display();
			break;
		case 3:	// ɾ��ģ��
			Delete();
			break;
		case 4:	// �޸�ģ��
			Modify();
			break;
		case 5:	//  ��ѯģ��
			Query();
			break;

		default:
			cout << "\n �������˴������ţ�����������!";
			option = -1;
			break;
		}

		if (option)	// ��������˳����򷵻ص������� 
		{
			cout << "\n�밴������������˵�����!\n";
			system("pause"); // �ȴ��������
		}

	} while (option);
}

int main()
{
	// ����һ��ͨѶ¼������� 
	tongxun oMan("ͨѶ¼.txt");
	// ʣ�µ�����ȫ����oMan����ȥ��
	oMan.ShowMainMenu();

	return 0;
}




