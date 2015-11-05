#include <iostream>
#include <string>
#include <vector>
#include "crimen.h"
#include "fecha.h"
#include "conjunto.h"

using namespace std;

typedef crimen entrada;
typedef unsigned int size_type;

conjunto::conjunto( )
{
    
}

conjunto::conjunto (const conjunto & d) 
{
    
}

pair<conjunto::entrada,bool> conjunto::find( const long int & id) const
{
    crimen c;
    return make_pair(c,true);
}

conjunto conjunto::findIUCR( const string & iucr) const
{
    conjunto c;
    for(int i = 0; (unsigned)i<this->vc.size(); i++){
        if(vc.at(i).getIUCR() == iucr){
            c.insert(vc.at(i));
        }
    }
    return c;
}

conjunto conjunto::findDESCR( const string & descr) const
{
    conjunto c;
    for(int i = 0; (unsigned)i<this->vc.size(); i++){
        if(vc.at(i).getDescription() == descr){
            c.insert(vc.at(i));
        }
    }
    return c;
}

bool conjunto::insert( const conjunto::entrada & e)
{
    
}

bool conjunto::erase(const long int & id)
{
    
}

bool conjunto::erase(const  conjunto::entrada & e)
{
    
}

conjunto & conjunto::operator=( const conjunto & org)
{
    
}

size_type conjunto::size() const
{
    return this->vc.size();
}

bool conjunto::empty() const
{
    return (this->size() == 0);
}

bool conjunto::cheq_rep( ) const
{
    
}

ostream & operator << ( ostream & sal, const conjunto & D)
{
    
}