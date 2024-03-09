#include <bits/stdc++.h>

using namespace std;

const double EPS { 1e-9 };

bool equals(double a, double b) {
    return fabs(a - b) < EPS;
}

double to_radians(int degrees) {
    return degrees * M_PI / 180.0;
}

struct Point {
    double x, y, theta;

    void print() {
        cout << "point.x = " << x << endl;
        cout << "point.y = " << y << endl;
        cout << "point.theta = " << theta << endl;
        cout << "---" << endl;
    }

    void move(int distance) {
        x += distance * cos(theta);
        y += distance * sin(theta);

        if (equals(x, 0.0))
            x = 0.0;

        if (equals(y, 0.0))
            y = 0.0;
    }

    void rotate(int degrees) {
        theta += to_radians(degrees);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int X;
    cin >> X;

    Point p = {0.0, 0.0, to_radians(90)};
    int count = 1;

    p.move(1);
    p.rotate(X);

    while (not (equals(p.x, 0.0) and equals(p.y, 0.0))) {
        p.move(1);
        p.rotate(X);
        count++;
    }

    cout << count << endl;

    return 0;
}
