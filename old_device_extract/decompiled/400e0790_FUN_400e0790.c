// Function : FUN_400e0790
// Address  : 0x400e0790
// Size     : 269 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e0790(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 local_90;
  undefined1 auStack_88 [4];
  undefined8 uStack_84;
  char *pcStack_7c;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [44];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d4330(param_3 + 0x18,"command_id");
  uVar1 = FUN_400e059c();
  FUN_400f0be8(auStack_44,uVar1);
  FUN_400d7378(auStack_78,0x100,0);
  local_90 = FUN_400e06e4(auStack_70);
  iVar2 = FUN_400e5988(0x3ffc4ae8,auStack_44,&local_90);
  if (iVar2 == 0) {
    pcStack_7c = " an SSL message";
    uStack_84 = local_90;
    uVar1 = FUN_400e0768(auStack_88,"aborted");
    FUN_400f0be8(auStack_34,uVar1);
    *param_1 = 1;
    FUN_400f0d4c(param_1 + 1,auStack_34);
  }
  else {
    FUN_400f0be8(auStack_34,"stopped");
    *param_1 = 0;
    FUN_400f0d4c(param_1 + 1,auStack_34);
  }
  param_1[5] = 0;
  FUN_400f0a50(auStack_34);
  FUN_400d73a8(auStack_78);
  FUN_400f0a50(auStack_44);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    do {
      FUN_400f0a50(auStack_34);
      FUN_400d73a8(auStack_78);
      FUN_400f0a50(auStack_44);
      thunk_FUN_401710d8(param_1);
    } while( true );
  }
  return;
}

