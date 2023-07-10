

<!-- INTRO OF THE PROJECT -->
## Activity goal

The goal of this laboratory activity is to design a digital position controller for the DC servomotor available in the laboratory. Two different design approaches are considered: in the design by emulation, the digital controller is obtained by discretization of a controller that is originally designed in the continuous–time domain; vice versa, in the direct digital design (or discrete design), the control design is performed directly in the discrete–time domain, using a discrete–time model of the plant to be controlled.PID–control system designed in the previous laboratory activity are introduced. The improvements
consist in the implementation of an anti–windup scheme to reduce the large overshoot occurring
in the step response when the controller output saturates, and a friction plus inertia feedforward compensator, which allows to enhance both the accuracy and speed of response of the conventional feedback controller.
The second part of the activity is devoted to the design of a continuous–time position control
system by using state–space techniques. Both nominal and robust tracking designs are considered.
Nominal tracking is performed by exploiting a conventional feedforward scheme; on the other hand, robust tracking is achieved by either exploiting an integral action (for robust tracking of constant set–points, or perfect rejection of constant load disturbances), or by resorting to the internal model principle (for robust tracking and perfect rejection of more general, possibly time–varying signals).

The project will touch:
1. Position PID–controller in discrete time domain
2. Position state–space controller in discrete time domain
3. Direct digital design

<!-- Get started -->
## Get Started

For start:
1. Download and install matlab/simulink
2. Download and install the related toolbox

## Prerequisite

Prerequisites for start:
1. Analytical model of the DC gearmotor
2. PID control design with frequency response methods, Bode’s method
3. Estimation of model parameters: Friction and Inertia
4. Bases of PID control theory


## Experimental setup

1. Quanser SRV–02 servomotor.
2. National Instruments PCI–6221 or PCIe–6321 Multifunction data acquisition board.
3. National Instruments BNC–2110 terminal board.
4. BNC–terminated connection cables
5. DC power supply with adjustable voltage output
6. PC workstation running Matlab/Simulink. The Simulink Desktop Real–Time (SLDRT)
toolbox

## Contact

Giulio Savian  - giuliosavian@gmail.com

<!--Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)-->

