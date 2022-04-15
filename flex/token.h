typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_ID,
    TOKEN_NUMBER,
    BASIC_END,
} basic_t;
typedef enum
{
    TOKEN_DEF = BASIC_END,
    TOKEN_CLASS,
    TOKEN_INT,
    TOKEN_STRING,
    KEYWORD_END
} keywords_t;
typedef enum
{
    TOKEN_EQ = KEYWORD_END,
    TOKEN_ADD,
    TOKEN_DQUOTE,
    TOKEN_SEMI,
    TOKEN_COMMA,
    TOKEN_COLON,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_LANGLE,
    TOKEN_RANGLE,
} op_t;
enum
{
    TOKEN_ERROR = 999,
};