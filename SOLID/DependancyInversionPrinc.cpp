//
// Created by David on 28/10/2021.
//

#include "DependancyInversionPrinc.h"
#include <iostream>
#include <vector>
// Specifies the best way to form dependancies between modules.

// 1. High level modules  should not depend on low level modules.
//      They both should depend on abstractions
// 2. Abstractions should not depend on details.
//      Details should depend on abstractions.
// Abstractions -> Interfaces or base classes to be inherited from
// As general as possible.

enum class Relationship
{
    parent,
    child,
    sibling
};


struct Person
{
    std::string name;

};


//LAST PART: To remedy broken dependancy, we make a lower level module that abstracts some functionality away
struct RelationshipBrowser
{
    virtual std::vector<Person> find_all_children_of(const std::string &name) = 0;
};


// Low -level module -> Interacts with data structures, provides functionality/ utility.
//IF anything is changed inside here then the higher level module would be broken. not what we want
// So we use abstraction to ease this.
// We inherit the browser so
struct Relationships : RelationshipBrowser
{

    std::vector<std::tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    //We move functionality from there high level module into the lower part or even lower to abstraction so
    //Its defined lower so it cannot be broken so easily.

    std::vector<Person> find_all_children_of(const std::string &name) override {
        std::vector<Person> result;
        for(auto && [first, rel, second] : relations)
        {
            if(first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

//TO do something with the relationships class we do research and modify after the fact,
//So this is high level
// Not what we want
//struct Research
//{
//    Research( Relationships &relationships)
//    {
//        auto& relations = relationships.relations;
//        for(auto &&[first, rel, second] : relations)
//        {
//            if(first.name == "John" && rel == Relationship::parent)
//            {
//                std::cout << "John has a child called" << second.name << std::endl;
//            }
//        }
//    }
//};


//Now we can just depend on a relationship browser (now a API) -> redirects the dependancy to
// A safer place. Want to have dependancies on Interfaces rather than direct dependancy on a class

struct Research
{
    Research(RelationshipBrowser &browser)
    {
        for(auto &child : browser.find_all_children_of("John"))
        {
            std::cout << "John has a child called " << child.name << std::endl;
        }
    }
};


static void depInvMain()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent,child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
}