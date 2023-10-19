/*
 * MIT License
 *
 * Copyright (c) 2023 UnB
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    map<char, int> coords;
    coords['a'] = 1;
    coords['b'] = 2;
    coords['c'] = 3;
    coords['d'] = 4;
    coords['e'] = 5;
    coords['f'] = 6;
    coords['g'] = 7;
    coords['h'] = 8;

    int x, y;
    char a, b;

    cin >> a >> x >> b >> y;

    int current_col = coords[a];
    int current_row = x;

    int target_col = coords[b];
    int target_row = y;

    int dx = current_col - target_col;
    int dy = current_row - target_row;

    vector<string> moves;

    while (dx != 0 and dy != 0) {
        if (dx > 0 and dy > 0) {
            moves.push_back("LD");
            dx--;
            dy--;
        } else if (dx > 0 and dy < 0) {
            moves.push_back("LU");
            dx--;
            dy++;
        } else if (dx < 0 and dy > 0) {
            moves.push_back("RD");
            dx++;
            dy--;
        } else if (dx < 0 and dy < 0) {
            moves.push_back("RU");
            dx++;
            dy++;
        }
    }

    while (dx != 0) {
        if (dx > 0) {
            moves.push_back("L");
            dx--;
        } else {
            moves.push_back("R");
            dx++;
        }
    }

    while (dy != 0) {
        if (dy > 0) {
            moves.push_back("D");
            dy--;
        } else {
            moves.push_back("U");
            dy++;
        }
    }

    cout << moves.size() << endl;

    for (auto move : moves) {
        cout << move << endl;
    }
}
