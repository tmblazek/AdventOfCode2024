#pragma once
#include "assert.h"
#include <aoc.hpp>

enum parseState_e { eNone,
    eOp,
    eOpen,
    eNumber1,
    eComma,
    eNumber2,
    eClose };
enum Calculator {
    eMul,
    eDoDont

};
enum DoDont {
    eDo,
    eDont
};
 class FSM {
    parseState_e state;
    Calculator op;
    DoDont dodont;
    int strLen;
    int numLen;
    char prevChar;
    int number1, number2;
    bool ex2;
    uint64_t total;

public:
    FSM()
        : state(eNone)
        , strLen(0)
        , numLen(0)
        , total(0)
        , dodont(eDo)
        , ex2(false)
    {
    }
    FSM(bool ex2)
        : state(eNone)
        , strLen(0)
        , numLen(0)
        , total(0)
        , dodont(eDo)
        , ex2(ex2)
    {
    }

    void compute()
    {
        switch (op) {
        case (eMul):
            total += number1 * number2;
            break;
        }
    }
    uint64_t readline(std::string input)
    {
        for (int ii = 0; ii < input.size(); ii++) {
            read(input[ii]);
        }
        return total;
    }
    void read(char c, bool redo = false)
    {
        switch (state) {
        case eNone:
            if (c == 'm' && (!ex2 || (dodont == eDo))) {
                op = eMul;
                proceed(c, false, eOp);
            } else if (c == 'd') {
                op =     eDoDont;
                proceed(c, false, eOp);
            }
            break;
        case eOp:
            switch (prevChar) {
            case 'm':
                if (c == 'u') {
                    proceed(c, true);
                } else {
                    reset(c, redo);
                }
                break;
            case 'u':
                if (c == 'l') {
                    proceed(c, true);
                } else {
                    reset(c, redo);
                }
                break;
            case 'l':
                if (c == '(') {

                    proceed(c, false, eOpen);
                } else
                    reset(c, redo);
                break;
            case 'd':
                if (c == 'o') {
                    proceed(c, true);
                } else
                    reset(c, redo);
                break;

            case 'o':
                if (c == 'n' || c == '(') {
                    proceed(c, true);
                }

                else
                    reset(c, redo);
                break;
            case 'n':
                if (c == '\'') {
                    proceed(c, true);
                } else
                    reset(c, redo);
                break;
            case '\'':
                if (c == 't') {
                    proceed(c, true);
                } else
                    reset(c, redo);
                break;
            case 't':
                if (c == '(') {
                    proceed(c, true);
                } else
                    reset(c, redo);
                break;            
            case '(':
                if (c == ')') {
                    if (strLen==3)
                        dodont = eDo;
                    else
                        dodont = eDont;
                    reset(c, false);
                } else
                    reset(c, redo);
                break;
            }
            break;
        case eOpen:
            if (c >= '0' && c <= '9') {
                number1 = c - '0';
                proceed(c, false, eNumber1);
                numLen = 1;
            } else
                reset(c, redo);
            break;
        case eNumber1:
            if ((numLen < 3) && (c >= '0' && c <= '9')) {
                number1 = number1 * 10 + c - '0';
                numLen++;
                proceed(c, true);
            } else {
                if (c == ',') {
                    proceed(c, false, eComma);
                } else
                    reset(c, redo);
            }
            break;
        case eComma:
            if (c >= '0' && c <= '9') {
                number2 = c - '0';
                proceed(c, false, eNumber2);
                numLen = 1;
            } else
                reset(c, redo);
            break;
        case eNumber2:
            if ((numLen < 3) && (c >= '0' && c <= '9')) {
                number2 = number2 * 10 + c - '0';
                numLen++;
                proceed(c, true);
            } else {
                if (c == ')') {
                    compute();
                    reset(c, false);
                } else
                    reset(c, redo);
            }
            break;
        }
    }
    void reset(char c, bool redo = true)
    {
        state = eNone;
        numLen = 0;
        number1 = 0;
        number2 = 0;
        strLen = 0;
        if (redo)
            read(c, false);
    }
    void proceed(char c, bool remain, parseState_e inState = eNone)
    {
        strLen++;
        prevChar = c;
        if (!remain) {
            state = inState;
        }
    }
};

uint64_t ex1(lines_t line)
{

    FSM fsm;
    return fsm.readline(line[0]);
}

uint64_t ex2(lines_t line)
{
    FSM fsm(true);
    return fsm.readline(line[0]);
}