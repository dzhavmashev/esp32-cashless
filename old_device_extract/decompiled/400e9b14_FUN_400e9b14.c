// Function : FUN_400e9b14
// Address  : 0x400e9b14
// Size     : 54 bytes


undefined4
FUN_400e9b14(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  FUN_400f057c(auStack_30);
  iVar1 = FUN_400e8470(param_2,auStack_30);
  uVar2 = 0;
  if (iVar1 != 0) {
    puStack_28 = &DAT_3f40a508;
    uStack_24 = uStack_2c;
    uVar2 = FUN_400e9a60(param_1,&puStack_28,param_3,param_2,param_4,param_5,param_6);
  }
  return uVar2;
}

