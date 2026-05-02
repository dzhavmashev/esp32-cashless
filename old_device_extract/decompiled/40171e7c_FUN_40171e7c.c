// Function : FUN_40171e7c
// Address  : 0x40171e7c
// Size     : 33 bytes


undefined4 FUN_40171e7c(int *param_1,int param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  puStack_28 = &DAT_3f40a508;
  uStack_24 = *(undefined4 *)(param_2 + 4);
  uVar1 = (**(code **)(*param_1 + 0x48))(param_1,&puStack_28,param_3,param_1[9]);
  return uVar1;
}

