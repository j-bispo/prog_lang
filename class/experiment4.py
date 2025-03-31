# Program: 

# Author: Jose Alberto

# Date: March, 31

# Description: 

# License: CC BY-SA

from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

class Point(Structure):
    _fields_ = [("x", c_long), ("y", c_long)] #1920x1080 resolution        

def query_mouse_position():
    pt = Point()
    windll.user32.GetCursorPos(byref(pt))
    return {"x": pt.x, "y": pt.y}

if __name__ == "__main__":
  
  while True:
      pos = query_mouse_position()
      print("Mouse Position: x=%d, y=%d"%(pos["x"],pos["y"]))
      time.sleep(0.1)  # Adjust delay as needed

      if msvcrt.kbhit():
          if msvcrt.getch() == b'c':
              break 

  ch = "k" 

  while(ch != "ESC"): 
      
      print("Hello world")
      ch = str(input("ch: "))