#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of documents: ";
    cin >> n;

    vector<string> docs(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter document " << i << ": ";
        cin >> ws;
        getline(cin, docs[i]);
    }

    vector<vector<string>> words(n);
    set<string> stop = {"the", "is", "and"};
    set<string> vocabulary;

    for (int i = 0; i < n; i++) {
        string word = "";

        for (int j = 0; j <= docs[i].size(); j++) {
            if (j == docs[i].size() || docs[i][j] == ' ') {

                for (char &c : word)
                    c = tolower(c);

                if (word != "" && stop.count(word) == 0) {
                    words[i].push_back(word);
                    vocabulary.insert(word);
                }

                word = "";
            }
            else {
                word += docs[i][j];
            }
        }
    }
    vector<string>vocab;

    for (string word : vocabulary)
        vocab.push_back(word);

    map<string, int> index;

    for (int i = 0; i < vocab.size(); i++)
        index[vocab[i]] = i;

    int m = vocab.size();

    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        for (string word : words[j]) {
            matrix[index[word]][j]++;
        }
    }

    cout << "\nWord Document Matrix\n";
    cout << "Word\t";

    for (int j = 0; j < n; j++)
        cout << "D" << j << "\t";

    cout << "\n";

    for (int i = 0; i < m; i++) {
        cout << vocab[i] << "\t";

        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";

        cout << "\n";
    }

    string query;
    cout << "\nEnter query";
    cin >> ws;
    getline(cin, query);

    for (char &c : query)
        c = tolower(c);

    vector<string> q;
    string word = "";

    for (int i = 0; i <= query.size(); i++) {
        if (i == query.size() || query[i] == ' ') {
            if (word != "")
                q.push_back(word);

            word = "";
        }
        else {
            word += query[i];
        }
    }

    vector<vector<int>> queryMat;
    vector<string> queryWords;

    for (string term : q) {
    

        queryWords.push_back(term);
        vector<int> row(n, 0);

        if (index.count(term)) {
            int r = index[term];

            for (int j = 0; j < n; j++) {
                if (matrix[r][j] > 0)
                    row[j] = 1;
            }
        }

        queryMat.push_back(row);
    }

    cout << "\nQuery Matrix\n";
    cout << "Word\t";

    for (int j = 0; j < n; j++)
        cout << "D" << j << "\t";

    cout << "\n";

    for (int i = 0; i < queryWords.size(); i++) {
        cout << queryWords[i] << "\t";

        for (int j = 0; j < n; j++)
            cout << queryMat[i][j] << "\t";

        cout << "\n";
    }

   
    
    return 0;
}