/*
 *
 * Created by: Amr Ayman
 *
 */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[6];

struct TrieNode
{
	map<int, struct TrieNode *> children;
	TrieNode()
	{
		cerr<<"Yaay"<<endl;
	}
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    	pNode->children.clear();

    return pNode;
}

void insert(struct TrieNode *root)
{
    int level;
    int length = 6;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {

    	map<int, struct TrieNode *>::iterator it;
		it=pCrawl->children.find(arr[level]);
        if (it==pCrawl->children.end())
        	pCrawl->children[arr[level]]=getNode();
        //cerr<<level<<" "<<pCrawl<<endl;
        pCrawl = pCrawl->children[arr[level]];
    }

}

bool search(struct TrieNode *root)
{
    int level;
    int length = 6;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
    	map<int, struct TrieNode *>::iterator it;
    	it=pCrawl->children.find(arr[level]);

        if (it==pCrawl->children.end())
            return 0;

       	pCrawl = it->second;
    }

    return pCrawl != NULL;
}

void cmp(int tmp[6])
{
	for (int i = 0; i < 6; i++)
	{
		if (tmp[i] < arr[i])
			break;
		if (tmp[i] > arr[i])
			return;
	}
	for (int i = 0; i < 6; i++)
		arr[i] = tmp[i];
}

int main()
{
	//std::cin.tie(0);
	//std::ios::sync_with_stdio(false);

	int n;
	//scanf("%d",&n);
	cin >> n;
	//TrieNode tmppp=;
	//TrieNode* aa=&tmppp;
	TrieNode *root = getNode();
	//cerr<<"3aa"<<endl;
	bool f = 0;
	int mn[6];
	for (int i = 0; i < n; i++)
	{
		int tmp[6];
		for (int j = 0; j < 6; j++)
		{
			//scanf("%d",&mn[j]);
			cin >> mn[j];
			arr[j] = mn[j];
		}
		for (int j = 0; j < 6; j++)
		{
			int ii = 0;
			for (int k = j; k < 6; k++)
				tmp[ii++] = mn[k];
			for (int k = 0; k < j; k++)
				tmp[ii++] = mn[k];
			cmp(tmp);
		}

		reverse(mn, mn + 6);

		for (int j = 0; j < 6; j++)
		{
			int ii = 0;
			for (int k = j; k < 6; k++)
				tmp[ii++] = mn[k];
			for (int k = 0; k < j; k++)
				tmp[ii++] = mn[k];
			cmp(tmp);
		}
		f |= search(root);
		insert(root);

		//cerr<<"3aa"<<endl;
	}
	if (f)
		//printf("Twin snowflakes found.\n");
		cout << "Twin snowflakes found.\n";
	else
		//printf("No two snowflakes are alike.\n");
		cout << "No two snowflakes are alike.\n";
	return 0;
}
