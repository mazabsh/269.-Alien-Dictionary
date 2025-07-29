#include<iostream> 
#include<unordered_map> 
#include<vector> 
#include<queue> 

using namespace std; 

class Solution{
public: 
     string alienOrder(vector<string> words){
       string ans; 
       if(words.empty()) return ans; 
       unordered_map<char, int> counts; 
       unordered_map<char, vector<char>> adjList; 

       for(string word: words){
         for(char c:word){
           counts[c]=0; 
           adjList[c] = vector<char> (); 
         }
       }
       for(int i=0; i< words.size()-1; ++i){
         string word1 = words[i]; 
         string word2 = words[i+1]; 
         int m = word1.size(); 
         int n = word2.size(); 
         if(m> n && word1.substr(0, n) == word2) return ""; 
         for(int j=0; j<min(m,n) ; ++j){
           if(word1[j]!=word2[j]){
             counts[word2[j]]++; 
             adjList[word1[j]].push_back(word2[j]); 
             break; 
           }
         }
       }
       queue<char> q; 
       for(auto item: counts){
         if(item.second==0) q.push(item.first);  
       }
       while(!q.empty()){
         char c = q.front(); 
         q.pop(); 
         ans +=c; 
         for(char next: adjList[c]){
           counts[next]--; 
           if(counts[next]==0) q.push(next); 
         }
       }
       if(ans.size() < counts.size()) return ""; 
       return ans; 
       
     }
};
int main(){
  vector<string> words = {"wrt","wrf","er","ett","rftt"}; 
  Solution sol; 
  cout << sol.alienOrder(words) <<endl; 
  return 0; 
}
