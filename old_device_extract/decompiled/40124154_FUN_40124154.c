// Function : FUN_40124154
// Address  : 0x40124154
// Size     : 112 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40124154(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 auStack_62 [6];
  undefined1 auStack_5c [32];
  undefined1 auStack_3c [8];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_62,param_3,6);
  (*(code *)&SUB_4008b3d0)(auStack_5c,param_4,0x20);
  FUN_40104fb4(auStack_3c);
  iVar1 = FUN_40102858(auStack_34,0x10);
  memw();
  FUN_40101ce8(param_1,0x20,param_2,auStack_62,0x3e,param_5,param_6);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1 >> 0x1f;
}

