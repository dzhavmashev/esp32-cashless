// Function : FUN_400e4af0
// Address  : 0x400e4af0
// Size     : 169 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e4af0(undefined1 *param_1)

{
  int iVar1;
  undefined1 auStack_3c [8];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_401845e4(auStack_3c);
  FUN_400ec7a4(auStack_3c,"y_error",0);
  FUN_400ec968(auStack_3c,"IVATING state",*param_1);
  FUN_400f0d4c(auStack_34,param_1 + 0x3c);
  FUN_400ecdc4(auStack_3c,"ror",auStack_34);
  FUN_400f0a50(auStack_34);
  FUN_400ec968(auStack_3c," - will retry",param_1[0x200]);
  FUN_400ec888(auStack_3c);
  FUN_400ec8a0(auStack_3c);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400ec8a0(auStack_3c);
      thunk_FUN_401710d8(iVar1);
    } while( true );
  }
  return;
}

