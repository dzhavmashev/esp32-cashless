// Function : FUN_400e9c84
// Address  : 0x400e9c84
// Size     : 62 bytes


undefined4 FUN_400e9c84(int param_1,int param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  if ((*(int *)(param_1 + 0x4c) == 0) || (*(int *)(param_1 + 0x50) == 0)) {
    puStack_28 = &DAT_3f40a508;
    uStack_24 = *(undefined4 *)(param_2 + 4);
    uVar1 = FUN_400e9aec(param_1,&puStack_28,param_3,*(undefined4 *)(param_1 + 0x40),
                         *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48));
  }
  else {
    puStack_28 = &DAT_3f40a508;
    uStack_24 = *(undefined4 *)(param_2 + 4);
    uVar1 = FUN_400e9c18(param_1,&puStack_28);
  }
  return uVar1;
}

