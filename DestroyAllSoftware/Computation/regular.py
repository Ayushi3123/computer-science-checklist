# Chomsky Hierarchy
#   Regular languages
#       Regular expressions
#       Regular grammars
#       Finite state machines
#   ...
#   ...
#   Turing-equivalent (CPUs, TM, LC)

import re

# regex
RE = r"""
    (
        [123]
        [+*]
    )*
    [123]
"""


def recognize(s):
    return bool(re.match("^" + RE + "$", s, re.VERBOSE))


print(recognize("1"))
print(recognize("1+1"))
print(recognize("1*1"))
print(recognize("1*1+1"))
print(recognize("3*2+1"))
print("---")
print(recognize("3*2+z"))
print(recognize("3*2+"))
print(recognize("*2+1"))

# regular grammar
# right regular grammar
# RULE1 = '1' (rule equals literal)
# RULE1 = '1' RULE2 (rule equals literal and another rule
r"""
    EXPR = '1'
    EXPR = '2'
    EXPR = '3'
    EXPR = '1' OP_EXPR
    EXPR = '2' OP_EXPR
    EXPR = '3' OP_EXPR
    OP_EXPR = '+' EXPR
    OP_EXPR = '*' EXPR
"""

# example of "3*2+1"
# EXPR -- always start with EXPR
# '3' OP_EXPR
# '3' '*' EXPR
# '3' '*' '2' OP_EXPR
# '3' '*' '2' '+' EXPR
# '3' '*' '2' '+' '1'


# finite state machine
# Ken Thompson
# Thompsons Construction (regex -> finite state machine)
# https://en.wikipedia.org/wiki/Thompson%27s_construction
