// Function : FUN_400e5484
// Address  : 0x400e5484
// Size     : 306 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e5484(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_401845e4(auStack_4c);
  FUN_400ec7a4(auStack_4c,"y_error",0);
  cVar1 = FUN_400ecfc4(auStack_4c,"IVATING state",0);
  iVar3 = FUN_400ecfa8(auStack_4c,"ror");
  if (iVar3 != 0) {
    FUN_400f0be8(auStack_44,&DAT_3f42161d);
    FUN_400ed090(auStack_34,auStack_4c,"ror",auStack_44);
    FUN_400f0d60(param_1 + 0x3c,auStack_34);
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_44);
  }
  uVar2 = FUN_400ecfc4(auStack_4c," - will retry",0);
  *(undefined1 *)(param_1 + 0x200) = uVar2;
  FUN_400ec888(auStack_4c);
  if ((byte)(cVar1 - 3U) < 3) {
    iVar4 = param_1 + 0x3c;
    iVar3 = FUN_400da468(iVar4);
    if (iVar3 == 0) {
      iVar3 = iVar4;
      if ((*(byte *)(param_1 + 0x4b) & 0x80) == 0) {
        iVar3 = *(int *)(param_1 + 0x3c);
      }
      FUN_400f06a4(0x3ffc5490,"by user",iVar3);
      FUN_400f0780(0x3ffc5490,"state.\n");
      FUN_400e53ac(param_1);
      FUN_400f0d70(iVar4,&DAT_3f42161d);
      *(undefined1 *)(param_1 + 0x200) = 0;
    }
  }
  FUN_400ec8a0(auStack_4c);
  iVar3 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400f0a50(auStack_44);
      FUN_400ec8a0(auStack_4c);
      thunk_FUN_401710d8(iVar3);
    } while( true );
  }
  return;
}

