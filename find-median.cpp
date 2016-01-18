/*
 * find-median.cpp
 * Date: 2016-01-18
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>


using namespace std;

using left_cmp = std::less< int >;
using right_cmp = std::greater< int >;

vector< int > left_heap , right_heap;

void insert_left( int v )
{
    left_heap.push_back( v );
    std::push_heap( left_heap.begin() , left_heap.end() , left_cmp() );
}

void insert_right( int v )
{
    right_heap.push_back( v );
    std::push_heap( right_heap.begin() , right_heap.end() , right_cmp() );
}

void pop_left()
{
    std::pop_heap( left_heap.begin() , left_heap.end() , left_cmp() );
    left_heap.pop_back();
}

void pop_right()
{
    std::pop_heap( right_heap.begin() , right_heap.end() , right_cmp() );
    right_heap.pop_back();
}

void balance_left()
{
    assert( left_heap.size() >= right_heap.size() );
    if( left_heap.size() > ( right_heap.size() + 1 ) )
    {
        insert_right( left_heap[0] );
        pop_left();
    }
}

void balance_right()
{
    assert( right_heap.size() >= left_heap.size() );
    if( right_heap.size() > ( left_heap.size() + 1 ) )
    {
        insert_left( right_heap[0] );
        pop_right();
    }
}

double get_median()
{
    if( left_heap.size() == right_heap.size() )
        return 0.5 * double( left_heap[0] + right_heap[0] );
    else
        return left_heap.size() > right_heap.size() ? left_heap[0] : right_heap[0];
}

int main()
{
    int N = 0;
    cin >> N;
 

    
    for( int i=0 ; i<N ; ++i )
    {
        int v;
        cin >> v;
        
        if( i == 0 )
        {
            insert_left( v );
        }
        else 
        {
            if( v > left_heap[0] )
            {
                insert_right( v );
                balance_right();
            }
            else
            {
                insert_left( v );
                balance_left();
            }
        }

        cout << get_median() << endl;
//         cout << "Median: " << get_median() << endl;
//         cout << "Left:";
//         for( size_t i=0 ; i<left_heap.size() ; ++i ) cout << " " << left_heap[i];
//         cout << endl;
//         cout << "Right:";
//         for( size_t i=0 ; i<right_heap.size() ; ++i ) cout << " " << right_heap[i];
//         cout << endl;
        
    }
    
    return 0;
}