// Function : FUN_40104f58
// Address  : 0x40104f58
// Size     : 43 bytes


uint FUN_40104f58(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = (*(code *)&LAB_40185007_1)(*param_1);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    uVar3 = (*(code *)&LAB_40185007_1)(param_1[1]);
    uVar2 = 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar2 = iVar1 << 4 | uVar3;
    }
  }
  return uVar2;
}

