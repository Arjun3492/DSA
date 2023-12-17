# Types of Expressions

Expressions in computer science and mathematics are representations of operations, values, and variables. Different types of expressions include infix, prefix, and postfix expressions. Here, we will discuss each type of expression and methods to convert one into another.

## Infix Expressions

An infix expression is a commonly used representation of mathematical and logical expressions. In this notation, operators are placed between operands, and parentheses can be used to control the order of evaluation. For example: `3 + 5 * (2 - 1)`.

## Prefix Expressions (Polish Notation)

In a prefix expression, also known as Polish notation, operators are placed before their operands. This notation eliminates the need for parentheses to indicate the order of operations. For example: `+ 3 * 5 - 2 1`.

## Postfix Expressions (Reverse Polish Notation)

In a postfix expression, also known as Reverse Polish Notation (RPN), operators are placed after their operands. Like prefix notation, it eliminates the need for parentheses. For example: `3 5 2 1 - * +`.

# Converting Between Notations

Infix expressions are the most common mathematical and logical expressions. However, they are not the most efficient for computers to evaluate. Therefore, it is often useful to convert infix expressions to prefix or postfix expressions. This can be done using a stack.

## Infix to Postfix

To convert an infix expression to a postfix expression, we can use the following algorithm:

1. Create an empty stack and an empty string.
2. Scan the infix expression from left to right.
3. If the current character is an operand, append it to the output string.
4. If the current character is an operator, pop all operators from the stack that have equal or higher precedence than the current operator, and append them to the output string. Push the current operator onto the stack.
5. If the current character is an opening parenthesis, push it onto the stack.
6. If the current character is a closing parenthesis, pop all operators from the stack and append them to the output string until an opening parenthesis is encountered. Pop the opening parenthesis from the stack.
7. After the input expression has been scanned, pop all operators from the stack and append them to the output string.
8. Return the output string.

## Infix to Prefix

To convert an infix expression to a prefix expression, we can use the following algorithm:

1. Reverse the infix expression.
2. Scan the reversed expression from left to right.
3. If the current character is an operand, append it to the output string.
4. If the current character is an operator, pop all operators from the stack that have equal or higher precedence than the current operator, and append them to the output string. Push the current operator onto the stack.
5. If the current character is an opening parenthesis, push it onto the stack.
6. If the current character is a closing parenthesis, pop all operators from the stack and append them to the output string until an opening parenthesis is encountered. Pop the opening parenthesis from the stack.
7. After the input expression has been scanned, pop all operators from the stack and append them to the output string.
8. Return the reversed output string.

## Postfix to Infix

To convert a postfix expression to an infix expression, we can use the following algorithm:

1. Create an empty stack.
2. Scan the postfix expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

## Postfix to Prefix

To convert a postfix expression to a prefix expression, we can use the following algorithm:

1. Create an empty stack.
2. Scan the postfix expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

## Prefix to Infix

To convert a prefix expression to an infix expression, we can use the following algorithm:

1. Reverse the prefix expression.
2. Scan the reversed expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

## Prefix to Postfix

To convert a prefix expression to a postfix expression, we can use the following algorithm:

1. Reverse the prefix expression.
2. Scan the reversed expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

# Evaluating Expressions

Once an expression has been converted to postfix or prefix notation, it can be evaluated using a stack.

## Postfix Evaluation

To evaluate a postfix expression, we can use the following algorithm:

1. Create an empty stack.
2. Scan the postfix expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

## Prefix Evaluation

To evaluate a prefix expression, we can use the following algorithm:

1. Reverse the prefix expression.
2. Scan the reversed expression from left to right.
3. If the current character is an operand, push it onto the stack.
4. If the current character is an operator, pop two operands from the stack, and push the result of the operation onto the stack.
5. After the input expression has been scanned, return the top of the stack.

# Summary

In this article, we discussed infix, prefix, and postfix expressions. We also discussed methods to convert between these notations and evaluate expressions in each notation. For more information, see the following resources:
