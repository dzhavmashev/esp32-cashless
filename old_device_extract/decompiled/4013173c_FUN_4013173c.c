// Function : FUN_4013173c
// Address  : 0x4013173c
// Size     : 88 bytes


int FUN_4013173c(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  
  param_3 = param_3 & 0xff;
  iVar2 = -4;
  if ((param_3 < 2) &&
     ((param_2 < (uint)(*(int *)(param_1 + 4) << 5) ||
      ((iVar2 = 0, param_3 != 0 && (iVar2 = FUN_40131574(param_1,(param_2 >> 5) + 1), iVar2 == 0))))
     )) {
    puVar1 = (uint *)(*(int *)(param_1 + 8) + (param_2 >> 5) * 4);
    iVar2 = 0;
    *puVar1 = (uint)(0xfffffffefffffffe >> 0x20 - (param_2 & 0x1f)) & *puVar1 |
              param_3 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  memw();
  return iVar2;
}

