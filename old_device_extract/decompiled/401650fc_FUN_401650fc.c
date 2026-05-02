// Function : FUN_401650fc
// Address  : 0x401650fc
// Size     : 40 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401650fc(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)&DAT_3ffc7d14;
  iVar1 = 0x13;
  do {
    if (*piVar2 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 0);
  memw();
  return;
}

