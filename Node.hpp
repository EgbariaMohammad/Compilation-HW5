//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Node.hpp

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include "hw3_output.hpp"
#define YYSTYPE Node *
#include "cg.hpp"

using namespace std;

class Node
{
    string type;
public:
    Node(const string& type) : type(type) {}
    virtual ~Node();
    const string& getType() const { return type; }
};

class Num : public Node
{
    int val;
public:
    Num(const string& value) : Node("Num"), val(std::atoi(value.c_str())) {}
    int getValue() const { return val; }
};

class myString : public Node
{
    string val;
public:
    myString(const string& val) : Node("STRING"), val(val) {}
    string getStringValue() const { return val; }
};
