/*
 * merging-communities.cpp
 * Date: 2016-01-22
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>

using namespace std;

using community = shared_ptr< set< int > >;
using communities = unordered_map< int , community >;

communities init( int N )
{
    communities cc;
    for( int i=0 ; i<N ; ++i )
    {
        cc.insert( make_pair( i + 1 , make_shared< set< int > >() ) );
        cc[i+1]->insert( i + 1 );
    }
    return cc;
}

void print( communities const& cc , int c )
{
    cout << cc.at( c )->size() << endl;
}

void merge( communities& cc , int c1 , int c2 )
{
    auto com1 = cc.at( c1 );
    auto com2 = cc.at( c2 );
    if( com1 != com2 )
    {
        com1->insert( com2->begin() , com2->end() );
        for( auto ind : *com2 )
            cc[ ind ] = com1;
    }
}

int main()
{
    int N = 0 , Q = 0;
    cin >> N >> Q;
    
    communities cc = init( N );
    
    for( int i=0 ; i<Q ; ++i )
    {
        char query;
        cin >> query;
        switch( query )
        {
            case 'Q':
            {
                int c = 0;
                cin >> c;
                print( cc , c );
            }
            break;
            case 'M':
            {
                int c1 = 0 , c2 = 0;
                cin >> c1 >> c2;
                merge( cc , c1 , c2 );
            }
        }
    }

    return 0;
}
