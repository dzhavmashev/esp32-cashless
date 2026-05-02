// Function : FUN_4012c9ac
// Address  : 0x4012c9ac
// Size     : 45 bytes


undefined4 FUN_4012c9ac(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff8f00;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = 0xffff8f80;
    if (*(char *)(*param_1 + 4) == '\0') {
      uVar1 = FUN_4012d964(param_1);
    }
    if (*(char *)(*param_1 + 4) == '\x01') {
      uVar1 = FUN_4012f598(param_1);
    }
  }
  return uVar1;
}

