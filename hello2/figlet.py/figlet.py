import sys
from pyfiglet import Figlet

# Create an instance of the Figlet class
figlet = Figlet()

# Get a list of available fonts
available_fonts = figlet.getFonts()

# Get the number of command-line arguments
nb = len(sys.argv)

# Check if the number of arguments is not 0 or 2
if nb !=3 :
    print("Error: Expected exactly two command-line arguments.")
    sys.exit(1)  # Exit the script with an error code

# Check if the first argument is "-f" or "--font"
if sys.argv[1] not in ("-f", "--font"):
    print("Error: The first argument must be '-f' or '--font'.")
    sys.exit(1)

# Check if the second argument is a valid font name
if sys.argv[2] not in available_fonts:
    print(f"Error: '{sys.argv[2]}' is not a valid font name.")
    sys.exit(1)

# If all validations pass, the program continues execution
f=input("Input:")
figlet.setFont(font=f)