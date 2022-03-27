# arduino-multitasking-interrupt

In computing terminology, multitasking is a concept of executing multiple tasks or processes by a computer over a period of time. The concept of Interrupts come into picture in the scenario of multitasking.

Interrupt is a process of letting the computer know that a different task is in need for its service. Consider a situation where there are no interrupts in a computing system. In this case, if a new task requires the service of the computer, it must wait until the present task is fully executed by the computer.

This is not feasible as the new task might be critical and requires urgent attention from the computer. Interrupts play an important role here. When a task interrupts the computer, it puts the present task on hold, executes the new task and returns back to the original task.

## Multitasking in Arduino
Arduino is a simple microcontroller based platform without the concept of operating system. This means that only one program can run in Arduino at a time.

Even though there is no operating system, we can still achieve the concept of multitasking i.e. handling multiple tasks in Arduino.

In order to handle multiple tasks in Arduino, you need to make use of two concepts. They are Interrupts and millis.

**Get rid of delay()**

When you use the delay (); function in Arduino, you are actually putting the processor in a busy state for the time period mentioned in the delay. During this time, the Arduino processor cannot do any other tasks like read from a button, for example.

Here comes millis to the rescue. Millis is a timekeeper function that starts when the Arduino is powered on (or reset) and the program in Arduino starts running. Whenever we call the millis function in our program, it returns the time in milliseconds from the moment the program started running.

**Interrupts in Arduino**

Arduino, or the microcontroller on the Arduino UNO board to be specific, supports Interrupts. Arduino UNO board has support for two external interrupts on Digital IO pins 2 and 3.

Using these external interrupt pins, you can trigger external interrupts and advice Arduino to perform a special task.

In an earlier tutorial called Arduino Interrupts Tutorial, I have spoken about interrupts in Arduino, how to enable them, what is an interrupt service routine (ISR), what care must be taken while writing an ISR function and an example program.

![Arduino-Multitasking-Tutorial-Circuit-Diagram](https://user-images.githubusercontent.com/37790017/160269576-d6f649ca-31cb-4a50-a10f-eae489122c56.jpg)


This is a simple example of implementing multitasking in Arduino. You can implement complex projects involving several components like motors, LEDs, servos, etc. and use interrupts to achieve multitasking.

