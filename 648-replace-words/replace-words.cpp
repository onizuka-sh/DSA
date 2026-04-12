class Solution {
public:

    struct trieNode {
        trieNode* children[26];
        bool eow;
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->eow = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    void insert(string word) {
        trieNode* crawler = root;

        for (char c : word) {
            int idx = c - 'a';

            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }

        crawler->eow = true;
    }

    string search(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (crawler->children[idx] == NULL) {
                return word;
            }

            crawler = crawler->children[idx];

            if (crawler->eow) {
                return word.substr(0, i + 1);
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = getNode();

        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;

        while (ss >> word) {
            result += search(word) + " ";
        }

        result.pop_back();  // remove the last added space
        return result;
    }
};