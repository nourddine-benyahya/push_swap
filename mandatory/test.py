import subprocess
from itertools import permutations

# Define the numbers
numbers = [1, 2, 6]

# Generate permutations
perms = permutations(numbers)

# Execute commands for all permutations
for perm in perms:
    perm_str = ' '.join(map(str, perm))
    # print(perm_str)
    arg_command = f'ARG="{perm_str}";'
    command = f'{arg_command} ./a.out $ARG | ./checker_Mac $ARG'
    subprocess.run(command, shell=True)