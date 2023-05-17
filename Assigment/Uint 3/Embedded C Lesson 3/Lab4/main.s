
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b480      	push	{r7}
   2:	b083      	sub	sp, #12
   4:	af00      	add	r7, sp, #0
   6:	4b1a      	ldr	r3, [pc, #104]	; (70 <main+0x70>)
   8:	681b      	ldr	r3, [r3, #0]
   a:	4a19      	ldr	r2, [pc, #100]	; (70 <main+0x70>)
   c:	f043 0304 	orr.w	r3, r3, #4
  10:	6013      	str	r3, [r2, #0]
  12:	4b18      	ldr	r3, [pc, #96]	; (74 <main+0x74>)
  14:	681b      	ldr	r3, [r3, #0]
  16:	4a17      	ldr	r2, [pc, #92]	; (74 <main+0x74>)
  18:	f423 0370 	bic.w	r3, r3, #15728640	; 0xf00000
  1c:	6013      	str	r3, [r2, #0]
  1e:	4b15      	ldr	r3, [pc, #84]	; (74 <main+0x74>)
  20:	681b      	ldr	r3, [r3, #0]
  22:	4a14      	ldr	r2, [pc, #80]	; (74 <main+0x74>)
  24:	f443 1300 	orr.w	r3, r3, #2097152	; 0x200000
  28:	6013      	str	r3, [r2, #0]
  2a:	4b13      	ldr	r3, [pc, #76]	; (78 <main+0x78>)
  2c:	681a      	ldr	r2, [r3, #0]
  2e:	8813      	ldrh	r3, [r2, #0]
  30:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
  34:	8013      	strh	r3, [r2, #0]
  36:	2300      	movs	r3, #0
  38:	607b      	str	r3, [r7, #4]
  3a:	e002      	b.n	42 <main+0x42>
  3c:	687b      	ldr	r3, [r7, #4]
  3e:	3301      	adds	r3, #1
  40:	607b      	str	r3, [r7, #4]
  42:	687b      	ldr	r3, [r7, #4]
  44:	f241 3287 	movw	r2, #4999	; 0x1387
  48:	4293      	cmp	r3, r2
  4a:	ddf7      	ble.n	3c <main+0x3c>
  4c:	4b0a      	ldr	r3, [pc, #40]	; (78 <main+0x78>)
  4e:	681a      	ldr	r2, [r3, #0]
  50:	8813      	ldrh	r3, [r2, #0]
  52:	f36f 334d 	bfc	r3, #13, #1
  56:	8013      	strh	r3, [r2, #0]
  58:	2300      	movs	r3, #0
  5a:	603b      	str	r3, [r7, #0]
  5c:	e002      	b.n	64 <main+0x64>
  5e:	683b      	ldr	r3, [r7, #0]
  60:	3301      	adds	r3, #1
  62:	603b      	str	r3, [r7, #0]
  64:	683b      	ldr	r3, [r7, #0]
  66:	f241 3287 	movw	r2, #4999	; 0x1387
  6a:	4293      	cmp	r3, r2
  6c:	ddf7      	ble.n	5e <main+0x5e>
  6e:	e7dc      	b.n	2a <main+0x2a>
  70:	40021060 	andmi	r1, r2, r0, rrx
  74:	40010810 	andmi	r0, r1, r0, lsl r8
  78:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <R_ODR>:
   0:	4001080c 	andmi	r0, r1, ip, lsl #16

00000004 <g_variables>:
   4:	Address 0x00000004 is out of bounds.


Disassembly of section .rodata:

00000000 <const_variable>:
   0:	Address 0x00000000 is out of bounds.


Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000001a4 	andeq	r0, r0, r4, lsr #3
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000095 	muleq	r0, r5, r0
  10:	00014d0c 	andeq	r4, r1, ip, lsl #26
  14:	00002200 	andeq	r2, r0, r0, lsl #4
  18:	00000000 	andeq	r0, r0, r0
  1c:	00007c00 	andeq	r7, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	06010200 	streq	r0, [r1], -r0, lsl #4
  28:	00000181 	andeq	r0, r0, r1, lsl #3
  2c:	0c080102 	stfeqs	f0, [r8], {2}
  30:	03000000 	movweq	r0, #0
  34:	0000002c 	andeq	r0, r0, ip, lsr #32
  38:	5d050202 	sfmpl	f0, 4, [r5, #-8]
  3c:	02000001 	andeq	r0, r0, #1
  40:	00650702 	rsbeq	r0, r5, r2, lsl #14
  44:	04020000 	streq	r0, [r2], #-0
  48:	00017805 	andeq	r7, r1, r5, lsl #16
  4c:	00780400 	rsbseq	r0, r8, r0, lsl #8
  50:	4f020000 	svcmi	0x00020000
  54:	00005919 	andeq	r5, r0, r9, lsl r9
  58:	07040200 	streq	r0, [r4, -r0, lsl #4]
  5c:	00000083 	andeq	r0, r0, r3, lsl #1
  60:	3f050802 	svccc	0x00050802
  64:	02000001 	andeq	r0, r0, #1
  68:	011a0708 	tsteq	sl, r8, lsl #14
  6c:	04050000 	streq	r0, [r5], #-0
  70:	746e6905 	strbtvc	r6, [lr], #-2309	; 0xfffff6fb
  74:	07040200 	streq	r0, [r4, -r0, lsl #4]
  78:	0000010d 	andeq	r0, r0, sp, lsl #2
  7c:	00007506 	andeq	r7, r0, r6, lsl #10
  80:	016f0400 	cmneq	pc, r0, lsl #8
  84:	30030000 	andcc	r0, r3, r0
  88:	00004d14 	andeq	r4, r0, r4, lsl sp
  8c:	01360400 	teqeq	r6, r0, lsl #8
  90:	05040000 	streq	r0, [r4, #-0]
  94:	00007c1f 	andeq	r7, r0, pc, lsl ip
  98:	04040700 	streq	r0, [r4], #-1792	; 0xfffff900
  9c:	00c70217 	sbceq	r0, r7, r7, lsl r2
  a0:	67080000 	strvs	r0, [r8, -r0]
  a4:	04000001 	streq	r0, [r0], #-1
  a8:	008d0c1a 	addeq	r0, sp, sl, lsl ip
  ac:	0d040000 	stceq	0, cr0, [r4, #-0]
  b0:	00230213 	eoreq	r0, r3, r3, lsl r2
  b4:	00013108 	andeq	r3, r1, r8, lsl #2
  b8:	0c1b0400 	cfldrseq	mvf0, [fp], {-0}
  bc:	0000008d 	andeq	r0, r0, sp, lsl #1
  c0:	02120104 	andseq	r0, r2, #4, 2
  c4:	09000023 	stmdbeq	r0, {r0, r1, r5}
  c8:	09140404 	ldmdbeq	r4, {r2, sl}
  cc:	000000e9 	andeq	r0, r0, r9, ror #1
  d0:	0001540a 	andeq	r5, r1, sl, lsl #8
  d4:	0b160400 	bleq	5810dc <g_variables+0x5810d8>
  d8:	0000008d 	andeq	r0, r0, sp, lsl #1
  dc:	6e69700b 	cdpvs	0, 6, cr7, cr9, cr11, {0}
  e0:	031c0400 	tsteq	ip, #0, 8
  e4:	00000099 	muleq	r0, r9, r0
  e8:	001a0400 	andseq	r0, sl, r0, lsl #8
  ec:	1e040000 	cdpne	0, 0, cr0, cr4, cr0, {0}
  f0:	0000c702 	andeq	ip, r0, r2, lsl #14
  f4:	00e90600 	rsceq	r0, r9, r0, lsl #12
  f8:	8d0c0000 	stchi	0, cr0, [ip, #-0]
  fc:	04000001 	streq	r0, [r0], #-1
 100:	010d1320 	tsteq	sp, r0, lsr #6
 104:	05010000 	streq	r0, [r1, #-0]
 108:	00000003 	andeq	r0, r0, r3
 10c:	f5040d00 			; <UNDEFINED> instruction: 0xf5040d00
 110:	0e000000 	cdpeq	0, 0, cr0, cr0, cr0, {0}
 114:	0000002c 	andeq	r0, r0, ip, lsr #32
 118:	00000123 	andeq	r0, r0, r3, lsr #2
 11c:	0000750f 	andeq	r7, r0, pc, lsl #10
 120:	0c000200 	sfmeq	f0, 4, [r0], {-0}
 124:	00000000 	andeq	r0, r0, r0
 128:	130f0601 	movwne	r0, #62977	; 0xf601
 12c:	01000001 	tsteq	r0, r1
 130:	00000305 	andeq	r0, r0, r5, lsl #6
 134:	330e0000 	movwcc	r0, #57344	; 0xe000
 138:	46000000 	strmi	r0, [r0], -r0
 13c:	0f000001 	svceq	0x00000001
 140:	00000075 	andeq	r0, r0, r5, ror r0
 144:	36030002 	strcc	r0, [r3], -r2
 148:	0c000001 	stceq	0, cr0, [r0], {1}
 14c:	000000f9 	strdeq	r0, [r0], -r9
 150:	46150701 	ldrmi	r0, [r5], -r1, lsl #14
 154:	01000001 	tsteq	r0, r1
 158:	00000305 	andeq	r0, r0, r5, lsl #6
 15c:	01100000 	tsteq	r0, r0
 160:	00000108 	andeq	r0, r0, r8, lsl #2
 164:	00060a01 	andeq	r0, r6, r1, lsl #20
 168:	7c000000 	stcvc	0, cr0, [r0], {-0}
 16c:	00000000 	andeq	r0, r0, r0
 170:	01000000 	mrseq	r0, (UNDEF: 0)
 174:	00003611 	andeq	r3, r0, r1, lsl r6
 178:	00004c00 	andeq	r4, r0, r0, lsl #24
 17c:	00018f00 	andeq	r8, r1, r0, lsl #30
 180:	00691200 	rsbeq	r1, r9, r0, lsl #4
 184:	6e0b1201 	cdpvs	2, 0, cr1, cr11, cr1, {0}
 188:	02000000 	andeq	r0, r0, #0
 18c:	13007491 	movwne	r7, #1169	; 0x491
 190:	00000058 	andeq	r0, r0, r8, asr r0
 194:	0000006e 	andeq	r0, r0, lr, rrx
 198:	01006912 	tsteq	r0, r2, lsl r9
 19c:	006e0b15 	rsbeq	r0, lr, r5, lsl fp
 1a0:	91020000 	mrsls	r0, (UNDEF: 2)
 1a4:	00000070 	andeq	r0, r0, r0, ror r0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0b0b0024 	bleq	2c00ac <g_variables+0x2c00a8>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	26030000 	strcs	r0, [r3], -r0
  20:	00134900 	andseq	r4, r3, r0, lsl #18
  24:	00160400 	andseq	r0, r6, r0, lsl #8
  28:	0b3a0e03 	bleq	e8383c <g_variables+0xe83838>
  2c:	0b390b3b 	bleq	e42d20 <g_variables+0xe42d1c>
  30:	00001349 	andeq	r1, r0, r9, asr #6
  34:	0b002405 	bleq	9050 <g_variables+0x904c>
  38:	030b3e0b 	movweq	r3, #48651	; 0xbe0b
  3c:	06000008 	streq	r0, [r0], -r8
  40:	13490035 	movtne	r0, #36917	; 0x9035
  44:	13070000 	movwne	r0, #28672	; 0x7000
  48:	3a0b0b01 	bcc	2c2c54 <g_variables+0x2c2c50>
  4c:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  50:	0013010b 	andseq	r0, r3, fp, lsl #2
  54:	000d0800 	andeq	r0, sp, r0, lsl #16
  58:	0b3a0e03 	bleq	e8386c <g_variables+0xe83868>
  5c:	0b390b3b 	bleq	e42d50 <g_variables+0xe42d4c>
  60:	0b0b1349 	bleq	2c4d8c <g_variables+0x2c4d88>
  64:	0b0c0b0d 	bleq	302ca0 <g_variables+0x302c9c>
  68:	00000a38 	andeq	r0, r0, r8, lsr sl
  6c:	0b011709 	bleq	45c98 <g_variables+0x45c94>
  70:	3b0b3a0b 	blcc	2ce8a4 <g_variables+0x2ce8a0>
  74:	010b390b 	tsteq	fp, fp, lsl #18
  78:	0a000013 	beq	cc <.debug_abbrev+0xcc>
  7c:	0e03000d 	cdpeq	0, 0, cr0, cr3, cr13, {0}
  80:	0b3b0b3a 	bleq	ec2d70 <g_variables+0xec2d6c>
  84:	13490b39 	movtne	r0, #39737	; 0x9b39
  88:	0d0b0000 	stceq	0, cr0, [fp, #-0]
  8c:	3a080300 	bcc	200c94 <g_variables+0x200c90>
  90:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  94:	0013490b 	andseq	r4, r3, fp, lsl #18
  98:	00340c00 	eorseq	r0, r4, r0, lsl #24
  9c:	0b3a0e03 	bleq	e838b0 <g_variables+0xe838ac>
  a0:	0b390b3b 	bleq	e42d94 <g_variables+0xe42d90>
  a4:	0c3f1349 	ldceq	3, cr1, [pc], #-292	; ffffff88 <g_variables+0xffffff84>
  a8:	00000a02 	andeq	r0, r0, r2, lsl #20
  ac:	0b000f0d 	bleq	3ce8 <g_variables+0x3ce4>
  b0:	0013490b 	andseq	r4, r3, fp, lsl #18
  b4:	01010e00 	tsteq	r1, r0, lsl #28
  b8:	13011349 	movwne	r1, #4937	; 0x1349
  bc:	210f0000 	mrscs	r0, CPSR
  c0:	2f134900 	svccs	0x00134900
  c4:	1000000b 	andne	r0, r0, fp
  c8:	0c3f012e 	ldfeqs	f0, [pc], #-184	; 18 <.debug_abbrev+0x18>
  cc:	0b3a0e03 	bleq	e838e0 <g_variables+0xe838dc>
  d0:	0b390b3b 	bleq	e42dc4 <g_variables+0xe42dc0>
  d4:	01120111 	tsteq	r2, r1, lsl r1
  d8:	42970640 	addsmi	r0, r7, #64, 12	; 0x4000000
  dc:	1100000c 	tstne	r0, ip
  e0:	0111010b 	tsteq	r1, fp, lsl #2
  e4:	13010112 	movwne	r0, #4370	; 0x1112
  e8:	34120000 	ldrcc	r0, [r2], #-0
  ec:	3a080300 	bcc	200cf4 <g_variables+0x200cf0>
  f0:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  f4:	0213490b 	andseq	r4, r3, #180224	; 0x2c000
  f8:	1300000a 	movwne	r0, #10
  fc:	0111010b 	tsteq	r1, fp, lsl #2
 100:	00000112 	andeq	r0, r0, r2, lsl r1
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000002 	andeq	r0, r0, r2
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000002 	andeq	r0, r0, r2
  10:	00000004 	andeq	r0, r0, r4
  14:	047d0002 	ldrbteq	r0, [sp], #-2
  18:	00000004 	andeq	r0, r0, r4
  1c:	00000006 	andeq	r0, r0, r6
  20:	107d0002 	rsbsne	r0, sp, r2
  24:	00000006 	andeq	r0, r0, r6
  28:	0000007c 	andeq	r0, r0, ip, ror r0
  2c:	10770002 	rsbsne	r0, r7, r2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000007c 	andeq	r0, r0, ip, ror r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	000000fa 	strdeq	r0, [r0], -sl
   4:	00a50003 	adceq	r0, r5, r3
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	63010000 	movwvs	r0, #4096	; 0x1000
  1c:	72615c3a 	rsbvc	r5, r1, #14848	; 0x3a00
  20:	6f745f6d 	svcvs	0x00745f6d
  24:	68636c6f 	stmdavs	r3!, {r0, r1, r2, r3, r5, r6, sl, fp, sp, lr}^
  28:	5c6e6961 			; <UNDEFINED> instruction: 0x5c6e6961
  2c:	2d6d7261 	sfmcs	f7, 2, [sp, #-388]!	; 0xfffffe7c
  30:	656e6f6e 	strbvs	r6, [lr, #-3950]!	; 0xfffff092
  34:	6261652d 	rsbvs	r6, r1, #188743680	; 0xb400000
  38:	6e695c69 	cdpvs	12, 6, cr5, cr9, cr9, {3}
  3c:	64756c63 	ldrbtvs	r6, [r5], #-3171	; 0xfffff39d
  40:	616d5c65 	cmnvs	sp, r5, ror #24
  44:	6e696863 	cdpvs	8, 6, cr6, cr9, cr3, {3}
  48:	3a630065 	bcc	18c01e4 <g_variables+0x18c01e0>
  4c:	6d72615c 	ldfvse	f6, [r2, #-368]!	; 0xfffffe90
  50:	6f6f745f 	svcvs	0x006f745f
  54:	6168636c 	cmnvs	r8, ip, ror #6
  58:	615c6e69 	cmpvs	ip, r9, ror #28
  5c:	6e2d6d72 	mcrvs	13, 1, r6, cr13, cr2, {3}
  60:	2d656e6f 	stclcs	14, cr6, [r5, #-444]!	; 0xfffffe44
  64:	69626165 	stmdbvs	r2!, {r0, r2, r5, r6, r8, sp, lr}^
  68:	636e695c 	cmnvs	lr, #92, 18	; 0x170000
  6c:	6564756c 	strbvs	r7, [r4, #-1388]!	; 0xfffffa94
  70:	7379735c 	cmnvc	r9, #92, 6	; 0x70000001
  74:	616d0000 	cmnvs	sp, r0
  78:	632e6e69 			; <UNDEFINED> instruction: 0x632e6e69
  7c:	00000000 	andeq	r0, r0, r0
  80:	6665645f 			; <UNDEFINED> instruction: 0x6665645f
  84:	746c7561 	strbtvc	r7, [ip], #-1377	; 0xfffffa9f
  88:	7079745f 	rsbsvc	r7, r9, pc, asr r4
  8c:	682e7365 	stmdavs	lr!, {r0, r2, r5, r6, r8, r9, ip, sp, lr}
  90:	00000100 	andeq	r0, r0, r0, lsl #2
  94:	6474735f 	ldrbtvs	r7, [r4], #-863	; 0xfffffca1
  98:	2e746e69 	cdpcs	14, 7, cr6, cr4, cr9, {3}
  9c:	00020068 	andeq	r0, r2, r8, rrx
  a0:	69725000 	ldmdbvs	r2!, {ip, lr}^
  a4:	65746176 	ldrbvs	r6, [r4, #-374]!	; 0xfffffe8a
  a8:	0000682e 	andeq	r6, r0, lr, lsr #16
  ac:	05000000 	streq	r0, [r0, #-0]
  b0:	02050001 	andeq	r0, r5, #1
  b4:	00000000 	andeq	r0, r0, r0
  b8:	05010a03 	streq	r0, [r1, #-2563]	; 0xfffff5fd
  bc:	0b053d0d 	bleq	14f4f8 <g_variables+0x14f4f4>
  c0:	08056767 	stmdaeq	r5, {r0, r1, r2, r5, r6, r8, r9, sl, sp, lr}
  c4:	2e130569 	cfmsc32cs	mvfx0, mvfx3, mvfx9
  c8:	054b0b05 	strbeq	r0, [fp, #-2821]	; 0xfffff4fb
  cc:	1e052e03 	cdpne	14, 0, cr2, cr5, cr3, {0}
  d0:	03040200 	movweq	r0, #16896	; 0x4200
  d4:	00030520 	andeq	r0, r3, r0, lsr #10
  d8:	3c010402 	cfstrscc	mvf0, [r1], {2}
  dc:	055a0705 	ldrbeq	r0, [sl, #-1797]	; 0xfffff8fb
  e0:	0b052e12 	bleq	14b930 <g_variables+0x14b92c>
  e4:	2e03054b 	cfsh32cs	mvfx0, mvfx3, #43
  e8:	02001e05 	andeq	r1, r0, #5, 28	; 0x50
  ec:	05200304 	streq	r0, [r0, #-772]!	; 0xfffffcfc
  f0:	04020003 	streq	r0, [r2], #-3
  f4:	13053c01 	movwne	r3, #23553	; 0x5c01
  f8:	00070254 	andeq	r0, r7, r4, asr r2
  fc:	Address 0x000000fc is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	61765f67 	cmnvs	r6, r7, ror #30
   4:	62616972 	rsbvs	r6, r1, #1867776	; 0x1c8000
   8:	0073656c 	rsbseq	r6, r3, ip, ror #10
   c:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  10:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  14:	61686320 	cmnvs	r8, r0, lsr #6
  18:	5f520072 	svcpl	0x00520072
  1c:	5f52444f 	svcpl	0x0052444f
  20:	3a440074 	bcc	11001f8 <g_variables+0x11001f4>
  24:	61654c5c 	cmnvs	r5, ip, asr ip
  28:	69206e72 	stmdbvs	r0!, {r1, r4, r5, r6, r9, sl, fp, sp, lr}
  2c:	6544206e 	strbvs	r2, [r4, #-110]	; 0xffffff92
  30:	5c687470 	cfstrdpl	mvd7, [r8], #-448	; 0xfffffe40
  34:	6c706944 			; <UNDEFINED> instruction: 0x6c706944
  38:	5c616d6f 	stclpl	13, cr6, [r1], #-444	; 0xfffffe44
  3c:	72617453 	rsbvc	r7, r1, #1392508928	; 0x53000000
  40:	69555c73 	ldmdbvs	r5, {r0, r1, r4, r5, r6, sl, fp, ip, lr}^
  44:	5c33746e 	cfldrspl	mvf7, [r3], #-440	; 0xfffffe48
  48:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xfffff2bb
  4c:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  50:	656c5f43 	strbvs	r5, [ip, #-3907]!	; 0xfffff0bd
  54:	6e6f7373 	mcrvs	3, 3, r7, cr15, cr3, {3}
  58:	4c5c3320 	mrrcmi	3, 2, r3, ip, cr0
  5c:	5c736261 	lfmpl	f6, 2, [r3], #-388	; 0xfffffe7c
  60:	3362614c 	cmncc	r2, #76, 2
  64:	6f687300 	svcvs	0x00687300
  68:	75207472 	strvc	r7, [r0, #-1138]!	; 0xfffffb8e
  6c:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  70:	2064656e 	rsbcs	r6, r4, lr, ror #10
  74:	00746e69 	rsbseq	r6, r4, r9, ror #28
  78:	69755f5f 	ldmdbvs	r5!, {r0, r1, r2, r3, r4, r6, r8, r9, sl, fp, ip, lr}^
  7c:	3233746e 	eorscc	r7, r3, #1845493760	; 0x6e000000
  80:	6c00745f 	cfstrsvs	mvf7, [r0], {95}	; 0x5f
  84:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  88:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  8c:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  90:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  94:	554e4700 	strbpl	r4, [lr, #-1792]	; 0xfffff900
  98:	37314320 	ldrcc	r4, [r1, -r0, lsr #6]!
  9c:	2e303120 	rsfcssp	f3, f0, f0
  a0:	20312e33 	eorscs	r2, r1, r3, lsr lr
  a4:	31323032 	teqcc	r2, r2, lsr r0
  a8:	34323830 	ldrtcc	r3, [r2], #-2096	; 0xfffff7d0
  ac:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  b0:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  b4:	2d202965 			; <UNDEFINED> instruction: 0x2d202965
  b8:	7570636d 	ldrbvc	r6, [r0, #-877]!	; 0xfffffc93
  bc:	726f633d 	rsbvc	r6, pc, #-201326592	; 0xf4000000
  c0:	2d786574 	cfldr64cs	mvdx6, [r8, #-464]!	; 0xfffffe30
  c4:	2d20336d 	stccs	3, cr3, [r0, #-436]!	; 0xfffffe4c
  c8:	6f6c666d 	svcvs	0x006c666d
  cc:	612d7461 			; <UNDEFINED> instruction: 0x612d7461
  d0:	733d6962 	teqvc	sp, #1605632	; 0x188000
  d4:	2074666f 	rsbscs	r6, r4, pc, ror #12
  d8:	68746d2d 	ldmdavs	r4!, {r0, r2, r3, r5, r8, sl, fp, sp, lr}^
  dc:	20626d75 	rsbcs	r6, r2, r5, ror sp
  e0:	72616d2d 	rsbvc	r6, r1, #2880	; 0xb40
  e4:	613d6863 	teqvs	sp, r3, ror #16
  e8:	37766d72 			; <UNDEFINED> instruction: 0x37766d72
  ec:	2d206d2d 	stccs	13, cr6, [r0, #-180]!	; 0xffffff4c
  f0:	61776467 	cmnvs	r7, r7, ror #8
  f4:	322d6672 	eorcc	r6, sp, #119537664	; 0x7200000
  f8:	6e6f6300 	cdpvs	3, 6, cr6, cr15, cr0, {0}
  fc:	765f7473 			; <UNDEFINED> instruction: 0x765f7473
 100:	61697261 	cmnvs	r9, r1, ror #4
 104:	00656c62 	rsbeq	r6, r5, r2, ror #24
 108:	6e69616d 	powvsez	f6, f1, #5.0
 10c:	736e7500 	cmnvc	lr, #0, 10
 110:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0xfffff897
 114:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
 118:	6f6c0074 	svcvs	0x006c0074
 11c:	6c20676e 	stcvs	7, cr6, [r0], #-440	; 0xfffffe48
 120:	20676e6f 	rsbcs	r6, r7, pc, ror #28
 124:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
 128:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
 12c:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
 130:	315f5000 	cmpcc	pc, r0
 134:	69760033 	ldmdbvs	r6!, {r0, r1, r4, r5}^
 138:	3233746e 	eorscc	r7, r3, #1845493760	; 0x6e000000
 13c:	6c00745f 	cfstrsvs	mvf7, [r0], {95}	; 0x5f
 140:	20676e6f 	rsbcs	r6, r7, pc, ror #28
 144:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
 148:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
 14c:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
 150:	00632e6e 	rsbeq	r2, r3, lr, ror #28
 154:	666c6c61 	strbtvs	r6, [ip], -r1, ror #24
 158:	646c6569 	strbtvs	r6, [ip], #-1385	; 0xfffffa97
 15c:	6f687300 	svcvs	0x00687300
 160:	69207472 	stmdbvs	r0!, {r1, r4, r5, r6, sl, ip, sp, lr}
 164:	5200746e 	andpl	r7, r0, #1845493760	; 0x6e000000
 168:	76657365 	strbtvc	r7, [r5], -r5, ror #6
 16c:	75006465 	strvc	r6, [r0, #-1125]	; 0xfffffb9b
 170:	33746e69 	cmncc	r4, #1680	; 0x690
 174:	00745f32 	rsbseq	r5, r4, r2, lsr pc
 178:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
 17c:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
 180:	67697300 	strbvs	r7, [r9, -r0, lsl #6]!
 184:	2064656e 	rsbcs	r6, r4, lr, ror #10
 188:	72616863 	rsbvc	r6, r1, #6488064	; 0x630000
 18c:	4f5f5200 	svcmi	0x005f5200
 190:	Address 0x00000190 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	4120554e 			; <UNDEFINED> instruction: 0x4120554e
   c:	45206d72 	strmi	r6, [r0, #-3442]!	; 0xfffff28e
  10:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  14:	20646564 	rsbcs	r6, r4, r4, ror #10
  18:	6c6f6f54 	stclvs	15, cr6, [pc], #-336	; fffffed0 <g_variables+0xfffffecc>
  1c:	69616863 	stmdbvs	r1!, {r0, r1, r5, r6, fp, sp, lr}^
  20:	3031206e 	eorscc	r2, r1, lr, rrx
  24:	322d332e 	eorcc	r3, sp, #-1207959552	; 0xb8000000
  28:	2e313230 	mrccs	2, 1, r3, cr1, cr0, {1}
  2c:	20293031 	eorcs	r3, r9, r1, lsr r0
  30:	332e3031 			; <UNDEFINED> instruction: 0x332e3031
  34:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  38:	30313230 	eorscc	r3, r1, r0, lsr r2
  3c:	20343238 	eorscs	r3, r4, r8, lsr r2
  40:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  44:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  48:	Address 0x00000048 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000007c 	andeq	r0, r0, ip, ror r0
  20:	87040e41 	strhi	r0, [r4, -r1, asr #28]
  24:	100e4101 	andne	r4, lr, r1, lsl #2
  28:	00070d41 	andeq	r0, r7, r1, asr #26

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002c41 	andeq	r2, r0, r1, asr #24
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000022 	andeq	r0, r0, r2, lsr #32
  10:	4d2d3705 	stcmi	7, cr3, [sp, #-20]!	; 0xffffffec
  14:	070a0600 	streq	r0, [sl, -r0, lsl #12]
  18:	1202094d 	andne	r0, r2, #1261568	; 0x134000
  1c:	15011404 	strne	r1, [r1, #-1028]	; 0xfffffbfc
  20:	18031701 	stmdane	r3, {r0, r8, r9, sl, ip}
  24:	1a011901 	bne	46430 <g_variables+0x4642c>
  28:	22061e01 	andcs	r1, r6, #1, 28
  2c:	Address 0x0000002c is out of bounds.

