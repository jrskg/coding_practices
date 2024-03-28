#include <iostream>
#include <set>

using namespace std;

int main() {
    set<pair<int, int>> st;
    st.insert(make_pair(1, 4));
    st.insert(make_pair(4, 3));
    st.insert(make_pair(3, 5));
    st.insert(make_pair(2, 7));
    st.insert(make_pair(6, 7));

    for(auto i : st){
        cout<<i.first<<" ";
    }cout<<endl;

    // auto it = st.find(make_pair(8,7));

    // if (it != st.end()) {
    //     auto res = *it;
    //     cout << res.first << endl;
    //     cout << res.second << endl;
    // } else {
    //     cout << "Pair not found!" << endl;
    // }

    return 0;
}