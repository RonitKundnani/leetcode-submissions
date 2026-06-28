# C++ `string` — DSA Essentials

A quick reference for the `std::string` operations you actually use in DSA.

```cpp
#include <string>
using namespace std;
```

## Creating

```cpp
string s;                       // empty ""
string s = "hello";             // from literal
string s("hello");              // same thing
string s(5, 'a');               // "aaaaa" — 5 copies of 'a'
string s2(s);                   // copy of s
string s3 = s.substr(1, 3);     // substring: start index 1, length 3 -> "ell"
string s4 = to_string(123);     // number -> string  -> "123"
int n   = stoi("123");          // string -> int      -> 123
long l  = stol("123456789");    // string -> long
double d = stod("3.14");        // string -> double
```

## Access

```cpp
s[i]            // char at i — NO bounds check (fast, use this)
s.at(i)         // char at i — throws if out of range
s.front()       // first char
s.back()        // last char
s.size()        // number of chars (returns unsigned!)  — same as s.length()
s.length()      // identical to s.size()
s.empty()       // true if size == 0
```

## Adding / Removing / Modifying

```cpp
s.push_back('x');       // append one char            O(1) amortized
s.pop_back();           // remove last char           O(1)
s += "world";           // append string or char      O(len added)
s.append("world");      // same as +=
s.insert(i, "xyz");     // insert at index i           O(n)
s.erase(i, len);        // remove len chars from i     O(n)
s.clear();              // make it empty               O(n)
s.replace(i, len, "x"); // replace len chars at i with "x"
```

## Searching

```cpp
s.find("lo");           // index of first match, or string::npos if absent
s.find("lo", 3);        // start searching from index 3
s.rfind("lo");          // last match (search from the right)
s.find_first_of("aeiou");   // index of first char that is any of these
s.substr(2);            // from index 2 to the end
s.substr(2, 4);         // from index 2, length 4

if (s.find("x") != string::npos) { /* found */ }
```

## Character Helpers (`#include <cctype>`)

```cpp
isalpha(c)      // letter?           a-z A-Z
isdigit(c)      // digit?            0-9
isalnum(c)      // letter or digit?
isspace(c)      // space/tab/newline?
isupper(c)      // uppercase?
islower(c)      // lowercase?
tolower(c)      // -> lowercase char
toupper(c)      // -> uppercase char
c - '0'         // char digit -> int value   ('7' -> 7)
i + '0'         // int 0..9    -> char digit  (7   -> '7')
```

## The Handful You'll Use in Algorithms

```cpp
sort(s.begin(), s.end());               // sort chars ascending      O(n log n)
reverse(s.begin(), s.end());            // reverse in place
count(s.begin(), s.end(), 'a');         // how many times 'a' appears
*max_element(s.begin(), s.end());       // largest char (note the *)
```

> `sort` / `reverse` / `max_element` need `#include <algorithm>`.
> Comparing strings: `s1 == s2`, `s1 < s2` (lexicographic) all work directly with operators.

## Looping (three ways — all useful)

```cpp
for (int i = 0; i < s.size(); i++) cout << s[i];   // index — use when you need i
for (char c : s) cout << c;                          // value copy — read only
for (char &c : s) c = toupper(c);                    // reference — modify in place
```

## Gotchas

- `s.size()` returns an **unsigned** type — same trap as vector. Avoid mixing it with possibly-negative `int` in comparisons.
- `s.find(...)` returns `string::npos` (a huge unsigned value) when not found — always compare against `string::npos`, never against `-1`.
- `tolower`/`toupper` take and return `int`; assign back to a `char` when storing: `c = tolower(c);`.
