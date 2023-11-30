//
//  main.cpp
//  Real Estate Search System
//
//  Created by Soumya Savarn on 28/11/23.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <cmath>
#include <utility>


#include "rules.h"
#include "database.h"


using namespace std;
#define pb push_back


class data{
    
public:
   string name;
   float afford_rate;
   float crime_rate;
   float pet;
   float school;
   float luxury;
    
};

//fuction to check substring
bool is_substr(string sub,string str)
{
    bool f=0;
    int n=str.length();
    int k=sub.length();
    for (int i=0;i<=n-k;i++)
        if (str.substr(i,k)==sub) f=1;
    if (f) return 1;
    else return 0;
}


//Search box text parsing fuction
pair<int,float> parser(string str)
{
    float score=0;
    if (is_substr("very",str) ) score=1;
    if (is_substr("Very",str) ) score=1;
    if (is_substr("VERY",str) ) score=1;
    
    int cas=-1;
    if (is_substr("affordable",str) ) cas=0;
    if (is_substr("Affordable",str) ) cas=0;
    if (is_substr("AFFORDABLE",str) ) cas=0;
    
    if (is_substr("pet-friendly",str) ) cas=2;
    if (is_substr("Pet-Friendly",str) ) cas=2;
    if (is_substr("Pet-friendly",str) ) cas=2;
    if (is_substr("pet friendly",str) ) cas=2;
    if (is_substr("Pet Friendly",str) ) cas=2;
    if (is_substr("Pet friendly",str) ) cas=2;
    if (is_substr("pet",str) ) cas=2;
    if (is_substr("school",str) ) cas=2;


    
    if (is_substr("crime",str) ) cas=1;
    if (is_substr("CRIME",str) ) cas=1;
    if (is_substr("Crime",str) ) cas=1;
    
    if (is_substr("swimming pool",str) ) cas=2;
    if (is_substr("luxury",str) ) cas=2;
    if (is_substr("clean",str) ) cas=2;
    if (is_substr("Clean",str) ) cas=2;
    if (is_substr("CLEAN",str) ) cas=2;
    if (is_substr("Swimming Pool",str) ) cas=2;
    if (is_substr("luxury",str) ) cas=2;
    if (is_substr("sea facinng",str) ) cas=2;
    
    if (is_substr("done",str) ) cas=-2;
    if (is_substr("Done",str) ) cas=-2;
    if (is_substr("DONE",str) ) cas=-2;
    if (is_substr("-1",str) ) cas=-2;
    
    if (cas>=0  ) if (score<1) score=0.5;
    
    pair <int,float> p;
    p.first=cas;
    p.second=score;
    return p;
}

//just an utility function
int level(int x)
{
    if (x==1) return 0;
    if (x>=2 && x<=4) return 1;
    if (x>=5 && x<=13) return 2;
    return -1;
}

//global vector to store the result of traversal algorithm
vector <int> selection;


//Habitat-Hunt travesal algorithm
void dfs(int i,vector <float> q, vector <int> v[])
{
    
    if (i>13)
    {
        selection.pb(i);
        return;
    }
    
    if (i<=13){
        
        if (q[level(i)]==1) {
            dfs(3*i+1,q,v);
        }
        
         else if (q[level(i)]==0.5)
         {
             dfs(3*i+1,q,v);
             dfs(3*i,q,v);
         }
        
         else if (q[level(i)]==0)
         {
             dfs(3*i+1,q,v);
             dfs(3*i,q,v);
             dfs(3*i-1,q,v);
         }
     
    }

}






signed main() {
    
    cout<<endl<<endl;
    cout<<"Habitat Hunt :  Real - Estate Property Search System"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
    
    cout<<"Do you wish to read instructions ? (Y/N)"<<endl;
    char response;
    cin>>response;
    if (response=='Y')
        instructions();
    
    while (1){
        
        //Declaring query vector
        vector <float> q(3,0);
        
        cout<<"Start entering your query: "<<endl;
        
        //Asking query from user and generating query vector accordingly
        while(1)
        {

            string str;
            getline (cin, str);
            
            //getting the result through parsing function
            pair <int,float> p = parser (str);
            
            //Means that the query is irrelevant
            if (p.first==-1) continue;
            //Means that the user is done with input
            if (p.first==-2) break;
            
            //safety check while generating vector
            if (p.first>=0&&p.first<=2)
                
            //storing the result in query vector
            q[p.first]=p.second;
        }
        
        //Testing done till parser function
        
        
        
        //prop means property
        data prop[41];
        
        
        //preparation of database starts here ...
        
        for (int i=14;i<=40;i++)
        {
            prop[i].name = name_gen(i);
        }
        
        //name generation done
        
        for (int i=32;i<=40;i++)
        {
            prop[i].afford_rate = high_rate_gen(i);
        }
        for (int i=23;i<=31;i++)
        {
            prop[i].afford_rate = mid_rate_gen(i);
        }
        for (int i=14;i<=22;i++)
        {
            prop[i].afford_rate = low_rate_gen(i);
        }
        
        //afford_rate done
        
        for (int i=14;i<=16;i++)
        {
            prop[i].crime_rate = low_rate_gen(i);
            prop[i+9].crime_rate = low_rate_gen(i);
            prop[i+18].crime_rate = low_rate_gen(i);
        }
        for (int i=17;i<=19;i++)
        {
            prop[i].crime_rate = mid_rate_gen(i);
            prop[i+9].crime_rate = mid_rate_gen(i);
            prop[i+18].crime_rate = mid_rate_gen(i);
        }
        for (int i=20;i<=22;i++)
        {
            prop[i].crime_rate = high_rate_gen(i);
            prop[i+9].crime_rate = high_rate_gen(i);
            prop[i+18].crime_rate = high_rate_gen(i);
        }

        //crime rate done
        
        for (int i=14;i<=40;i+=3)
        {
            prop[i].luxury = low_rate_gen(i);
            prop[i].school = low_rate_gen(i+rand()%5);
            prop[i].pet = low_rate_gen(i+rand()%7);

        }
        
        for (int i=15;i<=40;i+=3)
        {
            prop[i].luxury = mid_rate_gen(i);
            prop[i].school = mid_rate_gen(i+rand()%5);
            prop[i].pet = mid_rate_gen(i+rand()%7);
        }
        
        for (int i=16;i<=40;i+=3)
        {
            prop[i].luxury = high_rate_gen(i);
            prop[i].school = high_rate_gen(i+rand()%5);
            prop[i].pet = high_rate_gen(i+rand()%7);
        }
        
        //all done
        
        //database generation done
        
        
        //Generating Search Tree
        vector < int > v[41];
        
            for (int i=1;i<=13;i++){
                    v[i].pb(3*i+1);
                    v[i].pb(3*i-1);
                    v[i].pb(3*i);
                    v[3*i].pb(i);
                    v[3*i+1].pb(i);
                    v[3*i-1].pb(i);
            }
                    
        
        
        //Running the search algorithm
          dfs(1,q,v);
        
        
        //Generating results
        for (int i=0;i<selection.size();i++)
        {
            int index=selection[i];
            
            cout<<endl;
            
            //debugging line below
//            cout<<"index: "<<index<<endl<<endl;
            
            
            cout<<prop[index].name<<endl;
            cout<<"Affordability: "<<prop[index].afford_rate<<endl;
            cout<<"Safety Rating: "<<prop[index].crime_rate<<endl;
            cout<<"Pet Friendly / Cleanliness: "<<prop[index].pet<<endl;
            cout<<"Close to school: "<<prop[index].school<<endl;
            cout<<"Overall Luxury: "<<prop[index].luxury<<endl;
            cout<<"--------------------------"<<endl;
            cout<<endl;

        }
        
        
        
        //cache memory clear after result generation
        selection.clear();
        
        cout<<"Do you wish to continue? (Y/N)"<<endl;
        char c;
        cin>>c;
        if (c=='N') break;
        
    }
    
    cout<<"THANK YOU !"<<endl;
    cout<<endl;
        
    
    
    return 0;
}



/*Soumya Savarn
 220150031
 DSAI
 */
