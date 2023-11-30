//rules.cpp

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>


using namespace std;

void instructions()
{
    cout<<endl;
    cout<<"Rules:"<<endl;
    cout<<"------"<<endl;
    cout<<"Example: very clean <ENTER> very affordable <ENTER> -1 <ENTER>"<<endl;
    
    cout<<"1. Our search sysytem works step by step"<<endl;
    cout<<"2. Word -- very -- is our adjective which triggers preference for that feature "<<endl;
    cout<<"3. Valid words are affordable, pet friendly, close to school, crime free, clean, swimming pool, garden "<<endl;
    cout<<"4. Anything irrelevant would be ignored by our search system "<<endl;
    cout<<"5. Type done or -1 in query if you are done"<<endl;
    cout<<"6. If suppose you missed some features, our system will automatically assign least priority to that item"<<endl;
    
    cout<<endl;
}
