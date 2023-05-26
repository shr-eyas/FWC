.include "/home/sophia/FWC/main/assembly/setup/m328Pdef/m328Pdef.inc"

; Identifying pins 2, 3, 4, 5
ldi r17, 0b11000011
out DDRD, r17

; Activating pull-ups
ldi r17, 0b11111111
out PORTD, r17

; Declaring 8th pin as output
ldi r16, 0b00000001
out DDRB, r16

start:
  in r17, PIND ; Reading the data from pins 2, 3, 4, 5

  ; Taking a0
  ldi r24, 0b00000100
  mov r18, r17 ; Copy content of r17 into r18
  and r18, r24
  ldi r25, 0b00000010
  loopa0:
    lsr r18
    dec r25
    brne loopa0

  ; Taking a1
  ldi r24, 0b00001000
  mov r19, r17
  and r19, r24
  ldi r25, 0b00000011
  loopa1:
    lsr r19
    dec r25
    brne loopa1

  ; Taking b0
  ldi r24, 0b00010000
  mov r20, r17
  and r20, r24
  ldi r25, 0b00000100
  loopb0:
    lsr r20
    dec r25
    brne loopb0

  ; Taking b1
  ldi r24, 0b00100000
  mov r21, r17
  and r21, r24
  ldi r25, 0b00000100
  loopb1:
    lsr r21
    dec r25
    brne loopb1

  ldi r22, 0x00
  ldi r23, 0x00
  ldi r24, 0x00
  ldi r26, 0x00
  ldi r27, 0x00
  ldi r28, 0x00

  ; POS expression
  ; F = b0'a1 + a0a1b0' + a0a1b0'

  mov r22, r18 ; r22 = a0
  mov r23, r19 ; r23 = a1
  mov r24, r20 ; r24 = b0
  mov r26, r21 ; r26 = b1
  com r26
  and r23, r26 ; r23 = a1b1'
  com r24
  and r24, r23 ; r24 = b0'a1 //
  and r22, r24 ; r22 = a0a1b0' //
  mov r27, r26 ; r27 = b1'
  mov r28, r24 ; r28 = b0'
  and r27, r28 ; r27 = b0'b1'
  and r27, r22 ; r27 = a0a1b0' //

  or r24, r22
  or r24, r27

  out PORTB, r24

  rjmp start

