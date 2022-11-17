/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and 
which encompasses all the given points.
*/
#define hello <algorithm>
#define hello2 <vector>
#define hello3 <cmath>
#include<iostream>
#include hello3
#include hello2
#include hello 

using namespace std;
struct Point
{
    int x;
    int y;
};
int orientation(int p, int i, int q, Point points[])
{
    int val = (points[i].y - points[p].y)*(points[q].x - points[i].x) - (points[i].x - points[p].x)*(points[q].y - points[i].y);
    if (val < 0){
        return true;
    }
    else if (val == 0){
        int dist1 = (points[i].x - points[p].x)*(points[i].x - points[p].x) + (points[i].y - points[p].y)*(points[i].y - points[p].y);
        int dist2 = (points[q].x - points[p].x)*(points[q].x - points[p].x) + (points[q].y - points[p].y)*(points[q].y - points[p].y);
        if (dist1 <= dist2){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
void convexHull(int n, Point points[])
{
    int l = 0, count = 0;
    if (n < 3){
        cout << 0;
    }
    else{
        for (int i = 0; i < n; i++)    {
            if (points[i].x < points[l].x){
                l = i;
            }
        }
        int p = l, q;
        do{
            q = (p + 1) % n;
            for (int i = 0; i < n; i++){
                if (orientation(p, i, q, points)){
                    q = i;
                }
            }
            p = q;
            count++;
        } while (p != l);
        cout << count << endl;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case){
        int n;
        cin >> n;
        Point points[n];
        for (int i = 0; i < n; i++){
            cin >> points[i].x >> points[i].y;
        }
        convexHull(n, points);
    }
    return 0;
}
