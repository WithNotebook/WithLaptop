#include<stdio.h>

using namespace std;

#define N_MAX 100001

long long tree_even[N_MAX * 4];
long long tree_odd[N_MAX * 4];
long long arr[N_MAX];

long long init_even(int start, int end, int node)
{
	if (start == end)
	{
		return (tree_even[node] = ((arr[start] % 2) ? 0 : 1));
	}
	int mid = (start + end) / 2;
	return (tree_even[node] = init_even(start, mid, node * 2) + init_even(mid + 1, end, node * 2 + 1));
}

long long init_odd(int start, int end, int node)
{
	if (start == end)
	{
		return (tree_odd[node] = ((arr[start] % 2) ? 1 : 0));
	}
	int mid = (start + end) / 2;
	return (tree_odd[node] = init_odd(start, mid, node * 2) + init_odd(mid + 1, end, node * 2 + 1));
}

long long print_even(int start, int end, int node, int left, int right)
{
	if ((left > end) || (right < start)) return 0;
	if ((start >= left) && (right >= end)) return tree_even[node];

	int mid = (start + end) / 2;
	return (print_even(start, mid, node * 2, left, right) + print_even(mid + 1, end, node * 2 + 1, left, right));
}

long long print_odd(int start, int end, int node, int left, int right)
{
	if ((left > end) || (right < start)) return 0;
	if ((start >= left) && (right >= end)) return tree_odd[node];

	int mid = (start + end) / 2;
	return (print_odd(start, mid, node * 2, left, right) + print_odd(mid + 1, end, node * 2 + 1, left, right));
}
//if diff even
long long update_even(int start, int end, int node, int index, long long diff)
{	
	if ((start > index) || (end < index)) return 0;

	if (start == end)
	{
		if (start == index)
		{
			if ((arr[index] % 2)) //odd
			{				
				tree_odd[node] = 0;
				return (tree_even[node] = 1);
			}	
		}
		return 0;
	}

	int mid = (start + end) / 2;
	if (update_even(start, mid, node * 2, index, diff))
	{
		tree_odd[node] = tree_odd[node] - 1;
		tree_even[node] = tree_even[node] + 1;
		return 1;
	};
	if (update_even(mid+1, end, node * 2 + 1, index, diff))
	{
		tree_odd[node] = tree_odd[node] - 1;
		tree_even[node] = tree_even[node] + 1;
		return 1;
	}

	return 0;
}

//if diff odd
long long update_odd(int start, int end, int node, int index, long long diff)
{
	if ((start > index) || (end < index)) return 0;

	if (start == end)
	{
		if (start == index)
		{
			if (!(arr[index] % 2)) //even
			{				
				tree_even[node] = 0;
				return (tree_odd[node] = 1);
			}	
		}
		return 0;
	}

	int mid = (start + end) / 2;
	if (update_odd(start, mid, node * 2, index, diff))
	{
		tree_odd[node] = tree_odd[node] + 1;
		tree_even[node] = tree_even[node] - 1;
		return 1;
	};
	if (update_odd(mid +1, end, node * 2 + 1, index, diff))
	{
		tree_odd[node] = tree_odd[node] + 1;
		tree_even[node] = tree_even[node] - 1;
		return 1;
	}

	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		long long temp;
		scanf("%lld", &temp);
		arr[i] = temp;
	}

	init_even(1, N, 1);
	init_odd(1, N, 1);

	int M;
	scanf("%d", &M);
	
	for (int index = 0; index < M; index++)
	{
		int flag;
		scanf("%d", &flag);
		
		if (flag == 1)
		{
			int i;
			long long v;
			bool isChanged = false;
			scanf("%d %lld", &i, &v);
			if (v % 2)
			{
				isChanged = update_odd(1, N, 1, i, v);
			}
			else
			{
				isChanged = update_even(1, N, 1, i, v);
			}
			arr[i] = v;
		}
		else if (flag == 2)
		{
			int i, j;
			scanf("%d %d", &i, &j);
			long long res = print_even(1, N, 1, i, j);
			printf("%lld\n", res);
		}
		else
		{
			int i, j;
			scanf("%d %d", &i, &j);
			long long res = print_odd(1, N, 1, i, j);
			printf("%lld\n", res);
		}
	}
	
	return 0;
}