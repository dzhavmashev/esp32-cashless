// Function : FUN_40171ed0
// Address  : 0x40171ed0
// Size     : 57 bytes


undefined4 FUN_40171ed0(int *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  FUN_400f0584(auStack_30,0);
  iVar1 = FUN_400e8468(param_2,auStack_30);
  uVar2 = 0;
  if (iVar1 != 0) {
    puStack_28 = &DAT_3f40a508;
    uStack_24 = uStack_2c;
    uVar2 = (**(code **)(*param_1 + 0x48))(param_1,&puStack_28,param_3,param_4);
  }
  return uVar2;
}

