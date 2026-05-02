// Function : FUN_400f20e8
// Address  : 0x400f20e8
// Size     : 71 bytes


void FUN_400f20e8(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 != 0 && param_3 != 0) && (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      do {
        iVar1 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar1 != 1);
    }
    FUN_400f74e0((char)param_1[1],param_2,param_3);
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
    }
  }
  return;
}

