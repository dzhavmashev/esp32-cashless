// Function : FUN_4010d520
// Address  : 0x4010d520
// Size     : 81 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010d520(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if ((char)param_1 < '\0') {
    param_1 = 0x7f;
  }
  else if (param_1 == 0) {
    return;
  }
  uVar1 = param_1 - 1U & 0xff;
  uVar3 = 0;
  iVar4 = 0;
  for (iVar2 = _DAT_3ffc840c; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
    uVar5 = (uint)*(byte *)(iVar2 + 0x40);
    if ((uVar5 < uVar1) ||
       ((uVar5 == uVar1 && (uVar3 <= (uint)(_DAT_3ffc8414 - *(int *)(iVar2 + 0x4c)))))) {
      uVar3 = _DAT_3ffc8414 - *(int *)(iVar2 + 0x4c);
      uVar1 = uVar5;
      iVar4 = iVar2;
    }
  }
  if (iVar4 != 0) {
    FUN_4010d4dc();
  }
  return;
}

