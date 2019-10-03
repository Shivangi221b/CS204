#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
};

Point p0;

void swap(Point &p1, Point &p2)
{
    Point temp=p1;
    p1=p2;
    p2=temp;
}

Point afterTop(stack<Point> &p)
{
	Point x=p.top();
	p.pop();
	Point y=p.top();
	p.push(x);
	return y;
}

int dist(Point p1, Point p2)
{
    int d=(p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    return d;
}

int orientation(Point p1, Point p2, Point p3)
{
	int m=(p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);
	if(m==0) return 0;
	return (m>0)?1:2;
}

int compare(Point p1, Point p2)
{
   int o = orientation(p0, p1, p2);
   if (o == 0)
     return (dist(p0, p2) >= dist(p0, p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

void merge(Point arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    Point L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (compare(L[i],R[j])==-1)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Point arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void ConvexHull(Point point[], long long int n)
{
	int ymin=point[0].y;
	int min=0;

	for(int i=1; i<n; i++)
	{
		int y=point[i].y;
		if((y<ymin) || (y==ymin && point[i].x < point[min].x))
		{
			ymin=point[i].y;
			min=i;
		}
	}

	swap (point[0], point[min]);

	p0=point[0];

	mergeSort(point, 0, n-1);

	int m = 1;
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, point[i], point[i+1]) == 0)
        	i++;

        point[m] = point[i];
        m++;
    }

    if(m<3) return;

    stack<Point> p;
    p.push(point[0]);
    p.push(point[1]);
    p.push(point[2]);

    for(int i=3; i<m; i++)
    {
    	while(orientation(afterTop(p),p.top(),point[i])!=2)
    		p.pop();

    	p.push(point[i]);
    }

    int c=p.size();
    cout<<c<<endl;

    while(!p.empty())
    {
    	Point pt = p.top();
        cout << "(" << pt.x << ", " << pt.y <<")" << endl;
        p.pop();
    }
}

int main()
{
	long long int t;
	cin>>t;
	int x1,y1;
	Point point[t];
	//Point point[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

	for(int i=0; i<t; i++)
	{
		cin>>x1>>y1;
		point[i].x=x1;
		point[i].y=y1;
	}

	ConvexHull(point, t);
}


