from subprocess import Popen, PIPE
from time import sleep
from fcntl import fcntl, F_GETFL, F_SETFL
from os import O_NONBLOCK, read

# run the shell as a subprocess:
p = Popen(['python', 'shell.py'],
          stdin = PIPE, stdout = PIPE, stderr = PIPE, shell = False)
# set the O_NONBLOCK flag of p.stdout file descriptor:
flags = fcntl(p.stdout, F_GETFL) # get current p.stdout flags
fcntl(p.stdout, F_SETFL, flags | O_NONBLOCK)
# issue command:
p.stdin.write('command\n')
# let the shell output the result:
sleep(0.1)
# get the output
while True:
    try:
        print read(p.stdout.fileno(), 1024),
    except OSError:
        # the os throws an exception if there is no data
        print '[No more data]'
        break