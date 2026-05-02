// Function : FUN_400e9824
// Address  : 0x400e9824
// Size     : 32 bytes


undefined4 FUN_400e9824(int *param_1,int param_2,undefined2 param_3,int param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  puStack_28 = &DAT_3f40a508;
  uStack_24 = *(undefined4 *)(param_2 + 4);
  pcVar2 = *(code **)(*param_1 + 0x30);
  param_1[0xe] = param_4;
  uVar1 = (*pcVar2)(param_1,&puStack_28,param_3);
  return uVar1;
}

