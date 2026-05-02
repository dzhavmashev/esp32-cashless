// Function : FUN_400f7e4c
// Address  : 0x400f7e4c
// Size     : 74 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f7e4c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined1 auStack_128 [260];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  local_130 = *(undefined4 *)(param_1 + 0xc);
  uStack_12c = *(undefined4 *)(param_1 + 0x10);
  memw();
  iVar1 = FUN_400f8b1c(param_2,&local_130,auStack_128);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x1503;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return uVar2;
}

