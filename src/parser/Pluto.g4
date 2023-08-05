grammar Pluto;

function_list
    : funcdef+
    ;

funcdef
    : DEF func_name=Identifier parameters block
    ;


parameters
    : '(' args+=Identifier ')'
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
    : RETURN expressionStatement;

expressionStatement
    :   expression? ';'
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
    : constant                                                                                 #constantDefault
    | functionName=Identifier '(' (argument+=expression (',' argument+=expression)*)? ')'                      #functionCall
    | Identifier                                                                               #columnReference
    | '(' expression ')'                                                                       #parenthesizedExpression
    ;

constant
    :  VAR name = identifier_with_dim '=' constant_vector 
    ;


identifier_with_dim
    : name = Identifier dim = dim_value 
    ;

dim_value
    :  '<' dim_x = INTEGER_VALUE ',' dim_y = INTEGER_VALUE '>'
    ; 

constant_vector
    : '[' (vec+=DECIMAL_DIGITS (',' vec+=DECIMAL_DIGITS)*)? ']'
    ;

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |  DIGIT 
        )*
    ;

VAR
  : 'var';

DEF: 'def';

RETURN: 'return';

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

fragment DECIMAL_DIGITS
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