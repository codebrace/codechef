#include<bits/stdc++.h>//this includes all headers at once

using namespace std;
unordered_set<int> sfi;//making a hashset to store ids of all special friends
/*
 when we search an element using find(element) function, 
  if
    it is found then returns iterator(same as pointer) to that element.
 else
    it returns end of container , which here is sfi 
*/
bool comp(pair<pair<int,int>,string>&post1,pair<pair<int,int>,string>&post2){
    /*
          comparision function comp(a,b) asks if a should come before b in sorted.
         if it returns true then it puts a before b
         else it puts b before a
    */

    if(sfi.find(post1.first.first)!=sfi.end()){
       // if author of first post is in special friend list

        if(sfi.find(post2.first.first)!=sfi.end()){
         // if author of second post is also in special friend list

         //now comparision happens on the basis of popularity, which is second of first in post((authorid,popularity),stringcontent)
        
             return post1.first.second>post2.first.second;
              //here condition means post1 will come before post2 only when popularity of post1 is more 
        }
        else{
            //if author of first is special and author of second is not special so post1 will come before post2
            return true ;
        }
    }
    if(sfi.find(post2.first.first)!=sfi.end()){
     // if author of second post is in special friend list
        if(sfi.find(post1.first.first)!=sfi.end()){
         // if author of first post is in special friend list

            return post1.first.second>post2.first.second;
          //here condition means post1 will come before post2 only when popularity of post1 is more 
     
    }
        else{
          //if author of second is special and author of first is not special so post2 will come before post1
           return false;
        }
    }
    // if no author is special then it depend on popularity
    return post1.first.second>post2.first.second;
}
int main()
{
 
 int n,m;
 cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
       cin>>temp;
        sfi.insert(temp);
    }
 
 vector<pair<pair<int,int>,string>>posts;  // post((authorid,popularity),stringcontent)
    int f,p;
    string s;
    for(int i=0;i<m;i++){
        cin>>f;cin>>p;cin>>s;
        posts.push_back(make_pair(make_pair(f,p),s));
    }
    sort(posts.begin(),posts.end(),comp);
    for(int i=0;i<posts.size();i++)
     cout<<posts[i].second<<endl;
 
 
}