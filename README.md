this respository show you how you can run ros on arduino using rosserial library and control your bot by subscribing on /cmd_vel topic. 
i use arduino DUE in this exemple but it can also work for any arduino model, dont forget to delete or comment "#define USE_USBCON" if you use another aduino
1 - first you must run roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch on linux side
2 - run rosrun rosserial_python serial_node.py /dev/ttyACM0 //dont forget to change port (/dev/ttyACM0) by your using port
3 - control your robot using w->for forward  x->for bakc a->for left d-> for right s->for stop 
