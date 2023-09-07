class TrieNode{
    public: 
    char data;
    vector<TrieNode*> children;
    
    TrieNode(char data){
        this->data = data;
    }
    
};

class Trie {
public:
    TrieNode* root = new TrieNode('$');
    Trie() {
        root->data = '$';
    }
    
    void insert(string word) {
        int i = 0;
        int flag;
        TrieNode* tempRoot = root;
        while(i<word.size()){
            flag = 0;
            for(auto child : tempRoot->children){
                if(child->data == word[i]){
                    tempRoot = child;
                    i++;
                    flag=1;
                    break;
                }
            }
            if(flag==1) continue;
            TrieNode* newNode = new TrieNode(word[i]);
            (tempRoot->children).push_back(newNode);
            tempRoot = newNode;
            i++;
        }
        TrieNode* EOW = new TrieNode('/');
        (tempRoot->children).push_back(EOW);
    }
    
    bool search(string word) {
        int i=0;
        int flag;
        TrieNode* tempRoot = root;
         while(i<word.size()){
             flag=0;
             for(auto child : tempRoot->children){
                if(child->data == word[i]){
                    tempRoot = child;
                    i++;
                    flag=1;
                    break;
                }
             }
             if(flag==1) continue;
             return false;
         }
         for(auto child : tempRoot->children){
             if(child->data == '/') return true;
         }
        return false;
    }
    
    bool startsWith(string prefix) {
        int i=0;
        int flag;
        TrieNode* tempRoot = root;
         while(i<prefix.size()){
             flag=0;
             for(auto child : tempRoot->children){
                if(child->data == prefix[i]){
                    tempRoot = child;
                    i++;
                    flag=1;
                    break;
                }
             }
             if(flag==1) continue;
             return false;
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */