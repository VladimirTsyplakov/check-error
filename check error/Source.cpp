#include<iostream>
#include<cstdlib>
using namespace std;

class fraction
{
private:
	int a;
	int b;
public:
	fraction() : a(2), b(7)
	{}
	fraction(int ab, int bb) { a = ab; b = bb; }
	void get()
	{
		char c1;
		cout << "введите дробь в формате: x/y" << endl;
		cin >> a >> c1 >> b;
	}
	bool operator !=(fraction bad)
	{
		if (a == bad.a || b == bad.b)
		{
			cout << "ошибка" << endl; return 0;
		}
		else { return 1; }
	}

	fraction operator+(fraction drob)
	{
		fraction temp;
		temp.a = (a * drob.b + b * drob.a);
		temp.b = (b * drob.b);
		return temp;
	}
	fraction operator-(fraction drob)
	{
		fraction temp;
		temp.a = (a * drob.b - b * drob.a);
		temp.b = (b * drob.b);
		return temp;
	}
	fraction operator*(fraction drob)
	{
		fraction temp;
		temp.a = (a * drob.a);
		temp.b = (b * drob.b);
		return temp;
	}
	fraction operator/(fraction drob)
	{
		fraction temp;
		temp.a = (a * drob.b);
		temp.b = (b * drob.a);
		return temp;
	}
	void show()
	{
		int n = 1;
		while (n <= 10)
		{
			if (!(a % n) && !(b % n) && a != 0 && b != 0) { a /= n; b /= n; n = 1; }n++;
		}
		cout << a << "/" << b << endl;
	}
	friend ostream& operator <<(ostream& out, const fraction& per)
	{
		out << per.a << "/" << per.b << endl;
		return out;
	}
	friend istream& operator >>(istream& in, fraction& per)
	{
		char t = '/';
		while (true)
		{
			in >> per.a >> t >> per.b;
			if (t == '/')break;
			else cout << "через слэш" << endl;
			in.clear();
			in.ignore(5, '\n');
		}
		return in;
	}
	void putd1()
	{
		cout << "1 дробь? a/b" << endl;
	}
	void putd2()
	{
		cout << "2 дробь? a/b" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	fraction a;
	fraction b;
	fraction c;
	char ch = 'y';
	char zn;
	while (ch != 'n')
	{
		while (true)
		{
			a.putd1();
			cin >> a;
			if (cin.good()) {
				fraction bad(0, 0);
				if (a != bad) break; else cout << "не равно 0" << endl;
			}
			else cout << "цифры надо, еще раз" << endl;
			cin.clear();//сначала чистим поток от ошибок
			cin.ignore(5, '\n');// потом удаляем из потока данные
		}
		while (true)
		{
			cout << "введите знак" << endl;
			cin >> zn;
			if (cin.good())
			{
				if (zn == '+' || zn == '-' || zn == '/' || zn == '*')break; else cout << "введите допустимый знак" << endl;
			}
			else cout << "еще раз" << endl;
			cin.clear();
			cin.ignore(5, '\n');
		}
		while (true)
		{
			b.putd2();
			cin >> b;
			if (cin.good()) {
				fraction bad(0, 0);
				if (b != bad) break; else cout << "не равно 0" << endl;
			}
			else cout << "цифры надо, еще раз" << endl;
			cin.clear();
			cin.ignore(5, '\n');
		}
		switch (zn)
		{
		case '+': cout << a + b; break;
		case '-': cout << a - b; break;
		case '/': cout << a / b; break;
		case '*': cout << a * b; break;
		}
		cout << "ещë?" << endl;
		cin >> ch;
	}
}