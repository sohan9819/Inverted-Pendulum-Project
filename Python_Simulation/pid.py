import math
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Constants
L = 1  # Length of pendulum
g = 9.8  # Acceleration due to gravity
m = 1  # Mass of pendulum

# Control Parameters
Kp = 10  # Proportional gain
Ki = 5  # Integral gain
Kd = 2  # Derivative gain


class Pendulum:
    def __init__(self, L, m, g):
        self.L = L
        self.m = m
        self.g = g
        self.x = 0  # Position of cart
        self.x_dot = 0  # Velocity of cart
        self.theta = math.pi  # Angle of pendulum
        self.theta_dot = 0  # Angular velocity of pendulum

    def update_state(self, force, dt):
        self.x_dot += force / self.m * dt
        self.x += self.x_dot * dt
        self.theta_dot += (-self.g/self.L) * math.sin(self.theta) * dt
        self.theta += self.theta_dot * dt


def pid_control(pendulum, target_position, dt):
    error = target_position - pendulum.theta
    integral = 0
    derivative = 0
    integral = integral + error * dt
    derivative = (error - derivative) / dt
    return Kp * error + Ki * integral + Kd * derivative


def simulate(pendulum, target_position, dt):
    force = pid_control(pendulum, target_position, dt)
    pendulum.update_state(force, dt)
    return pendulum.x, pendulum.theta


def animate(i, pendulum, target_position, dt, scat):
    x, theta = simulate(pendulum, target_position, dt)
    scat.set_data(x, theta)
    return scat


def run_simulation(pendulum, target_position, dt):
    fig, ax = plt.subplots()
    ax.set_xlim(-2, 2)
    ax.set_ylim(-math.pi, math.pi)
    scat = ax.scatter([pendulum.x], [pendulum.theta], c='r')
    anim = animation.FuncAnimation(
        fig, animate, frames=300, fargs=(pendulum, target_position, dt, scat))
    plt.show()


# Start the simulation
pendulum = Pendulum(L, m, g)
target_position = math.pi
dt = 0.01
run_simulation(pendulum, target_position, dt)
