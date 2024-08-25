#include <bits/stdc++.h>

// This is an AIDs problem to write out my solution for. I am pretty sure that my solution would work,
// but it involves writing out formulas which is not fun.
//
// My idea is that you can find the projection of the starting point to the origin of the circle to find
// the vector which will intersect the journey to the end point. Then you can find the time at which the
// intersection would happen and if the journey from A to B has would be before this point at time T, then
// return NO, otherwise this circle will grow too slowly. Repeat this for each circle.
//
// I will now go and look to see if there is a nice simple solution.

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        int sx,sy,tx,ty;
        cin >> sx >> sy >> tx >> ty;
        float d = sqrt((tx-sx)*(tx-sx) + (ty-sy)*(ty-sy));
        int vx = tx-sx;
        int vy = ty-sy;
        float mv2 = sqrt(vx*vx+vy*vy) * sqrt(vx*vx+vy*vy);
        int sqx = x[i]-sx;
        int sqy = y[i]-sy;
        int sq2 = (x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy);
        for(int i=0; i < n; ++i) {
            float a = (sqx*vx + sqy*vy)*(sqx*vx + sqy*vy) / mv2;
            float b = a * vx;
            float c = a * vy;
            float r = (b*b) + (c*c);
            if (sqrt(sq2 - r) <
        }
    }
    return 0;
}
