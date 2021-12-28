# To be clear, there's no difference "" and '' in python
# if I'm not mistaken. I use '' when I'm thinking about
# a single character and "" when I mean string,
# but python doesn't care anyway
import sys
# Open i/o files
f_in = open( "./shaders/"+sys.argv[1], "r" )
# Here we add ".h" extension
f_out = open("./src/includes/shaders/sources/"+sys.argv[1]+".h", "w" )
print( "Input file: "+f_in.name )
print( "Iutput file: "+f_out.name )

# Read each line separately and store them
# in... ugh idk tbh, a list?
lines = f_in.readlines()

# Make a name for the new variable
# by splitting content of the filename string
# (which includes file extension) to list of 2 elements
# ( 1st is the name of the file and the 2nd one is its extension )
variable_name = f_in.name.rsplit( '/', -1 )[-1].rsplit('.', -1)[0]

# Write a "preamble"
f_out.write("#pragma once\n")
f_out.write( "const char *"+variable_name+sys.argv[1][-2:]+" = " )

# For every line in the input file
for line in lines:
    # We want to replace every new line character
    # with two separate characters
    
    if '\n' in line:
        line = line.replace( '\n', "\\n" )
    # I've seen that at the end of the input file
    # there is no '\n' character but you want it
    # to be in the output file. If so, we add
    # the two characters
    else:
        line += "\\n"
    # Just for debug
    print(line)
    # Add a newline character and tab followed by
    # C string continuation character
    line = "\""+line+"\""
    line += " \n"
    # Write parsed line to output file
    
    f_out.write(line)

# Close the C style variable declaration
f_out.write( ";" )

# Close both files
f_in.close()
f_out.close()
