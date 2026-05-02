// Function : FUN_400e071c
// Address  : 0x400e071c
// Size     : 29 bytes


void FUN_400e071c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_400e071c(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    FUN_400e0490(param_2);
    param_2 = iVar1;
  }
  return;
}

