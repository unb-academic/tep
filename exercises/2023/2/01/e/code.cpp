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
#include <vector>
#include <bitset>

using namespace std;

const int MAX{100010};

int limit, res = 0;
bitset<MAX> visited;
vector<int> adj[MAX];
vector<int> marked(MAX);

void dfs(int u, int counter = 0)
{
    if (visited[u])
        return;

    visited[u] = true;

    if (marked[u])
        counter++;
    else
        counter = 0;

    if (counter > limit)
        return;

    if (adj[u].size() <= 1 and u != 1)
        // We reached a leaf.
        res++;

    for (int v : adj[u])
        dfs(v, counter);
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N >> limit;

    for (int i = 0; i < N; ++i)
        cin >> marked[i + 1];

    for (int i = 0; i < N - 1; ++i)
    {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    dfs(1);
    cout << res << endl;
}
