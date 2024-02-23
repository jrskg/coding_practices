#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char data){
            this->data = data;
            for(int i = 0; i < 26; i++){
                this->children[i] = NULL;
            }
            this->isTerminal = false;
            this->childCount = 0;
        }
};

class Trie{
    private:
        void insertUtil(TrieNode*root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
                root->childCount += 1;
            }
            insertUtil(child, word.substr(1));
        }

        bool searchUtil(TrieNode* root, string word){
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'a';
            if(root->children[index] != NULL){
               return searchUtil(root->children[index], word.substr(1));
            }
            return false;
        }

        bool startsWithUtil(TrieNode* root, string word){
            if(word.length() == 0){
                return true;
            }

            int index = word[0] - 'a';
            if(root->children[index] != NULL){
               return startsWithUtil(root->children[index], word.substr(1));
            }
            return false;
        }

        void removeUtil(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }
            int index = word[0] - 'a';
            if(root->children[index] != NULL){
                removeUtil(root->children[index], word.substr(1));
            }
        }
    public:
        TrieNode* root;

        Trie(){
            this->root = new TrieNode('\0');
        }

        void insertWord(string word){
            insertUtil(root, word);
        }
        bool searchWord(string word){
            return searchUtil(root, word);
        }
        void removeWord(string word){
            removeUtil(root, word);
        }
        bool startsWith(string prefix){
            return startsWithUtil(root, prefix);
        }
};

string longestCommonPrefix(vector<string> &words){
    string ans = "";
    string firstWord = words[0];
    for(int i = 0; i < firstWord.size(); i++){
        bool match = true;

        for(int j = 1; j < words.size(); j++){
            if(firstWord[i] != words[j][i]){
                match = false;
                break;
            }
        }

        if(match){
            ans.push_back(firstWord[i]);
        }else{
            break;
        }
    }

    return ans;
}

string lcpWithTrie(vector<string> &words){
    Trie *t = new Trie();
    for(int i = 0; i < words.size(); i++){
        t->insertWord(words[i]);
    }

    string firstWord = words[0];
    string ans = "";

    TrieNode* temp = t->root;

    for(int i = 0; i < firstWord.size(); i++){
        char ch = firstWord[i];
        int index = ch - 'a';
        if(temp->childCount == 1){
            ans.push_back(ch);
            temp = temp->children[index];
        }else{
            break;
        }

        if(temp->isTerminal){
            break;
        }
    }

    return ans;
}

int main() {
    // Trie *t = new Trie();
    // t->insertWord("abc");
    // t->insertWord("ram");
    // t->insertWord("suraj");
    // cout<<t->searchWord("suraj")<<endl;
    // t->removeWord("suraj");
    // cout<<t->searchWord("suraj")<<endl;

    vector<string>words;
    words.push_back("coder");
    words.push_back("coding");
    words.push_back("codsen");
    // string lcp = longestCommonPrefix(words);
    string lcp = lcpWithTrie(words);
    cout<<"LCP : "<<lcp<<endl;

    return 0;
}