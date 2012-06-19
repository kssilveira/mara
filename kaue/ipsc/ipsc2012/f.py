import sys

"""
ld solve(int mask, int cur, int val) {
  if (cur == n) {
    return val;
  }
  ld next = solve(mask, cur + 1, (val + 1) % 2);
  if (mask & (1 << cur)) {
    ld res = 0;
    // 1 - solve
    //res += v[cur] * solve(mask, cur + 1, (val + 1) % 2);
    //res += (1 - v[cur]) * solve(mask, cur + 1, val % 2);
    res += v[cur] * next + (1 - v[cur]) * (1 - next);
    return res;
  }
  //return solve(mask, cur + 1, val);
  return 1 - next;
}
"""

ONE = 1000000

def solve(mask, cur, val, n, v):
  if cur == n:
    return val;
  next = solve(mask, cur + 1, (val + 1) % 2, n, v)
  if mask & (1 << cur):
    #res = v[cur] * next + (ONE - v[cur]) * (ONE - next)
    res = 0
    res += v[cur] * solve(mask, cur + 1, (val + 1) % 2, n, v)
    res += (ONE - v[cur]) * solve(mask, cur + 1, val, n, v)
    return res;
  return solve(mask, cur + 1, val, n, v)

def main():
  T = int(raw_input())
  while T > 0:
    #sys.stderr.write(str(T))
    T -= 1
    line = sys.stdin.readline()
    n = int(raw_input())
    s = raw_input()
    t = s.split(' ')
    v = []
    for i in range(n):
      r = t[i].split('.')
      #print r
      val = r[1]
      while len(val) < 6:
        val += '0'
      v.append(int(val))
    #print v

    cnt = 0
    for i in range(n):
      if v[i] == 500000:
        cnt += 1

    #print n, ' ', cnt
    res = (1 << n) - (1 << (n - cnt))
    print res

    #found = False
    #for mask in range(1 << n):
      #res = solve(mask, 0, 0, n, v)
      #cnt = 0
      #for i in range(n):
        #if mask & (1 << i):
          #cnt += 1
      ##print res, ' ', mask, ' ', cnt
      #if (str(res) == '5' + ('0' * (6 * cnt - 1))):
        ##print 'good!'
        #r = []
        #for i in range(n):
          #if mask & (1 << i):
            #r.append(v[i])
        #print r
#
        #found = True
        ##break
#
    #if found:
      #print 1
    #else:
      #print 0

main()
