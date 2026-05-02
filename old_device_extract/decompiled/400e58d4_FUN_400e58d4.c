// Function : FUN_400e58d4
// Address  : 0x400e58d4
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e58d4(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_84 [16];
  undefined1 *apuStack_74 [9];
  undefined4 uStack_50;
  undefined1 auStack_4c [40];
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar2 = FUN_400da4f0(*(undefined4 *)(param_1 + 0xf4));
  if (iVar2 == 0) goto LAB_400e596d;
  puVar4 = auStack_84;
  FUN_400f0be8(puVar4,&DAT_3f42161d);
  uVar3 = *param_3;
  uStack_50 = 0;
  apuStack_74[0] = puVar4;
  func_0x4008b3d8(auStack_4c,apuStack_74,0x28);
  FUN_400d58a8(uVar3,auStack_4c);
  FUN_400d3f28(auStack_4c);
  FUN_400d3f28(apuStack_74);
  FUN_400dba34(*(undefined4 *)(param_1 + 0xf4),param_2,puVar4);
  while( true ) {
    FUN_400f0a50(puVar4);
LAB_400e596d:
    puVar4 = puStack_24;
    puVar1 = _DAT_3ffc5708;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    FUN_400f0a50(puVar4);
    thunk_FUN_401710d8(puVar1);
  }
  return;
}

