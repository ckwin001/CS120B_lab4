file build/results/part4.elf
target remote :1234
break ckwin001_lab4_part4.c:54
commands
print PINA
print PORTB
print state
print PORTC
end
c
c
set PINA = 2
c
set PINA = 0
c
set PINA = 4
c
set PINA = 2
c
set PINA = 0
c
set PINA = 4
c
set PINA = 0
c
set PINA = 1
c
c
set PINA = 0
c
set PINA = 4
c
set PINA = 0
c
set PINA = 2
c
set PINA = 0x80
c
c
set PINA = 0
c

