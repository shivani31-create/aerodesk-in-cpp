#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<algorithm>
#include<map>
using namespace std;

//CUSTOM EXCEPTIONS

class AerodeskException:public exception
{
    protected: string msg;
    public:
        explicit AeroDeskException(const string&m):msg(m){}
        const char*what()const noexcept override{return msg.c_str();}
        }
};

class FlightNotFounfException:public AeroDeskException
{
public:
    explicit FlightNotFoundException(const string&id)
    :AeroDeskException("Flight Not Found: " +id){}
};

class SeatUnavailableException:public AeroDeskException
{
 public:
    explicit SeatUnavailableException(const string&cls)
    :AeroDeskException("No seats available in "+cls +"class."){}
};

class BookingNotFoundException:public AeroDeskException
{
public:
    explicit BookingNotFoundException(const string&id)
    :AeroDeskException("Booking not found: "+id){}
};

class InvalidInputException:public AeroDeskException
{
public:
    explicit InvalidInputException(const string&detail)
    :AeroDeskException("Invalid input: "+detail){}
};
//
//ENUM: Seat Class
//
enum class SeatClass{ECONOMY,BUSINESS,FIRST};

string seatClassToStr(SeatClass sc){
  if(sc==SeatClass::ECONOMY)
    return "Economy";
  if(sc==SeatClass::BUSINESS)
    return "Business";
  return "First";
}

SeatClassstrToSeatClass(const string&s)
{
    if(s=="Economy")
        return SeatClass::ECONOMY;
    if(s=="Business")
        return SeatClass::BUSINESS;
    if(s=="First")
        return SeatClass::FIRST;
    throw InvalidInputException("Unknown seat class" "+s" ". Use Economy/ Business/First")
}
