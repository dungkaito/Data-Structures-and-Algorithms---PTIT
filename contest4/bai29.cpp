#include <bits/stdc++.h>
using namespace std;

struct Point{
	double x, y;
};

int n;
Point P[100001];

bool cmpX(Point A, Point B) {
	return A.x < B.x;
}

bool cmpY(Point A, Point B) {
	return A.y < B.y;
}

double dist (Point A, Point B) {
	return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

double bruteForce (int start, int end) {
	double min = DBL_MAX;
	for (int i=start; i<end; i++) {
		for (int j=i+1; j<=end; j++) {
			double tmp = dist(P[i], P[j]);
			if (tmp < min) min = tmp;
		}
	}
	return min;
}

double minDistanceInStrip (vector<Point> strip, int sz, double min) {
	sort(strip.begin(), strip.end(), cmpY);
	
	for (int i=0; i<sz-1; i++) {
		for (int j=i+1; j<sz && strip[j].y-strip[i].y<min; j++) {
			double tmp = dist(strip[i],strip[j]);
			if (tmp < min) min=tmp; 
		}
	}
	return min;
}

double smallestDistance(int start, int end) {
	if (end+1-start<=3) 
		return bruteForce(start, end);
	int mid = (start + end) / 2;
	double d_left = smallestDistance(start, mid);
	double d_right = smallestDistance(mid+1, end);
	double d = min(d_left, d_right); 
	vector<Point> strip;
	for (int i=start; i<=end; i++)
		if (abs(P[i].x - P[mid].x) < d)
			strip.push_back(P[i]);
	double dmid = minDistanceInStrip(strip, strip.size(), d);
	return min(d, dmid);
	
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>P[i].x>>P[i].y;
		sort(P, P+n, cmpX);
//		cout<<fixed<<setprecision(6)<<smallestDistance(0, n-1)<<endl;
		printf("%0.6f\n", smallestDistance(0, n-1));
	}
	return 0;
}
