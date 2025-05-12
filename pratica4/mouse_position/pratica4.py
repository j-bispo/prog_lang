# Program: 

# Author: Jose Alberto

# Date: 

# Description: 

# License: CC BY-SA

from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

class Point(Structure):
    _fields_ = [("x", c_long), ("y", c_long)]

def query_mouse_position():
    pt = Point()
    windll.user32.GetCursorPos(byref(pt))
    return {"x": pt.x, "y": pt.y}

if __name__ == "__main__":
  
  while True:

        # Get and print the mouse position
        pos = query_mouse_position()
        print("Mouse Position: x=%d, y=%d"%(pos["x"],pos["y"]))

        # Print which quadrant the mouse is in
        if(pos["x"] < 1366/2 and pos["y"] < 768/2):
            print("Mouse is in A.")
        elif(pos["x"] > 1366/2 and pos["y"] < 768/2):
            print("Mouse is in B.")
        elif(pos["x"] < 1366/2 and pos["y"] > 768/2):
            print("Mouse is in C.")
        else:
            print("Mouse is in D.")
      
        # Wait for a short period before the next iteration
        time.sleep(0.6) 

        if msvcrt.kbhit():
            if msvcrt.getch() == b"\x1b":  # ESC key
                break