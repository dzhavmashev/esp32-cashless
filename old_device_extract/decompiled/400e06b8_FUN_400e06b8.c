// Function : FUN_400e06b8
// Address  : 0x400e06b8
// Size     : 41 bytes


void FUN_400e06b8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    FUN_400e7730(*(undefined4 *)(param_1 + 8),1);
    FUN_400f1ab4(param_3);
    FUN_400e7730(*(undefined4 *)(param_1 + 8),0);
    FUN_400f1ab4(param_3);
  }
  return;
}

