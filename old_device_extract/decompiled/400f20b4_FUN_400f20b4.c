// Function : FUN_400f20b4
// Address  : 0x400f20b4
// Size     : 51 bytes


void FUN_400f20b4(int *param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 auStack_24 [36];
  
  if (param_1 != (int *)0x0) {
    auStack_24[0] = param_2;
    if (*param_1 != 0) {
      do {
        iVar1 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar1 != 1);
    }
    FUN_400f74e0((char)param_1[1],auStack_24,1);
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
    }
  }
  return;
}

