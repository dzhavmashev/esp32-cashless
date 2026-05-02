// Function : FUN_400e9734
// Address  : 0x400e9734
// Size     : 102 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e9734(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined *puVar2;
  undefined1 auStack_36 [18];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  puVar1 = (undefined1 *)FUN_400e96f0(param_2);
  puVar2 = &DAT_3f42161d;
  if (puVar1 != (undefined1 *)0x0) {
    func_0x4008b538(auStack_36,0,0x12);
    FUN_4017435c(auStack_36,"iled!\r\n",*puVar1,puVar1[1],puVar1[2],puVar1[3],puVar1[4],puVar1[5]);
    puVar2 = auStack_36;
  }
  FUN_400f0be8(param_1,puVar2);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

