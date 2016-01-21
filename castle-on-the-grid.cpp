/*
 * castle-on-the-grid.cpp
 * Date: 2016-01-20
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <queue>
#include <deque>
#include <unordered_set>

using namespace std;

struct point { int x ; int y ; };

using container_type = deque< point >;
using grid_type = vector< bool >;

inline bool operator==( point const& p1 , point const& p2 ) { return ( ( p1.x == p2.x ) && ( p1.y == p2.y ) ); }

inline std::ostream& operator<<( std::ostream& out , point const& p )
{
    out << p.x << " " << p.y;
    return out;
}

int index( point const& p , int N )
{
    return p.y * N + p.x;
}


bool grid_value( grid_type const& grid , point const& p , int N )
{
    return grid[ index( p , N ) ];
}


bool add_upwards_moves( grid_type const& grid , container_type& next , point current , point const& goal , int N , unordered_set< int > const& visited )
{
    current.y --;
    for( ; current.y >= 0 ; --( current.y ) )
    {
        if( grid_value( grid , current , N ) == false ) break;
        if( visited.count( index( current , N ) ) ) continue;
        if( current == goal ) return true;
        next.push_back( current );
    }
    return false;
}

bool add_downwards_moves( grid_type const& grid , container_type& next , point current , point const& goal , int N , unordered_set< int > const& visited )
{
    ( current.y ) ++;
    for( ; current.y < N ; ++( current.y ) )
    {
        if( grid_value( grid , current , N ) == false ) break;
        if( visited.count( index( current , N ) ) ) continue;
        if( current == goal ) return true;
        next.push_back( current );
    }
    return false;
}

bool add_left_moves( grid_type const& grid , container_type& next , point current , point const& goal , int N , unordered_set< int > const& visited )
{
    current.x --;
    for( ; current.x >= 0 ; --( current.x ) )
    {
        if( grid_value( grid , current , N ) == false ) break;
        if( visited.count( index( current , N ) ) ) continue;
        if( current == goal ) return true;
        next.push_back( current );
    }
    return false;
}

bool add_right_moves( grid_type const& grid , container_type& next , point current , point const& goal , int N , unordered_set< int > const& visited )
{
    ( current.x ) ++;
    for( ; current.x < N ; ++( current.x ) )
    {
        if( grid_value( grid , current , N ) == false ) break;
        if( visited.count( index( current , N ) ) ) continue;
        if( current == goal ) return true;
        next.push_back( current );
    }
    return false;
}


int main( int argc , char *argv[] )
{
    int N = 0;
    cin >> N;
    grid_type grid( N*N , true );
    for( int i=0 ; i<N ; ++i )
    {
        for( int j=0 ; j<N ; ++j )
        {
            char current;
            cin >> current;
            if( current == 'X' ) grid[i*N+j] = false;
        }
    }
    point start , goal;
    cin >> start.y >> start.x >> goal.y >> goal.x;
    
//     cout << "Grid: " << endl;
//     for( int i=0 ; i<N ; ++i )
//     {
//         for( int j=0 ; j<N ; ++j )
//             cout << ( grid[i*N+j] ? '.' : 'X' );
//         cout << endl;
//     }
// 
//     
//     cout << endl << endl;
//     cout << "Start: " << start << endl;
//     cout << "Goal:  " << goal << endl;
    
    container_type current;
    current.push_back( start );
    
    unordered_set< int > visited;
    
    
    if( goal == start ) { cout << 0 << endl; return 0; }
    int count = 1;
    while( true )
    {
        container_type next;
        while( ! current.empty() )
        {
            point c = current.front();
            // cout << "Iteration " << count << ": " << c << endl;
            current.pop_front();
            visited.insert( index( c , N ) );
            if( add_upwards_moves( grid , next , c , goal , N , visited ) ) { cout << count << endl; return 0; }
            if( add_downwards_moves( grid , next , c , goal , N , visited ) ) { cout << count << endl; return 0; }
            if( add_left_moves( grid , next , c , goal , N , visited ) ) { cout << count << endl; return 0; }
            if( add_right_moves( grid , next , c , goal , N , visited ) ) { cout << count << endl; return 0; }
        }
        cout << count << " " << next.size() << " " << current.size() << endl;
        current = std::move( next );
        ++count;
        if( count == 100 ) break;
    }

    
    return 0;
}
