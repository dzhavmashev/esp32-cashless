// Function : FUN_400e1058
// Address  : 0x400e1058
// Size     : 249 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e1058(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 local_80;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [44];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  param_3 = param_3 + 0x18;
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d4330(param_3,"command_id");
  uVar1 = FUN_400e059c();
  FUN_400f0be8(auStack_44,uVar1);
  FUN_400d7378(auStack_78,0x400,0);
  iVar2 = FUN_400d4330(param_3,"Missing params");
  if (iVar2 != 0) {
    local_80._0_4_ = FUN_400d4330(param_3,"Missing params");
    FUN_400e1028(auStack_70,&local_80);
  }
  local_80 = FUN_401841b0(auStack_70);
  FUN_400e5614(0x3ffc4ae8,auStack_44,&local_80);
  FUN_400f0be8(auStack_34,"a_abort");
  *param_1 = 0;
  FUN_400f0d4c(param_1 + 1,auStack_34);
  param_1[5] = 0;
  FUN_400f0a50(auStack_34);
  FUN_400d73a8(auStack_78);
  FUN_400f0a50(auStack_44);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400d73a8(auStack_78);
      FUN_400f0a50(auStack_44);
      thunk_FUN_401710d8(param_1);
    } while( true );
  }
  return;
}

