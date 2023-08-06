grammar Pluto;

function_list
    : funcdef* EOF
    ;

funcdef
    : func_dec block
    ;

func_dec
    : 'def' func_name=Identifier parameters
    ;

parameters
    : '(' (argument+=Identifier (',' argument+=Identifier)*)? ')'
    ;

block
    : '{' blockItemList return_stmt? '}'
    ; 

blockItemList
    :   blockItem*
    ;

blockItem
    :  expressionStatement 
    ;

return_stmt
    : 'return' expression ';';

expressionStatement
    :   'var' name=Identifier '=' expression ';'  #normal_var_decl
    |   'var' name = Identifier dim = dim_value '=' expression ';' #constant_var_decl
    ;

expression
    :   valueExpression
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