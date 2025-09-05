
#ifndef parser_H
#define parser_H

#define LINESIZE 40

class parser
{
    
public:
    parser(void);
    bool	loadLine(const char* str, int ntok = 100, const char* delimiters = " \t");
    void	reset(void);
    const char*	getToken(int index) const;  
    int		getTokenAsInt(int index);  
    int		count(void) const;        

    int				getTokenPosition(const char *token) const;         
    static int		getTokenIndex(const char *token, const char *str); 
    int				getTokenIndex(int token) const;    
    int _atoi(const char *str);      
    bool str_to_int(const char *str, int *out_value);          

private:
    // parsers statics
    static const int PARSER_LINE_LEN = LINESIZE;
    static const int PARSER_MAX_TOKENS = 100;
    //int _atoi(const char *str);

    char	_inputStr[PARSER_LINE_LEN];
    char*	_tokens[PARSER_MAX_TOKENS];	
    int		_lastToken;
    int		_currToken;
};


#endif //parser_H
