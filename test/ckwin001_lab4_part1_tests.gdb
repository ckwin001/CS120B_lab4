file build/results/part1.elf
target remote :1234
break ckwin001_lab4_part1.c:45
commands
print PINA 
print state
print PORTB
end
c
c
set PINA = 1
c
set PINA = 0
c
set PINA = 1
c
set PINA = 0
c
