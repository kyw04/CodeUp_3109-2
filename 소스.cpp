#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct _data
{
	int number;
	string name;
};
bool compare(stack<_data> a, stack<_data> b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char code;
	int n, index, input_n;
	string input_s;
	cin >> n;
	vector<_data> result(n);
	vector<stack<_data>> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> code >> input_n >> input_s;
		index = input_n % n;
		_data d = { input_n, input_s };
		if (code == 'I')
		{
			while (s[index].size() && s[index].top().number != input_n) index = (index + 1) % n;
			s[index].push(d);
		}
		else if (code == 'D')
		{
			int cnt;
			for (cnt = 0; (!s[index].size() || s[index].top().number != input_n) && cnt <= n; cnt++) index = (index + 1) % n;
			if (cnt <= n && s[index].size() && s[index].top().number == input_n)
				s[index].pop();
		}
	}

	sort(s.begin(), s.end(), compare);
	for (int i = 0, j = 0; i < n; i++)
	{
		while (s[i].size())
		{
			result[j++] = s[i].top();
			s[i].pop();
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> input_n;
		input_n--;
		cout << result[input_n].number << ' ' << result[input_n].name << '\n';
	}
	return 0;
}
bool compare(stack<_data> a, stack<_data> b)
{
	if (!a.size())
		return 0;
	if (!b.size())
		return 1;
	if (a.top().number == 0)
		return 0;
	return a.top().number < b.top().number;
}