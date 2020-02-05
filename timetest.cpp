#include <bits/stdc++.h>

using namespace std;

// 引数として受け取った位置のフラグを立てる関数をuint64_tを利用したinlineの場合と
// std::bitset<64>を利用した通常の関数の場合で速さを比較

static inline uint64_t ObsRobotLarge(int idx) { return ((uint64_t)1 << (idx)); }

bitset<64> ObsRobotLarge2(int idx) { return bitset<64>(0).set(idx); }

int main() {
  int loops = 100000000; // 1億回のループを行って比較.
  clock_t inline_start, inline_end, start, end;
  // inlineの計測
  inline_start = clock();
  for (int i = 0; i < loops; i++) {
    auto tmp = ObsRobotLarge(10);
  }
  inline_end = clock();
  // 通常の関数の計測
  start = clock();
  for (int i = 0; i < loops; i++) {
    auto tmp = ObsRobotLarge2(10);
  }
  end = clock();
  // 結果
  cout << (double)(inline_end - inline_start) / CLOCKS_PER_SEC << endl;
  cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
  return 0;
}
