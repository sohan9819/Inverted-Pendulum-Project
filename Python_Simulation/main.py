import math
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.animation as animation

# Constants
m = 1  # mass of cart (kg)
M = 1  # mass of pendulum (kg)
g = 9.8  # acceleration due to gravity (m/s^2)
l = 0.5  # length of pendulum (m)
d = 0.1  # damping coefficient (N*s/m)

# Initial conditions
x = 0  # initial position of cart (m)
v = 0  # initial velocity of cart (m/s)
theta = math.pi  # initial angle of pendulum (rad)
w = 1  # initial angular velocity of pendulum (rad/s)

# Simulation parameters
dt = 0.01  # time step (s)
num_steps = 1000  # number of steps to simulate

############################
# PID controller parameters
kp = 2  # proportional gain
ki = 0.01  # integral gain
kd = 1  # derivative gain

############################

# Set up figure and axis
fig, ax = plt.subplots()
ax.set_xlim(-1.5, 1.5)
ax.set_ylim(-1, 1)
line, = ax.plot([], [], 'o-', lw=2)
rect = patches.Rectangle((0, 0), 0.1, 0.2, fc='y')
ax.add_patch(rect)

# Define update function for animation


def update(frame):
    global x, v, theta, w
    t = frame * dt

    # # Calculate accelerations
    a = -(g / l) * math.sin(theta) - d * w / (M + m)
    alpha = (m * g * math.sin(theta) - d * w +
             m * a * math.cos(theta)) / (M + m)
    alpha = alpha / l

    print("Acceleration : ", a * 100)

    # ######################
    # Calculate error and derivatives
    # error = -theta
    # de = -w
    # integral = integral + error * dt

    # print("Error : ", error)
    # print("de : ", de)
    # print("integral : ", integral)

    # Calculate control signal
    # u = kp * error + ki * integral + kd * de

    # Calculate accelerations
    # a = u / (m + M) - (m * l * w ** 2 * math.sin(theta) + d * w) / (m + M)
    # alpha = (u - (m * l * w ** 2 * math.sin(theta) + d * w)) / (m * l)
    # ######################

    # Update velocities
    w = w + alpha * dt
    v = v + a * dt

    # Update positions
    x = x + v * dt
    theta = theta + w * dt

    # Set cart back to center if it reaches end
    if x > 1:
        x = 1
        v = -v
    elif x < -1:
        x = -1
        v = -v

    line.set_data([x, x + l * math.sin(theta)], [0, -l * math.cos(theta)])
    rect.set_xy([x - 0.05, -0.1])
    return line, rect


ani = animation.FuncAnimation(
    fig, update, frames=range(num_steps), interval=10, blit=True)
plt.show()
