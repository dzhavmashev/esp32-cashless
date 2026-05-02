// Function : FUN_4011fc40
// Address  : 0x4011fc40
// Size     : 49 bytes


undefined4
FUN_4011fc40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined1 auStack_50 [8];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [32];
  
  puStack_28 = auStack_50;
  puStack_2c = auStack_20;
  uStack_24 = 0xc;
  memw();
  uStack_48 = param_3;
  uStack_44 = param_4;
  uStack_40 = param_5;
  uStack_3c = param_6;
  uVar1 = (*(code *)&SUB_4009164c)();
  uVar1 = FUN_400fee18(uVar1,param_1,param_2,param_3);
  return uVar1;
}

