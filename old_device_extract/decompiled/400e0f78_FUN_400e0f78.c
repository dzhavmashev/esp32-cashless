// Function : FUN_400e0f78
// Address  : 0x400e0f78
// Size     : 133 bytes


int FUN_400e0f78(undefined4 param_1,int param_2,undefined4 param_3,char param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_40183ab0(param_1,param_5);
  if (iVar1 != 0) {
    if (param_4 == '\0') {
      param_2 = FUN_40183bf4(param_5);
      if (param_2 != 0) {
        *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) | 0x80;
        *(int *)(iVar1 + 0xc) = param_2;
      }
    }
    else if (param_2 != 0) {
      *(int *)(iVar1 + 0xc) = param_2;
      *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0x7f;
    }
    if (param_2 == 0) {
      FUN_400e04ac(param_1,iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

