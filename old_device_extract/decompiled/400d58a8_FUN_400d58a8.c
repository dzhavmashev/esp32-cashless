// Function : FUN_400d58a8
// Address  : 0x400d58a8
// Size     : 140 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400d58a8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 auStack_a0 [40];
  undefined1 auStack_78 [40];
  undefined1 auStack_50 [40];
  undefined4 uStack_28;
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  func_0x4008b3d8(auStack_a0,param_2,0x28);
  func_0x4008b3d8(auStack_78,auStack_a0);
  func_0x4008b3d8(auStack_50,auStack_78);
  uStack_28 = 0;
  FUN_400d3f28(auStack_78);
  FUN_400d3f28(auStack_a0);
  puVar2 = (undefined4 *)&DAT_3ffc5708;
  if (param_1 == 0) goto LAB_400d5920;
  uVar1 = FUN_400d5744(param_1,auStack_50);
  puVar2 = (undefined4 *)&DAT_3ffc5708;
  while( true ) {
    FUN_400d3f28(auStack_50);
    memw();
    memw();
    puVar2 = (undefined4 *)*puVar2;
    if (puStack_24 == puVar2) break;
    func_0x40082ecc();
LAB_400d5920:
    FUN_400d4ac0(auStack_50,"PIO ISR null");
    uVar1 = uStack_28;
  }
  return uVar1;
}

