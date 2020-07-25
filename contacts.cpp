#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define CHAR_SIZE 26

class Trie
{
public:
    bool isEndOfWord;
    Trie* character[CHAR_SIZE];
    int words;
    Trie()
    {
        this->isEndOfWord = false;

        for (int i = 0; i < CHAR_SIZE; i++){
            this->character[i] = nullptr;
        }
        this->words = 0;
            
    }

    void insert(char* key);
    Trie* search(char* key);
    int countWords();
};


void Trie::insert(char* key)
{

    Trie* curr = this;
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (curr->character[key[i]-'a'] == nullptr){
            curr->character[key[i]-'a'] = new Trie();
        }

        curr = curr->character[key[i]-'a'];
        curr->words = curr->words + 1;
    }

    curr->isEndOfWord = true;
}

Trie* Trie::search(char* key)
{
    if (this == nullptr)
        return nullptr;

    Trie* curr = this;
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {	
        curr = curr->character[key[i]-'a'];
        if (curr == nullptr)
            return nullptr;
    }

    return curr;
}

int Trie::countWords()
{    
    if (!this) return 0;
    
    return this->words;
}


int main()
{
    int n, res;
    char cmd[35], name[35];

    scanf("%d\n",&n);
    
    Trie* head = new Trie();
    Trie* res_trie;
    
    for (int i=0;i<n;i++)
    {
    
    	scanf("%s %s\n",cmd, name);
    	
    	if (!strcmp("add",cmd))
    	{
    		head->insert(name);	
    	}	
    	else
    	{
		    res_trie = head->search(name);
		    res = res_trie->countWords();
            printf("%d\n",res);
        }
    }

    return 0;
}
