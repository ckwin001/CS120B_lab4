file build/results/part2.elf
target remote :1234
break ckwin001_lab4_part2.c:79
commands
print PINA
print state
print PORTC
end
c
c
set PINA = 1
c
set PINA = 0
c
set PINA = 1
c
set PINA = 2
c
set PINA = 0
c
set PINA = 3
c
set PINA = 0
c
