/**
* postfix_converter.c
*
* Cheick Ali M. DIALLO
* contact@cheickalimdiallo.com
*
* Converts a basic arithmetic expression from infix to postfix. Operators are (,),/,*,+,- 
* and operands are capital alphabetic characters only.
*/
#include <stdio.h>
#include <string.h>

// Maximum eXpression Length.
#define MAX_XL 1024

short isOperand(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

short isOperator(char c)
{
    if (c == '/' || c == '*' || c == '+' || c == '-')
        return 1;
    else
        return 0;
}

short isParenthesis(char c, short left)
{
    if (left)
    {
        if (c == '(')
            return 1;
        else
            return 0;
    }
    else
    {
        if (c == ')')
            return 1;
        else
            return 0;
    }
}

short precedence(char cc)
{
    short value = 0;

    switch (cc)
    {
        case '/':
            value = 4;
            break;
        case '*':
            value = 3;
            break;
        case '+':
            value = 2;
            break;
        case '-':
            value = 1;
            break;
        default:
            value = -1;
            break;
    }

    return value;
}

void toPostfix(char in[], char out[])
{
    // Stack to hold operators.
    char opstack[MAX_XL / 2];

    short in_len = strlen(in);
    char cc;
    short j, k;
    j = -1;
    k = -1;

    // Scan the expression from left to right.
    for (short i = 0; i < in_len; ++i)
    {
        cc = in[i];

        // If character is an operand then
        if (isOperand(cc))
        {
            // Append it to the end of the output list.
            out[++j] = cc;
        }
        else
        {
            // If the character is a left parenthesis,
            if (isParenthesis(cc, 1))
            {
                // Push it on the stack of operators.
                opstack[++k] = cc;
                continue;
            }
            
            // If the character is a right parenthesis,
            if (isParenthesis(cc, 0))
            {
                // Pop the stack of operators until the corresponding left parenthesis is removed.
                while ((out[++j] = opstack[k--]) != '(');
                --j;
                continue;
            }

            // If the character is an operator, push it to the stack of operators after moving all operators with
            // precedence >= to the end of the output list.
            if (isOperator(cc))
            {
                char op;
                while (k >= 0 && (precedence(op = opstack[k]) > precedence(cc)))
                {
                    out[++j] = op;
                    --k;
                }
                opstack[++k] = cc;
            }
        }
    }
    
    if (k > -1)
        while (k > -1)
            out[++j] = opstack[k--];
    out[++j] = '\0';
}

int main(void)
{
    char arex[MAX_XL], output[MAX_XL];
    printf("Enter infix expression: ");
    fgets(arex, MAX_XL, stdin);
    toPostfix(arex, output);
    printf("%s\n", output);
}