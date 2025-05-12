# Program: Calculating elements of circle and rectangle

# Author: Joseph Alberto

# Date: April, 18

# Description: This program calculates the circle length and area or the perimeter and area of a rectangle, based on user input.

# License: CC BY-SA

import msvcrt
    
PI = 3.14 # Constant for the value of pi

def circ_calc(radius):  # Function to calculate circle elements

   circ_length = 2 * PI * radius # Circle length calculation

   circ_area = PI * radius ** 2 # Circle area calculation

   print("\nThe circumference length is", circ_length)
   print("The circle area is:", circ_area)

def rec_calc (side1, side2):  # Function to calculate rectangle elements

   rec_perimeter = 2 * (side1 + side2) # Rectangle perimeter calculation

   rec_area = side1 * side2 # Rectangle area calculation

   print("\nThe rectangle perimeter is", rec_perimeter)

   print("The rectangle area is", rec_area)

if __name__ == "__main__":

   print("Press any key to start.\n")

   for i in range(0, 1): # Wait for user to press any key to start the program

      print("Choose the calculation you want. \nEnter 1 if you want to calculate circle elements. \nEnter 2 if you want to calculate rectangle elements")

      type_calc = str(input("Enter your choice: ")) # Calculation choice point

      if type_calc == "1":

         radius = float(input("Enter with the circle radius: ")) # Input of the radius of the circle

         circ_calc(radius)

      elif type_calc == "2":

         side1, side2 = map(float, input("Enter with rectangle sides <side 1, side2>: ").split(',')) # Input of sides of the rectangle 

         rec_calc(side1, side2)

      else:

         print("The character entered is not 1 or 2.") # Error in choosing the calculation

      print("\nIf you want continue, press any key. \nFor exit, press ESC.\n")