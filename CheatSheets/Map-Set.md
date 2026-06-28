# C++ `map` / `set` — DSA Essentials

Associative containers for "have I seen this?", counting, and key→value lookups.
Two families: **hash-based** (`unordered_*`, avg O(1)) and **tree-based** (ordered, O(log n), keeps keys sorted).

```cpp
#include <unordered_set>   // unordered_set, unordered_multiset
#include <unordered_map>   // unordered_map, unordered_multimap
#include <set>             // set, multiset        (ordered)
#include <map>             // map, multimap        (ordered)
using namespace std;
```

## Which one do I use?

| Need | Use | Why |
|---|---|---|
| "Have I seen X?" / unique elements | `unordered_set` | O(1) membership, no order needed |
| Count frequencies (X → how many) | `unordered_map<T,int>` | O(1) increment |
| Key → value lookup, order doesn't matter | `unordered_map` | O(1) average |
| Need keys **sorted** / range queries / min-max | `set` / `map` | O(log n), iterates in sorted order |
| Duplicates allowed (multiset of values) | `multiset` / `multimap` | keeps repeats |

**Default to `unordered_*` in DSA** unless you specifically need sorted order — it's faster (O(1) vs O(log n)).

---

## `unordered_set<T>` — membership / uniqueness

```cpp
unordered_set<int> s;
s.insert(5);                 // add (duplicates ignored)
s.erase(5);                  // remove by value
s.count(5);                  // 1 if present, 0 if not   ← typical membership check
s.find(5) != s.end();        // alternative membership check
s.size();                    // number of elements
s.empty();                   // true if empty
s.clear();                   // remove all

if (s.count(x)) { /* x is present */ }

for (int x : s) cout << x;    // iterate (NO guaranteed order)
```

## `set<T>` — unique + sorted

Same API as `unordered_set`, **plus** sorted iteration and ordered queries:

```cpp
set<int> s = {3, 1, 2};
// iterates in sorted order: 1, 2, 3
*s.begin();                  // smallest element
*s.rbegin();                 // largest element
s.lower_bound(x);            // iterator to first element >= x
s.upper_bound(x);            // iterator to first element >  x
```

> `multiset<T>` = same but keeps duplicates. `s.erase(x)` removes ALL copies of x;
> `s.erase(s.find(x))` removes just ONE copy.

---

## `unordered_map<K,V>` — key → value / counting

```cpp
unordered_map<char,int> m;
m['a'] = 5;                  // insert / overwrite
m['a']++;                    // increment (auto-creates as 0 first if absent!)
m.count('a');                // 1 if key present, 0 if not
m.find('a') != m.end();      // membership check (find returns iterator)
m.erase('a');                // remove key
m.size();  m.empty();  m.clear();

// THE counting idiom (frequency map):
unordered_map<char,int> freq;
for (char c : s) freq[c]++;          // count each char
if (freq['a'] == 2) { ... }

// iterate key/value pairs:
for (auto& [key, val] : m)           // structured binding (C++17)
    cout << key << "=" << val << "\n";
for (auto& p : m)                    // older style
    cout << p.first << "=" << p.second << "\n";
```

> ⚠️ **`m[key]` auto-inserts** the key with a default value (0 for int) if it doesn't exist —
> just *reading* `m[key]` can grow the map. To check presence without inserting, use `m.count(key)` or `m.find(key)`.

## `map<K,V>` — key → value, sorted by key

Same API as `unordered_map`, **plus** keys stay sorted and you get ordered queries:

```cpp
map<int,int> m;
m.begin();                   // smallest key
m.rbegin();                  // largest key
m.lower_bound(k);            // first entry with key >= k
// iterates in ascending key order
```

> `multimap<K,V>` = allows duplicate keys.

---

## Common DSA Idioms

```cpp
// 1. Sliding window: chars currently in the window
unordered_set<char> seen;
while (seen.count(s[right])) { seen.erase(s[left]); left++; }
seen.insert(s[right]);

// 2. Frequency count
unordered_map<int,int> freq;
for (int x : nums) freq[x]++;

// 3. Two Sum (unsorted) — value -> index
unordered_map<int,int> idx;
for (int i = 0; i < nums.size(); i++) {
    if (idx.count(target - nums[i])) return {idx[target - nums[i]], i};
    idx[nums[i]] = i;
}

// 4. Detect duplicates
unordered_set<int> seen;
for (int x : nums) { if (seen.count(x)) return true; seen.insert(x); }
```

---

## Complexity Cheat

| Operation | `unordered_set/map` | `set/map` |
|---|---|---|
| insert / erase / find | O(1) average | O(log n) |
| iterate in sorted order | ❌ (unordered) | ✅ |
| min / max element | ❌ (scan O(n)) | ✅ O(1) at begin/rbegin |
| worst case | O(n) (hash collisions, rare) | O(log n) guaranteed |

**Rule of thumb:** reach for `unordered_map` / `unordered_set` by default. Switch to `map` / `set` only when you need sorted order, range queries, or min/max on the fly.
