grammar Pluto;

function_list
    : funcdef* EOF
    ;

funcdef
    : func_dec parameters block
    ;

func_dec
    : 'def' func_name=Identifier
    ;

parameters
    : '(' (argument+=expression (',' argument+=expression)*)? ')'
    ;

block
    : '{' blockItemList return_stmt? '}'
    ; 

blockItemList
    :   blockItem
    ;

blockItem
    :  expressionStatement* 
    ;

return_stmt
    : 'return' expression ';';

expressionStatement
    :   'var' name=Identifier '=' expression ';'
    |   'var' identifier_with_dim '=' expression ';'
    ;

expression
    :   valueExpression
    |   valueExpression
    ;

valueExpression
    : primaryExpression                                                                      #valueExpressionDefault
    | left=valueExpression operator=(ASTERISK | SLASH | PERCENT) right=valueExpression #arithmeticBinary
    | left=valueExpression operator=(PLUS | MINUS) right=valueExpression       #arithmeticBinary
    ;

primaryExpression
    : constant_vector                                                                                 #constantDefault
    | functionName=Identifier '(' (argument+=expression (',' argument+=expression)*)? ')'                      #functionCall
    | Identifier                                                                               #columnReference
    | '(' expression ')'                                                                       #parenthesizedExpression
    ;

identifier_with_dim
    : name = Identifier dim = dim_value 
    ;

dim_value
    :  '<' dim_x = INTEGER_VALUE ',' dim_y = INTEGER_VALUE '>'
    ; 

constant_vector
    : '[' (vec+=(INTEGER_VALUE|DECIMAL_DIGITS) (',' vec+=(INTEGER_VALUE | DECIMAL_DIGITS))*)? ']'
    ;

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |  DIGIT 
        )*
    ;

PLUS: '+';
MINUS: '-';
ASTERISK: '*';
SLASH: '/';
PERCENT: '%';
TILDE: '~';
AMPERSAND: '&';
PIPE: '|';
HAT: '^';



INTEGER_VALUE
    : DIGIT+
    ;

DECIMAL_DIGITS
    : DIGIT+ '.' DIGIT*
    | '.' DIGIT+
    ;

fragment DIGIT
    : [0-9]
    ;

fragment IdentifierNondigit
    :   Nondigit
    ;

fragment Nondigit
    :   [a-zA-Z_]
    ;

SIMPLE_COMMENT
    : '--' ('\\\n' | ~[\r\n])* '\r'? '\n'? -> channel(HIDDEN)
    ;

BRACKETED_EMPTY_COMMENT
    : '/**/' -> channel(HIDDEN)
    ;

BRACKETED_COMMENT
    : '/*' ~[+] .*? '*/' -> channel(HIDDEN)
    ;

WS
    : [ \r\n\t]+ -> channel(HIDDEN)
    ;

UNRECOGNIZED
    : .
    ;