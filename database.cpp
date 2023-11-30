//database.cpp

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

//function to return a random value in an interval
float rand_int(int a,int b)
{

    float x = a + rand() % (b-a);
    return x/10.0;
}

//gives a random name of property
string name_gen(int i)
{
    if (i==14)
    {
        string str;
        str="GreenView Residency - Boring Road";
        return str;
    }
    
    if (i==15)
    {
        string str;
        str="Riverfront Estates - Kankarbagh";
        return str;
    }
    
    
    if (i==16)
    {
        string str;
        str="Sunshine Towers - Bailey Road";
        return str;
    }
    
    if (i==17)
    {
        string str;
        str="Heritage Heights - Rajendra Nagar";
        return str;
    }
    
    if (i==18)
    {
        string str;
        str="Tranquil Gardens - Patliputra Colony";
        return str;
    }
    
    if (i==19)
    {
        string str;
        str="Blissful Homes - Ashiana Nagar";
        return str;
    }
    
    
    if (i==20)
    {
        string str;
        str="Urban Oasis Apartments - Punaichak";
        return str;
    }
    
    if (i==21)
    {
        string str;
        str="Riverside Retreat - Danapur";
        return str;
    }
    
    if (i==22)
    {
        string str;
        str="Serenity Springs Villas - Phulwari Sharif";
        return str;
    }
    
    if (i==23)
    {
        string str;
        str="Skyline Towers - Kidwaipuri";
        return str;
    }
    
    if (i==24)
    {
        string str;
        str="Emerald Enclave - Anisabad";
        return str;
    }
    
    
    if (i==25)
    {
        string str;
        str="Golden Meadows - Rajvanshi Nagar";
        return str;
    }
    
    if (i==26)
    {
        string str;
        str="Majestic Mansions - Sheikhpura";
        return str;
    }
    
    if (i==27)
    {
        string str;
        str="Pearl Paradise Residences - Gulzarbagh";
        return str;
    }
    
    if (i==28)
    {
        string str;
        str="Harmony Heights - Frazer Road";
        return str;
    }
    
    
    if (i==29)
    {
        string str;
        str="Crescent City Homes - Raja Bazar";
        return str;
    }
    
    if (i==30)
    {
        string str;
        str="Royal Residences - Agam Kuan";
        return str;
    }
    
    if (i==31)
    {
        string str;
        str="Prime Plaza Apartments - Sipara";
        return str;
    }
    
    
    if (i==32)
    {
        string str;
        str="Lotus Gardens - Buddha Colony";
        return str;
    }
    
    if (i==33)
    {
        string str;
        str="Celestial City - Lodipur";
        return str;
    }
    
    
    if (i==34)
    {
        string str;
        str="Velvet Valley Homes - Keshri Nagar";
        return str;
    }
    
    if (i==35)
    {
        string str;
        str="Grandeur Greens - Phulwarisharif";
        return str;
    }
    
    if (i==36)
    {
        string str;
        str="Sapphire Skies Apartments - Kumhrar";
        return str;
    }
    
    if (i==37)
    {
        string str;
        str="Dreamland Towers - Rukanpura";
        return str;
    }
    
    
    if (i==38)
    {
        string str;
        str="Regency Residences - Lodipur";
        return str;
    }
    
    if (i==39)
    {
        string str;
        str="Ivory Heights - Ashok Rajpath";
        return str;
    }
    
    if (i==40)
    {
        string str;
        str="Prestige Parkview - Bakerganj";
        return str;
    }
    
    
    //Default case
    return "Azure Oasis Homes - Bihta";
    
}

//generates a high rating
float high_rate_gen(int i)
{

    if (rand()%2==0)
    return 4.6 + (i%4)/10.0;
    
    return 4.7 - (i%4)/10.0;

}


//generates a mid rating
float mid_rate_gen(int i)
{
    if (rand()%2==0)
    return 3.9 + (i%4)/10.0;
    
    return 3.9 - (i%4)/10.0;
}


//generates a low rating
float low_rate_gen(int i)
{
    if (rand()%2==0)
    return 2.8 + (i%4)/10.0;
    
    return 2.8 - (i%4)/10.0;
}
