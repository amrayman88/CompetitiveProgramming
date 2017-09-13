#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Smooshing
{
public:
	int savings(vector<string> program)
	{
		map<string, pair<int, int>> mp;
		for (int ii = 0; ii < program.size(); ii++)
		{
			string s = program[ii];
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					string tmp;
					tmp += s[i];
					int idx = i + 1;
					while ((s[idx] >= 'A' && s[idx] <= 'Z')
							|| (s[idx] >= 'a' && s[idx] <= 'z'))
					{
						tmp += s[idx];
						idx++;
					}
					if (mp.find(tmp) == mp.end())
					{
						mp[tmp].second = i+(60*ii);
					}
					i = idx - 1;
					mp[tmp].first++;
				}
				else if (s[i] >= 'a' && s[i] <= 'z')
				{
					i++;
					while ((s[i] >= 'A' && s[i] <= 'Z')
							|| (s[i] >= 'a' && s[i] <= 'z'))
					{
						i++;
					}
					i--;
				}
			}
		}
		set<pair<pair<int, int>, string>> st;
		for (auto it : mp)
		{
			it.second.first *= -1;
			st.insert(make_pair(it.second, it.first));
		}
		map<string, bool> mpp;
		int ans = 0;
		for (auto it : st)
		{
			int idx = 0;
			string tmp, s;
			s = it.second;
			tmp += s[0];
			while (mpp[tmp] == 1)
			{
				idx++;
				idx %= s.size();
				tmp += s[idx];
			}
			cout << s << " " << tmp << " " << it.first.first * -1<<" "<<it.first.second << endl;
			mpp[tmp] = 1;
			ans += (s.size() - tmp.size()) * (it.first.first * -1);
		}
		return ans;
	}
};
