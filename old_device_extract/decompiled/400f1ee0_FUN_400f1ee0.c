// Function : FUN_400f1ee0
// Address  : 0x400f1ee0
// Size     : 63 bytes


bool FUN_400f1ee0(int *param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      do {
        iVar2 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar2 != 1);
    }
    iVar2 = FUN_400f7d10((char)param_1[1],param_2);
    bVar1 = iVar2 == 0;
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0,0);
    }
  }
  return bVar1;
}

