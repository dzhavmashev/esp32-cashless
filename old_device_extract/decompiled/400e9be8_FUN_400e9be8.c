// Function : FUN_400e9be8
// Address  : 0x400e9be8
// Size     : 45 bytes


undefined4 FUN_400e9be8(int param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x4c) == 0) || (*(int *)(param_1 + 0x50) == 0)) {
    uVar1 = FUN_400e9b14(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x40),
                         *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48));
  }
  else {
    uVar1 = FUN_400e9b4c();
  }
  return uVar1;
}

