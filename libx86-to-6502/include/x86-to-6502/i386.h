#pragma once

#include "asm_line.h"
#include "instruction_operand.h"

enum class i386_opcode
{
    unknown,
    movzbl,
    movzwl,
    shrb,
    shrl,
    xorl,
    andl,
    andb,
    addb,
    ret,
    movb,
    cmpb,
    movl,
    jmp,
    jne,
    je,
    js,
    testb,
    incl,
    incb,
    decl,
    decb,
    sarl,
    addl,
    subl,
    subb,
    sall,
    orl,
    orb,
    rep,
    pushl,
    sbbb,
    negb,
    notb,
    retl,
    calll
};

class i386 : public asm_line
{
public:
    // Empty line
    explicit i386(const int line_number);

    // Comment
    i386(const int line_number, std::string line_text);

    i386(const int line_number, std::string line_text, line_type type, std::string opcode, std::string operand1 = "",
         std::string operand2 = "");

    static auto parse(const std::string &line, const int line_number) -> i386;

    auto line_number() const noexcept
    {
        return line_number_;
    }

    const auto &line_text() const noexcept
    {
        return line_text_;
    }

    auto line_text_unindented() const
    {
        auto text = line_text();
        if (text[0] == '\t')
        {
            text.erase(0, 1);
        }
        return text;
    }

    auto opcode() const noexcept
    {
        return opcode_;
    }

    const auto &operand1() const noexcept
    {
        return operand1_;
    }

    auto &operand1() noexcept
    {
        return operand1_;
    }

    const auto &operand2() const noexcept
    {
        return operand2_;
    }

    auto &operand2() noexcept
    {
        return operand2_;
    }

private:
    int line_number_;
    std::string line_text_;
    i386_opcode opcode_;
    instruction_operand operand1_;
    instruction_operand operand2_;
};
