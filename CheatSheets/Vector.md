# C++ `vector` — DSA Essentials

A quick reference for the `std::vector` operations you actually use in DSA.

```cpp
#include <vector>
using namespace std;
```

## Creating

```cpp
vector<int> v;                  // empty
vector<int> v(5);               // size 5, all 0   -> [0,0,0,0,0]
vector<int> v(5, 7);            // size 5, all 7   -> [7,7,7,7,7]
vector<int> v = {1, 2, 3};      // from list
vector<int> v2(v);              // copy of v
vector<vector<int>> grid(3, vector<int>(4, 0));  // 3x4 grid of 0s
```

## Access

```cpp
v[i]            // element at i — NO bounds check (fast, use this)
v.at(i)         // element at i — throws if out of range
v.front()       // first element
v.back()        // last element
v.size()        // number of elements (returns unsigned!)
v.empty()       // true if size == 0
```

## Adding / Removing

```cpp
v.push_back(x);              // append x to the end       O(1)
v.pop_back();               // remove last element        O(1)
v.clear();                  // remove everything          O(n)
v.insert(v.begin()+i, x);   // insert at index i          O(n) — avoid in hot loops
v.erase(v.begin()+i);       // remove at index i          O(n) — avoid in hot loops
```

## The Handful You'll Use in Algorithms

```cpp
sort(v.begin(), v.end());                  // ascending          O(n log n)
sort(v.begin(), v.end(), greater<int>());  // descending
reverse(v.begin(), v.end());               // reverse in place
*max_element(v.begin(), v.end());          // max value (note the *)
*min_element(v.begin(), v.end());          // min value
accumulate(v.begin(), v.end(), 0);         // sum — needs <numeric>
count(v.begin(), v.end(), x);              // how many times x appears
find(v.begin(), v.end(), x);               // returns iterator (== v.end() if absent)
```

> `sort` / `reverse` / `max_element` need `#include <algorithm>`; `accumulate` needs `#include <numeric>`.
> In practice people just `#include <bits/stdc++.h>` for contests — but know what lives where.

## Looping (three ways — all useful)

```cpp
for (int i = 0; i < v.size(); i++) cout << v[i];   // index — use when you need i
for (int x : v) cout << x;                          // value copy — read only
for (int &x : v) x *= 2;                            // reference — modify in place
```

> ⚠️ `v.size()` returns an **unsigned** type. Never write a downward loop like `for (int i = v.size()-1; i >= 0; i--)` mixing it with unsigned comparisons carelessly — and never compare a possibly-negative `int` against `v.size()` directly.
