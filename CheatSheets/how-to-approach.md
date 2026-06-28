# How to Approach Any DSA Problem

The real skill isn't solving a problem when someone feeds you hints — it's becoming the person who asks those hints **to yourself**. There are two separate skills: **recognizing the pattern**, and **cracking it**. Train them differently.

---

## Skill 1: Recognition — "What pattern is this?"

Recognition is pattern-matching on **signals**, not insight. Every pattern has tells. Memorize the tells, then scan any new problem for them *before* trying to solve it.

| Signal in the problem | Likely pattern |
|---|---|
| **Sorted** array + find pair/triplet/target | **Two pointers** (opposite ends) |
| Rearrange / remove / partition **in-place**, O(1) space | **Two pointers** (slow/fast) |
| **Contiguous** subarray/substring + "size k" / "longest" / "shortest" / "max" / "min" with a condition | **Sliding window** |
| "Count of" / "have I seen this before" / duplicates / frequency | **Hash map / set** |
| "All combinations / permutations / subsets" / "generate every" | **Backtracking** |
| Tree / "levels" / "shortest path in unweighted grid" | **BFS** |
| Tree / "all paths" / "explore deeply" | **DFS / recursion** |
| "Top K" / "K largest/smallest" / "median of a stream" | **Heap** |
| "Number of ways" / "min/max cost to" / overlapping choices | **DP** |
| "Next greater/smaller element" / matching brackets | **Stack (monotonic)** |

**Strongest tells:** the word **"sorted"** → two pointers; the phrase **"contiguous subarray/substring"** → sliding window. Hunt for keywords first.

---

## Skill 2: The Self-Questioning Script — "How do I crack it?"

The hint-questions a coach asks follow a **fixed template**. Internalize this 5-step script and you become your own coach.

### The universal script (any problem)

**Step 1 — Brute force first, always.** Ask: *"What's the dumbest correct solution?"* Usually nested loops / try-everything. Get its complexity. (It must be *correct* even if slow.)

**Step 2 — Find the bottleneck.** Ask: *"What is the brute force doing that's wasteful or repeated?"* The bottleneck almost always points at the pattern:
- Re-summing overlapping ranges → **sliding window**
- Ignoring that the array is sorted → **two pointers**
- Re-searching "have I seen X" → **hash map**

**Step 3 — Match to a pattern** using the signal table above.

**Step 4 — Run the pattern's mini-checklist** (see below).

**Step 5 — Trace a tiny example on paper** before trusting the code. Catches off-by-one and boundary bugs every time.

---

## Pattern Mini-Checklists

### Sliding Window
1. Fixed-size window or variable?
2. What do I track **incrementally** as the window moves? (sum / zero-count / char frequency)
3. **Grow:** when `right` moves, what updates?
4. **Shrink:** when do I shrink from `left`, and what updates as an element leaves?
5. **Record:** when is the window "valid," and where do I record the answer?

> **Min vs Max windows — the key structural difference:**
> - **Min** problem (smallest valid window): valid when condition met → shrink **while valid** (to shrink further), record length **inside** the while.
> - **Max** problem (largest valid window): shrink **while invalid** (only to restore validity), record length **after** the while (window is now valid), every iteration.

### Two Pointers
1. Same direction (slow/fast) or opposite ends?
2. What's the condition to move each pointer?
3. Why does moving it that way not skip a valid answer?

> - **slow/fast:** `write` = next slot to place a kept element; `read` scans all. In-place, O(1) space.
> - **opposite ends:** `left` from front, `right` from back, move toward each other. Each step discards a candidate → O(n). Requires sorted (or a monotonic property).

---

## The Cold-Start Ritual (do this on paper for EVERY problem)

```
1. Signals I see:        ____________  (sorted? contiguous? top-k?)
2. Guessed pattern:      ____________
3. Brute force + Big-O:  ____________
4. The bottleneck:       ____________
5. Pattern checklist:    ____________
```

It feels slow. The slowness **is** the learning — you're building the reflex. After ~30 mixed problems, steps 1–2 become instant.

---

## Why Interleave (mix problem types) instead of grinding one pattern

If every problem is labeled "sliding window," you never practice Steps 1–3 (recognition) — you already know the answer. **Mixed, unlabeled problems force you to choose the pattern**, which is the real test. Learn a pattern with a short focused burst (4–6 problems), then fold it into a mixed rotation and revisit at widening intervals (spaced repetition).

---

## Universal Complexity Reminders

- Two nested loops over n → O(n²). One pass → O(n).
- Halving/doubling each step → O(log n) (binary search).
- Sorting → O(n log n) (often the "brute force" to beat).
- Sliding window / two pointers turn an O(n²) or O(n·k) brute force into O(n).
- Dropping constants: O(2n), O(n + n) → O(n). Drop lower-order terms: O(n² + n) → O(n²).
- **Output space** (the array you must return) is separate from **auxiliary space**. In-place problems restrict *auxiliary* space to O(1).
