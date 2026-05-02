// Function : FUN_400ebe5c
// Address  : 0x400ebe5c
// Size     : 105 bytes


void FUN_400ebe5c(undefined2 *param_1,undefined1 *param_2,char param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  *param_1 = (short)param_4;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar2 = FUN_400ebc28(param_1,2,1);
  uVar1 = 1;
  if (iVar2 != 0) {
    **(char **)(param_1 + 2) = param_3;
    if (param_3 == '`') {
      **(byte **)(param_1 + 2) = **(byte **)(param_1 + 2) | 2;
    }
    iVar2 = FUN_401845b0(2,*(int *)(param_1 + 2) + 1);
    *(char *)(*(int *)(param_1 + 2) + iVar2 + 1) = (char)((param_4 & 0xffff) >> 8);
    uVar1 = 0;
    *(char *)(*(int *)(param_1 + 2) + iVar2 + 2) = (char)(param_4 & 0xffff);
  }
  *param_2 = uVar1;
  return;
}

