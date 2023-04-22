# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY Program1.c .
# Compile the C program
RUN gcc -o Program1 Program1.c
# Set the command to run when the container starts
CMD ["./Program1"]
