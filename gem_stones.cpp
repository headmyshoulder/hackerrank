/*
 * gem_stones.cpp
 * Date: 2014-08-25
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 *
 */


#include <iostream>
#include <algorithm>

using namespace std;

class gem_counter
{
public:
    
    void add( std::string rock )
    {
        sort( rock.begin() , rock.end() );
        auto end = std::unique( rock.begin() , rock.end() );
        if( first )
        {
            m_gems.assign( rock.begin() , end );
            first = false;
            return;
        }
        std::string new_gems;
        std::set_intersection( rock.begin() , end ,
                               m_gems.begin() , m_gems.end() ,
                               back_inserter( new_gems ) );
        m_gems = std::move( new_gems );

    }
    
    std::string const& gems() const { return m_gems; }
    
private:
    bool first = true;
    std::string m_gems;
};


int main( int argc , char *argv[] )
{
    size_t number_of_rocks;
    cin >> number_of_rocks;
    gem_counter gems;
    for( size_t i=0 ; i<number_of_rocks ; ++i )
    {
        std::string rock;
        cin >> rock;
        gems.add( rock );
    }

    cout << gems.gems().size() << endl;
    return 0;
}

//     gem_counter gems;
//     gems.add( "abcdde" );
//     gems.add( "baccd" );
//     gems.add( "eeabg" );
//     cout << gems.gems() << endl;
