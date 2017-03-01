# THE FINER POINTS OF C :|: PREPROCSESOR WIZARDRY
### Corresponding C source: "preprocessor.c"

(I'm just going to copy the C standard, 'cause I can't write it better myself.)

## A.12 Preprocessing
A preprocessor performs macro substitution, conditional compilation, and inclusion of named files.
Lines beginning with `#`, perhaps preceded by white space, communicate with this preprocessor.
The syntax of these lines is independent of the rest of the language; they may appear anywhere and
have effect that lasts (independent of scope) until the end of the translation unit. Line boundaries
are significant; each line is analyzed individually (bus see Par.A.12.2 for how to adjoin lines).
To the preprocessor, a token is any language token, or a
character sequence giving a file name as in the `#include directive` (Par.A.12.4); in
addition, any character not otherwise defined is taken as a token. However, the effect of
white spaces other than space and horizontal tab is undefined within preprocessor lines.
Preprocessing itself takes place in several logically successive phases that may, in a
particular implementation, be condensed.

1. First, trigraph sequences as described in Par.A.12.1 are replaced by their
equivalents. Should the operating system environment require it, newline characters
are introduced between the lines of the source file.

2. Each occurrence of a backslash character \ followed by a newline is deleted, this
splicing lines (Par.A.12.2).

3. The program is split into tokens separated by white-space characters; comments are
replaced by a single space. Then preprocessing directives are obeyed, and macros
(Pars.A.12.3-A.12.10) are expanded.

4. Escape sequences in character constants and string literals (Pars. A.2.5.2, A.2.6) are
replaced by their equivalents; then adjacent string literals are concatenated.

5. The result is translated, then linked together with other programs and libraries, by
collecting the necessary programs and data, and connecting external functions and
object references to their definitions.

### A.12.1 Trigraph Sequences
The character set of C source programs is contained within seven-bit ASCII, but is a
superset of the ISO 646-1983 Invariant Code Set. In order to enable programs to be
represented in the reduced set, all occurrences of the following trigraph sequences are
replaced by the corresponding single character. This replacement occurs before any other
processing.

     ??= # ??( [ ??< {
     ??/ \ ??) ] ??> }
     ??' ^ ??! | ??- ~

No other such replacements occur.<br>
Trigraph sequences are new with the ANSI standard.

### A.12.2 Line Splicing
Lines that end with the backslash character \ are folded by deleting the backslash and the
following newline character. This occurs before division into tokens.

### A.12.3 Macro Definition and Expansion
A control line of the form

     # define identifier token-sequence

causes the preprocessor to replace subsequent instances of the identifier with the given
sequence of tokens; leading and trailing white space around the token sequence is
discarded. A second #define for the same identifier is erroneous unless the second token
sequence is identical to the first, where all white space separations are taken to be
equivalent.

A line of the form

     # define identifier (identifier-list) token-sequence

where there is no space between the first identifier and the (, is a macro definition with
parameters given by the identifier list. As with the first form, leading and trailing white
space arround the token sequence is discarded, and the macro may be redefined only with a
definition in which the number and spelling of parameters, and the token sequence, is
identical.

A control line of the form

     # undef identifier

causes the identifier's preprocessor definition to be forgotten. It is not erroneous to apply
`#undef` to an unknown identifier.

When a macro has been defined in the second form, subsequent textual instances of the
macro identifier followed by optional white space, and then by `(`, a sequence of tokens
separated by commas, and a `)` constitute a call of the macro. The arguments of the call are
the comma-separated token sequences; commas that are quoted or protected by nested
parentheses do not separate arguments. During collection, arguments are not macroexpanded.
The number of arguments in the call must match the number of parameters in the
definition. After the arguments are isolated, leading and trailing white space is removed
from them. Then the token sequence resulting from each argument is substituted for each
unquoted occurrence of the corresponding parameter's identifier in the replacement token
sequence of the macro. Unless the parameter in the replacement sequence is preceded by `#`,
or preceded or followed by `##`, the argument tokens are examined for macro calls, and
expanded as necessary, just before insertion.

Two special operators influence the replacement process. First, if an occurrence of a
parameter in the replacement token sequence is immediately preceded by `#`, string quotes
(") are placed around the corresponding parameter, and then both the `#` and the parameter
identifier are replaced by the quoted argument. A \ character is inserted before each " or \
character that appears surrounding, or inside, a string literal or character constant in the
argument.

Second, if the definition token sequence for either kind of macro contains a `##` operator,
then just after replacement of the parameters, each `##` is deleted, together with any white
space on either side, so as to concatenate the adjacent tokens and form a new token. The
effect is undefined if invalid tokens are produced, or if the result depends on the order of
processing of the `##` operators. Also, `##` may not appear at the beginning or end of a
replacement token sequence.

In both kinds of macro, the replacement token sequence is repeatedly rescanned for more
defined identifiers. However, once a given identifier has been replaced in a given
expansion, it is not replaced if it turns up again during rescanning; instead it is left
unchanged.

Even if the final value of a macro expansion begins with with `#`, it is not taken to be a
preprocessing directive.

The details of the macro-expansion process are described more precisely in the ANSI standard
than in the first edition. The most important change is the addition of the # and ## operators,
which make quotation and concatenation admissible. Some of the new rules, especially those
involving concatenation, are bizarre. (See example below.)

For example, this facility may be used for 'manifest-constants,' as in

    #define TABSIZE 100
    int table[TABSIZE];

The definition

    #define ABSDIFF(a, b) ((a)>(b) ? (a)-(b) : (b)-(a))

defines a macro to return the absolute value of the difference between its arguments. Unlike
a function to do the same thing, the arguments and returned value may have any arithmetic
type or even be pointers. Also, the arguments, which might have side effects, are evaluated
twice, once for the test and once to produce the value.

Given the definition

    #define tempfile(dir) #dir "%s"

the macro call `tempfile(/usr/tmp)` yields

    "/usr/tmp" "%s"

which will subsequently be catenated into a single string. After

    #define cat(x, y) x ## y

the call `cat(var, 123)` yields var123. However, the call `cat(cat(1,2),3)` is
undefined: the presence of `##` prevents the arguments of the outer call from being
expanded. Thus it produces the token string

 `cat ( 1 , 2 )3`

and `)3` (the catenation of the last token of the first argument with the first token of the
second) is not a legal token. If a second level of macro definition is introduced,

    #define xcat(x, y) cat(x,y)

things work more smoothly; `xcat(xcat(1, 2), 3)` does produce `123`, because the
expansion of `xcat` itself does not involve the `##` operator.

Likewise, `ABSDIFF(ABSDIFF(a,b),c)` produces the expected, fully-expanded result.

### A.12.4 File Inclusion

A control line of the form

    # include <filename>

causes the replacement of that line by the entire contents of the file filename. The characters
in the name filename must not include > or newline, and the effect is undefined if it
contains any of ", ', \, or /*. The named file is searched for in a sequence of
implementation-defined places.

Similarly, a control line of the form

    # include "filename"

searches first in association with the original source file (a deliberately implementationdependent
phrase), and if that search fails, then as in the first form. The effect of using ', \,
or /* in the filename remains undefined, but > is permitted.

Finally, a directive of the form

    # include token-sequence

not matching one of the previous forms is interpreted by expanding the token sequence as
for normal text; one of the two forms with `<...>` or `"..."` must result, and is then
treated as previously described.
`#include` files may be nested.

### A.12.5 Conditional Compilation

Parts of a program may be compiled conditionally, according to the following schematic
syntax.

     preprocessor-conditional:
     if-line text elif-parts else-partopt #endif
     if-line:
     # if constant-expression
     # ifdef identifier
     # ifndef identifier
     elif-parts:
     elif-line text
     elif-partsopt
     elif-line:
     # elif constant-expression
     else-part:
     else-line text
     else-line:
     #else

Each of the directives `(if-line, elif-line, else-line, and #endif)` appears alone on a line. The
constant expressions in `#if` and subsequent `#elif` lines are evaluated in order until an
expression with a non-zero value is found; text following a line with a zero value is
discarded. The text following the successful directive line is treated normally. ''Text'' here
refers to any material, including preprocessor lines, that is not part of the conditional
structure; it may be empty. Once a successful `#if` or `#elif` line has been found and its
text processed, succeeding `#elif` and `#else` lines, together with their text, are discarded.
If all the expressions are zero, and there is an `#else`, the text following the `#else` is
treated normally. Text controlled by inactive arms of the conditional is ignored except for
checking the nesting of conditionals.
The constant expression in `#if` and `#elif` is subject to ordinary macro replacement.

Moreover, any expressions of the form

     defined identifier

or

     defined (identifier)

are replaced, before scanning for macros, by 1L if the identifier is defined in the
preprocessor, and by `0L` if not. Any identifiers remaining after macro expansion are
replaced by 0L. Finally, each integer constant is considered to be suffixed with L, so that all
arithmetic is taken to be long or unsigned long.
The resulting constant expression (Par.A.7.19) is restricted: it must be integral, and may not
contain sizeof, a cast, or an enumeration constant.


The control lines

    #ifdef identifier
    #ifndef identifier

are equivalent to

    # if defined identifier
    # if ! defined identifier

respectively.

`#elif` is new since the first edition, although it has been available is some preprocessors. The
defined preprocessor operator is also new.

### A.12.6 Line Control

For the benefit of other preprocessors that generate C programs, a line in one of the forms

    # line constant "filename"
    # line constant

causes the compiler to believe, for purposes of error diagnostics, that the line number of the
next source line is given by the decimal integer constant and the current input file is named
by the identifier. If the quoted filename is absent, the remembered name does not change.

Macros in the line are expanded before it is interpreted.

### A.12.7 Error Generation

A preprocessor line of the form

    # error token-sequenceopt

causes the preprocessor to write a diagnostic message that includes the token sequence.

### A.12.8 Pragmas

A control line of the form

    # pragma token-sequenceopt

causes the preprocessor to perform an implementation-dependent action. An unrecognized
pragma is ignored.

### A.12.9 Null directive

A control line of the form

    #

has no effect.

### A.12.10 Predefined names

Several identifiers are predefined, and expand to produce special information. They, and
also the preprocessor expansion operator defined, may not be undefined or redefined.

`__LINE__` A decimal constant containing the current source line number.

`__FILE__` A string literal containing the name of the file being compiled.

`__DATE__` A string literal containing the date of compilation, in the form "Mmmm dd
yyyy"

`__TIME__` A string literal containing the time of compilation, in the form "hh:mm:ss"

`__STDC__` The constant 1. It is intended that this identifier be defined to be 1 only in
standard-conforming implementations.

`#error` and `#pragma` are new with the ANSI standard; the predefined preprocessor macros are
new, but some of them have been available in some implementations. 