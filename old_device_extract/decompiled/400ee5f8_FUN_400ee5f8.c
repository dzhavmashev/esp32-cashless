// Function : FUN_400ee5f8
// Address  : 0x400ee5f8
// Size     : 197 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ee5f8(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined *puStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  undefined *puStack_24;
  
  iVar2 = *(int *)(param_2 + 0x98);
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  if (((iVar2 >> 0x1f) - iVar2 < 0) || (iVar2 == -1)) {
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_3c = 1000;
    puStack_44 = &DAT_3f40a51c;
    FUN_400f0be8(auStack_34,&DAT_3f42161d);
    puStack_44 = &DAT_3f40a554;
    iVar2 = FUN_400f0b60(auStack_34,*(int *)(param_2 + 0x98) + 1);
    if (iVar2 != 0) {
      FUN_400ee4a4(param_2,&puStack_44);
      FUN_400f0d04(param_1,auStack_34);
      puStack_44 = &DAT_3f40a554;
      FUN_400f0a50(auStack_34);
      goto LAB_400ee699;
    }
    puStack_44 = &DAT_3f40a554;
    FUN_400f0a50(auStack_34);
  }
  FUN_400f0be8(param_1,&DAT_3f42161d);
LAB_400ee699:
  puVar1 = puStack_24;
  memw();
  memw();
  if (puStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    puStack_44 = puVar1;
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(param_1);
  }
  return;
}

