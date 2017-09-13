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

class CrazySwitches
{
public:
	int minimumActions(vector<int> switches)
	{
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, 1));
		while (pq.size())
		{
			int msk, cnt;
			msk = pq.top().second;
			cnt = pq.top().first;
			pq.pop();
			//cerr<<msk<<endl;
			if (((1 << (switches.size() - 1)) & msk) != 0
					&& ((1 << (switches[0])) & msk) != 0)
			{
				int tmp = 0;
				bool f=0;
				for (int i = 0; i < switches.size(); i++)
				{
					if (((1 << i) & msk) != 0)
					{
						if(switches[i]==switches.size()-1)
							f=1;
						tmp++;
					}
				}
				if(!f)
					return -1;
				//cout<<cnt<<" "<<tmp<<endl;
				return (-1*cnt) + tmp - 2;
			}
			for (int i = 0; i < switches.size(); i++)
			{
				if (((1 << i) & msk) == 0 && ((1 << switches[i]) & msk) != 0)
				{
					int tmp = msk;
					tmp = (tmp | (1 << i));
					//cout << tmp << " " << i << " ";
					pq.push(make_pair(cnt - 1, tmp));
				}
			}
		}
		return -1;
	}
};
