/*
	Developer: zhijie Duan
	ProjectName: SnakeGluttony 3.0
*/


#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ExitSystem();
void EnrollAccount();
void Landing();
void ForgetPassWord();


extern bool Pastport = false;

void EnrollAccount()
{
	ofstream WriteOutFile;
	cout << "请输入您想要注册的账号: " << endl;
	string Account;
	cin >> Account;
	WriteOutFile.open("AccountOfSnake.txt", fstream::out);
	if (!WriteOutFile.is_open())
	{
		cout << "数据库写入发生异常，请询问游戏开发者!" << endl;
		system("pause");
		exit(0);
	}
	WriteOutFile << Account << endl;
	cout << "请输入您想要注册的密码: " << endl;
	string password;
	cin >> password;
	WriteOutFile << password << endl;
	cout << "请输入您的邮箱: (选填,跳过请输入skip)" << endl;
	string mailbox;
	cin >> mailbox;
	if (mailbox == "skip")
	{
		cout << "成功跳过邮箱输入" << endl;
	}
	cout << "正在将您的账户写入数据库.....请稍后" << endl;
	Sleep(5000);
	WriteOutFile.close();
	cout << "您已注册成功!开始愉快的旅行吧!" << endl;
}

void Landing()
{
	ifstream ReadinFile;
	ReadinFile.open("AccountOfSnake.txt", ios::in);
	if (!ReadinFile.is_open())
	{
		cout << "数据库读入发生异常，请询问游戏开发者!" << endl;
		cout << endl;
		cout << "你还没注册账户,请注册!" << endl;
		system("pause");
		exit(0);
	}
	cout << "请输入您的账号:" << endl;
	string Account;
	string buffer_Acc;
	cin >> Account;
	getline(ReadinFile, buffer_Acc);
	if (Account != buffer_Acc)
	{
		cout << "您输入的账号错误!请重新输入" << endl;
		cout << endl;
		return;
	}
	cout << "请输入您的密码:" << endl;
	string Password;
	cin >> Password;
	string buffer_Pas;
	getline(ReadinFile, buffer_Pas);
	if (Password != buffer_Pas)
	{
		cout << "您输入的密码错误!请重新输入" << endl;
		cout << endl;
		return;
	}
	cout << "正在数据库中寻找您的账号......请稍等" << endl;
	cout << endl;
	Sleep(5000);
	ReadinFile.close();
	Pastport = true;
	cout << "登陆成功!" << endl;
}

void ForgetPassWord()
{
	ifstream ReadinFile;
	ReadinFile.open("AccountOfSnake.txt", ios::in);
	cout << "请输入您原本的账号: (选填,跳过请输入skip)" << endl;
	string FAccount;
	cin >> FAccount;
	string NewAccount;
	getline(ReadinFile, NewAccount);
	if (FAccount != "skip" && FAccount==NewAccount)
	{
		ifstream Readin;
		Readin.open("AccountOfSnake.txt", ios::in);
		char buffer[1024];
		cout << "您的账户是:" << endl;
		while (Readin.getline(buffer, sizeof(buffer)))
		{
			cout << buffer << endl;
		}
		Readin.close();
	}
	else
	{
		cout << "请输入您的密码: (必填)" << endl;
		string NewPassword;
		cin >> NewPassword;
		string PasswordRight;
		getline(ReadinFile, PasswordRight);
		ReadinFile.close();
		if (PasswordRight == NewPassword)
		{
			ifstream ReadinFile;
			ReadinFile.open("AccountOfSnake.txt", ios::in);
			char buffer[1024];
			cout << "您的账户是:" << endl;
			while (ReadinFile.getline(buffer, sizeof(buffer)))
			{
				cout << buffer << endl;
			}
			ReadinFile.close();
		}
		else
		{
			cout << "您账号和密码都输入不正确，请联系游戏开发者" << endl;
			exit(0);
		}
	}
}

void ExitSystem()
{
	cout << "您已成功退出系统" << endl;
	exit(0);
}
