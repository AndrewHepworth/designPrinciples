//
// Created by David on 28/10/2021.
//

#include "InterfaceSegPrinc.h"

struct Document;
struct IMachine
{
    virtual void print(Document &doc) = 0;

    virtual void scan(Document &doc) = 0;

    virtual void fax(Document &doc) = 0;
};

//struct MFP : IMachine
//{
//    void print(Document &doc) override {
//
//    }
//
//    void scan(Document &doc) override {
//
//    }
//
//    void fax(Document &doc) override {
//
//    }
//};
//
//struct Scanner : IMachine
//{
//    void print(Document &doc) override {
//        //Do not want
//    }
//
//    void scan(Document &doc) override {
//        //This is the only implementation we want
//    }
//
//    void fax(Document &doc) override {
//        //Do not want
//    }
//};

struct IPrinter
{
    virtual void print(Document &doc) = 0;

};

struct IScanner
{
    virtual void scan(Document &doc) = 0;

};

struct IFax
{
    virtual void fax(Document &doc) = 0;
};

//These three struct only have to be written once (because of segregation,
// we dont have to redefine everytime we want to implement a machine

//So we can implement a print which can have any of these combos without having
//Redundant methods.
//Like below
struct Printer : IPrinter
{
    void print(Document &doc) override {

    }
};

struct Scanner : IScanner
{
    void scan(Document &doc) override {

    }
};

struct Machine : IPrinter, IScanner {
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

    void print(Document &doc) override {
        printer.print(doc);
    }

    void scan(Document &doc) override {
        scanner.scan(doc);
    }
};

//So we dont have to throw out functions or leave them out of implementation/
// Makes it alot clearers
