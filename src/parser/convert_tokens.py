import re

tokens = []

with open("./parser/parse.tab.h", "r") as f:
    matcher = " +([A-Z_]+) = ([0-9]+)"

    start = False
    real_start = False
    for l in f:
        if real_start:
            m = re.match(matcher, l)
            if m:
                tokens.append((m.group(1), m.group(2)))
            else:
                break
        if start:
            if (l == "  {\n"):
                real_start = True
        if (l == "  enum yytokentype\n"):
            start = True


with open("./parser/token_map.c", "w") as f:
    f.write("const char* get_token_name(int token) {\n switch(token) {\n")
    for (name, num) in tokens:
        f.write("case ")
        f.write(num)
        f.write(": return \"")
        f.write(name)
        f.write("\";\n")

    f.write("default: return \"ERROR\";\n} \n}")