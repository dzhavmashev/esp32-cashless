// Function : FUN_4018de9c
// Address  : 0x4018de9c
// Size     : 51 bytes


void FUN_4018de9c(void)

{
  uint uVar1;
  int *piVar2;
  int *in_t0;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  piVar2 = (int *)&DAT_3ffc6768;
  if ((uVar1 >> 0xd & 1) < 2) goto LAB_4018deb1;
  do {
    piVar2 = in_t0;
    (*(code *)&SUB_40094bc8)();
    in_t0 = piVar2;
LAB_4018deb1:
    do {
      memw();
    } while (*piVar2 == 0);
    (*(code *)&LAB_400fd3ba_2)();
    FUN_400fd1a0();
    (*(code *)&SUB_4009299c)();
  } while( true );
}

