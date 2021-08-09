
// Generated from /home/fatemeh/Documents/antlr4-delta/runtime/Cpp/demo/TLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TLexer : public antlr4::Lexer {
public:
  enum {
    LPAREN = 1, RPAREN = 2, LBRACE = 3, RBRACE = 4, LBRACK = 5, RBRACK = 6, 
    SEMI = 7, COMMA = 8, DOT = 9, ASSIGN = 10, GT = 11, LT = 12, COLON = 13, 
    EQUAL = 14, LE = 15, GE = 16, NOT_EQUAL = 17, ADD = 18, SUB = 19, MUL = 20, 
    DIV = 21, MOD = 22, NUMBER = 23, DIERESIS = 24, R1 = 25, AND = 26, ANIN = 27, 
    ANOUT = 28, B_AND = 29, B_NOT = 30, B_OR = 31, B_EXOR = 32, BOOL = 33, 
    BRAKE = 34, C_DIS = 35, C_ORI = 36, C_PTP = 37, C_VEL = 38, CASE = 39, 
    CAST_FROM = 40, CAST_TO = 41, CHAR = 42, CIRC_REL = 43, CIRC = 44, CONST = 45, 
    CONTINUE = 46, DELAY = 47, DECL = 48, DEF = 49, DEFAULT = 50, DEFDAT = 51, 
    DEFFCT = 52, DO = 53, ELSE = 54, END = 55, ENDDAT = 56, ENDFCT = 57, 
    ENDFOR = 58, ENDIF = 59, ENDLOOP = 60, ENDSWITCH = 61, ENDWHILE = 62, 
    ENUM = 63, EXIT = 64, EXT = 65, EXTFCT = 66, FALSE = 67, FOR = 68, GLOBAL = 69, 
    GOTO = 70, HALT = 71, IF = 72, IMPORT = 73, INTERRUPT = 74, INT = 75, 
    IS = 76, LIN_REL = 77, LIN = 78, LOOP = 79, MAXIMUM = 80, MINIMUM = 81, 
    NOT = 82, OR = 83, PRIO = 84, PTP_REL = 85, PTP = 86, PUBLIC = 87, REAL = 88, 
    REPEAT = 89, RETURN = 90, SEC = 91, SIGNAL = 92, STRUC = 93, SWITCH = 94, 
    THEN = 95, TO = 96, TRIGGER = 97, TRUE = 98, UNTIL = 99, WAIT = 100, 
    WHEN = 101, WHILE = 102, EXOR = 103, HEADERLINE = 104, WS = 105, NEWLINE = 106, 
    LINE_COMMENT = 107, CHARLITERAL = 108, STRINGLITERAL = 109, FLOATLITERAL = 110, 
    INTLITERAL = 111, IDENTIFIER = 112
  };

  TLexer(antlr4::CharStream *input);
  ~TLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
