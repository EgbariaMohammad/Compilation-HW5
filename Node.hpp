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
public:
    string type;
    Node(const string& type) : type(type) {}
    virtual ~Node();
    virtual int getValue() cosnt = 0;
};

class Num : public Node
{
    int val;
public:
    Num(const string& val) : Node("Num"), val(atoi(val)) {}
    int getValue() const override { return val; }
};

class myString : public Node
{
    string val;
public:
    myString(const string& val) : Node("STRING"), val(val) {}
    string getValue() const override { return val; }
};
