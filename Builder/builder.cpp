//
// Created by David on 28/10/2021.
//

#include "builder.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

//Some objects may require alot of variables to instantiate it.
//Would be painful for constructor args, so we build piece by piece
//This helps reduce errors in construction
//Builder provides a API for constructing an object step by step.

struct HtmlElement
{
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(const std::string &name, const std::string &text ) : name(name), text() {}

    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indent_size *indent, " ");
        oss << i << "<" << name << ">" << std::endl;
        if(text.size() > 0)
        {
            oss << std::string(indent_size*(indent + 1), " ") << text << std::endl;
        }

        for(const auto &e : elements)
        {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    }
    static HtmlBuilder create(std::string root_name)
    {
        return {root_name};
    }

    //Pointer Variant
//    static std::unique_ptr<HtmlBuilder> build(){
//        return std::make_unique<>();
//    }

};

struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(std::string &root_name)
    {
        root.name = root_name;
    }

    HtmlBuilder& add_child(std::string child_name, std::string child_text)
    {
        //Fluent Interface -> The return is a reference to this HTMLbuilder which allows the
        // chaining ability
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this; // Make a reference to html builder and return a ref to this so we can make builder work.
    }
    //Pointer Variant
    HtmlBuilder* add_child_two(std::string child_name, std::string child_text)
    {
        //Fluent Interface -> The return is a reference to this HTMLbuilder which allows the
        // chaining ability
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this; // Make a reference to html builder and return a ref to this so we can make builder work.
    }

    HtmlElement build(){return root;}

    std::string str() const {return root.str();}

    operator HtmlElement() const {return root};

};


static void builderMain()
{
    HtmlBuilder builder{"ul"};
//    builder.add_child("li", "hello");
//    builder.add_child("li", "hello");
//    builder.add_child("li", "hello");

    builder.add_child("li", "hello").add_child("li", "hello2");
    std::cout << builder.str() << std::endl;

    auto builder2 = HtmlElement::create("ul").add_child("","");
    HtmlElement ele = HtmlElement::create("ul").add_child("","");

    //Pointer Variant
    HtmlBuilder *builder3{"ul"};
    builder3->add_child_two("","")->add_child_two("","");

    //Can force the user to only use the builder if we make the constructors of htmlElement private
    // And use a friend class where the actual builder class can utilise it.

    //Assume htmlelement construcotr is private
    //Correct way to create the build chain.
    //The build function actually returns the HTMLelement that we have built.
    //Otherwise we would just have a HtmlBuilder object.
    HtmlElement::create("ui").add_child("","").build();
}