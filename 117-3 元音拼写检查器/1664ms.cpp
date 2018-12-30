typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005


bool isVowel[128];
class Solution {
public:
  bool cap(string &x, string &y) { //判断小写形式是否相等
    if (x.size() != y.size()) return false;
    REP(i,0,x.size()) {
      char a = x[i], b = y[i];
      if ('A' <= a && a <= 'Z') a = 'a' + (a - 'A');
      if ('A' <= b && b <= 'Z') b = 'a' + (b - 'A');
      if (a != b) return false;
    }
    return true;
  }
  bool vowel(string &x, string &y) { //转换元音是否相等
    if (x.size() != y.size()) return false;
    REP(i,0,x.size()) {
      char a = x[i], b = y[i];
      if ('A' <= a && a <= 'Z') a = 'a' + (a - 'A');
      if ('A' <= b && b <= 'Z') b = 'a' + (b - 'A');
      if (isVowel[a] && isVowel[b]) continue;
      if (a != b) return false;
    }
    return true;
  }
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    vector<string> ans;
    isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;
    REP(i,0,queries.size()) {
      string &q = queries[i];
      bool found = false;
      REP(j,0,wordlist.size()) { //判断是否直接相等
        string &w = wordlist[j];
        if (w == q) {
          found = true;
          ans.push_back(w);
          break;
        }
      }
      if (found) continue;
      REP(j,0,wordlist.size()) { //判断小写形式
        string &w = wordlist[j];
        if (cap(w, q)) {
          found = true;
          ans.push_back(w);
          break;
        }
      }
      if (found) continue;
      REP(j,0,wordlist.size()) { //判断元音形式
        string &w = wordlist[j];
        if (vowel(w, q)) {
          found = true;
          ans.push_back(w);
          break;
        }
      }
      if (found) continue;
      ans.push_back("");
    }
    return ans;
  }
};
