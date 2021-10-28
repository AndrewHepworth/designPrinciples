//
// Created by David on 28/10/2021.
//

#include "OpenClosed.h"
#include <iostream>
#include <vector>

//O part of SOLID Principles -> Open for extension , closed for modification (open-closed)
enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product {
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter {
    std::vector<Product *> by_color(std::vector<Product*> items, Color color)
    {
        std::vector<Product*> result;
        for(auto& i : items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }
};

template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    std::vector<Product *> filter(std::vector<Product *> items, Specification<Product> &spec) override {
        std::vector<Product*> result;
        for(auto& item : items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    explicit ColorSpecification(Color color) : color(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};

struct  SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(Size size) : size(size) {}

    bool is_satisfied(Product *item) override {
        return item->size == size;
    }
};

template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item) ;
    }
};


static void OpenClosedMain()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product*> items {&apple, &tree, &house};

    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);
    for(auto& item : green_things)
        std::cout << item->name << " Is green \n";
    BetterFilter bf;
    ColorSpecification green(Color::green);

    for(auto& item: bf.filter(items, green))
        std::cout << item->name << " is green!\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    for(auto& item : bf.filter(items, green_and_large))
        std::cout << item->name << " is green and large\n";
}


