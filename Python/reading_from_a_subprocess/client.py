from subprocess import Popen, PIPE
from time import sleep

# run the shell as a subprocess:
p = Popen(['python', 'shell.py'],
          stdin = PIPE, stdout = PIPE, stderr = PIPE, shell = False)
# issue command:
p.stdin.write('command\n')
# let the shell output the result:
sleep(0.1)
# get the output
while True:
    output = p.stdout.read() # <-- Hangs here!
    if not output:
        print '[No more data]'
        break
    print output