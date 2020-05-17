#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    if(w.length()==1) return "no answer";
    int i;
    auto itr=w.end();
    itr--;
    for(i=w.length()-1;i>0;i--){
        if(w[i]>w[i-1])
            break;
        itr--;
    }
    if(i==0)
        return "no answer";
    sort(itr,w.end());
    auto it=upper_bound(itr,w.end(),w[i-1]);
    char temp=w[i-1];
    w[i-1]=*it;
    *it=temp;
    sort(itr,w.end());
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

