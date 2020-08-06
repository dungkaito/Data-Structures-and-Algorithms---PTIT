/* open with vscode
C[0] = C[1] = 1
C2 = C0 * C1 + C1 * C0
C3 = C0*C2 + C1*C1 + C2*C0
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0

C[i]=0;
for j: 0 to i-1
    C[i] += C[j]*C[j-i+1]
*/
#include <bits/stdc++.h>
using namespace std;
string C[101];
string sumBig(string s1, string s2) {
    if (s1.size() > s2.size()) swap(s1,s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string s=""; int carry=0; //s = s1+s2
    for (int i=0; i<s1.size(); i++) {
        int sum = s1[i]-'0' + s2[i]-'0' + carry;
        s.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i=s1.size(); i<s2.size(); i++) {
        int sum = s2[i] - '0' + carry;
        s.push_back(sum % 10 +'0');
        carry = sum / 10;
    }
    if (carry) s.push_back(carry+'0');
    reverse(s.begin(), s.end());
    return s;
}
string mulBig(string s1, string s2) {
    int len1=s1.size(), len2=s2.size();
    int len=len1+len2, i, j;
    vector<int> prod(len, 0);
    for (i=len1-1; i>=0; i--) {
        for (j=len2-1; j>=0; j--) {
            prod[i+j+1] += (s1[i] - '0') * (s2[j] - '0'); 
        }
    }
    for (i=len-1; i>0; i--) {
        if (prod[i] > 9) {
            prod[i-1] += prod[i]/10;
            prod[i] %= 10;
        }
    }
    i=0; 
    while (i<len && prod[i]==0) i++;
    if(i==len) return "0";
    string s=""; 
    while (i<len) s+=to_string(prod[i++]);
    return s;
}
void init() {
    C[0] = C[1] = "1";
    for (int i=2; i<=100; i++) {
        C[i] = "";
        for (int j=0; j<i; j++)
            C[i] = sumBig(C[i], mulBig(C[j], C[i-j-1]));
    }
}
int main() {
    int t, n; cin>>t;
    init();
    while (t--) {
        // string s1 = "89";
        // string s2 = "26997";
        // cout<<mulBig(s1,s2)<<endl;
        cin>>n;
        cout<<C[n]<<endl;
    }
}