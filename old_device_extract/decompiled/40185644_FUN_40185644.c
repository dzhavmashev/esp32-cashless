// Function : FUN_40185644
// Address  : 0x40185644
// Size     : 30 bytes


int FUN_40185644(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    while( true ) {
      if (*param_1 == 0) break;
      iVar1 = iVar1 + (uint)*(ushort *)(*param_1 + 2);
      param_1 = param_1 + 1;
    }
  }
  return iVar1;
}

