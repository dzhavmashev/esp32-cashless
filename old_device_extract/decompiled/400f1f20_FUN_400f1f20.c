// Function : FUN_400f1f20
// Address  : 0x400f1f20
// Size     : 66 bytes


int FUN_400f1f20(int *param_1)

{
  int iVar1;
  int aiStack_24 [9];
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      do {
        iVar1 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar1 != 1);
    }
    FUN_400f76b4((char)param_1[1],aiStack_24);
    if (*(char *)((int)param_1 + 5) != '\0') {
      aiStack_24[0] = aiStack_24[0] + 1;
    }
    iVar1 = aiStack_24[0];
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
      iVar1 = aiStack_24[0];
    }
  }
  return iVar1;
}

