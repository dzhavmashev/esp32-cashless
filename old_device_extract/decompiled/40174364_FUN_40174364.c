// Function : FUN_40174364
// Address  : 0x40174364
// Size     : 87 bytes


undefined4
FUN_40174364(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined1 *local_c0 [2];
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 *puStack_b0;
  undefined4 uStack_ac;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_50;
  undefined1 auStack_40 [8];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_20 [32];
  
  uStack_ac = 0x7fffffff;
  uStack_b8 = 0x7fffffff;
  uStack_b4 = 0xffff0208;
  puStack_58 = auStack_20;
  puStack_54 = auStack_40;
  uStack_50 = 8;
  local_c0[0] = param_1;
  puStack_b0 = param_1;
  uStack_38 = param_3;
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  uVar1 = (*(code *)&SUB_4009164c)();
  uVar1 = FUN_40174c80(uVar1,local_c0,param_2,puStack_58,puStack_54,uStack_50);
  *local_c0[0] = 0;
  return uVar1;
}

