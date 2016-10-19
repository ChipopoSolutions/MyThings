import subprocess
import sys



def exec_shell(command):

    with open('test.log', 'a') as f:

        process = subprocess.Popen(command, stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=False)

        for line in iter(process.stdout.readline, ''):
            sys.stdout.write("[stdout] "+line)
            f.write(line)

        for line in iter(process.stderr.readline, ''):
            sys.stderr.write("[stderr] "+line)
            f.write(line)

        rc=process.wait()
        print("rc="+str(rc))




exec_shell(['bash','long_loop.sh'])
