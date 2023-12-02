#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string c[21] = {"", "(检查系统中)", "(检查版本中)", "(检查角色库中)", "(导入角色中)", "(初始化界面中)", "(初始化角色中)", "(检查代码中)", "(启动游戏中)", "()", "()", "()", "()"}, c1[7];
struct IDname
{
	int geshu;
	string NAME;
};
IDname jue_se[100], now[100];// 1.村民 2.狼人 3.女巫 4.预言家 5.猎人 6.守卫
struct ID
{
	int num;
	bool life;
	string name;
	bool know;
	int how;
};
ID player[100];
int n, MY, kill1, kill2, len = 1;
bool jieyao = 1, duyao = true;
int lieren, shouwei;
bool vis[101];
int protect = 0;
bool flag[100];
struct tou
{
	int xxx;
	int num;
	bool toupiaoquan;
};
tou TOU[13];
bool lr = 0;

void init1();
void init2(int nn);
void init3();
void display_jue_se();
void print(int day, int ti);
void print1();
void printresult();
void priiii(string x_1, int y_1);
bool cmp(tou x, tou y);
bool cmp1(tou x, tou y);
void night(int day, int op);
void c_lieren();
void toupiao(int day, int nnn);
bool game_over();
bool over();

int main()
{
	player[0].life = true;

	system("cls");
	SetConsoleTitle("狼人杀模拟器2.5.3");
	cout << setw(80) << "狼人杀模拟器 Version 2.6.7" << endl;
	cout << "请输入人数个数(5到20人，或50人):";
	cin >> n;
	init1();
	init2(n);
	cout << "在当前选择人数中,\n";
	display_jue_se();
	int k1;
	cout << "请输入模式(1:默认";
	{
		int i;
		for (i = 2; jue_se[i].geshu != 0; i++)
		{
			cout << i << ":" << jue_se[i].NAME;
			c1[i] = jue_se[i].NAME;
			len++;
		}
		cout << "):";
		while (true)
		{
			cin >> k1;
			if (k1 < 1 || k1 > i)
				cout << "输入错误,请重新输入.\n";
			else
				break;
		}
	}
	srand(time(0));
	int k = 1, l = 1;
	init3();
	do
	{
		k++;
		if (l <= 8)
		{
			system("cls");
			cout << "                             狼人杀模拟器\n请输入人数个数(5到20人，或50人):" << n << '\n';
			cout << "请输入模式(1:默认";
			for (int j = 2; j <= len; j++)
				cout << j << ":" << c1[j];
			cout << "):" << k1 << '\n';
			cout << "加载中，请耐心等待";
			priiii(c[l], 80 * (rand() % l + 2));
			l++;
		}
	} while (k <= n);
	system("cls");
	system("color F0");
	cout << "游戏即将开始";
	for (int i = 1; i <= 6; i++)
	{
		cout << ".";
		Sleep(100);
	}
	cout << endl
		 << endl
		 << "请大家查看身份牌......" << endl;
	Sleep(50);
	srand(time(0));
	cout << k1 << '\n';
	MY = 0;
	if (k1 > 1)
		while (player[MY].name != jue_se[k1].NAME)
			MY++;
	else
		MY = rand() % n + 1;
	cout << "您的身份是:" << player[MY].name << endl;
	Sleep(500);
	cout << "在" << player[MY].num << "号位上" << endl;
	system("pause");
	system("cls");
	player[MY].know = true;
	int day = 0;
	while (true)
	{
		print(day, 0);
		cout << "即将进入夜晚";
		for (int i = 1; i <= 6; i++)
		{
			cout << '.';
			Sleep(500);
		}
		cout << endl;
		night(day, 1);
		day++;
		print1();
		if (over())
			return 0;
		c_lieren();
		if (over())
			return 0;
		toupiao(day, 0);
		system("cls");
		print(day, 0);
		if (over() == true)
			return 0;
		c_lieren();
		system("cls");
	}
	return 0;
}
bool over()
{
	if (game_over() == false)
		return false;
	Sleep(2000);
	system("cls");
	cout << "Game OVER" << endl;
	printresult();
	return true;
}
void init1()
{
	jue_se[1].NAME = "村民";
	jue_se[2].NAME = "狼人";
	jue_se[3].NAME = "女巫";
	jue_se[4].NAME = "预言家";
	jue_se[5].NAME = "猎人";
	jue_se[6].NAME = "守卫";
}
void init2(int nn)
{
	switch (nn)
	{
	case 5:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 2;
		jue_se[3].geshu = 1;
		jue_se[4].geshu = 0;
		jue_se[5].geshu = 0;
		jue_se[6].geshu = 0;
		break;
	case 6:
		jue_se[1].geshu = 3;
		jue_se[2].geshu = 2;
		jue_se[3].geshu = 1;
		jue_se[4].geshu = 0;
		jue_se[5].geshu = 0;
		jue_se[6].geshu = 0;
		break;
	case 7:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 1;
		jue_se[3].geshu = 1;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 8:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 3;
		jue_se[3].geshu = 1;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 0;
		break;
	case 9:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 3;
		jue_se[3].geshu = 1;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 10:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 3;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 11:
		jue_se[1].geshu = 2;
		jue_se[2].geshu = 4;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 12:
		jue_se[1].geshu = 3;
		jue_se[2].geshu = 5;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 13:
		jue_se[1].geshu = 5;
		jue_se[2].geshu = 3;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 14:
		jue_se[1].geshu = 5;
		jue_se[2].geshu = 4;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 1;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 15:
		jue_se[1].geshu = 5;
		jue_se[2].geshu = 4;
		jue_se[3].geshu = 2;
		jue_se[4].geshu = 2;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 16:
		jue_se[1].geshu = 5;
		jue_se[2].geshu = 4;
		jue_se[3].geshu = 3;
		jue_se[4].geshu = 2;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 17:
		jue_se[1].geshu = 5;
		jue_se[2].geshu = 5;
		jue_se[3].geshu = 3;
		jue_se[4].geshu = 2;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 18:
		jue_se[1].geshu = 6;
		jue_se[2].geshu = 4;
		jue_se[3].geshu = 4;
		jue_se[4].geshu = 2;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 19:
		jue_se[1].geshu = 4;
		jue_se[2].geshu = 7;
		jue_se[3].geshu = 4;
		jue_se[4].geshu = 2;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 20:
		jue_se[1].geshu = 4;
		jue_se[2].geshu = 6;
		jue_se[3].geshu = 4;
		jue_se[4].geshu = 4;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	case 50:
		jue_se[1].geshu = 12;
		jue_se[2].geshu = 20;
		jue_se[3].geshu = 12;
		jue_se[4].geshu = 5;
		jue_se[5].geshu = 1;
		jue_se[6].geshu = 1;
		break;
	default:
		cout << "\n输入错误,再见: ";
		exit(0);
		break;
	}
	memcpy(now, jue_se, sizeof(jue_se));
	return;
}
void display_jue_se()
{
	for (int i = 1; i <= 6; i++)
		if (now[i].geshu != 0)
			cout << setw(8) << now[i].NAME << " 有 " << now[i].geshu << " 个." << endl;
	cout << endl;
	return;
}
void init3()
{
	srand(time(0));
	for (int i = 1; i <= n; i++)
	{
		/*
		int x;
		while (jue_se[x].geshu == 0)
			x = rand() % len + 1;
		player[i].name = jue_se[x].NAME;
		if (player[i].name == "守卫")
			shouwei = i;
		else if (player[i].name == "猎人 ")
			lieren = i;
		player[i].know = 0;
		player[i].life = 1;
		player[i].num = i;
		jue_se[x].geshu--;
		*/
		while (true)
		{
			int now = rand() % 6 + 1;
			if (jue_se[now].geshu > 0)
			{
				player[i].name = jue_se[now].NAME;
				if (player[i].name == "守卫")
					shouwei = i;
				else if (player[i].name == "猎人")
					lieren = i;
				player[i].know = false; // <--
				player[i].life = true;
				player[i].num = i;
				jue_se[now].geshu--;
				break;
			}
		}
	}
}
void printresult()
{
	int cm = 0;
	int sz = 0;
	for (int i = 1; i <= n; i++)
	{
		if (player[i].life == 0)
			continue;
		else if (player[i].name == "村民")
			cm++;
		else if (player[i].name == "女巫" || player[i].name == "预言家" || player[i].name == "猎人" || player[i].name == "守卫")
			sz++;
	}
	cout << "我的位置:" << MY << endl
		 << endl;
	cout << "RESULT:" << endl;
	if (sz == 0 || cm == 0)
		cout << "狼人阵营胜利" << endl;
	else
		cout << "好人阵营胜利" << endl;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << left << setw(3) << player[i].num << ": " << player[i].name << " ";
		if (player[i].life == 0)
			cout << "死亡"
				 << "\t";
		else
			cout << "存活"
				 << "\t";
		if (player[i].how == 0)
			cout << "最终存活 " << endl;
		else if (player[i].how == 1)
			cout << "最终被狼人杀死" << endl;
		else if (player[i].how == 2)
			cout << "最终被投票投死" << endl;
		else if (player[i].how == 3)
			cout << "最终被女巫毒死" << endl;
		else if (player[i].how == 4)
			cout << "最终被猎人射杀" << endl;
	}
	system("color 07");
	system("pause");
	system("pause");
	system("pause");
}
void print(int day, int ti)
{
	bool ME_DEAD = false;
	if (player[MY].life == false)
	{
		for (int i = 1; i <= n; i++)
			player[i].know = true;
		ME_DEAD = true;
	}

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ti == 0)
		SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
	else
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "\t\t\t\t第" << day << "天 ";
	if (ti == 0)
		cout << "白天" << endl;
	else
		cout << "夜晚" << endl;
	cout << "我的位置:" << MY << "号";
	if (ME_DEAD == true)
		cout << "(已阵亡)" << endl
			 << "观战中......";
	cout << endl;

	int qw = 1;
	for (int j = 1; j <= ceil(n / 10.0); j++)
	{
		int qq = qw + 10;
		if (qq > n)
			qq = n + 1;
		for (int i = qw; i < qq; i++)
			cout << setw(4) << player[i].num << "号位";
		cout << endl;
		for (int i = qw; i < qq; i++)
		{
			if (player[i].life == 1)
			{
				if (ti == 0)
					SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				else
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << setw(8) << "存活";
			}
			else
			{
				if (ti == 0)
					SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);
				else
					SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << setw(8) << "死亡";
			}
		}
		if (ti == 0)
			SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
		else
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << endl;
		for (int i = qw; i < qq; i++)
		{
			if (player[i].life == 0)
			{
				player[i].know = 1;
				if (flag[i] == false)
					for (int k = 1; k <= 6; k++)
						if (player[i].name == now[k].NAME)
						{
							now[k].geshu--;
							flag[i] = true;
							break;
						}
			}

			if (player[i].know == 0)
				cout << setw(8) << "未知";
			else if (player[i].know == 1)
				cout << setw(8) << player[i].name;
			// {
			//     if (player[i].name == "狼人")
			//         cout << "狼人";
			//     else
			//         cout << "好人  ";
			// }
		}
		cout << endl
			 << endl;
		qw += 10;
	}
	cout << endl
		 << endl;
	display_jue_se();
	return;
}
bool cmp(tou x, tou y)
{
	if (x.xxx == y.xxx)
		return x.num < y.num;
	return x.xxx > y.xxx;
}
bool cmp1(tou x, tou y)
{
	return x.num < y.num;
}
void toupiao(int day, int nnn)
{
	int x;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		TOU[i].num = i;
		TOU[i].toupiaoquan = true;
		TOU[i].xxx = 0;
	}
	int cnt = 0, alive = 0;
	for (int i = 1; i <= n; i++)
		if (player[i].life == true)
		{
			cnt++;
			alive++;
		}
	vector<int> next_turn;
	while (true)
	{
		Sleep(500);
		system("cls");
		print(day, nnn);
		cout << "即将开始新一轮的投票";
		if (next_turn.empty() == false)
		{
			Sleep(500);
			cout << "请对 ";
			for (int i = 0; i < next_turn.size(); i++)
				cout << next_turn[i] << ',';
			cout << '\b';
			cout << " 号再次投票.";
			Sleep(1000);
		}
		for (int i = 1; i <= 6; i++)
		{
			cout << '.';
			Sleep(100);
		}
		cout << endl;
		int qipiao = 0;
		for (int i = 1; i <= n; i++)
		{
			if (player[i].life == 1 && TOU[i].toupiaoquan == 1)
			{
				Sleep(700);
				if (i == MY)
				{
					cout << "请投票...(0弃权)" << endl;
					cin >> x;
					while (x < 0 || x > n || player[x].life == false)
					{
						cout << "投票无效, 请重新输入:";
						cin >> x;
					}
					while (cnt < alive && TOU[x].toupiaoquan == true)
					{
						cout << "输入错误,请重新输入有关玩家的编号:";
						cin >> x;
					}
					if (x == 0)
					{
						cout << MY << "号玩家弃权" << endl;
						qipiao++;
					}
					else
						cout << MY << "号玩家投给了" << x << "号玩家" << endl;
				}
				else
				{
					srand(time(0));
					if (player[i].name == "狼人")
					{
						x = rand() % n + 1;
						while (x != 0 && (player[x].life == 0 || player[x].name == "狼人" || x == i || (TOU[x].toupiaoquan == 1 && cnt < alive)))
						{
							srand(time(0));
							x = rand() % (n + 1);
						}
						if (x == 0)
						{
							cout << i << "号玩家弃权" << endl;
							qipiao++;
						}
						else
							cout << i << "号玩家投给了" << x << "号玩家" << endl;
					}
					else if (player[i].name == "预言家")
					{
						x = rand() % (n + 1);
						while (x != 0 && (player[x].life == 0 || player[x].name != "狼人" || x == i || (TOU[x].toupiaoquan == 1 && cnt < alive)))
						{
							srand(time(0));
							x = rand() % (n + 1);
						}
						if (x == 0)
						{
							cout << i << "号玩家弃权" << endl;
							qipiao++;
						}
						else
							cout << i << "号玩家投给了" << x << "号玩家" << endl;
					}
					else
					{
						x = rand() % (n + 1);
						while (x != 0 && (player[x].life == 0 || x == i || (TOU[x].toupiaoquan == 1 && cnt < alive)))
						{
							srand(time(0));
							x = rand() % (n + 1);
						}
						if (x == 0)
						{
							cout << i << "号玩家弃权" << endl;
							qipiao++;
						}
						else
							cout << i << "号玩家投给了" << x << "号玩家" << endl;
					}
				}
				if (x != 0 && TOU[i].toupiaoquan == true)
					TOU[x].xxx++;
			}
		}
		Sleep(700);
		sort(TOU + 1, TOU + n + 1, cmp);
		if (qipiao >= (cnt >> 1) + 1)
		{
			cout << "弃票人数过半,无人出局." << endl;
			Sleep(2000);
			break;
		}
		else if (TOU[2].xxx != TOU[1].xxx)
		{
			cout << "投票结束," << TOU[1].num << "号投票出局" << endl;
			player[TOU[1].num].life = 0;
			player[TOU[1].num].how = 2;
			Sleep(700);
			break;
		}
		else
		{
			for (int i = 1; i <= n; i++)
				TOU[i].toupiaoquan = true;
			int pin = 2;
			TOU[TOU[1].num].toupiaoquan = false;
			TOU[TOU[2].num].toupiaoquan = false;
			system("cls");
			print(day, nnn);
			cout << TOU[1].num << "号," << TOU[2].num << "号";
			cnt -= 2;
			int i;
			for (i = 3; i <= n; i++)
			{
				if (TOU[i].xxx == TOU[1].xxx)
				{
					cnt--;
					TOU[TOU[i].num].toupiaoquan = false;
					cout << "," << TOU[i].num << "号";
					pin++;
				}
				else
					break;
			}
			cout << "平票" << endl;
			if (pin == cnt)
			{
				cout << "由于无人可进行投票,无人出局." << endl;
				Sleep(3000);
				break;
			}
			Sleep(4000);
		}
		for (int i = 1; i <= n; i++)
			TOU[i].xxx = 0;
		cout << "即将开始下一轮投票......" << endl;
		Sleep(1000);
	}

	return;
}
bool game_over()
{
	int pingmin = 0;
	int langren = 0;
	int shenzhi = 0;
	for (int i = 1; i <= n; i++)
	{
		if (player[i].life == 0)
			continue;
		if (player[i].name == "狼人")
			langren++;
		else if (player[i].name == "村民")
			pingmin++;
		else if (player[i].name == "女巫" || player[i].name == "预言家" || player[i].name == "猎人")
			shenzhi++;
	}
	if (shenzhi == 0 || langren == 0 || pingmin == 0)
		return 1;
	return 0;
}
void night(int day, int op)
{
	system("cls");
	system("color 0f");
	print(day, 1);
	cout << "天~黑~请~闭~眼~~~" << endl;
	Sleep(700);
	system("cls");
	print(day, 1);
	if (n >= 9)
	{
		cout << "守~卫~请~睁~眼~~~" << endl;
		Sleep(700);
		cout << "今晚你要守护谁?" << endl;
		if (player[MY].name == "守卫")
		{
			cout << "请输入你要守护的玩家编号:";
			int x;
			cin >> x;
			while (x != protect)
			{
				cout << "该玩家上晚已被你守护,请重新选择:";
				cin >> x;
			}
			while (x < 1 || x > n)
			{
				cout << "输入错误,请重新输入:";
				cin >> x;
			}
			protect = x;
			Sleep(1000);
			cout << "今晚你要守护的是" << x << "号玩家" << endl;
			Sleep(500);
			cout << "今晚该玩家不会被狼刀." << endl;
			Sleep(1500);
		}
		else
		{
			Sleep(1000);
			int x;
			while (x != protect)
				x = rand() % n + 1;
			cout << "今晚你要守护的是...\n";
			Sleep(2000);
		}
		system("cls");
		print(day, 1);
	}
	cout << "狼~人~请~睁~眼~~~" << endl;
	if (player[MY].name == "狼人" && player[MY].life == true)
	{
		if (day == 1)
		{
			Sleep(1000);
			cout << "你的同伴有:";
			for (int i = 1; i <= n; i++)
			{
				if (i == MY)
					continue;
				if (player[i].name == "狼人")
				{
					cout << player[i].num << "号 ";
					player[i].know = true;
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			print(day, 1);
		}
		Sleep(700);
		cout << endl
			 << "请问你们要杀谁:" << endl
			 << "输入:";
		cin >> kill1;
		Sleep(1500);
		system("cls");
		print(day, 1);
		cout << "今晚你们要杀的是" << kill1 << "号玩家" << endl;
	}
	else
	{
		Sleep(1000);
		system("cls");
		print(day, 1);
		cout << "请问你们要杀谁?" << endl;
		do
		{
			Sleep(rand() % 18);
			srand(time(0));
			int x = rand() % n + 1;
			if (player[x].name != "狼人" && player[x].life == 1)
			{
				kill1 = x;
				break;
			}
		} while (true);
	}
	if (kill1 == protect)
		kill1 = 0;
	Sleep(700);
	system("cls");
	print(day, 1);
	cout << "狼~人~请~闭~眼~~~" << endl;
	Sleep(700);
	system("cls");
	print(day, 1);
	cout << "女~巫~请~睁~眼~~~" << endl;
	Sleep(700);
	system("cls");
	print(day, 1);
	if (player[MY].name == "女巫" && player[MY].life == 1)
	{
		Sleep(700);
		bool b = false;
		cout << "今晚" << kill1 << "号玩家被杀" << endl;
		Sleep(500);
		cout << "请问你要救吗???" << endl;
		if (jieyao == 1)
		{
			cout << "A. 救 B.不救" << endl
				 << "输入:";
			char op;
			cin >> op;
			if (op == 'A')
			{
				Sleep(500);
				system("cls");
				print(day, 1);
				cout << "今晚" << kill1 << "号玩家被你解救" << endl;
				jieyao = false;
				if (protect != kill1)
					kill1 = 0;
				else if (day == 0 && kill1 == MY)
				{
					cout << "第0晚你不能拯救自己!" << endl;
					Sleep(3000);
					b = true;
				}
				else
					kill1 = 0;
			}
			else
				b = true;
		}

		cout << "请问你要毒吗???" << endl;
		if (b == true && duyao == true)
		{
			if (protect == kill1)
				kill1 = 0;
			Sleep(700);
			system("cls");
			print(day, 1);
			cout << "A. 毒 B.不毒" << endl
				 << "输入:";
			char op;
			cin >> op;
			if (op == 'A')
			{
				cout << "请问你要毒谁???" << endl
					 << "输入:";
				cin >> kill2;
				while (player[kill2].life != 1 || kill2 > n || kill2 < 1)
				{
					cout << "输入错误,请重新输入:" << endl;
					cin >> kill2;
				}
				duyao = false;
			}
		}
	}
	else
	{
		bool b = false;
		cout << "请问你是否要用解药???" << endl;
		int FFF = 0, kkkk;
		for (int i = 1; i <= n; i++)
		{
			if (player[i].life == 1 && player[i].name == "村民")
				FFF++;
			if (player[i].name == "女巫")
				kkkk = i;
		}
		if (jieyao == 1 && player[kkkk].life == 1)
		{
			if (FFF == 1)
			{
				if (protect == kill1)
					jieyao = 1;
				else
					jieyao = 0;
				kill1 = 0;
				b = true;
			}
			else
				for (int i = 1; i <= n; i++)
				{
					if (player[i].name == "女巫" && kill1 == i)
					{
						kill1 = 0;
						if (protect == kill1)
							jieyao = 1;
						else
							jieyao = 0;
						b = 1;
						break;
					}
					else if (player[i].name == "预言家" && kill1 == i)
					{
						kill1 = 0;
						if (protect == kill1)
							jieyao = 1;
						else
							jieyao = 0;
						b = 1;
						break;
					}
				}
		}
		Sleep(700);
		system("cls");
		print(day, 1);
		cout << "请问你是否要用毒药???" << endl;
		Sleep(700);
		cout << "请问你要毒谁???" << endl;
		if (b == 0 && duyao == true && player[kkkk].life == 1)
		{
			srand(time(0));
			int x = rand() % 2;
			if (x == 1)
			{
				duyao = false;
				int y = rand() % n + 1;
				while ((player[y].name == "女巫" || player[y].name == "预言家" || y == kill1) || player[y].life == 0)
					y = rand() % n + 1;
				kill2 = y;
			}
		}
		Sleep(700);
	}
	system("cls");
	print(day, 1);
	cout << "女~巫~请~闭~眼~~~" << endl;
	if (n > 6)
	{
		Sleep(700);
		system("cls");
		print(day, 1);
		cout << "预~言~家~请~睁~眼~~~" << endl;
		Sleep(700);
		cout << "请问你想查验谁???" << endl;
		if (player[MY].name == "预言家")
		{
			cout << "输入:";
			int x;
			cin >> x;
			player[x].know = 1;
			Sleep(500);
			system("cls");
			print(day, 1);
			cout << "他的身份是:";
			Sleep(1000);
			cout << player[x].name << endl;
			Sleep(700);
		}
		else
		{
			Sleep(700);
			system("cls");
			print(day, 1);
			cout << "他的身份是:......";
			Sleep(700);
		}
		Sleep(700);
		system("cls");
		print(day, 1);
		cout << "预~言~家~请~闭~眼~~~" << endl;
	}
	Sleep(700);
	if (kill1 != 0)
		player[kill1].life = false;
	if (kill2 != 0)
		player[kill2].life = false;
	player[kill1].how = 1;
	player[kill2].how = 3;
	system("cls");
	system("color F0");
	print(2, 0);
	return;
}
void c_lieren()
{
	if (player[lieren].life == true)
		return;
	if (lr == 1)
		return;
	int target = 0;
	if (MY == lieren)
	{
		cout << "请射杀一名玩家." << endl;
		cin >> target;
		while (player[target].life != 1)
		{
			cout << "输入错误,请重新输入." << endl;
			cin >> target;
		}
	}
	else
	{
		srand(time(0));
		target = rand() % n + 1;
		while (player[target].life != 1)
			target = rand() % n + 1;
	}
	Sleep(1000);
	cout << lieren << "号猎人发动技能,开枪带走了" << target << "号" << endl;
	Sleep(3000);
	player[target].life = 0;
	player[target].how = 4;
	lr = 1;
}
void print1()
{
	cout << "天亮了,昨晚";
	if (kill1 != 0 || kill2 != 0)
	{
		cout << kill1 << "号";
		if (kill2 != 0)
		{
			cout << "," << kill2 << "号";
			kill2 = 0;
		}
		cout << "被杀" << endl;
	}
	else
		cout << "是平安夜" << endl;
}
void priiii(string x_1, int y_1)
{
	cout << x_1;
	Sleep(y_1);
	for (int k = 1; k <= 3; k++)
	{
		cout << '.';
		Sleep(y_1);
	}
}