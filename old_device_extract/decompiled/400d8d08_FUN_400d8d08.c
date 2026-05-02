// Function : FUN_400d8d08
// Address  : 0x400d8d08
// Size     : 95 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d8d08(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [36];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d716c(&local_50);
  local_50 = 0;
  uStack_4c = param_2;
  FUN_400f0d18(auStack_48,param_3);
  FUN_400d885c(param_1,&local_50);
  FUN_400d71a0(&local_50);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400d71a0(&local_50);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

