// Function : FUN_4012c9dc
// Address  : 0x4012c9dc
// Size     : 53 bytes


int FUN_4012c9dc(int *param_1)

{
  int iVar1;
  
  iVar1 = -0x7100;
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) &&
     ((*(char *)(*param_1 + 5) != '\x01' || ((param_1[0x17] != 0 && (param_1[0x18] != 0)))))) {
    do {
      if (param_1[1] == 0x10) {
        return 0;
      }
      iVar1 = FUN_4012c9ac(param_1);
    } while (iVar1 == 0);
  }
  return iVar1;
}

