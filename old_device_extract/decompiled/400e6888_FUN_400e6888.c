// Function : FUN_400e6888
// Address  : 0x400e6888
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6888(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_44,param_2);
  FUN_400f0be8(auStack_34,param_3);
  FUN_400f1558(param_1,auStack_44,auStack_34);
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(auStack_44);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400f0a50(auStack_44);
      thunk_FUN_401710d8(iVar1);
    } while( true );
  }
  return;
}

