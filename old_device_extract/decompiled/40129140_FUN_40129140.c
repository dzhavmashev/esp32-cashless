// Function : FUN_40129140
// Address  : 0x40129140
// Size     : 112 bytes


undefined4 FUN_40129140(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar4 = 2;
  uVar1 = 0;
  if (*(char *)(iVar5 + 5) != '\x01') {
    iVar4 = 0;
  }
  if (((param_1[1] == 0x10) && (param_1[2] != 3)) && (*(char *)(iVar5 + 0xd) != '\0')) {
    iVar5 = iVar5 + 0x24 + iVar4;
    uVar2 = (*(code *)&SUB_4008b33c)(param_1[0x1a] + iVar4,iVar5,8 - iVar4);
    uVar3 = (*(code *)&SUB_4008b33c)((int)param_1 + iVar4 + 0xdc,iVar5,8 - iVar4);
    uVar1 = 0;
    if ((-1 < (int)(uVar2 | uVar2 - 1)) || (-1 < (int)(uVar3 | uVar3 - 1))) {
      uVar1 = FUN_4012cd90(param_1);
    }
  }
  return uVar1;
}

