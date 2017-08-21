///
//the idea:
//by bruteforcing on a we can find the nearest b to the answer c by dividing c by the new a as a new b and then trying its floor and ceil values
///
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


class CorrectMultiplicationTwo {
public:
	int getMinimum(int a, int b, int c) {
		long long mn=1e9;
		for(int i=1;i<=10000000;i++)
        {
            long long x,y,z;
            x=i;
            y=c/i;
            y++;
            z=x*y;
            long long ans=abs(x-a)+abs(y-b)+abs(z-c);
            if(ans<mn)
            {
                mn=min(mn,ans);
                //cout<<x<<" "<<y<<" "<<z<<endl;
            }
            y--;
            z=x*y;
            if(y==0)
                continue;
            ans=abs(x-a)+abs(y-b)+abs(z-c);
            if(ans<mn)
            {
                mn=min(mn,ans);
                //cout<<x<<" "<<y<<" "<<z<<endl;
            }
        }
        return mn;
	}
};

