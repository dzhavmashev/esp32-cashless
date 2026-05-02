// Function : FUN_400d4268
// Address  : 0x400d4268
// Size     : 129 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d4268(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar3 = param_1 + 0x10;
  FUN_400f0be8(param_1,&DAT_3f42161d);
  FUN_400f0be8(iVar3,&DAT_3f42161d);
  FUN_400f0be8(auStack_34,&DAT_3f42161d);
  FUN_400f0d60(iVar3,auStack_34);
  FUN_400f0a50(auStack_34);
  iVar2 = iStack_24;
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400f0a50(iVar3);
      FUN_400f0a50(iVar2);
      thunk_FUN_401710d8(iVar1);
    } while( true );
  }
  return;
}

