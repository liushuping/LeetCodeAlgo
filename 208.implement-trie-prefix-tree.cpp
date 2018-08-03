/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (32.51%)
 * Total Accepted:    124.5K
 * Total Submissions: 382.9K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
class TrieNode {
public:
    TrieNode(): is_end(false) {
        memset(vec, 0, sizeof(vec));
    }

    bool is_end;
    TrieNode* vec[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        destroy(root);
    }

    void destroy(TrieNode* node) {
        for (int i(0); i < 26; ++i)
            if (node->vec[i]) destroy(node->vec[i]);
        delete node;
    }

    void insert(string s) {
        auto node = root;
        for (int i(0); i < s.size(); ++i) {
            char c(s[i]);
            int offset = c - 'a';
            if (!node->vec[offset])
                node->vec[offset] = new TrieNode();

            node = node->vec[offset];
        }

        node->is_end = true;
    }

    bool search(string key) {
        auto node = root;
        for (int i(0); i < key.size(); ++i) {
            if (!node) return false;
            char c(key[i]);
            int offset = c - 'a';
            node = node->vec[offset];
        }

        return !!node && node->is_end;
    }

    bool startsWith(string prefix) {
        auto node = root;
        for (int i(0); i < prefix.size(); ++i) {
            if (!node) return false;
            char c(prefix[i]);
            int offset = c - 'a';
            node = node->vec[offset];
        }

        return !!node;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
