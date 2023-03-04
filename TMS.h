#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;

class login
{
    char id[100];
    char pass[100];
    char password[10];
public:
    char* Id();
    char* Pass();
    char* Password();
    void getid();
    void displayid();
};

class Detail
{
    int date, month, year;
    char trainName[100];
    char boardingPoint[100];
    char destination[100];
    int firstClassSeatFare, secondClassSeatFare;
public:
    int trainNumber;
    int reqSeats_FirstClass, reqSeats_SecondClass;
    int datef() const;
    int monthf() const;
    int TrainNumber();
    int ReqSeats_FirstClass();
    int FirstClassSeatFare();
    int ReqSeats_SecondClass();
    int SecondClassSeatFare();
    char* TrainName();
    char* BoardingPoint();
    char* Destination();
    void setdate();
    void setSeats();
    void trainSpec();
    void getDetail();
    void displaydetail();
};

class reservation :public Detail
{
public:
    int pnr;
    char passengerName[10][100];
    int age[20];
    char travellingClass[10];
    int SeatsRequired;
    int concession;
    float amc;
    int Pnr();
    void getPnr();
    void getReserveDetails();
    void displayReserveDetails();
};

class Cancellation :public reservation
{
public:
    float moneyReturn;
    void getCancelDetails();
    void displayCancelDetails();
};

class train {
    char f[10] = "f";
    char s[10] = "s";
    int addr, ad, flag, f1, date, month, amt;
    float tamt;
public:
    void database();
    void reserve();
    void res();
    void displaypassdetail();
    void enquiry();
    void cancell();
    void can();
    void user();
    void manage();
};