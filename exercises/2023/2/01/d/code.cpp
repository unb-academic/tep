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

// This code must be optimized later.

#include <iostream>
#include <vector>
#include <bitset>
#include <array>

using namespace std;

const int MAX{10100};

array<int, MAX> C({0});
array<int, MAX> S({0});
vector<int> P[MAX];
bitset<MAX> visited;
bitset<MAX> changed;
int p = 0;

void set_tree(int u, int set)
{
    if (visited[u])
        return;

    visited[u] = true;
    S[u] = set;

    for (auto v : P[u])
        set_tree(v, set);
}

void dfs(int u)
{
    if (changed[u])
        return;

    changed[u] = true;

    if (S[u] != C[u])
    {
        visited.reset();
        p++;
        set_tree(u, C[u]);
    }

    for (auto v : P[u])
        dfs(v);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> A;
        P[A].push_back(i + 2);
    }

    for (int i = 1; i < N + 1; ++i)
    {
        cin >> C[i];
        S[i] = 0;
    }

    dfs(1);
    cout << p << endl;
}
