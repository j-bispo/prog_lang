%{
Program: Calculating elements of circle and rectangle

Author: Joseph Alberto

Date: March, 17.

Description: This program calculates the circle length and area or the perimeter and area of a rectangle, based on user input.

License: CC BY-SA
%}

% Declare the constant pi
PI = 3.14;

% Asks the user to choose the desired calculation
fprintf('Choose the calculation you want:\n')
fprintf('Enter 1 if you want to calculate circle elements\n')
fprintf('Enter 2 if you want to calculate rectangle elements\n')

% Requests and storages the user choice
choice = input('Enter your choice: ')

% Calculation of circle elements based on user choice
if choice == 1

  % Requests and storages the radius of circle
  radius = input('Enter with the circle radius: ');

  % Area and length calculation
  circ_length = 2 * PI * radius; % Cálculo do comprimento da circunferência
  circ_area = PI * radius^2; % Cálculo da área do círculo

  % Show the result for the circle
  fprintf('The circumference length is %.2f\n', circ_length);
  fprintf('The circle area is: %.2f\n', circ_area);

elseif choice == 2

  % Requests and storages the sides of rectangle
  sides = input('Enter with the sides of the rectangle: ', 's')

  % Convert the input string to numeric values
  values = sscanf(sides, '%f, %f');
  side1 = values(1);
  side2 = values(2);

  % Show the result for the rectangle
  fprintf('The rectangle perimeter is: %.2f\n', 2 * (side1 + side2));
  fprintf('The rectangle area is: %.2f\n', side1 * side2);


else

  % If the user does not choose a valid option, the program displays an error
  fprintf('Invalid choice')
  end
